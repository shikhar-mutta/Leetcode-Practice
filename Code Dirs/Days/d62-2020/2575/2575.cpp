// Link: https://leetcode.com/problems/find-the-divisibility-array-of-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(n) for the output array
// Approach: walk the digit string left to right, maintaining the running
// remainder mod m of the numeric prefix seen so far (rem = (rem*10 + digit) % m,
// avoids building the actual huge number). Prefix is divisible by m iff rem==0.
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> result;
        result.reserve(word.size());
        long long rem = 0;
        for (char c : word) {
            rem = (rem * 10 + (c - '0')) % m;
            result.push_back(rem == 0 ? 1 : 0);
        }
        return result;
    }
};
