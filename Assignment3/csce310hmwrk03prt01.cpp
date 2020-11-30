/*
* Name: Aryan Timla (atimla)
* Assignment 3 part01
* A function that should take an n×n vector (representing the adjacency matrix of a graph)
* as input and return the value of the maximum spanning tree of the graph defined by
* the n×n vector.
*/

#include <vector>
#include "csce310hmwrk03prt01.h"
#include <cmath>
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iterator>

using namespace std;

double maximumST( vector< vector<double> > adjacencyMatrix ){
  // initialize a boolean vector that stores if the edge has been visited or not
  std::vector<bool> visited(adjacencyMatrix.size());
  int size = visited.size();
  for (int i = 0; i < size; i++) {
    visited[i] = false;
  }
  // first node
  visited[0] = true;

  double maxST = 0;
  double current;
  double x;
  // continue finding until all the edges has been visited
  while (std::find (visited.begin(), visited.end(), false) != visited.end()) {
    current = -1;
    x = 0;
    for (int j = 0; j < size; j++) {
      for (int k = 0; k < size; k++) {
        if (visited[j] == true) {
          if (visited[k] == false) {
            // condition to check if the vertices make a path and is larger than the current largest edge
            if(adjacencyMatrix[j][k] != 0 && (adjacencyMatrix[j][k]>current)){
              current = adjacencyMatrix[j][k]; //store the current max
              x = k;
            }
          }
        }
      }
    }
    maxST += current;
    visited[x] = true;
  }
  return maxST;
}
