/** *****************************************************************
			Smallest Multiple

  Q5. 2520  is the smallest number that can be divided by each of 
      the numbers from 1  to 10  without any remainder. What is the 
      smallest positive number that is evenly divisible by all of the 
      numbers from 1  to 20 ?
	  
  A5. 232792560   
***************************************************************** **/

#include <stdio.h>
#include <stdint.h>

/** *****************************************************************
 To efficiently calculate the LCM, the code uses the gcd function. 
 This function implements Euclid's algorithm, a fast way to find the 
 GCD of two numbers.

 The for loop iterates through the numbers from 2 to 20, accumulating 
 the LCM in the result variable.
***************************************************************** **/

uint32_t gcd(uint32_t a, uint32_t b) {
    while (b != 0) {
        uint32_t temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/** *****************************************************************
By changing the order of operations from ((a * b)/ gcd(a, b)) to 
((a / gcd(a, b))* b), we reduce the risk of overflow, ensuring a 
correct result.
***************************************************************** **/
uint32_t lcm(uint32_t a, uint32_t b) {
    return (a / gcd(a, b)) * b;;
}

int main() {
    uint32_t result = 1;
	uint32_t i;
    for (i = 2; i <= 20; i++) {
        result = lcm(result, i);
    }

    printf("The smallest number divisible by 1 to 20 is: %d\n", result);
    return 0;
}

