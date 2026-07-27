// Link: https://leetcode.com/problems/vowels-game-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
// Approach: Alice wins iff the string contains at least one vowel — with any
// vowel present she can always make a first move and force a win regardless
// of parity/count details.
class Solution {
public:
    bool doesAliceWin(string s) {
        for (char c : s) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                return true;
        }
        return false;
    }
};
