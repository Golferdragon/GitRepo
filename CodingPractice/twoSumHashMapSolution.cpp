// #3. Like maybe a hash map to speed up the search? >>>>> Use Hash map as mentioned. Time complexity = O(1).

// < #3 >
// needed include(s)
#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target) {
		std::unordered_map<int, int> seen;		// value -> index
		
		for(int i = 0; i < nums.size(); i++) {
			int complement = target - nums[i];
			
			// check if already seen the complement
			if(seen.find(complement) != seen.end()) {
				std::cout << "Because nums[" << seen[complement] << "] + nums[" << i 
                          << "] == " << target << ", we return [" 
                          << seen[complement] << ", " << i << "]." << std::endl;
						  
				return {seen[complement], i};
				
			}	
		
			// store current value with its index
			seen[nums[i]] = i;
		}
	
		return {-1, -1};	// shouldn't happen, since problem guarantess a solution
	}
};

int main() {
	Solution test;
	std::vector<int> testNums = {2, 7, 11, 15};
	int testTarget = 9;
	
	std::vector<int> indices = test.twoSum(testNums, testTarget);
	
	std::cout << "Indices Returned by twoSum: [" 
              << indices[0] << ", " << indices[1] << "]" << std::endl;

    return 0;
}