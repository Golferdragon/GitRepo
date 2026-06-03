/*
Given an integer x, return true if x is a palindrome, and false otherwise.

Example 1:
Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:
Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:
Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

	Constraints:

	-2^31 	<= 	x 	<= 	2^31 - 1

Follow up: Could you solve it without converting the integer to a string? >>>>> Usage of Arrays? Make copy and reverse, then compare to input?
*/

// LEETCODE : C++ Practice - Palindrome Number

// needed libraries
#include <iostream>
#include <string>

class Solution {
public:
    bool isPalindrome(int x) {
		// negative numbers can not be palindromes, cleaner by addressing early
		if (x < 0) {
			return false;
		}
		
		// convert int x into string
		std::string temp = std::to_string(x);
		
		// iterators
		int i = 0, j = temp.size() - 1;
		
		// iterate through string, compare front to back, if all match then true, if not then false
		while (i < j) {
			if(temp[i++] != temp[j--]) {
				return false;	// is not palindrome
			}
		}
		
		return true;			// is palindrome
    }
};

int main() {
	Solution test;
	int testValue = 1212121;
	
	std::cout << "\nRESULT: ";
	
	if(test.isPalindrome(testValue)) {
		std::cout << "\tTRUE\n\nProcess Completed. Exiting." << std::endl;
	}
	else {
		std::cout << "\tFALSE\n\nProcess Completed. Exiting." << std::endl;
	}
	
	return 0;
}
