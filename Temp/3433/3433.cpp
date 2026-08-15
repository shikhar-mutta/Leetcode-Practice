// Link: https://leetcode.com/problems/count-mentions-per-user/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        int n = events.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            long long ta = stoll(events[a][1]), tb = stoll(events[b][1]);
            if (ta != tb) return ta < tb;
            // OFFLINE before MESSAGE at same timestamp
            bool offA = events[a][0] == "OFFLINE";
            bool offB = events[b][0] == "OFFLINE";
            return offA > offB;
        });

        vector<long long> offlineUntil(numberOfUsers, -1);
        vector<int> mentions(numberOfUsers, 0);

        for (int id : idx) {
            long long t = stoll(events[id][1]);
            if (events[id][0] == "OFFLINE") {
                int uid = stoi(events[id][2]);
                offlineUntil[uid] = t + 60;
            } else {
                string& s = events[id][2];
                if (s == "ALL") {
                    for (int i = 0; i < numberOfUsers; i++) mentions[i]++;
                } else if (s == "HERE") {
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (offlineUntil[i] <= t) mentions[i]++;
                    }
                } else {
                    stringstream ss(s);
                    string tok;
                    while (ss >> tok) {
                        int uid = stoi(tok.substr(2)); // strip "id"
                        mentions[uid]++;
                    }
                }
            }
        }

        return mentions;
    }
};
