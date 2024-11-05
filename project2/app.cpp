/*
    Author:         Evan Binkley
    Major:          Computer Science
    Creation Date:  October 18, 2022
    Due Date:       October 25, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 2
    Filename:       app.cpp
    Purpose:        To drive and test the implemented term doubly linked list class, ternm object array class, and term STL list class
*/

#include <cstdio>
#include <math.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include "TermList.h"
#include "TermDblLinkList.h"
#include "TermSTLObjList.h"
#include "TermArrayList.h"
#include "Term.h"

using namespace std;

ifstream data; // Global declaration of ifstream for ease of access
                    // I'm sure there's a better way to do this, but I'm not knowledgable enough to implement it without
                    // an outside resource, so this will have to suffice.


// FUNCTION PROTOTYPES/HEADERS


string setFile(int argc, char **argv); // Sets and checks file input by user, also manages batch file parameteres and makes sure they are within regulation, otherwise will most likely (hopefully) terminate program.
bool doubleCheck(string input); // Checks if string for argv is proper input, bool value return false if not, true if is

void mainMenu(string filename, TermList *ThePoly, int argc, char **argv); // Main menu for display of submenus. Contains ThePoly and filename for transfer
void OAMenu(string filename, TermList *ThePoly);
void STMenu(string filename, TermList *ThePoly); // The three submenus for each implementation 
void DBMenu(string filename, TermList *ThePoly);

void OAItPrint(string filename, TermList *ThePoly);
void OAPoPrint(string filename, TermList *ThePoly);
void OAPoly(string filename, TermList *ThePoly, double x = -1.111);

void STItPrint(string filename, TermList *ThePoly);
void STPoly(string filename, TermList *ThePoly, double x = -1.111); // Admittedly, I got lazy here, but I'm really sleep deprived and couldn't 
                                                                    // think of a better way to implement batch mode easier.
void DBItPrint(string filename, TermList *ThePoly);
void DBPoly(string filename, TermList *ThePoly, double x = -1.111);

void OARead(string filename, TermList *ThePoly);
void STRead(string filename, TermList *ThePoly);
void DBRead(string filename, TermList *ThePoly);

int main(int argc, char **argv) {
    TermList *ThePoly;
    string filename = setFile(argc, argv);
    mainMenu(filename, ThePoly, argc, argv);
    return 0;
}

/* 
    Function Name:      doubleCheck
    Description:        This function will check if the inputted string is capable of being properly converted to a double
    Parameters:         string input - string in question for checking input
    Return Value:       bool - true if double conversion possible, false if not


    // NOT MY DESIGN!!!! SEE BELOW !!!!// I understand the concepts used, and how to implement them, but I gathered in information on how to create this function HERE.
    Source, as logic, inspiration, and general double conversion from: https://stackoverflow.com/a/39813237
*/
bool doubleCheck(string input) {

    char* end; // Char for end only

    double result = strtod(input.c_str(), &end); // Temporarily converts to 'double'

    if (end == input.c_str() || *end != '\0') { // If end is same as string result, or end isn't only remaining null pointer from strtod

        return false; // Return false
    }

    return true; // Return true
}

/* 
    Function Name:      setFile
    Description:        This function simply sets the file name based on input from the user.
    Parameters:         none
    Return Value:       string - The input the user enters, entered into the file variable
*/
string setFile(int argc, char **argv) {

    if(argc > 3) { // Checks if proper batch mode inputs/manualinputs
        cout << "\nToo any batch mode inputs detected, shutting down.\n\n";
        exit(0); // Exits if not
    }

    if(argc > 2) {
        if(!doubleCheck(argv[2])) { // Checks that if x parameter included, that is proper double conversion
            cout << "\nImproper batch parameter included, ending program.\n\n";
            exit(0); // Exits program
            return "";
        }
    }

    string fileName; // Name of file declaration

    if(argc > 1) {
        fileName = argv[1]; // If argc proper, assign to file value
    }
    else {
        cout << "Enter the name of the file you would like to read from: \n\n";
        cin >> fileName; // Otherwise, ask user for input
    }

    ifstream file;
    file.open(fileName);
    if(!file.is_open()) {
        cout << "Something went wrong when trying to open the file, exiting program. \n";
        exit(0);
    }
    file.close(); // I don't know if this counts as accessing the file more than once, as I don't explicitly take elements from it.. this function is from another program of mine, c&p'd in
    cout << "\n\n\n";

    return fileName; // End function
}

