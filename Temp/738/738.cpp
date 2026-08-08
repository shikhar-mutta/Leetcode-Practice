// Link: https://leetcode.com/problems/monotone-increasing-digits/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) SC: O(log n)
// Approach: scan right to left; whenever a digit is smaller than the one before it, decrement the previous digit and mark all digits from that point onward as '9'. Repeat until stable.
class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        int markFrom = s.size();
        for (int i = (int)s.size()-1; i > 0; i--) {
            if (s[i-1] > s[i]) {
                s[i-1]--;
                markFrom = i;
            }
        }
        for (int i = markFrom; i < (int)s.size(); i++) s[i] = '9';
        return stoi(s);
    }
};
