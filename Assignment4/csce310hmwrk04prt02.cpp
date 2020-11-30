/*
* Name: Aryan Timla (atimla)
* Assignment 4 part02
* An implementation of Section 8.3 in The Design and Analysis of Algorithms.
* Given a vector of double values (probabilities of searching for given values),
* return the average number of comparisons required to find a value in the
* optimal binary search tree of those values.
*/

#include "csce310hmwrk04prt02.h"
#include <vector>

using namespace std;

double optimalBST( vector<double> numbers ){
  int n = numbers.size();
  double C[n+1][n+1];
  // double R[n+1][n+1];

  int j, kmin;
  double minval, sum;

  for (int i = 0; i < n; i++) {
    C[i][i]= 0;
    C[i][i+1] = numbers[i];
    // R[i][i] = i;
  }

  for (int d = 2; d <= n; d++) {         //diagonalcount
      for (int i = 0; i <= n - d; i++) {
        j = i + d;
        minval = 999999;                 // INFINITY
        for (int k = i; k < j; k++) {
        if (C[i][k] + C[k+1][j] < minval) {
          minval = C[i][k]+C[k+1][j];
          kmin = k;
        }
      }
        // R[i][j] = kmin;

        sum = numbers[i];
        for (int s = i + 1; s < j; s++) {
          sum = sum + numbers[s];
        }
        C[i][j] = minval + sum;
      }
    }

return C[0][n];
}
