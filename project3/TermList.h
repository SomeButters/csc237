/*!
      \mainpage "Project 3, Polymorphism and Function Efficiency"
      \brief "An introduction to polymorphism, and timing the different methods to accomplish a task to determine their speed."
      \n
      "This program is made specifically for project 3."
      \n
      "It will read in a given file, and present the user with options corresponding to the read data from the file (As long as they are properly formatted to be inputted as a polynomial)."

      \file TermList.h
      \brief "Superclass to TermDblLinkList, TermSTLObjList, and TermArrayList"

      \class TermList
      \brief "Superclass to TermDblLinkList, TermSTLObjList, and TermArrayList"
*/

/*
    Author:         Evan Binkley
    Major:          Computer Science
    Updated Date:   November 7. 2022
    Due Date:       November 11, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 3 (Updated file)
    Filename:       TermList.h
    Purpose:        To manage Term lists and manage Doxygen briefing as well
*/

#ifndef TERMLIST_H
#define TERMLIST_H

#include <fstream>
#include <string>

using namespace std;

class TermList {
public:

  // Place the line of text into the data structure
  /*!
      \fn readIntoList
      \brief "Reads a file into the specified subclass list"
      \param "string filename" "String representation of a file name, for a file to be opened and inputted into a term list"
  */
  virtual void readIntoList(string filename)=0;
  
  // Print the data iteratively
  /*!
      \fn printIteratively
      \brief "Prints the contents of the subclass list in an iterative method"
  */
  virtual void printIteratively()=0;

  // Print the data recursively
  /*!
      \fn printRecursively
      \brief "Prints the contents of the subclass list in a recursive method"
      \param "int x" "A value to hold the recursive iteration value of the current function's phase"
  */
  virtual void printRecursively(int x = 0)=0;
  
  // Print the data Iteratively with a pointer
  /*!
      \fn printPtr
      \brief "Prints the contents of the subclass list using a method utilizing a pointer"
  */
  virtual void printPtr() {}   // not pure virtual; why?

  // Evaluate the Polynomial
   /*!
      \brief "Evaluates the subclass list using the value of the parameter x"
      \param "double x" "The value to be evaluated against the list"
  */
  virtual double operator()(double x) const=0;
    
};
  
#endif