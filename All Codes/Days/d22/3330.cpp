// Link: https://leetcode.com/problems/find-the-original-typed-string-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // TC: O(n), SC: O(1)
    int possibleStringCount(string word) {
        // At most one run was over-pressed. A run of length L could have been
        // shortened to any of 1..L-1 (L-1 options); plus 1 for no over-press.
        int ans = 1;
        for (int i = 1; i < (int)word.size(); i++)
            if (word[i] == word[i - 1]) ans++;   // each extra char in a run adds one option
        return ans;
    }
};
