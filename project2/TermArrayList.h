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

  TermArrayList();

  // Put a string of strings into the list object
  //void readIntoList(ifstream &source);
  void readIntoList(string filename);

  // Print the data iteratively
  void printIteratively();
  
  // Print the data with a pointer
  void printPtr();

  // Evaluate the Polynomial
  virtual double operator()(double x) const;

private:
  Term ThePoly[10];
  int numTerms;
  
};
  
#endif