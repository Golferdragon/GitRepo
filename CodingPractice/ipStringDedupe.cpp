// C++ Coding Practice - In place string dedupe
// Preserve first occurrence order
// Can't use "using namespace std"

// Libraries
#include <iostream>
#include <string>
#include <cassert>

// string dedupe function
void removeDuplicates(std::string &s) {
    bool seen[256] = {false};
    int write = 0;
    for (int read = 0; read < (int)s.size(); read++) {
        unsigned char c = s[read];
        if (!seen[c]) {
            seen[c] = true;
            s[write++] = c;
        }
    }
    s.resize(write); // shrink string to new size
}

// main function with test cases
int main() {
    const char* tests[] = {
        "EmbeddedSystemsEngineer",    // mix of repeat letters
        "Mississippi",                // classic duplicate-heavy
        "abcdefg",                    // already unique
        "aabbccddeeff",               // pairs of duplicates
        "123123456456",               // numbers repeating
        "AaBbCc",                     // case-sensitive check
        " spaced  out ",              // spaces + duplicates
        "The quick brown fox",        // pangram fragment
        "Lorem ipsum dolor sit amet", // sentence with spaces
        "ZZZZZZ",                     // all same char
        "OpenAI GPT Chat",            // mixed caps + spaces
        "C++ C++ C++",                // symbols + repeats
        "Hello, World!",              // punctuation
        "123!@#123!@#",               // numbers + symbols
        "AaAaBbBbCcCc"                // alternating repeats
    };

    const char* expected[] = {
        "EmbedSystngir",  // preserve first seen
        "Misp",
        "abcdefg",
        "abcdef",
        "123456",
        "AaBbCc",
        " spacedout",
        "The quickbrownfx",
        "Lorem ipsudlta",
        "Z",
        "OpenAI GPTChat",
        "C+ ",
        "Helo, Wrd!",
        "123!@#",
        "AaBbCc"
    };

    size_t numTests = sizeof(tests) / sizeof(tests[0]);

    for (size_t i = 0; i < numTests; i++) {
        std::string s = tests[i];
        removeDuplicates(s);
        if (s == expected[i]) {
            std::cout << "✅ Test " << i+1 << " passed: [" << s << "]\n";
        } else {
            std::cout << "❌ Test " << i+1 << " failed:\n"
                      << "Input:    [" << tests[i] << "]\n"
                      << "Got:      [" << s << "]\n"
                      << "Expected: [" << expected[i] << "]\n";
        }
    }

    return 0;
}
