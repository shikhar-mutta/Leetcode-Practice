// Link: https://leetcode.com/problems/find-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(n)
// Approach: fill 1..n+1 in order, then for each maximal run of 'D's reverse
// the corresponding segment (inclusive of the number after the run)
class Solution {
public:
    vector<int> findPermutation(string s) {
        int n = s.size() + 1;
        vector<int> res(n);
        iota(res.begin(), res.end(), 1);

        int i = 0;
        while (i < (int)s.size()) {
            if (s[i] == 'I') { i++; continue; }
            int j = i;
            while (j < (int)s.size() && s[j] == 'D') j++;
            reverse(res.begin() + i, res.begin() + j + 1);
            i = j;
        }
        return res;
    }
};
