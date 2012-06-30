/***********************************************************/
/* fp2binTest.c: Test double to binary string conversion   */
/*                                                         */
/* Rick Regan, http://www.exploringbinary.com              */
/*                                                         */
/***********************************************************/
#include "fp2bin.h"
#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char *argv[])
{
 char binString[FP2BIN_STRING_MAX];
 int numb_of_elements = 0;
 int block_length = 0;
 cout<<"no of elements"<<endl;
 cin>>numb_of_elements;
 
  cout<<"block_length is"<<endl;
 cin>>block_length;
 double pmf[numb_of_elements];
 double cdf[numb_of_elements];
 int numb_of_bits[numb_of_elements];
 int string[block_length];
 cdf[0] = 0;
 
 
 cout<< "input the probabilities"<<endl;
 for(int i = 0 ; i < numb_of_elements ; i++)
 {
 		cin>>pmf[i];
 		if(i>0)
 		cdf[i] = cdf[i-1] + pmf[i-1];
 		cout<<"cdf the i="<<i<<"is :"<<cdf[i]<<endl;
 }
 
 double tp = 0;
 for(int i = 0 ; i < numb_of_elements ; i++)
 {
 		tp = log((1/pmf[i]))/log(2);
    numb_of_bits[i] = (int)tp + 1; 
    cout<<"numbofbits the i="<<i<<"is :"<<numb_of_bits[i]<<endl;		
 }
  
  
  
  double length = 1;
  double pivot = 0;
  cout<<" what is the string"<<endl;
  for(int j = 0 ; j < block_length ; j++)
  {
  	cin>>string[j];
  }
  for(int j = 0 ; j < block_length ; j++)
  {
  	pivot = pivot + length*cdf[string[j]] ;
  	length = length*pmf[string[j]];	
  }
  
  pivot = pivot + length/2;
  tp = log((1/length))/log(2);
  int numb = (int)tp + 2;
  fp2bin(pivot,binString);
  
  for(int k = 2 ; k < (numb+2) ; k++)
  {
  	  cout<<binString[k];
  }
  cout<<endl;
  
 //fp2bin(0.6,binString);
 //printf("0.6 is %s\n",binString);
 //printf("0.6 is %c\n",binString[1]);
 
 
 
 

 return (0);
}
