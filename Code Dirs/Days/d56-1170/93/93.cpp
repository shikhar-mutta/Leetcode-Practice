// Link: https://leetcode.com/problems/restore-ip-addresses/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(3^4) - Each of the 4 parts can have a maximum of 3 digits, leading to a maximum of 3^4 combinations. However, due to pruning and validation, the actual number of combinations is much lower.
// SC: O(1) - The space used for the result is not counted towards the space complexity, as it is required for the output. The additional space used is for the recursion stack, which can go up to a maximum depth of 4 (for the 4 parts of the IP address). Therefore, the space complexity is O(1) in terms of additional space used.
// Approach:
//   1. We define a helper function isValid that checks if a given part of the IP address is valid. A part is valid if it is not empty, does not have leading zeros (except for "0"), and is between 0 and 255 inclusive.
//   2. We define a backtrack function that takes the current index in the string, the number of parts formed so far, and the current string being built. If 4 parts are formed and we have consumed all characters in the string, we add the current string (without the trailing dot) to the result.
//   3. We prune the search space by checking if the remaining digits are sufficient to form the remaining parts. If not, we return early.
//   4. We iterate through possible lengths (1 to 3) for the next part, check if it is valid, and recursively call backtrack with the updated index, parts count, and current string.
//   5. Finally, we call the backtrack function starting from index 0, with 0 parts formed and an empty current string. The result vector is returned containing all valid IP addresses formed from the input string.
class Solution
{
public:
    vector<string> result;

    bool isValid(const string &part)
    {
        // No empty part
        if (part.empty())
            return false;

        // Leading zero is not allowed, except "0"
        if (part.size() > 1 && part[0] == '0')
            return false;

        int value = stoi(part);
        return value >= 0 && value <= 255;
    }

    void backtrack(const string &s, int index, int parts, string current)
    {
        // If 4 parts are formed
        if (parts == 4)
        {
            if (index == s.size())
            {
                current.pop_back(); // remove final dot
                result.push_back(current);
            }
            return;
        }

        // Remaining digits pruning
        int remainingDigits = s.size() - index;
        int remainingParts = 4 - parts;

        if (remainingDigits < remainingParts ||
            remainingDigits > remainingParts * 3)
        {
            return;
        }

        // Each IP part can have maximum 3 digits
        for (int length = 1; length <= 3 && index + length <= s.size(); length++)
        {
            string part = s.substr(index, length);

            if (!isValid(part))
                continue;

            backtrack(
                s,
                index + length,
                parts + 1,
                current + part + ".");
        }
    }

    vector<string> restoreIpAddresses(string s)
    {
        if (s.size() < 4 || s.size() > 12)
        {
            return {};
        }

        backtrack(s, 0, 0, "");
        return result;
    }
};