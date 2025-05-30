# DearImGCC
## 1) What is that ?
DearImGCC is a GUI wrapper of the GCC (and also G++) compiler <br/>
You can specifies multiple source files and it will choose the right compiler as you need <br/>
If there's only `*.c` files, then DearImGCC will call the **GCC** compiler. <br/>
If, in your project, you have only one `*.cpp` (or other C++ extensions), therefore it will call the **G++** compiler <br/>
Of course: it isn't a serious application! It's just to learn *DearImGUI* and improve myself in *C++*, and, by that, DearImGCC can only be compile on ***Windows***

## 2) How to use it ?
### 1st way
If you just wanna try this app, download it from the release page
### 2nd way
And then, if you want, you can compile by using *CMAKE* <br/>
Here are the step <br/>
First of all, clone this repo
```bash
git clone https://github.com/Hemdy-M/ImDearGCC.git
```
Then, go to `ImDearGCC` folder and execute *cmake*
```bash
cmake .
```
When this is complete, create a build folder and compile
```bash
mkdir buid
cd build
# When you're in the build folder
cmake --build .
```
And at last, run the actual app
```bash
./DearImGCC.exe
```
Like above (with the terminal) of by using the file explorer