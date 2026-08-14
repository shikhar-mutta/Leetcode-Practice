// Link: https://leetcode.com/problems/intervals-between-identical-elements/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<long long> getDistances(vector<int>& arr) {
        int n = arr.size();
        unordered_map<int, vector<int>> groups;
        for (int i = 0; i < n; i++) groups[arr[i]].push_back(i);

        vector<long long> res(n, 0);
        for (auto& [val, idx] : groups) {
            int k = idx.size();
            vector<long long> prefix(k + 1, 0);
            for (int i = 0; i < k; i++) prefix[i + 1] = prefix[i] + idx[i];
            long long total = prefix[k];
            for (int p = 0; p < k; p++) {
                long long leftSum = prefix[p];
                long long rightSum = total - prefix[p + 1];
                long long leftContrib = (long long)p * idx[p] - leftSum;
                long long rightContrib = rightSum - (long long)(k - p - 1) * idx[p];
                res[idx[p]] = leftContrib + rightContrib;
            }
        }
        return res;
    }
};
