/*
    Author:             Evan Binkley
    Major:              Computer Science
    Modification Date:  November 2, 2022
    Due Date:           December 4, 2022
    Course:             CSC237 020
    Professor:          Dr. Spiegel
    Assignment:         Project 4
    Filename:           TermTree.h
    Purpose:            To implement the subclass of TermTree from BinaryTree
*/
/*! \file TermTree.h
    \brief  A Term object to print the tree in a separate manner

    \class TermTree
    \brief A Term object to print the tree in a separate manner
   
    Capabilities:
		\n - Prints the tree in reverse order (with plus)
		\n - Public helper to print the tree in reverse order
*/
// File: TermTree.h
// Update with your documentation, including a *good* description.
// And give proper attribution.

#ifndef TERMTREE_H
#define TERMTREE_H

#include "BinarySearchTree.h"
#include "Term.h"

using namespace std;

const char symbol='+';

class TermTree : public BinaryTree<Term> {
//               ^^^^^^
public:

 TermTree(); 

/*!
  *   \fn  printRevOrder
  *   \brief   Helper function to print preorder with only symbol parameter
  *                                                                   
  *  , Display Polynomial using Reverse InOrder Traversal  
  *********************************************************************/
 void printRevOrder() const;

private:
/*!
  *   \fn  printReverseInorder
  *   \brief   Prints the polynomial inorder reversed using recursion 
  *   \param TreeNode<eltType> *t (import) - a pointer to the tree to be printed
  *   \param bool& first (import/export) - if the current node is the first one 
  *		to be printed, it's true --> no + sign. Otherwise, false --> + sign first                                                            
  *   \return n/a
  *   Display Polynomial using Reverse InOrder Traversal, inserting + signs between terms
  *********************************************************************/
  void printReverseInorder(TreeNode<Term> *t, bool& first) const;

};

#endif