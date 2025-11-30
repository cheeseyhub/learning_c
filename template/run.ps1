# Requires -RunAsAdministrator

# --- Configuration ---
$repoUrl = "https://github.com/cheeseyhub/learning_c.git"
$projectDirName = "cfp_project"
$desktopPath = "$env:USERPROFILE\Desktop"
$fullProjectPath = Join-Path -Path $desktopPath -ChildPath $projectDirName
$templateTempPath = Join-Path -Path $desktopPath -ChildPath "template_temp_$(Get-Random)"
$templatePath = Join-Path -Path $fullProjectPath -ChildPath "template"
$toolsToInstall = "make", "mingw", "vscode", "git"

# Set execution policy for the current process to allow the script to run.
Set-ExecutionPolicy -Scope Process -ExecutionPolicy Bypass -Force

# --- Function to Install Chocolatey ---
function Install-Chocolatey {
    Write-Host "Checking for Chocolatey..." -ForegroundColor Yellow
    if (-not (Get-Command choco -ErrorAction SilentlyContinue)) {
        Write-Host "Chocolatey not found. Installing now..." -ForegroundColor Cyan
        
        # Installation command (Must be run in elevated shell)
        [System.Net.ServicePointManager]::SecurityProtocol = [System.Net.ServicePointManager]::SecurityProtocol -bor 3072
        iex ((New-Object System.Net.WebClient).DownloadString('https://community.chocolatey.org/install.ps1'))
        
        # Ensure choco command is available in the current session
        $env:Path = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")
        Write-Host "Chocolatey installed successfully." -ForegroundColor Green
    } else {
        Write-Host "Chocolatey is already installed." -ForegroundColor Green
    }
}

# --- Main Setup Process ---

# 1. Install Chocolatey
Install-Chocolatey

# 2. Install Required Tools
Write-Host "Installing required development tools: $($toolsToInstall -join ', ')..." -ForegroundColor Yellow
choco install $toolsToInstall -y

# 3. Navigate to Desktop and Set up Project Directory
Write-Host "Setting up project directory on the Desktop..." -ForegroundColor Yellow

# Ensure the desktop path exists
if (-not (Test-Path $desktopPath)) {
    Write-Error "Desktop path not found: $desktopPath"
    exit 1
}

# Create and navigate to the project folder
New-Item -Path $fullProjectPath -ItemType Directory -Force | Out-Null
cd $fullProjectPath

# 4. Clone the Repository
Write-Host "Cloning repository $repoUrl into $fullProjectPath..." -ForegroundColor Yellow
git clone $repoUrl .

# 5. Clean up and Isolate the 'template' Folder
Write-Host "Isolating 'template' folder..." -ForegroundColor Yellow

if (-not (Test-Path $templatePath)) {
    Write-Error "The 'template' folder was not found after cloning. Aborting cleanup."
    exit 1
}

# Temporarily move 'template' folder out
Move-Item -Path $templatePath -Destination $templateTempPath -Force

# Delete everything else in the current directory ($fullProjectPath)
Get-ChildItem -Path $fullProjectPath | Remove-Item -Force -Recurse

# Move 'template' folder back in
Move-Item -Path $templateTempPath -Destination $templatePath -Force

# 6. Change Directory into Template
cd $templatePath

# 7. Open in VS Code
Write-Host "Setup complete! Opening project in VS Code..." -ForegroundColor Green
code .

Write-Host "---"
Write-Host "You are now in the $projectDirName/template directory. Start coding!" -ForegroundColor Green
# The script execution finishes here.
