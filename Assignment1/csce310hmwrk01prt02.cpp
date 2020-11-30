/*
* Name: Aryan Timla
* A function that takes one string and one integer n as input
* and print out the first n permutations of that string in reverse
* lexicographic (alphabetical) order.
*/


#include "csce310hmwrk01prt02.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;

void printPermutations( string word , int permutations )
{
  //Sort the string in reverse lexiographic order
  sort(word.rbegin(), word.rend());

  // Using the std function printing the permutations till the nth permutation
  int i = 0;
  do {
    if (i < permutations) {
      cout << word << endl;
    }
  } while (prev_permutation(word.begin(), word.end()));
  //used the std::prev_permutation to resolve the reversing issue
  return;
}
