/** *****************************************************************
						Sum Square Difference

  Q6. The sum of the squares of the first ten natural numbers is, 385.
      The square of the sum of the first ten natural numbers is, 3025.

      Hence the difference between the sum of the squares of the first 
	  ten natural numbers and the square of the sum is 3025−385=2640.

	  Find the difference between the sum of the squares of the first 
	  one hundred natural numbers and the square of the sum.
	  
  A6. 25164150  
***************************************************************** **/

#include <stdio.h>
#include <stdint.h>

int main(){
	
	// Direct calculation using formula n(n+1)/2
    uint32_t square_of_sum = 5050; 
    square_of_sum *= square_of_sum; // Square the sum
	
    // Direct calculation using formula n(n+1)(2n+1)/6
    uint32_t sum_of_squares = (100 * 101 * 201) / 6; 

    uint32_t difference = square_of_sum - sum_of_squares; 

    printf("The difference between the sum of the squares of the first hundred natural numbers and the square of the sum is %u\n", difference);

    return 0;
}


