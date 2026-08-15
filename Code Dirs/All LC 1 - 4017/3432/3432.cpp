// Link: https://leetcode.com/problems/count-partitions-with-even-sum-difference/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long sum = 0;
        for (int x : nums) sum += x;
        if (sum % 2 != 0) return 0;
        return (int)nums.size() - 1;
    }
};
