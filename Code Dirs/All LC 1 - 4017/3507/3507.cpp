// Link: https://leetcode.com/problems/minimum-pair-removal-to-sort-array-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int opr = 0;

        auto isSorted = [&]() {
            for (int i = 0; i + 1 < (int)nums.size(); i++)
                if (nums[i] > nums[i + 1])
                    return false;
            return true;
        };

        while (!isSorted()) {
            int n = nums.size(), minInd = 0, minSum = INT_MAX;
            for (int i = 0; i + 1 < n; i++) {
                int s = nums[i] + nums[i + 1];
                if (s < minSum) {
                    minSum = s;
                    minInd = i;
                }
            }
            nums[minInd] = minSum;
            nums.erase(nums.begin() + minInd + 1);
            opr++;
        }

        return opr;
    }
};
