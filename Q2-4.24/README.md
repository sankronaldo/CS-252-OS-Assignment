
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

 ### Note:
 - The rand() function which is present in the stdlib header file is used for generating numbers.
 - The issue with using rand() is that it is not thread-safe
 - [More information about thread safety](https://en.wikipedia.org/wiki/Thread_safety)
 - Therefore, in the parallel_pi.c program, random numbers are generated using  linear congruential generator algorithm instead of rand().
 - [More information on linear congruential generator](https://betterprogramming.pub/calculating-pi-%CF%80-with-monte-carlo-using-parallel-computing-with-openmp-and-c-2b3a357f0f78)
 
  **Output**

 ![App Screenshot](https://github.com/sankronaldo/CS-252-OS-Assignment/blob/main/Q2-4.24/2.png)

---


## Implementation

- Two programs were written to estimate the value of pi using the Monte Carlo method
- One program was run serially using a loop (serial_pi.c) while the other program made use of threading to parallely compute the value of pi (parallel_pi.c) 
- The number of random points chosen for the computation was 800000000

## Inference

- The serial computation of pi took **36.164631 seconds** to estimate the value of pi.
- The computation of pi using threading took just **10.727070 seconds** to estimate the value of pi.
- Clearly, as expected, the computation of the value of pi using threading was approximately **3.38 times** faster than the serial computation of pi.
- When we consider only the first 6 decimal places in pi (i.e. 3.141592), we can see that the serial method gave an absolute error of **0.000077** while the method that used threading gave an absolute error of **0.000002**.
- This showed that using threading helps in faster computation with a smaller absolute error.

---

## Reference(s)
- https://github.com/SeanStaz/monteCarloMethod.c/blob/master/A3.c
- https://betterprogramming.pub/calculating-pi-%CF%80-with-monte-carlo-using-parallel-computing-with-openmp-and-c-2b3a357f0f78
- https://github.com/ilias1111/parallel-monte-carlo-pi
- https://www.geeksforgeeks.org/how-to-measure-time-taken-by-a-program-in-c/
- The code for the assignment has been taken from the above mentioned sources
