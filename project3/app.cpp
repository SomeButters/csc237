/*!
    \file app.cpp
    \brief "Driver application for project 3, 'app'"
*/

/*
    Author:         Evan Binkley
    Major:          Computer Science
    Creation Date:  November 7, 2022
    Due Date:       November 11, 2022
    Course:         CSC237 020
    Professor:      Dr. Spiegel
    Assignment:     Project 3
    Filename:       app.cpp
    Purpose:        To drive and test the implemented term doubly linked list class, ternm object array class, and term STL list class, as well as to test the speed of each
*/

#include <chrono>
#include <cmath>
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

/*!
    \fn setFile
    \brief "Validates the inputted file for correctness for no crashes based on file input"
    \param "int argc" "Main's number of arguments"
    \param "char **argv" "Main's array of arguments"
    \return "string" "Returns a string of the filename if passed validation, closes program else-wise"
*/
string setFile(int argc, char **argv); // Sets and checks file input by user, also manages batch file parameteres and makes sure they are within regulation, otherwise will most likely (hopefully) terminate program.

/*!
    \fn doubleCheck
    \brief "Checks to see if the value presented by a string is a proper integer or double"
    \param "string input" "The string to be validated"
    \return bool "True if a valid double or integer, false else-wise"
*/
bool doubleCheck(string input); // Checks if string for argv is proper input, bool value return false if not, true if is

/*!
    \fn mainMenu
    \brief "Presents the user with a main menu to select submenus"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void mainMenu(string filename, TermList *ThePoly, int argc, char **argv); // Main menu for display of submenus. Contains ThePoly and filename for transfer

/*!
    \fn OAMenu
    \brief "Presents the user with a menu for the Object Array selection"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void OAMenu(string filename, TermList *ThePoly);

/*!
    \fn STMenu
    \brief "Presents the user with a menu for the STL Object List selection"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void STMenu(string filename, TermList *ThePoly); // The three submenus for each implementation 

/*!
    \fn DBMenu
    \brief "Presents the user with a menu for the Doubly Linked List selection"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void DBMenu(string filename, TermList *ThePoly);


/*!
    \fn OAItPrint
    \brief "Prints the Object Array List iteratively"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void OAItPrint(string filename, TermList *ThePoly);

/*!
    \fn OAProPrint
    \brief "Prints the Object Array List using a pointer"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void OAPoPrint(string filename, TermList *ThePoly);

/*!
    \fn OARePrint
    \brief "Prints the Object Array List recursively"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void OARePrint(string filename, TermList *ThePoly);

/*!
    \fn OAPoly
    \brief "Evaluates the Object Array List's full polynomial and prints the result based on an x value from the user's input or batch mode"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
    \param "double x" "A value to validate input from either within the function, or outside using batch mode"
*/
void OAPoly(string filename, TermList *ThePoly, double x = -1.111);


/*!
    \fn STItPrint
    \brief "Prints the STL Object List iteratively"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void STItPrint(string filename, TermList *ThePoly);

/*!
    \fn STRePrint
    \brief "Prints the STL Object List recursively"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void STRePrint(string filename, TermList *ThePoly);

/*!
    \fn STPoly
    \brief "Evaluates the STL Object List's full polynomial and prints the result based on an x calue from the user's input or batch mode"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
    \param "double x" "A value to validate input from either within the function, or outside using batch mode"
*/
void STPoly(string filename, TermList *ThePoly, double x = -1.111); // Admittedly, I got lazy here, but I'm really sleep deprived and couldn't 
                                                                    // think of a better way to implement batch mode easier.

/*!
    \fn DBItPrint
    \brief "Prints the Doubly Linked List iteratively"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/                                                                    
void DBItPrint(string filename, TermList *ThePoly);

/*!
    \fn DBRePrint
    \brief "Prints the Doubly Linked List recursively"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void DBRePrint(string filanem, TermList *ThePoly);

/*!
    \fn DBPoly
    \brief "Evaluates the STL Object List's full polynomial and prints the result based on an x calue from the user's input or batch mode"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
    \param "double x" "A value to validate input from either within the function, or outside using batch mode"
*/
void DBPoly(string filename, TermList *ThePoly, double x = -1.111);


