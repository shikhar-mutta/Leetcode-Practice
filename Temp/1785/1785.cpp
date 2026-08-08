// Link: https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long sum = 0;
        for (int x : nums) sum += x;
        long long diff = llabs(goal - sum);
        return (int)((diff + limit - 1) / limit);
    }
};
