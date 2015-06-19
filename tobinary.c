//
// ************************************************************************************
// 
// Class     : PCC CS201
// Assignment: 1
// Project   : Decimal/Binary Converter - tobinary.c
//
// Student   : Erik Ratcliffe
// Date      : April 21, 2014
// 
// ************************************************************************************
//

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "tobinary.h"


// ----------------------------------------------------------------- 
// decToBinary: converts decimal (base 10) number to binary (base 2)
// -----------------------------------------------------------------
//
// Input:
//   int    aDecimalNumber - an integer, range is platform-dependent
//   char * binaryBits     - pointer to array that holds bit values
//
// Returns:
//   int totalBits         - number of bits used in conversion (not padding bits)
//
// Notes:
//   - binaryBits[] array stores bits in low-to-high order
//   
int decToBinary(int aDecimalNumber, char * binaryBits)
{

    int idx;               // Reused for all index values
    int totalBits = 0;     // Bits generated during binary conversion (no padding)
    int absDecimalNumber;  // Absolute value of decimal number
    int carry;             // Holds the carry value during binary addition
    int bitTotal;          // Holds total value of all bits during binary addition

    // Start by filling binaryBits[] with '0's
    //
    for(idx = 0; idx < INTBITS; idx++)
    {
        binaryBits[idx] = '0';
    }

    // Make sure we're starting with a positive decimal number
    //
    absDecimalNumber = abs(aDecimalNumber);

    // Convert decimal number to binary bits, tracking number of bits generated
    //
    idx = 0;
    while(absDecimalNumber > 0)
    {
        binaryBits[idx++] = (absDecimalNumber % 2 ? '1' : '0');
        absDecimalNumber /= 2;
        totalBits++;
    }

    // If the decimal number is negative, generate two's complement
    //
    if(aDecimalNumber < 0) 
    {
        // Step 1: "Flip" the bits.
        //
        idx = 0;
        while(idx < INTBITS)
        {
            binaryBits[idx] = (binaryBits[idx] == '0' ? '1' : '0');
            idx++;
        }

        // Step 2: Add 1.
        //
        carry = 1; // Let carry hold the initial 1 that is being added
        idx = 0;
        while(idx < INTBITS)
        {
            // The int value of a char is the char minus char value of '0'
            //
            bitTotal = (binaryBits[idx] - '0') + carry;

            // Replace bit values as necessary to accommodate for binary math
            //
            switch(bitTotal)
            {
                case 0:
                    binaryBits[idx] = '0';
                    carry = 0;
                    break;
                case 1:
                    binaryBits[idx] = '1';
                    carry = 0;
                    break;
                case 2:
                    binaryBits[idx] = '0';
                    carry = 1;
            }
            idx++;
        }

        // SPECIAL CASE, "max negative value" exception: binary value must be 1 
        // followed by all 0s.
        //
        if(aDecimalNumber == INT_MIN)
        {
            binaryBits[INTBITS - 1] = '1';
        }
    }

    return totalBits;

} // end of decToBinary()


