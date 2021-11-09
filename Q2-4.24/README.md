
# Q 4.24 Solution

Note: All the information written below is specific to Ubuntu operating system


## Requirements

You will require the GNU Compiler Collection (GCC) in order to be able to run the programs **serial_pi.c** and **parallel_pi.c**

[Steps to install GCC compiler on Ubuntu](https://linuxize.com/post/how-to-install-gcc-compiler-on-ubuntu-18-04/#installing-gcc-on-ubuntu)



## Steps to run the programs

### serial_pi.c
 - Open the terminal and navigate to the directory where the file **serial_pi.c** is present
 - `gcc serial_pi.c -o serial_pi.o`
 - `./serial_pi.o`
 
  **Output**

 ![App Screenshot](https://github.com/sankronaldo/CS-252-OS-Assignment/blob/main/Q2-4.24/1.png)

---

### parallel_pi.c
 - Open the terminal and navigate to the directory where the file **parallel_pi.c** is present
 - `gcc -pthread parallel_pi.c -o parallel_pi.o`
 - `./parallel_pi.o`
 
  **Output**

 ![App Screenshot](https://github.com/sankronaldo/CS-252-OS-Assignment/blob/main/Q2-4.24/2.png)

---


## Reference(s)
- https://github.com/SeanStaz/monteCarloMethod.c/blob/master/A3.c
- https://betterprogramming.pub/calculating-pi-%CF%80-with-monte-carlo-using-parallel-computing-with-openmp-and-c-2b3a357f0f78
- https://github.com/ilias1111/parallel-monte-carlo-pi
- The code for the assignment has been taken from the above mentioned sources
