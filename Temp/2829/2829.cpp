// Link: https://leetcode.com/problems/determine-the-minimum-sum-of-a-k-avoiding-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_set<int> used;
        int sum = 0, x = 1;
        while ((int)used.size() < n) {
            if (used.count(k - x)) { x++; continue; }
            used.insert(x);
            sum += x;
            x++;
        }
        return sum;
    }
};
