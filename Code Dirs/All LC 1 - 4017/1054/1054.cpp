// Link: https://leetcode.com/problems/distant-barcodes/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        unordered_map<int,int> cnt;
        for (int b : barcodes) cnt[b]++;
        vector<pair<int,int>> items(cnt.begin(), cnt.end());
        sort(items.begin(), items.end(), [](auto& a, auto& b) { return a.second > b.second; });

        int n = barcodes.size();
        vector<int> res(n);
        int idx = 0;
        for (auto& [val, freq] : items) {
            for (int i = 0; i < freq; i++) {
                if (idx >= n) idx = 1;
                res[idx] = val;
                idx += 2;
            }
        }
        return res;
    }
};
