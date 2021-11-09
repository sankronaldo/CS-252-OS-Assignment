// serial implementation to estimate the value of pi
// using the instructions given in Q 4.24

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>


//defining a SEED in order to have same random samples generated every time we run the program
// for the same number of points(N)
// this ensures consistency in results

#define SEED 7

// defining the total number of points from which random points are selected

#define N 800000000

// function to estimate pi using for loop
void estimate_serial ()
{
  int count = 0;
  double est_pi_value;

  srand (SEED);

  // a loop to iterate N times and check if the points lie inside a unit circle

  for (int i = 0; i < N; i++)
    {
      double x,y;

      // RAND_MAX >~= 32767

      // x coordinate
      x = (double)rand () / RAND_MAX;

      // y coordinate
      y = (double)rand () / RAND_MAX;


      // checking condition of unit circle
      if (x * x + y * y <= 1)
        {
          count++;
        }

    }

  // estimating value of pi according to the formula given in the question
  est_pi_value = (4.0 * count) / N;

  printf ("No of trials: %d \nNo of points inside unit circle: %d \nEst value of pi:%lf\n",N,count,est_pi_value);

}



int main ()
{


  // calculating the time taken by the function estimate()
  clock_t t;
  t = clock ();
  estimate_serial ();
  t = clock () - t;
  double time_taken = ((double)t) / CLOCKS_PER_SEC;     // in seconds
  printf ("estimate_serial() took %f seconds to execute \n", time_taken);

  return 0;

}



