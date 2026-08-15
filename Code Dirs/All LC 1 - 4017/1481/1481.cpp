// Link: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        vector<int> counts;
        for (auto& [v, c] : cnt) counts.push_back(c);
        sort(counts.begin(), counts.end());

        int remaining = counts.size();
        for (int c : counts) {
            if (k >= c) { k -= c; remaining--; }
            else break;
        }
        return remaining;
    }
};
