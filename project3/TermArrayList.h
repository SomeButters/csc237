/*!
    \file TermArrayList.h
    \brief "Subclass to TermList, implements functions using an array"

    \class TermArrayList
    \brief "Subclass to TermList, implements functions using an array"
*/
/*
    Author:         Evan Binkley
    Major:          Computer Science
    Updated Date:   November 7. 2022
    Due Date:       November 11, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 3
    Filename:       TermArrayList.h
*/

// File: TermArrayList.h
// Container of TermArray objects. 

#ifndef WORDDATALIST_H
#define WORDDATALIST_H

#include <fstream>
#include <string>
#include "TermList.h"
#include "Term.h"

using namespace std;

const int MAXTERMS=10;

class TermArrayList : public TermList {
public:
  /*!
    \fn TermArrayList()
    \brief "Basic constructor for TermArrayList"
  */
  TermArrayList();

  // Put a string of strings into the list object
  //void readIntoList(ifstream &source);
  void readIntoList(string filename);

  // Print the data iteratively
  void printIteratively();

  // Print the data recurisvely
  void printRecursively(int x = 0);
  
  // Print the data with a pointer
  void printPtr();

  // Evaluate the Polynomial
  virtual double operator()(double x) const;

private:
  Term ThePoly[10];
  int numTerms;
  
};
  
#endif