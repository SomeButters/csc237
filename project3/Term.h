/*!
	\file Term.h
	\brief "Object that contains information for a polynomial"

	\class Term
	\brief "Object that contains information for a polynomial"
*/

/***************************************************************
Author:         Dr. Spiegel 
Filename:       Term.h   
Purpose:        A Term holds one term of a polynomial. A term 
		can be created, evaluated, compared, and printed
***************************************************************/
#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

class Term
{
public:
	//Constructor
	/*!
            \fn Term(double=0, int=0)
            \brief "Basic constructor for the Term object
            \param double "Value for the coefficient of the polynomial"
			\param int "Value for the exponent of the polynomial"
    */
	Term(double=0, int=0); 	//default value of 0x^0

	//Gets (No sets in immutable object)
	/*!
            \fn getCoefficient
            \brief "Returns the value of the coefficient of the polynomial within the object"
            \return double "Value of the coefficient"
    */
	double getCoefficient() const; 		//returns the coefficient

	/*!
            \fn getExponent
            \brief "Returns the value of the exponent of the polynomial within the object"
            \return double "Value of the exponent"
    */
	int getExponent() const; 		//returns the exponent

	//evaluate
	/*!
            \brief "Returns the value of the evaluation of the polynomial given x
			\param "double x" "The value to evaluate the polynomial with"
            \return double "Value of the evalutaed polynomial"
    */
	double operator()(double x) const; 	// evaluation of term
	
	//other
	// does exponent match the parameter? Note signature ==(Term&,int)
	/*!
            \brief "Compares one term against a value"
			\param "int value" "The value to compare the term to"
            \return bool "True if the polynomials exponent is the same as the integer value, false if else-wise"
    */
	bool operator==(int value); 

	// does exponent match that of the param?  Signature: ==(Term,Term)
	/*!
            \brief "Compares one term against another term"
			\param "const Term &right" "The term to compare the term to"
            \return bool "True if the terms' exponents are the same, false if else-wise"
    */
	bool operator==(const Term &right); 

	// is this term's exponent less than right's? Signature <(Term&,Term&)
	/*!
            \brief "Returns the bool for the term being less than another value via their exponents"
			\param "Term &right" "The value to compare to the term"
            \return bool "True if the exponent of the term is less than the compared one, false if else-wise"
    */
	bool operator<(Term &right);

	// is this term's exponent less than right? Signature: <(Term&,int)
	/*!
            \brief "Returns the bool for the term being less than an integer via it's exponent"
			\param "int right" "The value to compare the term to"
            \return bool "True if the term's exponent is less than the integer, false if else-wise"
    */
	bool operator<(int right);

private:
	double coefficient; //holds the coefficient value
	int exponent; //holds the exponent value

};
	// Stream insert a term
	ostream &operator<<(ostream &output,const Term &term); 
#endif