/** *****************************************************************
			Special Pythagorean Triplet

  Q9. A Pythagorean triplet is a set of three natural numbers, 
  
			a < b < c,
	
      for which,
	  
     			(a^2) + (b^2) = (c^2).

      For example, (3^2)+(4^2)= 9 + 16 = 25 = (5^2).

      There exists exactly one Pythagorean triplet for 
      which,
	  
			a + b + c = 1000.

      Find the product abc
	  
  A9. 31875000  
***************************************************************** **/

#include <stdio.h>
#include <stdint.h>

int main(){
    uint32_t a, b, c;

    for (a = 1; a < 1000; a++) {
        for (b = a + 1; b < 1000; b++) {
            c = 1000 - a - b;
            if (a * a + b * b == c * c) {
                printf("a = %d, b = %d, c = %d\n", a, b, c);
                printf("Product abc = %d\n", a * b * c);
                return 0;
            }
        }
    }

    return 0;
}

