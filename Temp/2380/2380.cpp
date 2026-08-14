// Link: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int time = 0, zeros = 0;
        for (char c : s) {
            if (c == '0') zeros++;
            else if (zeros > 0) time = max(time + 1, zeros);
        }
        return time;
    }
};
