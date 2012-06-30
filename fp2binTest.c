/***********************************************************/
/* fp2binTest.c: Test double to binary string conversion   */
/*                                                         */
/* Rick Regan, http://www.exploringbinary.com              */
/*                                                         */
/***********************************************************/
#include "fp2bin.h"
#include <stdio.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
 char binString[FP2BIN_STRING_MAX];




 fp2bin(0.6,binString);
 printf("0.6 is %s\n",binString);
 printf("0.6 is %c\n",binString[1]);
 
 
 
 

 return (0);
}
