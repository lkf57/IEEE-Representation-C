/* Lauren Farr - March 18, 2022
A program that uses bitwise operations to analyze the
parts of a floating point binary number */

// include header files
#include <stdio.h>
#include <stdint.h>
#include <string.h>

// constants

// prototypes
void int_to_bin(int number, int places);

// main program function
int main()
{
	// initialize variables
	float decimalFloat;
	uint32_t bits;
	unsigned int sign;
	int exponent;
	int significand;

	
	// get input data
	   
	   // get floating point decimal number
	   printf("Enter real number: ");
	   scanf("%f", &decimalFloat);
	   printf("\n");
	   
	// processing
	
	   // convert the float to the int version of its IEEE binary format
	   bits = *((uint32_t*) &decimalFloat);
	   
	   // get the sign of the number - 0 for positive, 1 for negative
	   sign = bits >> 31;
	   
	   // get the exponent of the number
	   exponent = (bits >> 23) & 0xFF;
	   
	   // get the significand of the number
	   significand = bits & ((1 << 23) - 1);
	   
	
	// output results
	
	   // output the bit pattern of the number
	   printf("Float analysis\n");
	   printf("   Bit Pattern: %d ", sign);
	   int_to_bin(exponent, 8);
	   printf(" ");
	   int_to_bin(significand, 23);
	   printf("\n");
	   printf("                S Exponent Significand\n\n");
	   
	   // output the sign of the number (0 or 1)
	   printf("   Sign:         %u\n", sign);
	   
	   // output the exponent of the number with explanation
	   printf("   Exponent:     ");
	   int_to_bin(exponent, 8);
	   printf(" = %d; w/ bias 127 -> %d\n", exponent, exponent-127);
	   
	   // output the significand without implied 1
	   printf("   Significand:  ");
	   int_to_bin(significand, 23);
	   printf("\n");
	   
	   // with implied 1
	   printf("   w/ implied 1: 1.");
	   int_to_bin(significand, 23);
	   printf("\n\n");
	   
	   // output the floating point binary in scientific notation
	   printf("   Combined:   ");
	   if (sign == 0)
	   	{
	   		printf(" + 1.");
	   		
		}
	   else
	   {
	   		printf(" - 1.");
	   }
	   int_to_bin(significand, 23);
	   printf(" * 2^%d\n", (exponent-127));
	   
	return 0;	
}

// this function is from the website 
// https://www.tutorialspoint.com/decimal-to-binary-conversion-using-c-programming
void int_to_bin(int number, int places)
{
    int j;
    for(int i = places; i >= 0; i--)
    {
        j = number >> i;
        
        if(j & 1)
            printf("1");
        else
            printf("0");
    }
}
