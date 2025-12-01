# C Projects
  Here are my labs_practice , and c projects;
 Must have make , gcc or mingw installed to compile .
## Instruction for installing the library (5.5v)
 
 
### Setting  for computer center in university (pieas)(windows).
The proxy may vary depending on the university, so edit as desired. Paste this command below in PowerShell
```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression

scoop install git mingw make

git config --global http.proxy http://172.30.10.11:3128
git config --global https.proxy http://172.30.10.11:3128

scoop bucket add extras
scoop install vscode
```

### For setting up a personal computer
Please remember, if you have already installed git and make and mingw, you can just  skip the following part.

Pase The command below in powershell.

```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression

scoop install git mingw make


scoop bucket add extras
scoop install vscode
 
```

---

<img width="964" height="608" alt="image" src="https://github.com/user-attachments/assets/7efc46b9-697d-4b1f-8d46-d77c2bf79739" />


**Now click on the Green code button in the current repository:**

<img width="453" height="377" alt="image" src="https://github.com/user-attachments/assets/051b9b16-ac6d-4a35-8dea-96ac5af47a91" />

---

**Download the zip file and extract it.**

<img width="351" height="146" alt="image" src="https://github.com/user-attachments/assets/2eef1f0d-7a50-47c1-9603-1ee90f3b85f3" />

---

**Open the folder and then cut and paste the template folder into your desired location.**

<img width="515" height="218" alt="image" src="https://github.com/user-attachments/assets/65dcdfc0-70d5-4197-9a2f-12d41adc4cf7" />

---

**You can now delete the other folders only the template folder is required,  Other folders contain examples**

<img width="175" height="149" alt="image" src="https://github.com/user-attachments/assets/487142b0-7165-41d2-bc87-917fc3b92990" />

---

**Now open vscode click on the file tab on the top left and navigate to the place where you put the template folder and open it.**

<img width="802" height="459" alt="image" src="https://github.com/user-attachments/assets/672a55ab-6145-47e4-b303-69c88b28d46a" /> \

<img width="550" height="414" alt="image" src="https://github.com/user-attachments/assets/b6df752f-c13e-4307-b56d-08fbe05a5bbd" />\



---
**Now click on the gear icon on the bottom left and set the autosave option.**

<img width="375" height="517" alt="image" src="https://github.com/user-attachments/assets/bd771087-c213-4b83-af53-02053f15c269" />

<img width="740" height="493" alt="image" src="https://github.com/user-attachments/assets/0a9882f2-82c9-44ca-8f82-dd1b7de3537f" />

<img width="569" height="333" alt="image" src="https://github.com/user-attachments/assets/d703d3a8-8421-411c-bca4-1105e792830b" />


---
**Now click on the main.c file**
You can open the terminal with the  ""Control + `"" shortcut.

Type make windows to compile the file.
<img width="782" height="766" alt="image" src="https://github.com/user-attachments/assets/2f3fcc5f-656f-4d71-b9b0-3af100cae68c" />

Then type ".\main.exe" to run the file.
<img width="903" height="656" alt="image" src="https://github.com/user-attachments/assets/3f5980b8-0fed-4b26-bdbb-f98d0e27ff01" />

















