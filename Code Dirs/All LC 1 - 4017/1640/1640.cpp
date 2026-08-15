// Link: https://leetcode.com/problems/check-array-formation-through-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int, vector<int>> byFirst;
        for (auto& p : pieces) byFirst[p[0]] = p;
        int i = 0, n = arr.size();
        while (i < n) {
            if (!byFirst.count(arr[i])) return false;
            auto& p = byFirst[arr[i]];
            for (int x : p) {
                if (i >= n || arr[i] != x) return false;
                i++;
            }
        }
        return true;
    }
};
