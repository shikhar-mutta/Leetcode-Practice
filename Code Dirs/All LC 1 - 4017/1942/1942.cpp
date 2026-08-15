// Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return times[a][0] < times[b][0];
        });

        priority_queue<int, vector<int>, greater<int>> freeChairs;
        for (int i = 0; i < n; i++) freeChairs.push(i);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> occupied; // {leaveTime, chair}

        for (int i : idx) {
            int arrive = times[i][0], leave = times[i][1];
            while (!occupied.empty() && occupied.top().first <= arrive) {
                freeChairs.push(occupied.top().second);
                occupied.pop();
            }
            int chair = freeChairs.top(); freeChairs.pop();
            if (i == targetFriend) return chair;
            occupied.push({leave, chair});
        }
        return -1;
    }
};
