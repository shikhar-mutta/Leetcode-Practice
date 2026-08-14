// Link: https://leetcode.com/problems/count-asterisks/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        bool inBar = false;
        for (char c : s) {
            if (c == '|') inBar = !inBar;
            else if (c == '*' && !inBar) count++;
        }
        return count;
    }
};
