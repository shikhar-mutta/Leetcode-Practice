// Link: https://leetcode.com/problems/construct-string-with-repeat-limit/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) (26-bucket counting sort scan, n = s.length())
// SC: O(1) (fixed 26-slot frequency array)
// Approach: count letter frequencies, then greedily emit from the
// highest-remaining letter each round (up to repeatLimit copies), and
// whenever that bucket still has leftovers after hitting the cap, break the
// run by borrowing one character from the next-highest nonempty bucket
// before continuing.
class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        string str = "";
        vector<int> vec(26);
        for (auto it : s) {
            vec[it - 'a']++;
        }
        int i = 25;
        while (i >= 0) {
            while (i >= 0 && vec[i] == 0) {
                i--;
            }
            if (i < 0)
                break;
            int len = min(repeatLimit, vec[i]);
            for (int k = 0; k < len; k++) {
                str.push_back(i + 'a');
            }
            vec[i] -= len;
            if (vec[i] == 0) {
                i--;
                continue;
            }

            int j = i - 1;
            while (j >= 0 && vec[j] == 0) {
                j--;
            }
            if (j < 0)
                break;

            str.push_back(j + 'a');
            vec[j]--;
        }

        return str;
    }
};
