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
        TermSTLObjList();

        void readIntoList(string filename);

        void printIteratively();

        virtual double operator()(double x) const;

    private:
        vector<Term> ThePoly;
};

#endif