/* 
    Function Name:      mainMenu
    Description:        This function outputs the options available to the user, and uses them to engage in a switch case, tethered to other subfunctions.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to pass to submenus
    Return Value:       none
*/
void mainMenu(string filename, TermList *ThePoly, int argc, char **argv) {

    data.open(filename); // Opens global declaration file for reading and later use

    while(true) {
        int choice;
        cout << "Input a number that corresponds to a following command:\n"; 
        cout << right << setw(15) << "1"; cout << " - Term Object Array. \n";
        cout << right << setw(15) << "2"; cout << " - Term Doubly Linked List. \n";
        cout << right << setw(15) << "3"; cout << " - Term STL List. \n";               // Menu to direct user input
        cout << right << setw(15) << "4"; cout << " - Exit. \n";

        if(argc > 2) { // Batch mode bypass to menu interaction
            double x = 0;
            x = stod(argv[2]); // Converts argv to proper x value

            OAItPrint(filename, ThePoly);
            OAPoPrint(filename, ThePoly);
            OAPoly(filename, ThePoly, x);

            DBItPrint(filename, ThePoly);
            DBPoly(filename, ThePoly, x);

            STItPrint(filename, ThePoly);
            STPoly(filename, ThePoly, x);

            return; // Ends program when complete with batch
        }

        cin >> choice; 
        
        switch (choice) { 
            case 1: { // Term Object Array
                OAMenu(filename, ThePoly);
                break;
            }
            case 2: { // Doubly Linked List
                DBMenu(filename, ThePoly);
                break;
            }
            case 3: { // STL List
                STMenu(filename, ThePoly);
                break;
            }
            case 4: { // Exit
                exit(0);
                break;
            }
            default: { // Default to repeat menu
                cout << "\n\n Please enter a valid menu option \n\n"; // For incorrect inputs
                break;
            }
        }

    }

    return; // End function
}

/* 
    Function Name:      OAMenu
    Description:        This function outputs the options available to the user, and uses them to engage in a switch case, tethered to other subfunctions.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to pass to submenus
    Return Value:       none
*/
void OAMenu(string filename, TermList *ThePoly) {

    int choice; // User choice

    while(true) {

        cout <<endl;
        cout << "Select Your Option?"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "Object C++ Array"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "1. Object Array Iterative Print" << endl;
        cout << "2. Object Array Pointer Print" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Back" << endl;

        cin >> choice;
    
        switch (choice) { 
            case 1: { // Prints Iteratively
                OAItPrint(filename, ThePoly);
                break;
            }
            case 2: { // Prints using pointer
                OAPoPrint(filename, ThePoly);
                break;
             }
            case 3: { // Evals Poly
                OAPoly(filename, ThePoly);
                break;
            }
            case 4: { // Back
                return;
            }
            default: { // Default to repeat menu
                cout << "\n\n Please enter a valid menu option \n\n"; // For incorrect inputs
                break;
            }
        }
    }
    return;
}

/* 
    Function Name:      DBMenu
    Description:        This function outputs the options available to the user, and uses them to engage in a switch case, tethered to other subfunctions.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to pass to submenus
    Return Value:       none
*/
void DBMenu(string filename, TermList *ThePoly) {

    int choice; // User choice

    while(true) {

        cout <<endl;
        cout << "Select Your Option?"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "Doubly Linked List"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "1. Doubly Linked Iterative Print" << endl;
        cout << "2. <Blank Option>" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Back" << endl;

        cin >> choice;
    
        switch (choice) { 
            case 1: { // Prints Iteratively
                DBItPrint(filename, ThePoly);
                break;
            }
            case 2: { // Repeats the looped menu
                break;
             }
            case 3: { // Evaluates the polynomial
                DBPoly(filename, ThePoly);
                break;
            }
            case 4: { // Back
                return;
            }
            default: { // Default to repeat menu
                cout << "\n\n Please enter a valid menu option \n\n"; // For incorrect inputs
                break;
            }
        }
    }
    return;
}

