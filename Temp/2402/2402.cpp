// Link: https://leetcode.com/problems/meeting-rooms-iii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        vector<long long> count(n, 0);
        priority_queue<int, vector<int>, greater<int>> avail;
        for (int i = 0; i < n; i++) avail.push(i);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> busy;

        for (auto &m : meetings) {
            long long start = m[0], end = m[1];
            while (!busy.empty() && busy.top().first <= start) {
                avail.push(busy.top().second);
                busy.pop();
            }
            if (!avail.empty()) {
                int room = avail.top(); avail.pop();
                count[room]++;
                busy.push({end, room});
            } else {
                auto [freeTime, room] = busy.top(); busy.pop();
                count[room]++;
                busy.push({freeTime + (end - start), room});
            }
        }

        int best = 0;
        for (int i = 1; i < n; i++) if (count[i] > count[best]) best = i;
        return best;
    }
};
