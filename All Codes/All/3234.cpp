// Link: https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * sqrt(n)) amortized, SC: O(n)
// Approach: For each right endpoint, a substring is "dominant ones" if
// count(1)^2 >= count(0) (since count(0) can be at most sqrt(n) for a fixed
// left choice to stay valid, bounding the inner loop). c1[k] records the
// count of 1s seen by the time k zeros have occurred, letting the number of
// valid left boundaries for a target zero-count be computed via prefix
// differences.
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> c1 = {0};
        int counts[2] = {0, 0};
        int ret = 0;
        for (const char c : s) {
            ++counts[c - '0'];
            if (c == '0')
                c1.push_back(counts[1]);
            ret += counts[1] - c1[counts[0]];
            for (int c0 = counts[0] - 1; c0 >= 0; --c0) {
                const int num0 = counts[0] - c0;
                if (num0 * num0 > counts[1])
                    break;
                const int hi = counts[1] - c1[c0];
                const int lo = counts[1] - c1[c0 + 1];
                if (hi < num0 * num0)
                    continue;
                else
                    ret += max(0, hi - max(lo, num0 * num0) + 1);
            }
        }
        return ret;
    }
};
