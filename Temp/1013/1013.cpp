// Link: https://leetcode.com/problems/partition-array-into-three-parts-with-equal-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) return false;
        int target = total / 3;
        int sum = 0, parts = 0;
        for (int x : arr) {
            sum += x;
            if (sum == target) { parts++; sum = 0; }
        }
        return parts >= 3;
    }
};
