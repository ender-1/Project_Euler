/** *****************************************************************
						Summation of Primes

  Q9. The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
	  Find the sum of all the primes below two million.
	  
  A9.  
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
    uint64_t sum = 5; // Start with 5 to include the values of 2 and 3
    uint32_t num = 5;
    uint32_t add = 2;

    while (num < 2000000) {
        if (is_prime(num)) {
            sum += num; 
        }
        num += add;
        add = 6 - add;
    }

    printf("The sum of all the primes below two million is %llu.\n", sum);

    return 0;
}


