// Link: https://leetcode.com/problems/maximum-product-of-word-lengths/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2 + total_len)  SC: O(n)
// Approach: bitmask each word's letter set, two words share no letters iff
// their masks AND to 0
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> masks(n, 0);
        for (int i = 0; i < n; i++)
            for (char c : words[i]) masks[i] |= 1 << (c - 'a');

        int best = 0;
        for (int i = 0; i < n; i++)
            for (int j = i + 1; j < n; j++)
                if (!(masks[i] & masks[j]))
                    best = max(best, (int)(words[i].size() * words[j].size()));
        return best;
    }
};