/* 
    Function Name:      STMenu
    Description:        This function outputs the options available to the user, and uses them to engage in a switch case, tethered to other subfunctions.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to pass to submenus
    Return Value:       none
*/
void STMenu(string filename, TermList *ThePoly) {
    
    int choice; // User choice

    while(true) {

        cout <<endl;
        cout << "Select Your Option?"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "STL Object List"<<endl;
        cout << "------------------------------------------------"<<endl;
        cout << "1. Doubly Linked Iterative Print" << endl;
        cout << "2. <Blank Option>" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Back" << endl;

        cin >> choice;
    
        switch (choice) { 
            case 1: { // Prints Iteratively
                STItPrint(filename, ThePoly);
                break;
            }
            case 2: { // Repeats the looped menu
                break;
             }
            case 3: { // Evaluates the polynomial
                STPoly(filename, ThePoly);
                break;
            }
            case 4: { // Back
                return;
            }
            default: { // Default to repeat menu
                cout << "\n\n Please enter a valid menu option \n\n"; // For incorrect inputs
                break;
            }
        }
    }
    return;
}

/* 
    Function Name:      OAItPrint
    Description:        This function outputs an iteratively printed term string to the user.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void OAItPrint(string filename, TermList *ThePoly) {
    cout << "\n\n";
    ThePoly = new TermArrayList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename); 
    ThePoly->printIteratively(); // Prints terms
    cout << "\n\n";
    return;
}

/* 
    Function Name:      OAPoPrint
    Description:        This function outputs a pointer based term string to the user.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void OAPoPrint(string filename, TermList *ThePoly) {
    cout << "\n\n";
    ThePoly = new TermArrayList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printPtr(); // Prints terms, pointer-wise
    cout << "\n\n";
    return;
}

/* 
    Function Name:      OAPoly
    Description:        This function outputs the (formatted) polynomial expression calculated, given x
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void OAPoly(string filename, TermList *ThePoly, double x) {
    cout << "\n\n";
    ThePoly = new TermArrayList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    if(x == -1.111) { // Check for proper argc without carrying parameter, (not most efficient or sage)
        cout << "Enter a value x for P(x): ";
        cin >> x;
    }
    cout << "P(" << x << ") = " << (*ThePoly)(x) << "\n"; // Polynomial expression print
    cout << "\n\n";
    return;
}

/* 
    Function Name:      DBItPrint
    Description:        This function outputs an iteratively printed term string to the user.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void DBItPrint(string filename, TermList *ThePoly) {
    cout << "\n\n";
    ThePoly = new TermDblLinkList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printIteratively(); // Prints terms
    cout << "\n\n";
    return;
}

/* 
    Function Name:      DBPoly
    Description:        This function outputs the (formatted) polynomial expression calculated, given x
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void DBPoly(string filename, TermList *ThePoly, double x) {
    cout << "\n\n";
    ThePoly = new TermDblLinkList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    if(x == -1.111) { // Check for proper argc without carrying parameter, (not most efficient or sage)
        cout << "Enter a value x for P(x): ";
        cin >> x;
    }
    cout << "P(" << x << ") = " << (*ThePoly)(x) << "\n"; // Polynomial expression print
    cout << "\n\n";
    return;
}

/* 
    Function Name:      STItPrint
    Description:        This function outputs an iteratively printed term string to the user.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void STItPrint(string filename, TermList *ThePoly) {
    cout << "\n\n";
    ThePoly = new TermSTLObjList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printIteratively(); // Prints terms
    cout << "\n\n";
    return;
}

/* 
    Function Name:      STPoly
    Description:        This function outputs the (formatted) polynomial expression calculated, given x
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void STPoly(string filename, TermList *ThePoly, double x) {
    cout << "\n\n";
    ThePoly = new TermSTLObjList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    if(x == -1.111) { // Check for proper argc without carrying parameter, (not most efficient or sage)
        cout << "Enter a value x for P(x): ";
        cin >> x;
    }
    cout << "P(" << x << ") = " << (*ThePoly)(x) << "\n"; // Polynomial expression print
    cout << "\n\n";
    return;
}