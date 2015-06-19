//
// ************************************************************************************
// 
// Class     : PCC CS201
// Assignment: 1
// Project   : Decimal/Binary Converter - tobinary.h
//
// Student   : Erik Ratcliffe
// Date      : April 21, 2014
// 
// ************************************************************************************
//

#ifndef TOBINARY_H
#define TOBINARY_H


#define INTBITS (sizeof(int) * 8)                       // Total # of bits in an integer.
                                                        // Can't be a const if it's used to
                                                        // initialize arrays (which it is)

int decToBinary(int aDecimalNumber, char * binaryBits); // Convert decimal to binary


#endif
