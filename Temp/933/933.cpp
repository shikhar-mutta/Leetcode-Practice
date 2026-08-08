// Link: https://leetcode.com/problems/number-of-recent-calls/description/

#include <bits/stdc++.h>
using namespace std;

class RecentCounter {
    deque<int> q;
public:
    RecentCounter() {}

    int ping(int t) {
        q.push_back(t);
        while (q.front() < t - 3000) q.pop_front();
        return q.size();
    }
};
