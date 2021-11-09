// implementation of threading to estimate the value of pi
// using the instructions given in Q 4.24


#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>


#define SEED 7

unsigned int seed = 7;


// defining the total number of points from which random points are selected
int N = 800000000;


//global variable for number of points inside unit circle
int totalPts = 0;


//Random number generator with linear congruential generator
double randUint (long i)
{

  seed = seed * 1103515245 + 123456;

  return seed / (double)UINT_MAX;
}


//function to find the number of random points inside the unit circle
void * count (void *X)
{
  /* initialize random numbers */
  for (int i = 0; i < N; i++)
    {
      double x = (double)randUint (i);
      double y = (double)randUint (i);


      // checking if it is a unit circle
      if (((x * x) + (y * y)) <= 1)
        {
          totalPts++;
        }
    }
  return NULL;
}

//function to estimate pi using pthreads
void estimate_parallel ()
{

  srand (SEED);

  // defining the thread variable as pthread_t datatype
  pthread_t thread;

  // creating a pthread which computes the number of points inside the unit circle
  pthread_create (&thread, NULL, &count, NULL);

  //waiting for the termination of the pthread
  pthread_join (thread, NULL);

  // estimating the value of pi using the formula given in the question
  double est_pi_value = (4.0 * totalPts) / N;

  printf ("No of trials: %d \nNo of points inside unit circle: %d \nEst value of pi:%lf\n",N,totalPts,est_pi_value);

}




int main ()
{

  // calculating the time taken by the function estimate()
  clock_t t;
  t = clock ();
  estimate_parallel ();
  t = clock () - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;     // in seconds
  printf ("estimate_parallel() took %f seconds to execute \n", time_taken);

  return 0;
}
