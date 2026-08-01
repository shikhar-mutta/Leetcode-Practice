// Link: https://leetcode.com/problems/maximum-value-of-concatenated-binary-segments/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(m log m * L)  SC: O(m * L), m=segment count, L=max segment length
// Approach: each segment i is built from nums1[i] ones and nums0[i] zeros;
// arranging all ones before all zeros maximizes that segment's own value.
// Segments are then ordered via the classic "largest concatenation"
// comparator (a+b > b+a as strings) to maximize the overall concatenated
// value, same greedy used for arranging numbers into the largest
// concatenation. The final binary string's value is computed mod 1e9+7 by
// folding each segment in: value = value*2^len(segment) + segmentValue.
class Solution {
    static const long long MOD = 1000000007;
public:
    int maxValue(vector<int>& nums1, vector<int>& nums0) {
        int m = nums1.size();
        vector<string> segs(m);
        for (int i = 0; i < m; i++) {
            segs[i] = string(nums1[i], '1') + string(nums0[i], '0');
        }
        sort(segs.begin(), segs.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });

        long long value = 0;
        for (auto& s : segs) {
            long long segVal = 0;
            long long p2 = 1;
            for (int i = s.size() - 1; i >= 0; i--) {
                if (s[i] == '1') segVal = (segVal + p2) % MOD;
                p2 = (p2 * 2) % MOD;
            }
            long long shift = 1;
            for (size_t i = 0; i < s.size(); i++) shift = (shift * 2) % MOD;
            value = (value * shift + segVal) % MOD;
        }
        return (int)value;
    }
};
