# C Projects
  Here are my labs_practice , and c projects;
 Must have make, gcc, or mingw installed to compile.
## Instruction for installing the library (5.5v)
 
 
### Setting  for computer center in university (pieas)(windows).
#### The proxy may vary depending on the university, so edit as desired. Paste this command below in PowerShell and then scroll down and follow picture instructions.
```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression

scoop install git mingw make

git config --global http.proxy http://172.30.10.11:3128
git config --global https.proxy http://172.30.10.11:3128

scoop bucket add extras
scoop install vscode
```

## For setting up on  a personal computer
#### Please remember, if you have already installed git and make, and mingw, you can just  skip the following part.

#### Paste the command below in PowerShell and scroll down and follow the image instructions.

```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression

scoop install git mingw make


scoop bucket add extras
scoop install vscode
 
```

---

<img width="964" height="608" alt="image" src="https://github.com/user-attachments/assets/7efc46b9-697d-4b1f-8d46-d77c2bf79739" />


#### **Now click on the Green code button in the current repository:**

<img width="453" height="377" alt="image" src="https://github.com/user-attachments/assets/051b9b16-ac6d-4a35-8dea-96ac5af47a91" />

---

#### **Download the zip file and extract it.**

<img width="351" height="146" alt="image" src="https://github.com/user-attachments/assets/2eef1f0d-7a50-47c1-9603-1ee90f3b85f3" />

---

#### **Open the folder and then cut and paste the template folder into your desired location.**

<img width="515" height="218" alt="image" src="https://github.com/user-attachments/assets/65dcdfc0-70d5-4197-9a2f-12d41adc4cf7" />

---

#### **You can now delete the other folders; only the template folder is required.  Other folders contain examples**

<img width="175" height="149" alt="image" src="https://github.com/user-attachments/assets/487142b0-7165-41d2-bc87-917fc3b92990" />

---

#### **VsCode will automatically be installed by the above commands so now open vscode click on the file tab on the top left, and navigate to the place where you put the template folder and open it.**

<img width="802" height="459" alt="image" src="https://github.com/user-attachments/assets/672a55ab-6145-47e4-b303-69c88b28d46a" /> \

<img width="550" height="414" alt="image" src="https://github.com/user-attachments/assets/b6df752f-c13e-4307-b56d-08fbe05a5bbd" />\

---



#### **Now click on the gear icon on the bottom left and set the autosave option.**

<img width="375" height="517" alt="image" src="https://github.com/user-attachments/assets/bd771087-c213-4b83-af53-02053f15c269" />

<img width="1269" height="617" alt="image" src="https://github.com/user-attachments/assets/4e9f326c-c4c8-4cd1-bb62-b31d99b00d00" />


<img width="569" height="333" alt="image" src="https://github.com/user-attachments/assets/d703d3a8-8421-411c-bca4-1105e792830b" />


---


#### **Also install the C/C++ extension pack** 
#### Click on the box like icon in the left panel.And search C/C++

<img width="777" height="493" alt="image" src="https://github.com/user-attachments/assets/d0842f59-3856-4085-be7f-fdc046eca14a" />

<img width="1358" height="358" alt="image" src="https://github.com/user-attachments/assets/34ee5663-6f91-45ee-8f21-8495da979ed1" />




---




**Now click on the main.c file**

#### You can open the terminal by pressing the control key and the ` key together (which is right on top of your tab key). 
#### Type "make windows" to compile the file.

<img width="782" height="766" alt="image" src="https://github.com/user-attachments/assets/2f3fcc5f-656f-4d71-b9b0-3af100cae68c" />

#### Then type ".\main.exe" to run the file in windows. and for linux only type ./main .

<img width="903" height="656" alt="image" src="https://github.com/user-attachments/assets/3f5980b8-0fed-4b26-bdbb-f98d0e27ff01" />


#### ***You should see a black screen pop up after that***.


#### **To Draw a basic Circle the Draw Circle function  should be placed between the BeginDrawing and EndDrawing functions.**

<img width="700" height="551" alt="image" src="https://github.com/user-attachments/assets/9ba213db-bf26-44b9-b4af-2780726e1878" />


#### **After any change to the file you need to compile and run the file again. so open the terminal and type "make windows" then "./main.exe" or you can also press the up arrow key in the terminal to cycle thhrough previous commands.**

<img width="1042" height="675" alt="image" src="https://github.com/user-attachments/assets/3042fea2-4905-411e-aad9-61a32b77ee85" />

---

<img width="997" height="494" alt="image" src="https://github.com/user-attachments/assets/e23ed530-a533-4dbb-a8be-5b335bb7825e" />

#### **You should see a Red Ball on the black screen. Thats it enjoy**
<img width="1120" height="379" alt="image" src="https://github.com/user-attachments/assets/299e8df5-0302-4c2c-a8b3-dcf715e9546b" />
























