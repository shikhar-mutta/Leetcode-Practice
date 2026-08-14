// Link: https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0) return {};
        vector<long long> res;
        long long next = 2, remaining = finalSum;
        while (remaining >= next) {
            res.push_back(next);
            remaining -= next;
            next += 2;
        }
        res.back() += remaining;
        return res;
    }
};
