// Link: https://leetcode.com/problems/password-strength/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
// Approach: track distinct characters seen, score each once by its
// category (lowercase 1, uppercase 2, digit 3, special "!@#$" 5).
class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> seen;
        int score = 0;
        for (char c : password) {
            if (seen.count(c)) continue;
            seen.insert(c);
            if (islower(c)) score += 1;
            else if (isupper(c)) score += 2;
            else if (isdigit(c)) score += 3;
            else score += 5;
        }
        return score;
    }
};
