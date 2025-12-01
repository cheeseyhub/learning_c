# C Projects
  Here are my labs_practice , and c projects;

## template 
 It has the template for a raylib library. must have make , gcc or mingw installed to compile .
 
### Setting  for computer center in university (pieas).
The proxy may vary depending on the university so edit as desired.
```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression

scoop install git mingw make

git config --global http.proxy http://172.30.10.11:3128
git config --global https.proxy http://172.30.10.11:3128

scoop bucket add extras
scoop install vscode
 
```
### For setting up for personal computer
Please remember if you have already installed git and make and mingw you can just run the skip the following part.

```
Set-ExecutionPolicy -ExecutionPolicy RemoteSigned -Scope CurrentUser
Invoke-RestMethod -Uri https://get.scoop.sh | Invoke-Expression

scoop install git mingw make


scoop bucket add extras
scoop install vscode
 
```



