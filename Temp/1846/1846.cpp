// Link: https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < (int)arr.size(); i++) {
            arr[i] = min(arr[i], arr[i-1] + 1);
        }
        return arr.back();
    }
};
