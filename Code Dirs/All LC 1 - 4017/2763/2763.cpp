// Link: https://leetcode.com/problems/sum-of-imbalance-numbers-of-all-subarrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        int n = nums.size();
        long long total = 0;

        for (int i = 0; i < n; i++) {
            multiset<int> s;
            int imbalance = 0;
            for (int j = i; j < n; j++) {
                int x = nums[j];
                auto it = s.lower_bound(x);
                bool hasLeft = (it != s.begin());
                bool hasRight = (it != s.end());
                int left = hasLeft ? *prev(it) : 0;
                int right = hasRight ? *it : 0;

                if (hasLeft && hasRight && right - left > 1) imbalance--;
                if (hasLeft && x - left > 1) imbalance++;
                if (hasRight && right - x > 1) imbalance++;

                s.insert(x);
                total += imbalance;
            }
        }
        return (int)total;
    }
};
