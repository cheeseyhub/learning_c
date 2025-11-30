# --- Automated C Project Setup Script (Run as Administrator) ---
# Paste this entire block into an elevated PowerShell window.

# --- 0. CRITICAL CHECK: Ensure Elevation ---
if (-not ([Security.Principal.WindowsPrincipal][Security.Principal.WindowsIdentity]::GetCurrent()).IsInRole([Security.Principal.WindowsBuiltInRole] "Administrator")) {
    Write-Host "--- ERROR: ELEVATION REQUIRED ---" -ForegroundColor Red
    Write-Host "This script MUST be run in an elevated (Run as Administrator) PowerShell window." -ForegroundColor Red
    Write-Host "Exiting script. Please restart PowerShell as Administrator." -ForegroundColor Red
    exit 1
}

# --- Function to Reload the Environment PATH ---
function Update-SessionPath {
    Write-Host "Reloading system PATH environment variables..." -ForegroundColor DarkYellow
    $env:Path = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")
}

# --- Configuration ---
$repoUrl = "https://github.com/cheeseyhub/learning_c.git"
$projectDirName = "cfp_project"
$desktopPath = "$env:USERPROFILE\Desktop"
$fullProjectPath = Join-Path -Path $desktopPath -ChildPath $projectDirName
$toolsToInstall = "make", "mingw", "vscode", "git"

# Set execution policy for the current process to allow script execution
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass -Force

# 1. Check and Install Chocolatey
Write-Host "Checking for and installing Chocolatey..." -ForegroundColor Yellow
if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
    [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12
    iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
    
    # Reload PATH immediately after installing Choco
    Update-SessionPath 
    Write-Host "Chocolatey installed." -ForegroundColor Green
} else {
    Write-Host "Chocolatey is already installed." -ForegroundColor Green
}

# 2. Install Required Tools
Write-Host "Installing required tools: $($toolsToInstall -join ', ')..." -ForegroundColor Yellow
try {
    choco install $toolsToInstall -y -Force -ErrorAction Stop
    
    # Reload PATH immediately after installing tools like Git and VS Code
    Update-SessionPath 
    Write-Host "Tools installed successfully." -ForegroundColor Green
} catch {
    Write-Host "--- ERROR: TOOL INSTALLATION FAILED ---" -ForegroundColor Red
    Write-Host "The installation of required tools failed. Error: $($_.Exception.Message)" -ForegroundColor Red
    exit 1
}

# 3. Create Project Directory
Write-Host "Creating project directory..." -ForegroundColor Yellow
New-Item -Path $fullProjectPath -ItemType Directory -Force | Out-Null
cd $fullProjectPath

# 4. Clone the Repository
Write-Host "Attempting to clone repository $repoUrl..." -ForegroundColor Yellow
try {
    # Final check: ensure git command is recognized now
    if (-not (Get-Command git -ErrorAction SilentlyContinue)) {
        throw "The 'git' command is still not recognized after PATH update. Manual intervention is required."
    }
    
    git clone $repoUrl . -ErrorAction Stop
    Write-Host "Repository cloned successfully." -ForegroundColor Green
} catch {
    Write-Host "--- CRITICAL ERROR: GIT CLONE FAILED ---" -ForegroundColor Red
    Write-Host "Failed to clone the repository $repoUrl." -ForegroundColor Red
    Write-Host "Specific Error Message (Likely PATH or Network issue):" -ForegroundColor Red
    Write-Host "$($_.Exception.Message)" -ForegroundColor Red
    exit 1
}


# 5. Clean up and Isolate the 'template' Folder
Write-Host "Isolating 'template' folder..." -ForegroundColor Yellow
$tempDir = "template_temp_$(Get-Random)"
$templatePath = Join-Path -Path $fullProjectPath -ChildPath "template"
$templateTempPath = Join-Path -Path $desktopPath -ChildPath $tempDir

if (Test-Path $templatePath) {
    Move-Item -Path $templatePath -Destination $templateTempPath -Force
    cd $desktopPath # Move out of the directory before deletion
    Remove-Item -Path $fullProjectPath -Recurse -Force
    New-Item -Path $fullProjectPath -ItemType Directory -Force | Out-Null
    Move-Item -Path $templateTempPath -Destination $templatePath -Force
    cd $templatePath
} else {
    Write-Error "Template folder not found after cloning. Cannot proceed with cleanup."
    exit 1
}

# 6. Open in VS Code
Write-Host "Setup complete. Opening project in VS Code..." -ForegroundColor Green
code .

Write-Host "---"
Write-Host "You are now in the $projectDirName/template directory. Start coding!" -ForegroundColor Green
