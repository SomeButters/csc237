/*!
    \file TermDblLinkList.h
    \brief "Subclass to TermList, implements functions using a doubly linked list"

    \class TermDblLinkList
    \brief "Subclass to TermList, implements functions using a doubly linked list"
*/

/*
    Author:         Evan Binkley
    Major:          Computer Science
    Updated Date:   November 7, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 3
    Filename:       TermDblLinkList.h
*/


// File: TermDblLinkList.h
// Container of TermArray objects.

#ifndef TERMDBLLINK_H
#define TERMDBLLINK_H

#include <fstream>
#include <string>
#include "DblLink.h"
#include "TermList.h"
#include "Term.h"

using namespace std;

class TermDblLinkList : public TermList {
    public:
        /*!
            \fn TermDblLinkList()
            \brief "Basic constructor for TermDblLinkList"
        */
        TermDblLinkList();

        //Put file into list of term objects
        void readIntoList(string filename);

        // Print the data using the iterator
        void printIteratively();

        // Print the data recursively
        void printRecursively(int x = 0);

        // Evaluate the Polynomial
        virtual double operator()(double x) const;

    private:
        DblLink<Term> ThePoly;
};

#endif