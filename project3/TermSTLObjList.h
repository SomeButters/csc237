/*!
    \file TermSTLObjList.h
    \brief "Subclass to TermList, implements functions using an STL object (Vector)"

    \class TermSTLObjList
    \brief "Subclass to TermList, implements functions using an STL object (Vector)"
*/

/*
    Author:         Evan Binkley
    Major:          Computer Science
    Updated Date:   November 7. 2022
    Due Date:       November 11, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 3 (Updated file)
    Filename:       TermSTLObjectList.h
*/

// File: TermSTLObjList.h
// Container of Term objects

#ifndef TERMSTL_H
#define TERMSTL_H

#include <vector>
#include <fstream>
#include <string>
#include "TermList.h"
#include "Term.h"

using namespace std;

class TermSTLObjList : public TermList {
    public:
        /*!
            \fn TermSTLObjList()
            \brief "Basic constructor for TermSTLObjList"

        */
        TermSTLObjList();

        void readIntoList(string filename);

        void printIteratively();

        void printRecursively(int x = 0);

        virtual double operator()(double x) const;

    private:
        vector<Term> ThePoly;
};

#endif