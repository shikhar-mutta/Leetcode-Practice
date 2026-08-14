// Link: https://leetcode.com/problems/append-k-integers-with-minimal-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        nums.erase(unique(nums.begin(), nums.end()), nums.end());
        long long sum = 0;
        long long prev = 0;
        long long remaining = k;
        for (int x : nums) {
            long long gap = x - prev - 1;
            if (gap > 0) {
                long long take = min(gap, remaining);
                sum += (prev + 1 + prev + take) * take / 2;
                remaining -= take;
                if (remaining == 0) return sum;
            }
            prev = x;
        }
        sum += (prev + 1 + prev + remaining) * remaining / 2;
        return sum;
    }
};
