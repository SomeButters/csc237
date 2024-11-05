// File: TreeTest.cpp
// Driver for Binary Tree ADT

/*
    Author:             Evan Binkley
    Major:              Computer Science
    Modification Date:  November 2, 2022
    Due Date:           December 4, 2022
    Course:             CSC237 020
    Professor:          Dr. Spiegel
    Assignment:         Project 4
    Filename:           Treetest.cpp
    Purpose:            To drive and create the overall program, adding terms from user input, and printing them out in differing orders
*/

#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "TermTree.h"
#include "Term.h"

using namespace std;

typedef TermTree BinTree;

char getChoice(string ok);

int main()
{BinTree Tree;
 double entry1;
 int entry,result;
 char Choice;
 Term tot;
 do {
  cout << "\n\nSelect: A)dd    R)emove     P)rint     T)ree Print     Q)uit\n";
  Choice=getChoice("ARPTQ");
  switch (Choice) {
   case 'A':
    cout << " Enter a Term's Coefficient >";
    cin >> entry1;
    cout << "\nEnter a Term's Exponent >";
    cin >> entry;
    tot.setCoefficient(entry1);
    tot.setExponent(entry);
    result=Tree.insertToTree(tot);
    if (!result) 
      cout << "\n" << tot << " Already In Tree, adding coefficients\n";
    else cout << "\n" << tot << " Added to Tree\n";
    break;
   case 'P':
    cout << "The Tree:" << endl;
    Tree.printRevOrder();
    break;
   case 'R':
    cout << "Value of Polynomial's Exponent to delete? >";
    cin >> entry;
    tot.setCoefficient(0);
    tot.setExponent(entry);
    result=Tree.treeSearch(tot);
    if (!result) 
      cout << "\nA term with the exponent of" << entry << " Not Found\n";
    else {
     cout << "\nA term with the exponent of" << entry << " Will Be Removed\n";
     Tree.deleteFromTree(tot);
    }
    break;
   case 'T':
    cout << "The tree, as it appears (sort of)..\n";
    Tree.treePrint(); 
  }
 } while (Choice!='Q');
}

char getChoice(string ok)
{char ch=' ';
 do ch=toupper(cin.get()); while (ok.find(ch)==string::npos);
 cin.get(); // eat CR
 return(toupper(ch));
}