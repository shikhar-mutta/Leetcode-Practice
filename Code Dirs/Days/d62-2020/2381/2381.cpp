// Link: https://leetcode.com/problems/shifting-letters-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + shifts.size())
// SC: O(n)
// Approach: a difference array over net shift direction (+1 forward, -1
// backward) per range, applied via start/end+1 markers so each range's
// contribution is O(1) to record. A running prefix sum then gives the
// total net shift at each index in one pass, applied to that character mod
// 26 (with a +26 before the final mod to handle negative shifts).
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);

        for (auto& sh : shifts) {
            int start = sh[0], end = sh[1], dir = sh[2] == 1 ? 1 : -1;
            diff[start] += dir;
            diff[end + 1] -= dir;
        }

        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift += diff[i];
            int c = ((s[i] - 'a' + shift) % 26 + 26) % 26; // wrap negatives
            s[i] = 'a' + c;
        }
        return s;
    }
};
