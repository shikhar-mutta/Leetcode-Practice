// Link: https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {
        vector<int> numsOdd, numsEven, targetOdd, targetEven;
        for (int x : nums) (x % 2 ? numsOdd : numsEven).push_back(x);
        for (int x : target) (x % 2 ? targetOdd : targetEven).push_back(x);

        sort(numsOdd.begin(), numsOdd.end());
        sort(numsEven.begin(), numsEven.end());
        sort(targetOdd.begin(), targetOdd.end());
        sort(targetEven.begin(), targetEven.end());

        long long total = 0;
        for (int i = 0; i < (int)numsOdd.size(); i++)
            total += abs(numsOdd[i] - targetOdd[i]);
        for (int i = 0; i < (int)numsEven.size(); i++)
            total += abs(numsEven[i] - targetEven[i]);

        return total / 4;
    }
};
