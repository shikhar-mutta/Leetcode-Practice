// Link: https://leetcode.com/problems/pancake-sorting/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> res;
        int n = arr.size();
        for (int size = n; size >= 2; size--) {
            int idx = max_element(arr.begin(), arr.begin() + size) - arr.begin();
            if (idx == size - 1) continue;
            if (idx != 0) {
                reverse(arr.begin(), arr.begin() + idx + 1);
                res.push_back(idx + 1);
            }
            reverse(arr.begin(), arr.begin() + size);
            res.push_back(size);
        }
        return res;
    }
};
