//
// ************************************************************************************
// 
// Class     : PCC CS201
// Assignment: 1
// Project   : Decimal/Binary Converter - main.c
//
// Student   : Erik Ratcliffe
// Date      : April 21, 2014
// 
// ************************************************************************************
//

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "tobinary.h"


// ------------------------------------------- 
// promptForInput: prompts user for an integer
// -------------------------------------------
//
// Input:
//   char      * promptString       - pointer to array that holds prompt string
//   long long * inputDecimalNumber - pointer to long long int that holds input number
//
// Returns:
//   int validChars                 - number of valid characters input by user
//
// Notes:
//   - Valid input characters include 0-9 with an optional leading '-'. Integers only.
//   - Input is limited to the platform's signed range of long integers. Truncation 
//     to LONG_MIN or LONG_MAX will occur if the input number is outside that range. 
//   - When an invalid character is encountered, the character and all characters 
//     after it are ignored.
// 
int promptForInput(char * promptString, long long * inputDecimalNumber)
{

    int ch;          // Used to flush stdin
    int validChars;  // Valid characters entered by user

    // Start with an innocent number
    //
    *inputDecimalNumber = 0;

    // Display prompt and get user input. Max out at 25 characters of
    // input. That should leave a few spare characters even on 64 bit.
    //
    printf("\n%s", promptString);
    validChars = scanf("%25lld", inputDecimalNumber);

    // Flush stdin.
    //
    while ((ch = getchar()) != '\n' && ch != EOF);


#ifdef DEBUG

    // Show what was actually saved to decimalNumber
    //
    printf("DEBUG >>> Numeric value (poss. truncated): %lld\n", *inputDecimalNumber);

#endif 


    return validChars;

} // end of promptForInput()



// ----------------------------------------- 
// main function
// -----------------------------------------
//
// Input:
//   none
//
// Returns:
//   0/1 - success/failure
//
// Notes:
//   none
// 
int main(void)
{
    long long inputDecimalNumber; // Number input by the user. Needs to be long long int to 
                                  // accommodate full range of integers on 32bit & 64bit machines.
    int  decimalNumber;           // Final number within integer range.
    int  validChars;              // Number of valid characters entered by user in inputString[].
    int  idx;                     // Reused for all index values
    char binaryBits[INTBITS + 1]; // Array of converted bits, low-to-high order
    char promptString[] = "Enter a number (CTRL-C to cancel): "; 


#ifdef DEBUG

    // Show ranges for long int and int.
    //
    // On 32 bit systems, LONG and INT seem to be the same range.
    //
    printf("DEBUG >>> LLONG_MIN: %lld\n", LLONG_MIN);
    printf("DEBUG >>> LLONG_MAX: %lld\n", LLONG_MAX);
    printf("DEBUG >>> LONG_MIN : %ld\n",  LONG_MIN);
    printf("DEBUG >>> LONG_MAX : %ld\n",  LONG_MAX);
    printf("DEBUG >>> INT_MIN  : %d\n",   INT_MIN);
    printf("DEBUG >>> INT_MAX  : %d\n",   INT_MAX);

#endif


    // Prompt for a number. Loop until we get a number we can use, then
    // display the binary number and break the loop.
    //
    while(1)
    {
        validChars = promptForInput(promptString, &inputDecimalNumber);

        // If no valid characters were entered...
        //
        if( validChars <= 0)
        {
            printf("Invalid number.\n");
        }
        // If the number entered was outside the min/max range of regular integers...
        //
        else if( inputDecimalNumber < INT_MIN || inputDecimalNumber > INT_MAX )
        {
            printf("Number is outside of integer range (%d to %d).\n", INT_MIN, INT_MAX);
        }
        // If we get this far, we have a valid number. Convert it, then
        // display it and break from the while loop.
        //
        else
        {
            // Convert number input by user to normal integer
            //
            decimalNumber = (int)inputDecimalNumber;

            // Convert decimal number to binary
            //
            decToBinary(decimalNumber, binaryBits);

            printf("Binary conversion: ");

            // Bits are stored low-to-high order in binaryBits[], so display 
            // them in reverse order.
            //
            idx = INTBITS - 1;
            while(idx >= 0)
            {
                printf("%c", binaryBits[idx--]);
            }
            printf("\n\n");

            break;
        }
    }

    return 0;

} // end of main()


