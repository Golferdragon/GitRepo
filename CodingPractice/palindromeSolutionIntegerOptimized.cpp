// optimized version of the palindrome solution using the integer input without modification (no string usage)

#include <iostream>

class Solution {
public:
	bool isPalindrome (int x) {
		int reversedHalf = 0;
		
		// Negative numbers and multiples of 10 (except 0) cannot be palindromes
		if (x < 0 || (x % 10 == 0 && x != 0)) {
			return false;
		}
		while (x > reversedHalf) {
			reversedHalf = reversedHalf * 10 + x % 10;
			x /= 10;
		}
		
		// For even digits counts: x == reversedHalf
		// For odd digit counts: drop the middle digit from the reversedHalf
		return (x == reversedHalf) || (x == reversedHalf / 10);
	}
};

int main() {
	Solution test;
	
	int testValues[] = {121, -121, 10, 0, 12321, 1234321, 12345};
	
	for (int val : testValues) {
		std::cout << "Input: " << val
				  << " -> Palindrome? "
				  << (test.isPalindrome(val) ? "TRUE" : "FALSE")
				  << std::endl;
	}
	
	return 0;
}