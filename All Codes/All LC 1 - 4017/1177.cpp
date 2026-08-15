// Link: https://leetcode.com/problems/can-make-palindrome-from-substring/description/

#include <bits/stdc++.h>
using namespace std;

#if __cplusplus >= 202002L
#include <bit> // For std::popcount in C++20
#endif

// TC: O(n + q) where n is the length of the string and q is the number of queries
// SC: O(n) for the prefix bitmask array
//  Approach:
//   1. Precompute a prefix bitmask array where each bit represents the parity (odd/even) of the count of each character in the string up to that index.
//   2. For each query, compute the bitmask for the substring using the prefix array and count the number of set bits (characters with odd counts).
//   3. Check if the number of characters with odd counts can be made into a palindrome with at most k replacements. A string can be rearranged into a palindrome if at most one character has an odd count (for odd-length palindromes) or all characters have even counts (for even-length palindromes). The number of characters with odd counts divided by 2 gives the minimum number of replacements needed to make the substring a palindrome. If this number is less than or equal to k, the answer for that query is true; otherwise, it is false.
//  4. Return the results for all queries as a vector of booleans.
class Solution
{
public:
    std::vector<bool>
    canMakePaliQueries(std::string s, std::vector<std::vector<int>> &queries)
    {
        int n = s.length();

        // dp[i] stores the bitmask state of the prefix string s[0...i-1]
        std::vector<int> dp(n + 1, 0);

        // Step 1: Precompute prefix masks
        for (int i = 1; i <= n; ++i)
        {
            int char_bit = 1 << (s[i - 1] - 'a');
            dp[i] = dp[i - 1] ^ char_bit;
        }

        std::vector<bool> ans;
        ans.reserve(queries.size()); // Optimize memory allocation

        // Step 2: Answer each query in O(1) time
        for (const auto &query : queries)
        {
            int left = query[0];
            int right = query[1];
            int k = query[2];

            // XOR isolates the character odd/even parity for the range
            // s[left...right]
            int substring_mask = dp[right + 1] ^ dp[left];

            // Count set bits (characters with odd frequencies)
            int odds = 0;
#if __cplusplus >= 202002L
            odds = std::popcount(
                static_cast<unsigned int>(substring_mask)); // C++20 optimal
#else
            odds = __builtin_popcount(
                substring_mask); // GCC built-in for older standards
#endif

            // Check if allowed replacements (k) can fix the odd character
            // counts
            ans.push_back((odds / 2) <= k);
        }

        return ans;
    }
};