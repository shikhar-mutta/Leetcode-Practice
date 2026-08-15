// Link: https://leetcode.com/problems/minimum-time-to-type-word-using-special-typewriter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToType(string word) {
        int cur = 0;
        int total = 0;
        for (char c : word) {
            int target = c - 'a';
            int diff = abs(target - cur);
            total += min(diff, 26 - diff) + 1;
            cur = target;
        }
        return total;
    }
};
