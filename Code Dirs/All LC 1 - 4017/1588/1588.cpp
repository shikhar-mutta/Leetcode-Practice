// Link: https://leetcode.com/problems/sum-of-all-odd-length-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            int left = i + 1, right = n - i;
            int oddLeft = (left + 1) / 2, evenLeft = left / 2;
            int oddRight = (right + 1) / 2, evenRight = right / 2;
            int count = oddLeft * oddRight + evenLeft * evenRight;
            total += count * arr[i];
        }
        return total;
    }
};
