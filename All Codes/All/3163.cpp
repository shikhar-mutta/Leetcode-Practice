// Link: https://leetcode.com/problems/string-compression-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: Run-length encode word, capping each run at 9 (splitting longer
// runs into multiple <=9-length chunks since the digit must be a single
// character), emitting count-then-char for each chunk.
class Solution {
public:
    string compressedString(string& word) { // Passed by reference if possible,
                                            // otherwise use word directly
        string built = "";
        int n = word.length();

        // Optimization: Pre-allocate memory to completely avoid re-allocations
        built.reserve(n * 2);

        int i = 0;
        while (i < n) {
            char curr_char = word[i];
            int seqlen = 0;

            // Seamlessly consume up to 9 matching characters
            while (i < n && word[i] == curr_char && seqlen < 9) {
                seqlen++;
                i++;
            }

            // Convert to char digit directly instead of using heavy to_string()
            built += (seqlen + '0');
            built += curr_char;
        }

        return built;
    }
};
