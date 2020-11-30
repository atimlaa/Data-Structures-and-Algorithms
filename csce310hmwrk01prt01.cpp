/*
* Name: Aryan Timla
* a function that should take two strings as input a return a Boolean value.
* isAnagram should return true if the first word is an anagram of the second
* (consisting of the exact same letters as the second), and false otherwise.
*/

#include "csce310hmwrk01prt01.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

bool isAnagram( string word01 , string word02 ){
  //base check
  if(word01.size() != word02.size()){
    return false;
  }

  // Sorting the strings with the std sort functions
  sort(word01.begin(),word01.end()); //sorting word01
  sort(word02.begin(),word02.end());  //sorting word02

  if(word01.compare(word02) != 0){
    return false;
  }

  return true;
}
