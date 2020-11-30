#include "csce310hmwrk02prt02.h"
#include <math.h>

using namespace std;

int findMaxima( vector<int> xs , vector<int> ys ){
  // vector<int> xsr = std::reverse(xs.begin(),xs.end());
  int size = xs.size()-1;
  int count = 0;

  // for (int i = 0; i < size; i++) {  // ith element
  //     if((xsr.at(i) < xsr.at(i+1) && ys.at(i) <= ys.at(i+1)) || (xsr.at(i) < xsr.at(i+1) && ys.at(i) <= ys.at(i+1))){
  //       count++;
  //     }
  //   }

  for (int i = 0; i < size; i++) {
    if(ys.at(i) <= ys.at(i+1)){
      count++;
    }
  }
  return count;
}
