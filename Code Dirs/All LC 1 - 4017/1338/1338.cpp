// Link: https://leetcode.com/problems/reduce-array-size-to-the-half/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> freq;
        for (int x : arr) freq[x]++;
        vector<int> counts;
        for (auto& [k, v] : freq) counts.push_back(v);
        sort(counts.rbegin(), counts.rend());

        int n = arr.size();
        int removed = 0, sets = 0;
        for (int c : counts) {
            removed += c;
            sets++;
            if (removed * 2 >= n) break;
        }
        return sets;
    }
};
