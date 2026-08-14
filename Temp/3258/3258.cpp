// Link: https://leetcode.com/problems/count-substrings-that-satisfy-k-constraint-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int n = s.size();
        int cnt0 = 0, cnt1 = 0, left = 0;
        long long total = 0;
        for (int right = 0; right < n; right++) {
            if (s[right] == '0') cnt0++; else cnt1++;
            while (cnt0 > k && cnt1 > k) {
                if (s[left] == '0') cnt0--; else cnt1--;
                left++;
            }
            total += (right - left + 1);
        }
        return (int)total;
    }
};
