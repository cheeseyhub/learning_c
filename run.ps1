# --- Automated Tool Installation Script (Run as Administrator) ---
# This script ensures Chocolatey is installed, then installs make, mingw, vscode, and git.
# It stops immediately after successful installation and reloading the environment path.
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
    # Pulls the latest PATH variables from the system environment
    $env:Path = [System.Environment]::GetEnvironmentVariable("Path", "Machine") + ";" + [System.Environment]::GetEnvironmentVariable("Path", "User")
}

# --- Configuration ---
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

# --- Final Message ---
Write-Host "--------------------------------------------------------" -ForegroundColor Cyan
Write-Host "Prerequisite setup is complete!" -ForegroundColor Green
Write-Host "You may need to close and reopen your PowerShell window or VS Code for the new tools (make, git, code) to be recognized globally." -ForegroundColor White
Write-Host "--------------------------------------------------------" -ForegroundColor Cyan
