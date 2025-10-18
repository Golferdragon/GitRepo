/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
Input: nums = [3,2,4], target = 6
Output: [1,2]

Example 3:
Input: nums = [3,3], target = 6
Output: [0,1]
 
Constraints:
	  2		<= nums.length	<= 10^4
	-10^9	<= nums[i]		<= 10^9
	-10^9	<= target		<= 10^9
	Only one valid answer exists.
 
			Follow-up: Can you come up with an algorithm that is less than O(n2) time complexity?
*/
// LEETCODE : C++ Practice - Two Sum : 9/15/2025
// #1. Brute force method. >>>>> Using nested for() loops. Time Complexity O(n^2) : Space Complexity O(1)
// #2. Can we change our array somehow so that this search becomes faster? >>>>> Use sorta array and two pointers?  Time complexity = O(n log n).
// #3. Like maybe a hash map to speed up the search? >>>>> Use Hash map as mentioned. Time complexity = O(n) : Space Complexity O(n)

// < #1 >

					// ISSUES PRESENT WITH COMPILATION

// needed include(s)
#include <iostream>
#include <vector>

class Solution {std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> toStore = {-1, -1};		// default if nothing found
        
        // nested for loop
        for(int i = 0; i < nums.size() - 1; i++) {
            for(int j = i + 1; j < nums.size(); j++ ) {
				if(nums[i] + nums[j] == target) {
                    toStore[0] = i;
                    toStore[1] = j;

                    // output the resulting indices of the two numbers that add up to the "target value"
                    std::cout << "Because nums[" << i << "] + nums[" << j << "] == " 
                              << target << ", we return [" << toStore[0] << ", " 
                              << toStore[1] << "]." << std::endl;

                    // exit for solution found
                    return toStore;
                }
            }
        }
        // exit for no solutions found
        return toStore;
    }
};

int main() {
    // Containers for testing purposes
    Solution test;
	std::vector<int> testNums = {2,7,11,15};
    int testTarget = 9;

    // run the Two Sum Solution/function
    std::vector<int> indices = test.twoSum(testNums, testTarget);

    // Print Results
    std::cout << "Indices Returned by twoSum: [" << indices[0] << ", " << indices[1] << "]" << std::endl;

    // exit
    return 0;
}
