/*
    Author:             Evan Binkley
    Major:              Computer Science
    Modification Date:  November 2, 2022
    Due Date:           December 4, 2022
    Course:             CSC237 020
    Professor:          Dr. Spiegel
    Assignment:         Project 4
    Filename:           TermTree.cpp
    Purpose:            To implement the functions of TermTree.h
*/

// File: TermTree.cpp
// Update with your documentation, including a *good* description.
// And give proper attribution.

#include "TermTree.h"

// This is Complete
TermTree::TermTree() : BinaryTree()
{}

// Need Helper to Recursively Print the Polynomial
//The boolean is a reference so once the first node is printed, the rest have their flag changed
void TermTree::printReverseInorder(TreeNode<Term> *t, bool& first) const
{ if (t) {

// Complete the function body

    printReverseInorder(t->right, first);
    if(first == true) {
        cout << t->info;
        first = false;
    }
    else {
        cout << " + " << t->info; 
    }
    printReverseInorder(t->left, first);
  
  }
}

// Display Polynomial using Reverse InOrder Traversal
void TermTree::printRevOrder() const
{ bool firstNode = true;
  printReverseInorder(root, firstNode);
  cout << endl;
}
