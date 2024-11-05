/*
    Author:         Evan Binkley
    Major:          Computer Science
    Creation Date:  October 18, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 2
    Filename:       TermDblLinkList.cpp
    Purpose:        To implement TermDblLinkList.h
*/

// File: TermDblLinkList.cpp
// Container of Term objects
// Implementations of member functions including inherited pure virtual fns.

#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermDblLinkList.h"

using namespace std;


// Constructor for TermDblLinkList
TermDblLinkList::TermDblLinkList() {}

/* 
    Function Name:      readIntoList
    Description:        This function reads the values into the specified list type - usually through polymorphism
    Parameters:         filename - filename to open as source
    Return Value:       none
*/
void TermDblLinkList::readIntoList(string filename) {
    ifstream source(filename.c_str());
    DblLinkItr<Term> v1(ThePoly);
    double coeff;
    int expo;
    while (source >> coeff >> expo) {
        Term T(coeff,expo);
        int flip = 0;
        v1.start();
        while(true) {
            if(v1.isEmpty()) {
                break;
            }
            if(v1.isLastNode()) {
				if(T == *v1) {
					Term LL = *v1;
					double holder = 0;
					holder = T.getCoefficient() + LL.getCoefficient();
					Term H(holder, T.getExponent());
					ThePoly.remove(T); 
					ThePoly.insert(H);
					flip = -1;
				}				
                break;            
            }                   
            if(T == *v1) {
                Term LL = *v1;
                double holder = 0;
                holder = T.getCoefficient() + LL.getCoefficient();
                Term H(holder, T.getExponent());
                ThePoly.remove(T); 
                ThePoly.insert(H);
                flip = -1;
                break;
            }
            ++v1;
        }

        if(flip != -1) {
            ThePoly.insert(T);
        }
    }

    source.close();
    source.clear();
}

/* 
    Function Name:      printIteratively
    Description:        This function prints out the data values of DblLinkList
    Parameters:         none
    Return Value:       none
*/
void TermDblLinkList::printIteratively() {
    cout<<"---------------------------------"<<endl;
    cout<<"|Doubly Linked List Iterative   |"<<endl;
    cout<<"---------------------------------"<<endl;

    DblLinkItr<Term> v2(ThePoly);
    v2.start();

    while(true) {
        if(v2.isEmpty()) {
            cout << "This list is empty.\n\n";
            return;
        }
        if(v2.isLastNode()) {
            cout << *v2 << "\n\n";
            return;
        }

        cout << *v2 << " + ";

        ++v2;
    }
    return;
}

/* 
    Function Name:      operator()
    Description:        This function prints out the calculated polynomial of DblLinkList
    Parameters:         double x - expression to evaluate the polynomial
    Return Value:       result - result formed by evaluation
*/
double TermDblLinkList::operator()(double x) const {
    double result = 0;

    DblLinkItr<Term> v3(ThePoly);
    v3.start();

    while(true) {
        if(v3.isEmpty()) {
            cout << "This list is empty.\n\n";
            return(result);
        }
        Term G = *v3;
        result += G.operator()(x);

        if(v3.isLastNode()) {
            return(result);
        }
        ++v3;
    }
    return(result);
}