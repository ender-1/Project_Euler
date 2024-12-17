/** *****************************************************************
						Smallest Multiple

  Q5. 2520  is the smallest number that can be divided by each of 
      the numbers from 1  to 10  without any remainder. What is the 
	  smallest positive number that is evenly divisible by all of the 
	  numbers from 1  to 20 ?
	  
  A5. 906609   
***************************************************************** **/

#include <stdio.h>

/** *****************************************************************
 To efficiently calculate the LCM, the code uses the gcd function. 
 This function implements Euclid's algorithm, a fast way to find the 
 GCD of two numbers.

The for loop iterates through the numbers from 2 to 20, accumulating 
the LCM in the result variable.
***************************************************************** **/

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
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
int lcm(int a, int b) {
    return (a / gcd(a, b)) * b;;
}

int main() {
    int result = 1;
	int i;
    for (i = 2; i <= 20; i++) {
        result = lcm(result, i);
    }

    printf("The smallest number divisible by 1 to 20 is: %d\n", result);
    return 0;
}

