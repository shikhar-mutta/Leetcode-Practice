// Link: https://leetcode.com/problems/maximum-elegance-of-a-k-length-subsequence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long findMaximumElegance(vector<vector<int>>& items, int k) {
        sort(items.begin(), items.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] > b[0];
        });
        int n = items.size();
        long long sum = 0;
        unordered_set<int> cats;
        stack<int> dup;
        for (int i = 0; i < k; i++) {
            sum += items[i][0];
            if (cats.count(items[i][1])) dup.push(items[i][0]);
            else cats.insert(items[i][1]);
        }
        long long ans = sum + (long long)cats.size() * (long long)cats.size();
        for (int i = k; i < n; i++) {
            if (!cats.count(items[i][1]) && !dup.empty()) {
                sum += items[i][0] - dup.top();
                dup.pop();
                cats.insert(items[i][1]);
                ans = max(ans, sum + (long long)cats.size() * (long long)cats.size());
            }
        }
        return ans;
    }
};
