// Link: https://leetcode.com/problems/is-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: two-pointer, advance s pointer only on a match
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        for (int j = 0; j < (int)t.size() && i < (int)s.size(); j++) {
            if (s[i] == t[j]) i++;
        }
        return i == (int)s.size();
    }
};
