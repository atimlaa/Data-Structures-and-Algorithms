/*
 * Name: Aryan Timla (atimla)
 * Assignment 2 part03 (bonus)
 * The function will take one argument: a vector of double values
 * and return the distance between the two closest numbers.
 * It may be assumed that the vector will be in descending order.
*/

#include "csce310hmwrk02prt03.h"
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

double closestNumbers( vector<double> numbers )
{
  int size = numbers.size();
  double diff = numbers.at(0) - numbers.at(1);
  double newdiff;

  // iterate through all the elements in the vector
  for (int i = 0; i < size; i++) {  // ith element
    for (int j = i + 1; j < size; j++) { // proceeding element
      newdiff = fabs(numbers.at(i) - numbers.at(j)); // in descending order so
      if(newdiff < diff) {
        diff = newdiff;
      }
    }
  }
  return diff;
}
