// Link: https://leetcode.com/problems/detect-capital/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: valid iff all uppercase, all lowercase, or only the first
// letter uppercase with the rest lowercase
class Solution {
public:
    bool detectCapitalUse(string word) {
        int upper = 0;
        for (char c : word) if (isupper(c)) upper++;
        if (upper == 0 || upper == (int)word.size()) return true;
        return upper == 1 && isupper(word[0]);
    }
};
