/*! \file Term.h
    \brief An object that can hold one term of a polynomial.
*/

/***************************************************************
Author:         Dr. Spiegel - Modified by Patrick Stelmach
Filename:       Term.h   
Purpose:        A Term holds one term of a polynomial. A term 
		can be created, evaluated, compared, and printed
***************************************************************/
#ifndef TERM_H
#define TERM_H

#include <iostream>

using namespace std;

/*! 
    \class Term
    \brief A Term holds one term of a polynomial.
   
    The term can be created, evaluated, compared, and printed. Created by Dr. Spiegel.
*/
class Term
{
public:
	///Constructor
	Term(double=0, int=0); 	//default value of 0x^0

	///Gets - returns the coefficient
	double getCoefficient() const;
	///Gets - returns the exponent
	int getExponent() const;

	///Sets the coefficient
	double setCoefficient(double coeff) ;
	
	///Sets the exponent
	int setExponent(int expn);

	///evaluation of term
	double operator()(double x) const; 	
	
	//other
	/// updates the exponent 
	bool operator=(int value); //Note signature ==(Term&,int)
	/// does exponent match the parameter? 
	bool operator==(int value); //Note signature ==(Term&,int)
	/// does exponent match that of the param?  
	bool operator==(const Term &right); //Signature: ==(Term,Term)
	/// adds the term coefficents and updates this coefficient
	bool operator+=(const Term &right); //Signature: +=(Term,Term)
	/// does exponent match that of the param?  
	bool operator!=(int value); //Note signature !=(Term&,int)
	/// does exponent match that of the param?  
	bool operator!=(const Term &right); //Signature: !=(Term,Term)
	/// is this term's exponent less than right? 
	bool operator<(const Term &right) const;//Signature <(Term&,Term&)
	/// is this term's exponent less than right? 
	bool operator<(int right);//Signature: <(Term&,int)

private:
	double coefficient; //holds the coefficient value
	int exponent; //holds the exponent value

};
	/// Stream insert a term
	ostream &operator<<(ostream &output,const Term &term); 
#endif