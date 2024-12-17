/** *****************************************************************
			Largest Prime Factor

  Q3. The prime factors of 13195 are 5, 7, 13 and 29.
      What is the largest prime factor of the number 600851475143 ?
	  
  A3. 6857 
***************************************************************** **/

#include <stdio.h>
#include <stdint.h>

uint32_t is_prime(uint32_t n){
	uint32_t i;
	for (i = 5; i*i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    uint64_t n = 600851475143LL; // Use uint64_t and LL suffix
	uint64_t m;
	m = n;
	uint64_t pf = 2; //Assuming that the largest prime factor is 2
	uint32_t i;
	uint64_t f;
	
// Removes all factors of 2
	
	while (n%2 == 0){
		n /= 2;
	}
	
// Removes all factors of 3
	
	while (n % 3 == 0) {
        pf = 3;
        n /= 3;
    }
	
/** ****************************************************************
    The loop iterates through potential odd prime factors of n.
    The loop variable starts with 5 as we are using the 
    6k ± 1 Optimization which is based on the mathematical property 
    that all prime numbers greater than 3 can be expressed in the 
    form 6k ± 1, where k is any integer. By starting with f = 5 and 
    incrementing it by 2 and 4 alternately, the loop efficiently 
    checks all numbers of this form, effectively covering all 
    potential prime factors greater than 3.
	
    n /= f: This divides the number n by prime factor pf 
    repeatedly to remove all instances of the prime factor pf 
    from the number n. This helps f += i: In each iteration,
    f is incremented by i.
	
    i = 6 - i: This alternates the value of i between 2 
    and 4 (2 -> 4 -> 2 -> 4 ...), effectively generating the 
    sequence 5, 7, 11, 13, 17, 19, and so on.
	
    If n is divisible by f, it means f is a prime factor.
	
    pf = f: The pf variable which stores the largest prime 
    factor found so far is updated to f.
	
    n /= f: The code divides n by f repeatedly to remove all 
    occurrences of this prime factor from n. This is crucial for 
    efficiency because it reduces the size of n and helps in 
    finding the next largest prime factor more quickly.
***************************************************************  **/
    for (f = 5, i = 2; f * f <= n; f += i, i = 6 - i) {        
	if(is_prime(f)){
		pf = f;
		while (n % f == 0) {
			n /= f;
		}
	}
   }
 

/** ****************************************************************
    If above test conditions fail then this checks if n > 1
    and if n > 1 then it implies that n is itself a prime number
***************************************************************  **/

    if (n > 1) { 
        pf = n;
    }

    printf("The largest prime factor of %lld is %u.\n", m, pf); 

    return 0;
}


