/*
* Name: Aryan Timla (atimla)
* Assignment 2 part01
* A function that should take a vector of n integers and
* a string of length n − 1 as input and return a vector of n integers.
* with ordering of the numbers such that the conditions encoded in the string
* are met. A value in the string will be < if the number that would be to its
* left is less than the number that would be to its right, and > otherwise.
* Assuming the numbers are already sorted in an ascending order
*/

#include "csce310hmwrk02prt01.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> placeNumbers( vector<int> numbers , string signs ){
  // Create empty vector to store the placed numbers
  vector<int> pNumbers(numbers.size());
  int begin = 0;
  int end = numbers.size() - 1;

  // check if first element is smallest or biggest
  if(signs.at(0) == '<'){
    pNumbers.at(0) = numbers.at(begin);
    begin++;
  } else if(signs.at(0) == '>'){
    pNumbers.at(0) = numbers.at(end);
    end--;
  }

  // Loop through the numbers and put in their positions
  for(int i = 1; i < signs.size(); i++){
    if((signs.at(i-1) == '>' && signs.at(i) == '<') || (signs.at(i-1) == '<' && signs.at(i) == '<')){
      pNumbers.at(i) = numbers.at(begin);
      begin++;
    }
    else if((signs.at(i-1) == '>' && signs.at(i) == '>') || (signs.at(i-1) == '<' && signs.at(i) == '>')){
      pNumbers.at(i) = numbers.at(end);
      end--;
    }
  }

  // the last element
  pNumbers.at(pNumbers.size()-1) = numbers.at(end);

  return pNumbers;
}
