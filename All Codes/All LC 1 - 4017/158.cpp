// Link: https://leetcode.com/problems/read-n-characters-given-read4-ii-call-multiple-times/description/

#include <bits/stdc++.h>
using namespace std;

// The read4 API is provided by the judge/driver at submission time.
int read4(char *buf4);

// TC: O(n) amortized across all calls  SC: O(1)
// Approach: keep a small internal leftover buffer (+ pointer/count) across calls, since a read4 call
// may return more chars than the current read() needs; drain the leftover first before calling read4 again
class Solution {
public:
    int read(char *buf, int n) {
        int total = 0;
        while (total < n) {
            if (leftoverPos < leftoverCount) {
                buf[total++] = leftoverBuf[leftoverPos++];
                continue;
            }
            leftoverCount = read4(leftoverBuf);
            leftoverPos = 0;
            if (leftoverCount == 0) break;
        }
        return total;
    }
private:
    char leftoverBuf[4];
    int leftoverCount = 0;
    int leftoverPos = 0;
};