/*!
    \fn OARead
    \brief "Reads the file into an Object Array version of the TermList"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void OARead(string filename, TermList *ThePoly);

/*!
    \fn STRead
    \brief "Reads the file into an STL Object List version of the TermList"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
void STRead(string filename, TermList *ThePoly);

/*!
    \fn DBRead
    \brief "Reads the file into a Doubly Linked List version of the TermList"
    \param "string filename" "The filename for the data to be read"
    \param "TermList *ThePoly" "The polynomial termlist superclass overarching the entire program"
*/
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
            OARePrint(filename, ThePoly);
            OAPoly(filename, ThePoly, x);

            DBItPrint(filename, ThePoly);
            DBRePrint(filename, ThePoly);
            DBPoly(filename, ThePoly, x);

            STItPrint(filename, ThePoly);
            STRePrint(filename, ThePoly);
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
        cout << "3. Object Array Recursive Print" << endl;
        cout << "4. Evaluate the Polynomial" << endl;
        cout << "5. Back" << endl;

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
            case 3: { // Prints recursively
                OARePrint(filename, ThePoly);
                break;
            }
            case 4: { // Evals Poly
                OAPoly(filename, ThePoly);
                break;
            }
            case 5: { // Back
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
        cout << "2. Double Linked Recursive Print" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Back" << endl;

        cin >> choice;
    
        switch (choice) { 
            case 1: { // Prints Iteratively
                DBItPrint(filename, ThePoly);
                break;
            }
            case 2: { // Prints recursively
                DBRePrint(filename, ThePoly);
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
        cout << "1. Vector Iterative Print" << endl;
        cout << "2. Vector Recursive Print" << endl;
        cout << "3. Evaluate the Polynomial" << endl;
        cout << "4. Back" << endl;

        cin >> choice;
    
        switch (choice) { 
            case 1: { // Prints Iteratively
                STItPrint(filename, ThePoly);
                break;
            }
            case 2: { // Prints recursively
                STRePrint(filename, ThePoly);
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

    auto begin = chrono::high_resolution_clock::now(); // Chrono testing start

    ThePoly = new TermArrayList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printIteratively(); // Prints terms

    auto end = chrono::high_resolution_clock::now(); // Chrono testing end
    auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin); // Calc the difference in the clocks
    cout << "\nThe function above took " << ticks.count() << " microseconds.\n"; // Prints microsecond result out

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

    auto begin = chrono::high_resolution_clock::now(); // Chrono testing start

    ThePoly = new TermArrayList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printPtr(); // Prints terms

    auto end = chrono::high_resolution_clock::now(); // Chrono testing end
    auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin); // Calc the difference in the clocks
    cout << "\nThe function above took " << ticks.count() << " microseconds.\n"; // Prints microsecond result out

    cout << "\n\n";
    return;
}

/* 
    Function Name:      OARePrint
    Description:        This function outputs a recursive based term string to the user.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void OARePrint(string filename, TermList *ThePoly) {
    cout << "\n\n";

    auto begin = chrono::high_resolution_clock::now(); // Chrono testing start

    ThePoly = new TermArrayList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printRecursively(); // Prints terms

    auto end = chrono::high_resolution_clock::now(); // Chrono testing end
    auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin); // Calc the difference in the clocks
    cout << "\nThe function above took " << ticks.count() << " microseconds.\n"; // Prints microsecond result out

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

    auto begin = chrono::high_resolution_clock::now(); // Chrono testing start

    ThePoly = new TermDblLinkList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printIteratively(); // Prints terms

    auto end = chrono::high_resolution_clock::now(); // Chrono testing end
    auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin); // Calc the difference in the clocks
    cout << "\nThe function above took " << ticks.count() << " microseconds.\n"; // Prints microsecond result out

    cout << "\n\n";
    return;
}

/* 
    Function Name:      DBRePrint
    Description:        This function outputs a recursive based term string to the user.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void DBRePrint(string filename, TermList *ThePoly) {
    cout << "\n\n";
    
    auto begin = chrono::high_resolution_clock::now(); // Chrono testing start

    ThePoly = new TermDblLinkList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printRecursively(); // Prints terms

    auto end = chrono::high_resolution_clock::now(); // Chrono testing end
    auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin); // Calc the difference in the clocks
    cout << "\nThe function above took " << ticks.count() << " microseconds.\n"; // Prints microsecond result out

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

    auto begin = chrono::high_resolution_clock::now(); // Chrono testing start

    ThePoly = new TermSTLObjList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printIteratively(); // Prints terms

    auto end = chrono::high_resolution_clock::now(); // Chrono testing end
    auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin); // Calc the difference in the clocks
    cout << "\nThe function above took " << ticks.count() << " microseconds.\n"; // Prints microsecond result out

    cout << "\n\n";
    return;
}

/* 
    Function Name:      STRePrint
    Description:        This function outputs a recursive based term string to the user.
    Parameters:         string filename - the name of the file | TermList ThePoly - superclass to manage subclass creation
    Return Value:       none
*/
void STRePrint(string filename, TermList *ThePoly) {
    cout << "\n\n";

    auto begin = chrono::high_resolution_clock::now(); // Chrono testing start

    ThePoly = new TermSTLObjList; // Instantiates and reclaims TermList data to polymorphise it into correct class
    ThePoly->readIntoList(filename);
    ThePoly->printRecursively(); // Prints terms

    auto end = chrono::high_resolution_clock::now(); // Chrono testing end
    auto ticks = chrono::duration_cast<chrono::microseconds>(end-begin); // Calc the difference in the clocks
    cout << "\nThe function above took " << ticks.count() << " microseconds.\n"; // Prints microsecond result out

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

