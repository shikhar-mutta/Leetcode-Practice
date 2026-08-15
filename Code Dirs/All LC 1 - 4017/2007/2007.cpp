// Link: https://leetcode.com/problems/find-original-array-from-doubled-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findOriginalArray(vector<int>& changed) {
        int n = changed.size();
        if (n % 2 != 0) return {};
        vector<int> sorted = changed;
        sort(sorted.begin(), sorted.end());
        unordered_map<int,int> count;
        for (int x : sorted) count[x]++;
        vector<int> res;
        for (int x : sorted) {
            if (count[x] == 0) continue;
            count[x]--;
            if (x == 0) {
                if (count[0] == 0) return {};
                count[0]--;
                res.push_back(0);
            } else {
                if (count[2 * x] == 0) return {};
                count[2 * x]--;
                res.push_back(x);
            }
        }
        return res;
    }
};
