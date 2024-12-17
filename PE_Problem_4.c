/** *****************************************************************
			Largest Palindrome Product

  Q4. A palindromic number reads the same both ways. The largest 
      palindrome made from the product of two -digit numbers is 
	  
    			9009 = 91 x 99.
	  
      Find the largest palindrome made from the product of 
      two-digit numbers.
	  
  A4. 906609   
***************************************************************** **/

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

// Function to check if a number is a palindrome
bool is_palindrome(int num) {
  uint32_t original = num;
  uint32_t reversed = 0;

  while (num > 0) {
    reversed = reversed * 10 + num % 10;
    num /= 10;
  }

  return original == reversed;
}

int main() {
  uint32_t largest_palindrome = 0;
  uint32_t i,j;

for (i = 999; i >= 100; i--) {
/** *****************************************************************
Optimization: If i*i is less than the current largest palindrome,
there's no need to continue with this i, as any product with 
a smaller j will also be smaller. Start j from 999 so can reach 
largest palindrome faster
***************************************************************** **/
        for (j = 999; j >= i; j--) { 
            uint32_t product = i * j;
            if (is_palindrome(product)) {
                if (product > largest_palindrome) {
                    largest_palindrome = product;
                }
            }
        }
    }

  printf("The largest palindrome made from the product of two 3-digit numbers is: %d\n", largest_palindrome);

  return 0;
}

