/*
    Author:         Evan Binkley
    Major:          Computer Science
    Creation Date:  October 16, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 2
    Filename:       testLL.cpp
    Purpose:        To test the DblLink.h file and corresponding linked list, and linked list iterator.
*/

#include <iomanip>
#include <iostream>
#include "DblLink.h" 

using namespace std;

void menuSystem(DblLink<int> &t);
void insertToList(DblLink<int> &t);
void removeFromList(DblLink<int> &t);
void printForward(DblLink<int> &t);
void printBackward(DblLink<int> &t);

// FUNCTION IMPLEMENTATION

/* 
    Function Name:      main
    Description:        This function is the main function that oversees the running of the entire program, calling multiple other functions (Prototyped above) to do so.
    Parameters:         none
    Return Value:       int - returns 0 and exits if the programs operates properly
*/
int main() {
    DblLink<int> test;
    menuSystem(test);
}

/* 
    Function Name:      menuSystem
    Description:        This function will present the user with menu options using a switch case, and call corresponding functions based on the decision.
    Parameters:         DblLink<int> &t - The doubly-linked list utilized throughout the program, passed through reference
    Return Value:       none
*/
void menuSystem(DblLink<int> &t) {
    while(true) {
        int choice;
        cout << "Input a number that corresponds to a following command:\n"; 
        cout << right << setw(15) << "1"; cout << " - Insert \n";
        cout << right << setw(15) << "2"; cout << " - Remove \n";
        cout << right << setw(15) << "3"; cout << " - Print Forward \n";        
        cout << right << setw(15) << "4"; cout << " - Print Backward \n";
        cout << right << setw(15) << "5"; cout << " - Exit \n";


        cin >> choice;
        
        switch (choice) { 
            case 1: {
                insertToList(t);
                break;
            }
            case 2: {
                removeFromList(t);
                break;
            }
            case 3: {
                printForward(t);
                break;
            }
            case 4: {
                printBackward(t);
                break;
            }
            case 5: {
                return;
            }
            default: { // Default to repeat menu
                cout << "\n\n Please enter a valid menu option \n\n"; // For incorrect inputs
                break;
            }
        }

    }
}

/* 
    Function Name:      insertToList
    Description:        This function will prompt the user for an integer, and subsequently insert that integer to the doubly-linked list.
    Parameters:         DblLink<int> &t - The doubly-linked list utilized throughout the program, passed through reference
    Return Value:       none
*/
void insertToList(DblLink<int> &t) {
    int num = 0;
    cout << "\nEnter a number to add to the list: ";
    cin >> num;
    t.insert(num);
    cout << num << " added\n\n";
    return;
}

/* 
    Function Name:      removeFromList
    Description:        This function will prompt the user for an integer, and subsequently remove that integer from the doubly-linked list.
    Parameters:         DblLink<int> &t - The doubly-linked list utilized throughout the program, passed through reference
    Return Value:       none
*/
void removeFromList(DblLink<int> &t) {
    DblLinkItr<int> v1(t);
    if(v1.isEmpty()) {
        cout << "\n\nThe list is currently empty.\n\n";
        return;
    }
    v1.start();

    int x = 0;
    cout << "\nEnter a number to remove to the list: ";
    cin >> x;
    cout << "\n";
    while(true) {

        if(*v1 == x) {
           t.remove(x);
           cout << x << " removed\n\n";
           return;
        }
        if(v1.isLastNode()) {
            return;         
        }
            ++v1;
        }
    return;
}

/* 
    Function Name:      printForward
    Description:        This function will print the given doubly-linked list forwards using its iterator.
    Parameters:         DblLink<int> &t - The doubly-linked list utilized throughout the program, passed through reference
    Return Value:       none
*/
void printForward(DblLink<int> &t) {
    DblLinkItr<int> pf(t);
    if(pf.isEmpty()) {
        cout << "\n\nThe list is currently empty.\n\n";
        return;
    }
    pf.start();

    cout << "\n";

    if(!pf.isEmpty()) {
        cout << *pf << " ";
    }
    while(!pf.isLastNode()) {
        ++pf;
        cout << *pf << " ";
    }

    cout << "\n\n";

    return;
}

/* 
    Function Name:      printBackward
    Description:        This function will print the given doubly-linked list backwards using its iterator.
    Parameters:         DblLink<int> &t - The doubly-linked list utilized throughout the program, passed through reference
    Return Value:       none
*/
void printBackward(DblLink<int> &t) {
    DblLinkItr<int> pb(t);
    if(pb.isEmpty()) {
        cout << "\n\nThe list is currently empty.\n\n";
        return;
    }
    pb.start();

    
    cout << "\n";

    while(true) {
    if(pb.isLastNode()) {
            break;
        }
        ++pb;
    }
    if(!pb.isEmpty()) {
        cout << *pb << " ";
    }
    while(!pb.isFirstNode()) {
        --pb;
        cout <<  *pb << " ";
    }

    cout << "\n\n";

    return;
}