// LEETCODE : C++ Practice - Roman to Integer

// needed library(ies)
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cassert>

int romanToInt(const std::string& s) {
    std::unordered_map<char, int> roman = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int total = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (i + 1 < s.size() && roman[s[i]] < roman[s[i + 1]]) {
            total -= roman[s[i]];
        } else {
            total += roman[s[i]];
        }
    }
    return total;
}

int main() {
    // Original test cases
    std::vector<std::pair<std::string, int>> test_cases = {
        {"I", 1},
        {"III", 3},
        {"IV", 4},
        {"IX", 9},
        {"LVIII", 58},
        {"MCMXCIV", 1994}
    };

    // 15 additional test cases for thoroughness
    std::vector<std::pair<std::string, int>> extra_cases = {
        {"II", 2},         // smallest repeat
        {"VI", 6},         // simple addition
        {"XIII", 13},      // mixed
        {"XIV", 14},       // subtraction case
        {"XX", 20},        // repeat of tens
        {"XL", 40},        // subtractive notation
        {"XC", 90},        // subtractive tens
        {"CXL", 140},      // 100 + 40
        {"CD", 400},       // subtractive hundreds
        {"DCCC", 800},     // large repetition
        {"CM", 900},       // subtractive hundreds near 1000
        {"MCM", 1900},     // 1000 + 900
        {"MMM", 3000},     // maximum conventional Roman numeral
        {"MMXXV", 2025},   // modern year (nice sanity check)
        {"MDCLXVI", 1666}  // contains all symbols once, ordered
    };

    // Merge both sets
    test_cases.insert(test_cases.end(), extra_cases.begin(), extra_cases.end());

    // Run and verify
    for (size_t i = 0; i < test_cases.size(); i++) {
        const auto& [roman, expected] = test_cases[i];
        int result = romanToInt(roman);
        std::cout << "Test " << (i + 1) << ": " << roman 
                  << " -> " << result 
                  << " (expected " << expected << ")\n";
        assert(result == expected);
    }

    std::cout << "✅ All " << test_cases.size() << " test cases passed!\n";
    return 0;
}
