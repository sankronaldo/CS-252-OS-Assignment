
# Q 2.24 Solution

Note: All the information written below is specific to Ubuntu operating system

---

## Requirements

You will require the GNU Compiler Collection (GCC) in order to be able to run the program **answer.c**

[Steps to install GCC compiler on Ubuntu](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/#installing-gcc-on-ubuntu)

---

## Steps to run the program
 - Open the terminal and navigate to the directory where the file **answer.c** is present
 - Create a text file (used as an input file) from which you would like to copy the contents in the same directory as the source file.
 - `gcc answer.c -o answer.o`
 - `./answer.o`
 - The program will prompt to enter the name of the input file and output file
 -  If it has been executed successfully, a "Success" message will be displayed

## Screenshots
- Before running the program 

![App Screenshot](https://github.com/sankronaldo/CS-252-OS-Assignment/blob/main/Q1-2.24/images/1.png)

- After running the program

![App Screenshot](https://github.com/sankronaldo/CS-252-OS-Assignment/blob/main/Q1-2.24/images/2.png)

---

### Command to create a log file in which the system calls are logged
- `strace -ostrace_log ./answer.o`
- The program will prompt the user to provide the name of the input file and output file
- If it has been executed successfully, a "Success" message will be displayed

## Screenshots
- Running the strace command to trace the system calls

![App Screenshot](https://github.com/sankronaldo/CS-252-OS-Assignment/blob/main/Q1-2.24/images/3.png)

---

## Implementation

- A program was written in C language for copying the contents from an existing file and paste the contents into a new file (which does not exist before executing the program).
- The input file was sample.txt from which the contents were copied.
- The output file was output.txt to which the copied content was pasted.
- A strace_log file was also created in which all the system calls were logged.



## Reference(s)
- https://github.com/mattlevan/copy.c
- The code for the assignment has been taken from the above repository
