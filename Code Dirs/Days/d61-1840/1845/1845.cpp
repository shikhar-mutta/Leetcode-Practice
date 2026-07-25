// Link: https://leetcode.com/problems/seat-reservation-manager/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n), SC: O(n)
//   Approach:
//   1. We can use a priority queue to keep track of the available seats.
//   2. When a seat is reserved, we can pop the top element from the priority queue and return it.
class SeatManager
{
    priority_queue<int, vector<int>, greater<int>> pq;
    int cnt;

public:
    SeatManager(int n) { cnt = 1; }
    int reserve()
    {
        if (pq.empty() || pq.top() > cnt)
            return cnt++;
        int seat = pq.top();
        pq.pop();
        return seat;
    }
    void unreserve(int seatNumber)
    {
        if (seatNumber == cnt - 1)
            cnt--;
        else
            pq.push(seatNumber);
    }
};
