/*
    Author:         Evan Binkley
    Major:          Computer Science
    Creation Date:  November 7, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 2
    Filename:       TermDblLinkList.cpp
    Purpose:        To implement TermSTLObjList.h
*/

#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermSTLObjList.h"

using namespace std;

// Constructor for TermSTLObjList
TermSTLObjList::TermSTLObjList() {}

/* 
    Function Name:      printIteratively
    Description:        This function reads into the specified STL Object List
    Parameters:         string filename - file to be opened as source for reading
    Return Value:       none
*/
void TermSTLObjList::readIntoList(string filename) {
    ifstream data(filename.c_str());

    double tempco;
    int tempex;

    while((data >> tempco) && (data >> tempex)) { // While file not ended, will continue
        //data >> tempco; // Temp variables to hold data
        //data >> tempex;
        int flip = 0;
        for(int i = 0; i < ThePoly.size(); i++) { // For loop to check if need to combine data
            if(tempex == ThePoly[i].getExponent()) {
                double cotemp = tempco + ThePoly[i].getCoefficient();
                Term temp(cotemp, ThePoly[i].getExponent()); // Creation of temporary term to exchange values
                ThePoly[i] = temp;
                flip = -1; // A boolean int, flips if value is same as to not repeat after merging
                break;
            }
        }
        
        if(flip != -1) { // Flip check after merge
            Term T(tempco, tempex); // Creation of temporary term
            ThePoly.push_back(T); // Assignment of data to end of vector
        }
    }
    for(int i = 0; i < ThePoly.size(); i++) {
        int lrg = ThePoly[i].getExponent();
        int lrgi = i;
        for(int k = i; k < ThePoly.size(); k++) { // Insert sorting algorithm
            if(ThePoly[k].getExponent() > lrg) {
                lrgi = k;
                lrg = ThePoly[k].getExponent();
            }
        } // exit for loop, (looking through list again, comparing to "first")
        swap(ThePoly[lrgi], ThePoly[i]); // Swap command utilized in order to swap to sort in descending order.
    }

    return; // End function
}

/* 
    Function Name:      printIteratively
    Description:        This function prints out the calculated polynomial of TermSTLObjList
    Parameters:         none
    Return Value:       none
*/
void TermSTLObjList::printIteratively() {
    cout<<"---------------------------------"<<endl;
    cout<<"|Object  Vector Iterative       |"<<endl;
    cout<<"---------------------------------"<<endl;

    for(int i = 0; i < ThePoly.size(); i++) {
        cout << ThePoly[i] << (i < ThePoly.size()-1?" + ":"\n");
    }

    return;
}

/* 
    Function Name:      printRecursively
    Description:        This function prints out the calculated polynomial of TermSTLObjList recursively
    Parameters:         int x - value to hold data recursively
    Return Value:       none
*/
void TermSTLObjList::printRecursively(int x) {
    if (x==0) {
        cout<<"---------------------------------"<<endl;
        cout<<"|Object  Vector Recursive       |"<<endl;
        cout<<"---------------------------------"<<endl;
    }

    if(x >= (ThePoly.size()-1)) {
        cout << ThePoly[x] << "\n\n";
        return;
    }

    cout << ThePoly[x] << " + ";
    printRecursively(x+1);
    return;
}


/* 
    Function Name:      operator()
    Description:        This function prints out the calculated polynomial of TermSTLObjList
    Parameters:         double x - value at which to evaluate the polynomials 
    Return Value:       double - result formed by evaluation
*/
double TermSTLObjList::operator()(double x) const {
    double result = 0;

    for(int i = 0; i < ThePoly.size(); i++) {
        result += ThePoly[i](x);
    }
    return(result);
}