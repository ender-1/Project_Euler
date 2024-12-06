/** *****************************************************************
						Multiples of 3 or 5
  
  Q1. A palindromic number reads the same both ways. The largest 
      palindrome made from the product of two -digit numbers is 
	  9009 = 91 x 99.
	  
	  Find the largest palindrome made from the product of two 
	  -digit numbers.
	  
  A1. 906609   
***************************************************************** **/

#include <stdio.h>

/** ***********************************************8
     This function calculates the sum of numbers 
	 divisible by n up to target. It uses the 
	 arithmetic series formula.
************************************************ **/
int sum_divisible_by(int n, int target) {
    int p = target / n; 
    return n * (p * (p + 1)) / 2; 
}

int main() {
    int sum = sum_divisible_by(3, 999) + 
              sum_divisible_by(5, 999) - 
              sum_divisible_by(15, 999);

    printf("The sum of all multiples of 3 or 5 below 1000 is %d.\n", sum);
    return 0;
}

