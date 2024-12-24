/** *****************************************************************
			Largest Product in a Series

  Q8. The four adjacent digits in the 1000-digit number that have the 
      greatest product are 9×9×8×9=5832.

	7316717653133062491922511967442657474235534919493
        96983520312774506326239578318016984801869478851843
	85861560789112949495459501737958331952853208805511
 	12540698747158523863050715693290963295227443043557
	66896648950445244523161731856403098711121722383113
	62229893423380308135336276614282806444486645238749
	30358907296290491560440772390713810515859307960866
	70172427121883998797908792274921901699720888093776
	65727333001053367881220235421809751254540594752243
	52584907711670556013604839586446706324415722155397
	53697817977846174064955149290862569321978468622482
	83972241375657056057490261407972968652414535100474
	82166370484403199890008895243450658541227588666881
	16427171479924442928230863465674813919123162824586
	17866458359124566529476545682848912883142607690042
	24219022671055626321111109370544217506941658960408
	07198403850962455444362981230987879927244284909188
	84580156166097919133875499200524063689912560717606
	05886116467109405077541002256983155200055935729725
	71636269561882670428252483600823257530420752963450

      Find the thirteen adjacent digits in the 1000-digit number that 
      have the greatest product. 
	  
  A8. 23514624000  
***************************************************************** **/
/** *****************************************************************

    This is solved using the Sliding Window Concept

    The fundamental concept behind the Sliding Window is to maintain 
	a "window" over the input data. This window represents a contiguous 
	portion of the array or string. The algorithm then systematically 
	"slides" this window across the input, adjusting its size as needed, 
	to explore different subarrays/substrings and find the desired 
	solution.

    Key Components:

    Window: A contiguous subarray or substring of the input. 
            It's typically defined by two pointers:

            Left Pointer (Start): Marks the beginning of the window.

            Right Pointer (End): Marks the end of the window.
			
    Window Size: The number of elements within the current window. 
                 This size can be fixed or variable.

    Sliding: The process of moving the window across the input. 
             This is done by either:

	Expanding the window: Incrementing the right pointer to include 
		              more elements.
						  
	Shrinking the window: Incrementing the left pointer to exclude 
	                      elements from the beginning.

    General Algorithm:

		Initialization:

			Initialize the left and right pointers (usually both start at 0).
			
			Initialize any necessary variables to track the current state of 
			the window (e.g., sum, product, count of specific elements).
			
		Iteration: While the right pointer is within the bounds of the input:

		Expand: Add the element at the right pointer to the window and update 
		        the relevant variables.

		Check Condition: Evaluate if the current window satisfies the 
		                 desired condition (e.g., sum within a certain range, 
				 contains all required characters).
						 
		Shrink (if needed): If the condition is not met or if you need to 
			            optimize the window size, start shrinking the 
				    window by incrementing the left pointer and 
				    updating the variables accordingly. Continue 
				    shrinking until the condition is satisfied or a 
				    minimum window size is reached.
							
		Update Result: If the current window is a valid solution, update the 
			       overall result (e.g., minimum/maximum length, best sum).
					   
		Move the Window: Move the right pointer forward to continue the process.

***************************************************************** **/
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main() {
    char num[] = "73167176531330624919225119674426574742355349194934"
                 "96983520312774506326239578318016984801869478851843"
                 "85861560789112949495459501737958331952853208805511"
                 "12540698747158523863050715693290963295227443043557"
                 "66896648950445244523161731856403098711121722383113"
                 "62229893423380308135336276614282806444486645238749"
                 "30358907296290491560440772390713810515859307960866"
                 "70172427121883998797908792274921901699720888093776"
                 "65727333001053367881220235421809751254540594752243"
                 "52584907711670556013604839586446706324415722155397"
                 "53697817977846174064955149290862569321978468622482"
                 "83972241375657056057490261407972968652414535100474"
                 "82166370484403199890008895243450658541227588666881"
                 "16427171479924442928230863465674813919123162824586"
                 "17866458359124566529476545682848912883142607690042"
                 "24219022671055626321111109370544217506941658960408"
                 "07198403850962455444362981230987879927244284909188"
                 "84580156166097919133875499200524063689912560717606"
                 "05886116467109405077541002256983155200055935729725"
                 "71636269561882670428252483600823257530420752963450";

    uint64_t max_product = 0;
    uint32_t len = strlen(num);
    uint64_t current_product = 1;
    uint32_t num_zeros = 0;
	uint32_t i;
	uint32_t j;

    //Initialize first window
    for(i = 0; i < 13; i++){
        uint32_t digit = num[i] - '0';
        if (digit == 0) {
            num_zeros++;
        }
        current_product *= digit;
    }
    
    if (current_product > max_product) {
        max_product = current_product;
    }

    for (i = 13; i < len; i++) {
        uint32_t prev_digit = num[i-13] - '0';
        uint32_t next_digit = num[i] - '0';

        if(prev_digit == 0){
            num_zeros--;
        }
        if(next_digit == 0){
            num_zeros++;
        }
        
        if (num_zeros > 0) {
            current_product = 0; // Reset if there's a zero in the window
        } else {
             if (prev_digit != 0) {
                current_product = current_product / prev_digit * next_digit;
             } else {
                // Recalculate the product if prev_digit was zero.
                current_product = 1;
                for (j = i - 12; j <= i; j++) {
                    current_product *= (num[j] - '0');
                }
             }
        }

        if (current_product > max_product) {
            max_product = current_product;
        }
    }

    printf("The greatest product of thirteen adjacent digits is: %lld\n", max_product);

    return 0;
}

