// Link: https://leetcode.com/problems/find-three-consecutive-integers-that-sum-to-a-given-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> sumOfThree(long long num) {
        if (num % 3 != 0) return {};
        long long mid = num / 3;
        return {mid - 1, mid, mid + 1};
    }
};
