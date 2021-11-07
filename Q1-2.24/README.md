
# Q 2.24 Solution

Note: All the information written below is specific to Ubuntu operating system

---

## Requirements

You will require the GNU Compiler Collection (GCC) in order to be able to run the program **answer.c**

[Steps to install GCC compiler on Ubuntu](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/#installing-gcc-on-ubuntu)

---

## Steps to run the program
 - Open the terminal and navigate to the directory where the file **answer.c** is present
 - `gcc answer.c -o answer.o`
 - `./answer.o`
 - The program will prompt to enter the name of the input file and output file

---
### Command to trace the system calls 
- `strace ./copy.o`

### Command to create a log file
A log file is a file where all the system calls are listed
- `strace -ostrace_log ./copy.o`
---

## Reference(s)
- https://github.com/mattlevan/copy.c