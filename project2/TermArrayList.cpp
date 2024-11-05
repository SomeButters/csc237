// File: TermArrayList.cpp
// Container of Term objects 
//   Implementations of member functions including inherited pure virtual fns.

#include <fstream>
#include <iostream>
#include <iomanip>
#include "TermArrayList.h"

using namespace std;

  // Constructor for TermArrayList
  TermArrayList::TermArrayList()
  { numTerms=0; }


  /* 
    Function Name:      readIntoList
    Description:        This function reads from a file into the specified Object Container
    Parameters:         string filename - the file to be a source to read from
    Return Value:       none
*/
  void TermArrayList::readIntoList(string filename)
  { ifstream source(filename.c_str());
    double coeff;
    int expn;
    while (numTerms < MAXTERMS && source >> coeff >> expn)  {
        int flip = 0;
      Term T(coeff,expn);

        for(int i = 0; i < numTerms; i++) {
            if(T == ThePoly[i]) {
                double holder = 0;
                holder = T.getCoefficient() + ThePoly[i].getCoefficient();
                Term H(holder,T.getExponent());
                ThePoly[i]=H;
                flip = -1;
            }
        }

        if(flip != -1) {
            ThePoly[numTerms++]=T;
        }
    }
    for(int i = 0; i < numTerms; i++) {
        Term lrg = ThePoly[i];
        int lrgi = i;
        for(int k = i; k < numTerms; k++) {
            if(!(ThePoly[k] < lrg)) {
                lrgi = k;
                lrg = ThePoly[k];
            }
        }
        swap(ThePoly[lrgi],ThePoly[i]);
    }
        
    source.close();
    source.clear();
  }

/* 
    Function Name:      printIteratively
    Description:        This function prints out the full polynomial expression of TermArrayList
    Parameters:         none
    Return Value:       none
*/
  // Print the data iteratively
  void TermArrayList::printIteratively()
//  void printObjectArrayIterator(TermArray ThePoly[], int numTerms)
  { cout<<"---------------------------------"<<endl;
    cout<<"|Object  Array  Iterative       |"<<endl;
    cout<<"---------------------------------"<<endl;
    for(int i=0; i<numTerms; i++) {
//      cout<<" "<<ThePoly[i]<< "    " << ThePoly[i].getArea() << 
//	    		"    " << ThePoly[i].getPerimeter() << endl;
      cout <<  ThePoly[i] << (i < numTerms-1?" + ":"");
    }
    cout << endl << endl;
}


/* 
    Function Name:      printPtr
    Description:        This function prints out the full polynomial expression of TermArrayList
    Parameters:         none
    Return Value:       none
*/
  // Print the data with a pointer
  void TermArrayList::printPtr()
  { cout<<"---------------------------------"<<endl;
    cout<<"|Object  Array  Pointer         |"<<endl;
    cout<<"---------------------------------"<<endl;
    Term *now=ThePoly;
    for(int i=0; i<numTerms; i++)
      cout << " " << *(now++)  << (i < numTerms-1?" +":"");
    cout << endl << endl;
  }

/* 
    Function Name:      operator()
    Description:        This function prints out the calculated polynomial of TermArrayList
    Parameters:         double x - value at which to evaluate the polynomials 
    Return Value:       double - result formed by evaluation
*/
  // Evaluate the Polynomial
  double TermArrayList::operator()(double x) const
  { double result=0.0;
    for (int idx=0;idx<numTerms;idx++)
      result+=ThePoly[idx](x);
    return(result);
  }