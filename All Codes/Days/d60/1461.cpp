// Link: https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(2^k)
    //  Approach:
    //  1. Check if the length of the string s is less than k. If it is, return false since it's impossible to have all binary codes of size k.
    //  2. Calculate the total number of binary codes of size k, which is 2^k.
    //  3. Check if the number of substrings of length k in s (which is n - k + 1) is less than the total number of binary codes. If it is, return false since it's impossible to have all binary codes of size k.
    //  4. Create a boolean vector seen of size total (2^k) to keep track of which binary codes have been seen in the string s.
    //  5. Initialize a mask to keep track of the last k bits of the current substring and a counter cnt to count how many unique binary codes have been seen.
    //  6. Iterate through the string s, updating the current substring's value by shifting left and adding the new bit, while applying the mask to keep only the last k bits.
    //  7. If the current substring's value is a new binary code (not seen before), mark it as seen and increment the counter. If the counter reaches the total number of binary codes, return true since all binary codes of size k have been found.
    //  8. After iterating through the string, return whether the counter equals the total number of binary codes, indicating that all binary codes of size k have been found in the string s.
    bool hasAllCodes(string s, int k)
    {
        int n = s.size();
        if (n < k)
            return false;
        int total = 1 << k;
        if (n - k + 1 < total)
            return false;

        vector<bool> seen(total, false);
        int mask = total - 1, cur = 0, cnt = 0;
        for (int i = 0; i < n; ++i)
        {
            cur = ((cur << 1) | (s[i] - '0')) & mask;
            if (i >= k - 1 && !seen[cur])
            {
                seen[cur] = true;
                if (++cnt == total)
                    return true;
            }
        }
        return cnt == total;
    }
};