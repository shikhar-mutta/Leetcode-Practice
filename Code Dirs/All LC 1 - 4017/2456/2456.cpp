// Link: https://leetcode.com/problems/most-popular-video-creator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        int n = creators.size();
        unordered_map<string, long long> totalViews;
        unordered_map<string, int> bestIdx;
        for (int i = 0; i < n; i++) {
            totalViews[creators[i]] += views[i];
            if (!bestIdx.count(creators[i])) {
                bestIdx[creators[i]] = i;
            } else {
                int cur = bestIdx[creators[i]];
                if (views[i] > views[cur] || (views[i] == views[cur] && ids[i] < ids[cur]))
                    bestIdx[creators[i]] = i;
            }
        }

        long long maxViews = 0;
        for (auto &[c, v] : totalViews) maxViews = max(maxViews, v);

        vector<vector<string>> ans;
        for (auto &[c, v] : totalViews) {
            if (v == maxViews) {
                int idx = bestIdx[c];
                ans.push_back({creators[idx], ids[idx]});
            }
        }
        return ans;
    }
};
