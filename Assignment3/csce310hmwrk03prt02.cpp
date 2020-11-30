/*
* Name: Aryan Timla (atimla)
* Assignment 3 part02
* A function that should take an n×n vector (representing the adjacency matrix of a graph)
* and a value i between 1 and n as input and return the n×n vector representing the
* matrix computed after the ith stage of Floyd’s algorithm.
* For the purposes of this program, infinity (∞) will be represented as −1.
*/

#include <vector>
#include "csce310hmwrk03prt02.h"
#include <cmath>
#include <iostream>

using namespace std;

vector< vector<double> > allPairsSP( vector< vector<double> > adjacencyMatrix , int i ){
  int size = adjacencyMatrix.size();

  // Floyd's algorithm
  for (int j = 0; j < i; j++) {
    for (int r = 0; r < size; r++) {
      for (int c = 0; c < size; c++) {
        //check for infinity
        if (adjacencyMatrix[r][j] != -1 && adjacencyMatrix[j][c] !=-1) {
          if (adjacencyMatrix[r][c] != -1) {
            adjacencyMatrix[r][c] = min(adjacencyMatrix[r][c], adjacencyMatrix[r][j] + adjacencyMatrix[j][c]);
          } else{
            adjacencyMatrix[r][c] = adjacencyMatrix[r][j] + adjacencyMatrix[j][c];
          }
        }
      }
    }
  }
  return adjacencyMatrix;
}
