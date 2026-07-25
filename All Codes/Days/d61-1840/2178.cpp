// Link: https://leetcode.com/problems/maximum-split-of-positive-even-integers/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(sqrt(finalSum)) (the greedy loop runs ~k times, k ~ sqrt(finalSum))
// SC: O(k) for the output
// Approach: greedily take the smallest unused positive even numbers
// 2,4,6,... until adding the next one would overshoot finalSum, then dump
// the remaining leftover onto the last chosen number (still even, still
// bigger than everything before it, so distinctness holds). This maximizes
// the count of parts since using any larger values earlier would only
// shrink how many distinct evens fit before hitting finalSum.
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 != 0)
            return {};
        long long sum = 0, num = 2;
        vector<long long> res;
        while (sum < finalSum) {
            if (sum + num <= finalSum) {
                res.push_back(num);
                sum += num;
                num += 2;
            } else {
                res.back() += finalSum - sum;
                sum += res.back();
                break;
            }
        }
        return res;
    }
};
