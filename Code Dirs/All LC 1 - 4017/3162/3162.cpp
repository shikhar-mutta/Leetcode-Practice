// Link: https://leetcode.com/problems/find-the-number-of-good-pairs-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int cnt = 0;
        for (int a : nums1)
            for (int b : nums2)
                if (b * k != 0 && a % (b * k) == 0) cnt++;
        return cnt;
    }
};
