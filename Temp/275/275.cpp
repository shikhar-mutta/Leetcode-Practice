// Link: https://leetcode.com/problems/h-index-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n)  SC: O(1)
// Approach: binary search on the ascending-sorted array for the largest h with n - i >= citations[i]
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (citations[mid] >= n - mid) r = mid - 1;
            else l = mid + 1;
        }
        return n - l;
    }
};
