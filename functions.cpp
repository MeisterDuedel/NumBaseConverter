/*
    Definition of all functions neccesary for conversion
    Author: Christoph Pircher
    Created: 28.10.2021 (DD-MM-YYYY)
    Last edited: 04.11.2021
    Licenced under GPL-V3
*/


#include "functions.h"

/*Converts a number from inputBase to outputBase */
std::string Convert(std::string input, unsigned short inputBase, unsigned short outputBase){
    double decimal = ToDecimal(input, inputBase); //Converting to Decimal
    if(decimal <0){
        return "ERROR";
    }else{
        return DecimalToBase(decimal, outputBase); //Converting from decimal to outputBase
    }
}

/*Calculates the decimal Value of a digit of any base*/
unsigned short Digit2DecVal(char digit){
    /* Calculating decimal Value of digit based on ASCII Code*/
    if(isdigit(digit)){
        return digit -48; //0-9
    }else if(isalpha(digit)){
        if(isupper(digit)){
            return digit -55; //10-35
        }else{
            return digit - 61;//36-61
        }
    }else{
        return 64; //Error
    }
}

/*Converts a number from inputBase to Base10/decimal*/
double ToDecimal(const std::string & input, const unsigned short & base){
    std::string integer;
    std::string placesSTR;

    /* Splitting input into integer and places if intput is fixed point */
    if(input.find(".") != std::string::npos){
        integer = input.substr(0,input.find("."));
        placesSTR = input.substr(input.find(".")+1, input.length()-input.find(".")+1);
    }else{
        integer = input;
        placesSTR = "0";
    }

    double decimal = 0.0;
    /* Converting integer part to decimal using horner's scheme (starting from the front of string) */
    for(size_t i{0}; i<integer.length(); ++i){
        unsigned short digitVal = Digit2DecVal(integer.at(i)); //Get decimal value of digit
        if(digitVal >= base){
            return -1.0;
        }

        decimal += digitVal;
        decimal *= base;
    }

    decimal /= base; //there is one multipication by base too much in the loop and I don't want to check every turn if it's the last

    double decPlacesDBL = 0.0;

    /* Converting the places to decimal using horner's scheme (starting from the back of string) */
    for(int i = placesSTR.length()-1; i>= 0; --i){
        unsigned short digitVal = Digit2DecVal(placesSTR.at(i));
        if(digitVal >= base){
            return -1;
        }
        decPlacesDBL += digitVal;
        decPlacesDBL *= 1.0/base;
    }

    return decimal + decPlacesDBL;

}

/* Gets the digit of a decimal value */
char Decimal2Digit(unsigned short value){
    std::string digits {"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"};
    return digits.at(value);
}

/*Converts the decimal representation to outputBase*/
std::string DecimalToBase(const double & decimal,const unsigned short & outputBase){
    if(outputBase == 10){
        return std::to_string(decimal);
    }else{
        /* Splitting integer and places*/
        unsigned long integer = static_cast<unsigned long>(decimal);
        double places = decimal - integer;
        std::vector<unsigned short> intDecVals; //reading result back to front
        std::queue<unsigned short> placesDecVals; //reading result front to back

        /* Convert integer part to decimal values of the digits using repeated division by base */
        do{
            intDecVals.push_back(integer % outputBase); //storing remainder
            integer /= outputBase;
        }while(integer > 0);

        /* Convert places to decimal values of the digits using repeated multiplication by base */
        int safetyCounter{0};
        do{
            places *= outputBase;
            placesDecVals.push(floor(places)); //storing overflow
            places -= floor(places);
            ++safetyCounter;
        }while(places > 0 && safetyCounter < 64); //do this loop a maximum of 64 times

        /* Converting decimal values to corresponding digits */
        std::stringstream sstream;
        while(intDecVals.size()>0){ //integer part
            sstream << Decimal2Digit(intDecVals.back()); // back to front
            intDecVals.pop_back();
        }
        sstream << ".";
        while(placesDecVals.size()>0){ //places
            sstream << Decimal2Digit(placesDecVals.front()); // front to back
            placesDecVals.pop();
        }

        return sstream.str();
    }

}
