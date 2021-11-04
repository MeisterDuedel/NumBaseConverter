/*
    Declaration of all functions neccesary for conversion
    Author: Christoph Pircher
    Created: 28.10.2021 (DD-MM-YYYY)
    Last edited: 04.11.2021
    Licenced under GPL-V3
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <cctype>
#include <cmath>
#include <vector>
#include <queue>
#include <sstream>

/*Converts a number from inputBase to outputBase */
std::string Convert(std::string input, unsigned short inputBase, unsigned short outputBase);

/*Calculates the decimal Value of a digit of any base*/
unsigned short Digit2DecVal(char digit);

/*Converts a number from inputBase to Base10/decimal*/
double ToDecimal(const std::string & input, const unsigned short & base);

/* Gets the digit of a decimal value */
char Decimal2Digit(unsigned short value);

/*Converts the decimal representation to outputBase*/
std::string DecimalToBase(const double & decimal,const unsigned short & outputBase);

#endif // FUNCTIONS_H
