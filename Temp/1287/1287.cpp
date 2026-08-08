// Link: https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n = arr.size();
        int quarter = n / 4;
        for (int i = 0; i + quarter < n; i++) {
            if (arr[i] == arr[i + quarter]) return arr[i];
        }
        return arr[0];
    }
};
