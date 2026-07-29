// Link: https://leetcode.com/problems/threshold-majority-queries/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> subarrayMajority(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();

        vector<int> sortedVals(nums.begin(), nums.end());
        sort(sortedVals.begin(), sortedVals.end());
        sortedVals.erase(unique(sortedVals.begin(), sortedVals.end()), sortedVals.end());
        int distinctCnt = sortedVals.size();
        vector<int> id(n);
        for (int i = 0; i < n; i++) id[i] = lower_bound(sortedVals.begin(), sortedVals.end(), nums[i]) - sortedVals.begin();

        vector<int> cnt(distinctCnt, 0);
        vector<set<int>> freqToValues(n + 2);
        int maxFreq = 0;

        auto add = [&](int idx) {
            int v = id[idx];
            int old = cnt[v];
            if (old > 0) freqToValues[old].erase(sortedVals[v]);
            cnt[v]++;
            freqToValues[cnt[v]].insert(sortedVals[v]);
            if (cnt[v] > maxFreq) maxFreq = cnt[v];
        };
        auto remove = [&](int idx) {
            int v = id[idx];
            int old = cnt[v];
            freqToValues[old].erase(sortedVals[v]);
            cnt[v]--;
            if (cnt[v] > 0) freqToValues[cnt[v]].insert(sortedVals[v]);
            if (old == maxFreq && freqToValues[maxFreq].empty()) {
                while (maxFreq > 0 && freqToValues[maxFreq].empty()) maxFreq--;
            }
        };

        int block = max(1, (int)sqrt((double)n));
        vector<int> qOrder(q);
        iota(qOrder.begin(), qOrder.end(), 0);
        sort(qOrder.begin(), qOrder.end(), [&](int a, int b) {
            int la = queries[a][0], lb = queries[b][0];
            int ba = la / block, bb = lb / block;
            if (ba != bb) return ba < bb;
            if (ba % 2 == 0) return queries[a][1] < queries[b][1];
            return queries[a][1] > queries[b][1];
        });

        vector<int> ans(q);
        int curL = 0, curR = -1;
        for (int qi : qOrder) {
            int l = queries[qi][0], r = queries[qi][1], th = queries[qi][2];
            while (curR < r) { curR++; add(curR); }
            while (curL > l) { curL--; add(curL); }
            while (curR > r) { remove(curR); curR--; }
            while (curL < l) { remove(curL); curL++; }

            if (maxFreq >= th) ans[qi] = *freqToValues[maxFreq].begin();
            else ans[qi] = -1;
        }

        return ans;
    }
};
