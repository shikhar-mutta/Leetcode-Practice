// Link: https://leetcode.com/problems/count-zero-request-servers/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](auto &a, auto &b) { return a[1] < b[1]; });

        int q = queries.size();
        vector<int> qIdx(q);
        iota(qIdx.begin(), qIdx.end(), 0);
        sort(qIdx.begin(), qIdx.end(), [&](int a, int b) { return queries[a] < queries[b]; });

        vector<int> ans(q);
        unordered_map<int,int> freq;
        int activeCount = 0;
        int left = 0, right = 0;

        for (int qi : qIdx) {
            int hi = queries[qi], lo = hi - x;
            while (right < (int)logs.size() && logs[right][1] <= hi) {
                int server = logs[right][0];
                if (freq[server]++ == 0) activeCount++;
                right++;
            }
            while (left < right && logs[left][1] < lo) {
                int server = logs[left][0];
                if (--freq[server] == 0) activeCount--;
                left++;
            }
            ans[qi] = n - activeCount;
        }
        return ans;
    }
};
