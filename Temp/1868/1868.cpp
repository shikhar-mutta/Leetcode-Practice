// Link: https://leetcode.com/problems/product-of-two-run-length-encoded-arrays/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> res;
        int i = 0, j = 0;
        int n1 = encoded1.size(), n2 = encoded2.size();
        while (i < n1 && j < n2) {
            int val = encoded1[i][0] * encoded2[j][0];
            int cnt = min(encoded1[i][1], encoded2[j][1]);
            if (!res.empty() && res.back()[0] == val) {
                res.back()[1] += cnt;
            } else {
                res.push_back({val, cnt});
            }
            encoded1[i][1] -= cnt;
            encoded2[j][1] -= cnt;
            if (encoded1[i][1] == 0) i++;
            if (encoded2[j][1] == 0) j++;
        }
        return res;
    }
};
