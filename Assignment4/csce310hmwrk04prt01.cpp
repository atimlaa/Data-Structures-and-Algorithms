/*
* Name: Aryan Timla (atimla)
* Assignment 4 part01
* A gradebook has been corrupted so that the columns have been removed. Now,
* a student’s record is no longer a collection of individual grades, it’s just a string of digits.
* It is known that the string came from n separate grades, each grade was between 0 and 100 (inclusive),
* and grades donot have leading zeros (5 is a valid grade, 05 is not).
* Return the maximum average possible if the string is parsed into n separate grades.
* 1 100 would return 100.0
* 2 100 would return 5.0
* 3 99199 would return 66.333. . .
*/

#include "csce310hmwrk04prt01.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// helper function to calculate all the possible averages
vector<double> search(int n, string str, double sum, int count){
    vector<double> averages;

    if(n==0 && str.length() == 0){
        vector<double> calculatedAverage;
        calculatedAverage.push_back(sum/count);
        return calculatedAverage;
    }

    else if(n == 0 || str.length() == 0){
        return vector<double>();
    }

    vector<double> searchedAverages;

    // if the grade is 100
    if(str.length()>=3 && str.substr(0,3)== "100"){
        searchedAverages = search(n-1, str.substr(3), sum+100, count+1);
        averages.insert( averages.end(), searchedAverages.begin(), searchedAverages.end() );
    }
    //if any double digit grade
    if(str.length()>=2 && str[0] != '0'){
        searchedAverages = search(n-1, str.substr(2), sum+stod(str.substr(0,2)), count+1);
        averages.insert( averages.end(), searchedAverages.begin(), searchedAverages.end() );
    }
    // for 1 digit grades
    searchedAverages = search(n-1, str.substr(1), sum + stod(str.substr(0,1)), count+1);
    averages.insert( averages.end(), searchedAverages.begin(), searchedAverages.end() );

    return averages;
}

// function to be made, uses the helper function and returns the maximum average of all possible averages
double corruptedGrades( int n , string str){
    vector<double> allAverages = search(n, str, 0, 0);
    double maxAverage = 0.0;

    for(int i=0; i < allAverages.size(); i++) {
        if (allAverages[i] > maxAverage) {
            maxAverage = allAverages[i];
        }
    }

    return maxAverage;
}
