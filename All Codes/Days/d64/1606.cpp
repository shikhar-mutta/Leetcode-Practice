// Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> free;
        for (int i = 0; i < k; i++) free.insert(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy; // endTime, server
        vector<int> cnt(k, 0);
        int n = arrival.size();
        for (int i = 0; i < n; i++) {
            int t = arrival[i];
            while (!busy.empty() && busy.top().first <= t) {
                free.insert(busy.top().second);
                busy.pop();
            }
            if (free.empty()) continue;
            auto it = free.lower_bound(i % k);
            if (it == free.end()) it = free.begin();
            int server = *it;
            free.erase(it);
            cnt[server]++;
            busy.push({t + load[i], server});
        }
        int mx = *max_element(cnt.begin(), cnt.end());
        vector<int> res;
        for (int i = 0; i < k; i++) if (cnt[i] == mx) res.push_back(i);
        return res;
    }
};
