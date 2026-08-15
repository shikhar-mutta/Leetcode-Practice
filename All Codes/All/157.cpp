// Link: https://leetcode.com/problems/read-n-characters-given-read4/description/

#include <bits/stdc++.h>
using namespace std;

// The read4 API is provided by the judge/driver at submission time.
int read4(char *buf4);

// TC: O(n)  SC: O(1)
// Approach: repeatedly call read4 into a small local buffer, copy as many of its chars as still needed
// into the caller's buf, stop once read4 returns fewer than 4 (end of file) or n chars are filled
class Solution {
public:
    int read(char *buf, int n) {
        char buf4[4];
        int total = 0;
        while (total < n) {
            int cnt = read4(buf4);
            for (int i = 0; i < cnt && total < n; i++) buf[total++] = buf4[i];
            if (cnt < 4) break;
        }
        return total;
    }
};
