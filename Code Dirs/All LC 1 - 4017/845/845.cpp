// Link: https://leetcode.com/problems/longest-mountain-in-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        int best = 0, i = 0;
        while (i < n) {
            int start = i;
            while (i + 1 < n && arr[i] < arr[i+1]) i++;
            if (i > start) {
                bool hasPeak = (i > start);
                int peak = i;
                while (i + 1 < n && arr[i] > arr[i+1]) i++;
                if (i > peak) best = max(best, i - start + 1);
            }
            if (i == start) i++;
        }
        return best;
    }
};
