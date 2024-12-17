/** *****************************************************************
						10001st Prime

  Q7. By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
      we can see that the 6th prime is 13.
	  
	  What is the 10001st prime number?
	  
  A7. 104743  
***************************************************************** **/

#include <stdio.h>
#include <stdint.h>

int is_prime(uint32_t num) {
    if (num <= 1) return 0;
    if (num <= 3) return 1;
    if (num % 2 == 0 || num % 3 == 0) return 0;
	uint32_t i;

    for (i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return 0;
    }
    return 1;
}

int main() {
    uint32_t count = 1;// Count variable to keep track of number of prime numbers
	uint32_t num = 5;// Starting with prime number 5 as 2 and 3 do not follow  6k ± 1 pattern of prime numbers
	uint32_t add = 2;// Variable used to generate 6k ± 1 sequence
	uint32_t prime;// Variable to store prime number

    while (count < 10000){
	if (is_prime(num)){
			prime = num;
            count++;		
        }
       	num += add;
		add = 6 - add;
    }

    printf("The 10001st prime number is %u.\n", prime);
	
    return 0;
}















	
	