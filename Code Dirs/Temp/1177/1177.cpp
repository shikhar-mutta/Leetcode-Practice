// Link: https://leetcode.com/problems/can-make-palindrome-from-substring/description/

#include <bits/stdc++.h>
using namespace std;

#if __cplusplus >= 202002L
#include <bit> // For std::popcount in C++20
#endif

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