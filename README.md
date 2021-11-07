
# CS-252-OS-Assignment

The assignment consists of two questions from the exercise section of the 10th edition of Operating
System Concepts by Abraham Silberschatz, Peter Baer Galvin and Greg Gagne.



## Questions
**[Question 1: Chapter 2- 2.24](https://github.com/sankronaldo/CS-252-OS-Assignment/tree/main/Q1-2.24)**

In Section 2.3, we described a program that copies the contents of one file
to a destination file. This program works by first prompting the user for
the name of the source and destination files. Write this program using
either the POSIX or Windows API. Be sure to include all necessary error
checking, including ensuring that the source file exists.

Once you have correctly designed and tested the program, if you used
a system that supports it, run the program using a utility that traces system calls. Linux systems provide the strace utility, and macOS systems
use the dtruss command. (The dtruss command, which actually is a
front end to dtrace, requires admin privileges, so it must be run using
sudo.) These tools can be used as follows (assume that the name of the
executable file is FileCopy:

**Linux:
strace ./FileCopy**

**macOS:
sudo dtruss ./FileCopy**

Since Windows systems do not provide such a tool, you will have to
trace through the Windows version of this program using a debugger.

**[Question 2: Chapter 4- 4.24](https://github.com/sankronaldo/CS-252-OS-Assignment/tree/main/Q2-4.24)**

An interesting way of calculating π is to use a technique known as Monte
Carlo, which involves randomization. This technique works as follows:
Suppose you have a circle inscribed within a square, as shown in
Figure 4.25. (Assume that the radius of this circle is 1.)

• First, generate a series of random points as simple (x, y) coordinates.
These points must fall within the Cartesian coordinates that bound
the square. Of the total number of random points that are generated,
some will occur within the circle.

• Next, estimate π by performing the following calculation:

*π = 4× (number of points in circle) / (total number of points)*

Write a multithreaded version of this algorithm that creates a separate
thread to generate a number of random points. The thread will count
the number of points that occur within the circle and store that result
in a global variable. When this thread has exited, the parent thread will
calculate and output the estimated value of π. 

It is worth experimenting with the number of random points generated. As a general rule, the
greater the number of points, the closer the approximation to π.

In the source-code download for this text, you will find a sample
program that provides a technique for generating random numbers, as
well as determining if the random (x, y) point occurs within the circle.

Readers interested in the details of the Monte Carlo method for
estimating π should consult the bibliography at the end of this chapter.
In Chapter 6, we modify this exercise using relevant material from that
chapter.


## Author(s)

- [@sankarsh_r](https://www.linkedin.com/in/sankarsh-r-8441081a0/)

Sankarsh R - 191EC261


