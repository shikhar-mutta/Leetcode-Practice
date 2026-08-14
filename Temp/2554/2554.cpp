// Link: https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-i/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_set<int> bannedSet(banned.begin(), banned.end());
        long long sum = 0;
        int count = 0;
        for (int i = 1; i <= n; i++) {
            if (bannedSet.count(i)) continue;
            if (sum + i > maxSum) break;
            sum += i;
            count++;
        }
        return count;
    }
};
