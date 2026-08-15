// Link: https://leetcode.com/problems/xor-queries-of-a-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++) prefix[i+1] = prefix[i] ^ arr[i];
        vector<int> res;
        for (auto& q : queries) {
            res.push_back(prefix[q[0]] ^ prefix[q[1] + 1]);
        }
        return res;
    }
};
