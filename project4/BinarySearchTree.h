/*!
    \mainpage "Project 4 - Binary Tree"
    \section intro_sec "This is project 4 for CSC237-020. Here, I have modified a pre-made set of files to work with Term objects within a binary tree. Below are the classes included in the program in combination with the driver to run."
    \brief #######################################################################################################################################################################
    
    \section class1 Treetest.cpp
    \brief The driver of the program
    \section class2 TermTree.h
    \brief The subclass of BinarySearchTree.h for Term printing
    \section class3 BinarySearchTree.h
    \brief The main generic creation of a binary tree
    \section class4 Term.h
    \brief The object to hold term-like data

    // I'm not really sure what to include here on the main page, so here's what I have as a general placeholder
*/


/*! \file BinarySearchTree.h
    \brief  Holds a generalized binary tree of data

    \class BinaryTree
    \brief Holds a generalized binary tree of data
*/

// File: BinarySearchTree.h
// Binary Tree ADT defined using Linked Structures

/*
    Author:             Evan Binkley
    Major:              Computer Science
    Modification Date:  November 2, 2022
    Due Date:           December 4, 2022
    Course:             CSC237 020
    Professor:          Dr. Spiegel
    Assignment:         Project 4
    Filename:           BinarySearchTree.h
    Purpose:            To prototype functions in BinarySearchTree.cpp
*/

#include "Term.h"
#ifndef TREE_H
#define TREE_H
 

 template <typename eltType> class BinaryTree;

 template <typename eltType> class TreeNode {
/*!
    \class TreeNode
    \brief Implements a node system for use in the binary tree located at BinaryTree
*/
 public:
  eltType info;
  TreeNode<eltType> *left,*right;  
  TreeNode(const eltType &data,
                        TreeNode<eltType> *lChild=NULL,TreeNode *rChild=NULL)
  {info=data;   left=lChild; right=rChild;  }
  
  friend class BinaryTree<eltType>;
 };

template <typename eltType> class BinaryTree {

public:

/*!
    \fn "BinaryTree"
    \brief Basic constructor for BinaryTree
*/
 // Constructor
 BinaryTree();

 // Place Element into Tree
 // Returns 1 if inserted, 0 if Data already in tree
 /*!
    \fn insertToTree(const eltType &data)
    \brief Inserts an element into the binary tree
    \param "const eltType &data" "The element to be inserted into the tree"
    \return int - returns 1 if inserted, 0 else-wise
*/
 int insertToTree(const eltType &data);

 // Search for Element in Tree
 // Assumes == is defined for eltType
 // Returns bool according to success
 /*!
    \fn treeSearch(const eltType &data)
    \brief Searches the tree for the selected element 
    \param "const eltType &data" "The element to search for"
    \return bool - returns true if found, false else-wise
*/
 bool treeSearch(const eltType &data);

 // Retrieve Element from Tree (leaving Tree Intact)
 // Precondition: Item is in Tree
 /*!
    \fn &retrieveFromTree(const eltType &data) 
    \brief Returns an element from the 
    \param "const eltType &data" "The element to retrieve from the tree"
    \return eltType - The element retrieved from the tree
*/
 eltType &retrieveFromTree(const eltType &data);

 // Remove an Element from the tree
 // Pre: Element is in the Tree
 /*!
    \fn deleteFromTree(const eltType &data)
    \brief Deletes the specified element from the tree
    \param "const eltType &data" "The specified element to delete from the tree"
*/
 void deleteFromTree(const eltType &data);

 // Display Tree using InOrder Traversal
 /*!
    \fn inorder()
    \brief Display Tree using InOrder Traversal
*/
 void inorder() const;

 // Display Tree using PreOrder Traversal
 /*!
    \fn preorder()
    \brief Display Tree using PreOrder Traversal
*/
 void preorder() const;

 // Display Tree using PostOrder Traversal
 /*!
    \fn postorder()
    \brief Display Tree using PostOrder Traversal
*/
 void postorder() const;
 
 // Breadth first print
 /*!
    \fn treePrint()
    \brief Breadth first print
*/
 void treePrint() const;
 
protected:

 TreeNode<eltType> *root;

 // Display Tree using InOrder Traversal
/*!
    \fn printInorder(TreeNode<eltType> *) const
    \brief Display Tree using InOrder Traversal
    \param "TreeNode<eltType> *" - The current node, used for traversal
*/
 void printInorder(TreeNode<eltType> *) const;

 // Display Tree using PreOrder Traversal
/*!
    \fn printPreorder(TreeNode<eltType> *) const
    \brief Display Tree using PreOrder Traversal
    \param "TreeNode<eltType> *" - The current node, used for traversal
*/
 void printPreorder(TreeNode<eltType> *) const;

 // Display Tree using PostOrder Traversal
/*!
    \fn printPostorder(TreeNode<eltType> *) const
    \brief Display Tree using PostOrder Traversal
    \param "TreeNode<eltType> *" - The current node, used for traversal
*/
 void printPostorder(TreeNode<eltType> *) const;
 
/*!
    \fn treePrintHelper(TreeNode<eltType> *) const
    \brief Helps to print the tree breadth first
    \param "TreeNode<eltType> *" - The current node, used for traversal
*/
 void treePrintHelper(TreeNode<eltType> *) const;

};

#endif