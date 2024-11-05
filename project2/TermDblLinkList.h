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
        TermDblLinkList();

        //Put file into list of term objects
        void readIntoList(string filename);

        // Print the data using the iterator
        void printIteratively();

        // Evaluate the Polynomial
        virtual double operator()(double x) const;

    private:
        DblLink<Term> ThePoly;
};

#endif