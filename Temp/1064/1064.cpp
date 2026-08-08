// Link: https://leetcode.com/problems/fixed-point/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fixedPoint(vector<int>& arr) {
        int lo = 0, hi = arr.size() - 1, res = -1;
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (arr[mid] == mid) { res = mid; hi = mid - 1; }
            else if (arr[mid] < mid) lo = mid + 1;
            else hi = mid - 1;
        }
        return res;
    }
};
