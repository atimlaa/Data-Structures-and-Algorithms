/*
* Name: Aryan Timla (atimla)
* Assignment 4 part03 (bonus)
* A function that, given an unsigned long long int i, will return the ith Pell number.
* The ith Pellnumber is defined as Pi = 2×Pi−1+Pi−2 for i>1. P0 = 0 and P1 = 1.
*/

#include "csce310hmwrk04prt03.h"

using namespace std;

unsigned long long int pellNumber( unsigned long long int number ){
  unsigned long long int x = 0, y = 1;
  unsigned long long int p, i;

  if (number == 0) {                  // Given P0 = 0
    return 0;
  } else if (number == 1) {           // Given P1 = 1
    return 1;
  } else {
    for (i = 2; i <= number; i++) {   // formula to calculate ith Pellnumber for i>1
      p = 2  * y + x;
      x = y;
      y = p;
    }
    return y;
    // return 2 * pellNumber(number - 1) + pellNumber(number - 2);
  }
}
