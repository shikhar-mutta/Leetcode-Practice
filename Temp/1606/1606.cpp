// Link: https://leetcode.com/problems/find-servers-that-handled-most-number-of-requests/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {
        set<int> available;
        for (int i = 0; i < k; i++) available.insert(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> busy; // endTime, server

        vector<int> count(k, 0);
        for (int i = 0; i < (int)arrival.size(); i++) {
            int start = arrival[i], end = start + load[i];
            while (!busy.empty() && busy.top().first <= start) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) continue;

            auto it = available.lower_bound(i % k);
            if (it == available.end()) it = available.begin();
            int server = *it;
            available.erase(it);
            busy.push({end, server});
            count[server]++;
        }

        int mx = *max_element(count.begin(), count.end());
        vector<int> res;
        for (int i = 0; i < k; i++) if (count[i] == mx) res.push_back(i);
        return res;
    }
};
