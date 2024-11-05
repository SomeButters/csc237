#    Author:             Evan Binkley
#    Major:              Computer Science
#    Modification Date:  November 2, 2022
#    Due Date:           December 4, 2022
#    Course:             CSC237 020
#    Professor:          Dr. Spiegel
#    Assignment:         Project 4
#    Filename:           makefile
#    Purpose:            compile the program in a smooth manor

cc=g++
debugFlag=-g

tree: BinarySearchTree.o Treetest.o TermTree.o Term.o
	$(cc) -o tree Treetest.o BinarySearchTree.o TermTree.o Term.o  $(debugFlag)

Term.o: Term.cpp Term.h
	$(cc) -c Term.cpp $(debugFlag)

Treetest.o: Treetest.cpp  BinarySearchTree.h TermTree.h Term.h
	$(cc) -c Treetest.cpp $(debugFlag)

BinarySearchTree.o: BinarySearchTree.cpp BinarySearchTree.h Term.h
	$(cc) -c BinarySearchTree.cpp $(debugFlag)

TermTree.o: TermTree.cpp TermTree.h Term.h
	$(cc) -c TermTree.cpp $(debugFlag)



clean: 
	\rm -f *.o testdate
