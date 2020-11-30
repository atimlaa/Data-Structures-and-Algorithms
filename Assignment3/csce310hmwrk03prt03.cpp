/*
* Name: Aryan Timla (atimla)
* Assignment 3 part03
* A function that should take a vector of integers (coefficients of a polynomial)
* and another integer as input and return the value of polynomial,
* evaluated at that particular integer.
*/

#include <vector>
#include "csce310hmwrk03prt03.h"
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

int hornersRule( vector<int> coeffs , int value ){
  int result = coeffs[0];
  int size = coeffs.size() - 1;
  // simple implementation of the hornersRule
  for (int i = 0; i < size; i++) {
    result = (result*value) + coeffs[i+1];
  }
  return result;
}
