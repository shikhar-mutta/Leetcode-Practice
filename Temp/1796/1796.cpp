// Link: https://leetcode.com/problems/second-largest-digit-in-a-string/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int secondHighest(string s) {
        int first = -1, second = -1;
        for (char c : s) {
            if (!isdigit(c)) continue;
            int d = c - '0';
            if (d > first) { second = first; first = d; }
            else if (d < first && d > second) second = d;
        }
        return second;
    }
};
