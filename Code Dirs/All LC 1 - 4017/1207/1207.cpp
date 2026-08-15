// Link: https://leetcode.com/problems/unique-number-of-occurrences/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> cnt;
        for (int x : arr) cnt[x]++;
        unordered_set<int> seen;
        for (auto& [k, v] : cnt) {
            if (seen.count(v)) return false;
            seen.insert(v);
        }
        return true;
    }
};
