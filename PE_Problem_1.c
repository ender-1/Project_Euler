/** *****************************************************************
			Multiples of 3 or 5
  
  Q1. If we list all the natural numbers below 10 that are multiples 
      of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 
	  23.

	  Find the sum of all the multiples of 3 or 5 below 1000.
	  
  A1. 233168   
***************************************************************** **/

#include <stdio.h>
#include <stdint.h>

/** ***********************************************8
     This function calculates the sum of numbers 
	 divisible by n up to target. It uses the 
	 arithmetic series formula.
************************************************ **/
uint32_t sum_divisible_by(uint32_t n, uint32_t target) {
    uint32_t p = target / n; 
    return n * (p * (p + 1)) / 2; 
}

int main() {
    uint32_t sum = sum_divisible_by(3, 999) + 
              sum_divisible_by(5, 999) - 
              sum_divisible_by(15, 999);

    printf("The sum of all multiples of 3 or 5 below 1000 is %u.\n", sum);
    return 0;
}

