// Link: https://leetcode.com/problems/meeting-rooms-iii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(M log N), SC: O(N)
// Approach: min-heap of free room indices, min-heap of (endTime, room) for busy rooms.
// Sort meetings by start; free up rooms whose meetings ended; use a free room if available,
// else delay to the earliest-freeing room. Track usage count per room.
class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        priority_queue<int, vector<int>, greater<int>> freeRooms;
        for (int i = 0; i < n; i++) freeRooms.push(i);
        priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> busy;
        vector<int> count(n, 0);

        for (auto& m : meetings) {
            long long start = m[0], end = m[1];
            while (!busy.empty() && busy.top().first <= start) {
                freeRooms.push(busy.top().second);
                busy.pop();
            }
            if (!freeRooms.empty()) {
                int room = freeRooms.top(); freeRooms.pop();
                busy.push({end, room});
                count[room]++;
            } else {
                auto [freeAt, room] = busy.top(); busy.pop();
                long long dur = end - start;
                busy.push({freeAt + dur, room});
                count[room]++;
            }
        }

        int ans = 0;
        for (int i = 1; i < n; i++) if (count[i] > count[ans]) ans = i;
        return ans;
    }
};
