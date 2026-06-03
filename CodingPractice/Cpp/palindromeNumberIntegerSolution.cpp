/*
Boolean class to determine if number is Palindrome
This version does not change the input value to a string, 
but rather uses the value as is - an integer.
*/

// LEETCODE : C++ Practice - Palindrome Number

// needed libraries
#include <iostream>
#include <vector>

class Solution {
public:
    bool isPalindrome(int x) {
		// negative numbers can not be palindromes, cleaner by addressing early
		if (x < 0) {
			return false;
		}
		// special case of int x == 0
		if (x == 0) {
			return true;
		}
		
		std::vector<int> temp;
		
		// extract digits into vector
		while (x > 0) {
			temp.push_back(x % 10);
			x /= 10;
		}
		
		// iterators
		int i = 0, j = temp.size() - 1;
		
		// compare from both ends
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
	int testValues[] = {121, -121, 10, 0, 12321, 1234321, 12345};
	
	for (int val : testValues) {
		std::cout << "Input: " << val
				  << " -> Palindrome? "
				  << (test.isPalindrome(val) ? "TRUE" : "FALSE")
				  << std::endl;
	}
	
	return 0;
}
