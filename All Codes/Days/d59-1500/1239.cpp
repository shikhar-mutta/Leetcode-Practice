// Link: https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * 2^n) where n is the number of strings in the input array arr. This is because we are generating all possible combinations of the strings in arr, which takes O(2^n) time, and for each combination, we are checking if it has unique characters, which takes O(n) time.
    // SC: O(n) for the masks vector, which can store up to 2
    // Approach:
    // 1. We will use a bitmask to represent the characters in each string.
    // 2. We will iterate through each string in the input array arr and create a bitmask for it. If the string has duplicate characters, we will skip it.
    // 3. We will maintain a vector of masks that represent the unique combinations of characters we have seen so far.
    // 4. For each new string's bitmask, we will check it against all existing masks in the vector. If it does not overlap with any existing mask, we will create a new combination by OR-ing the two masks together and add it to the vector of masks.
    // 5. We will keep track of the maximum number of unique characters we have seen so far and return that as the final result.
    int maxLength(vector<string> &arr)
    {
        vector<int> masks{0};
        int best = 0;
        for (auto &s : arr)
        {
            int m = 0;
            bool ok = true;
            for (char c : s)
            {
                int b = 1 << (c - 'a');
                if (m & b)
                {
                    ok = false;
                    break;
                }
                m |= b;
            }
            if (!ok)
                continue;
            int sz = masks.size();
            for (int i = 0; i < sz; ++i)
            {
                if (masks[i] & m)
                    continue;
                int comb = masks[i] | m;
                masks.push_back(comb);
                best = max(best, __builtin_popcount(comb));
            }
        }
        return best;
    }
};