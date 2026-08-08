// Link: https://leetcode.com/problems/seat-reservation-manager/description/

#include <bits/stdc++.h>
using namespace std;

class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int next;

    SeatManager(int n) {
        next = 1;
    }

    int reserve() {
        if (!pq.empty()) {
            int seat = pq.top(); pq.pop();
            return seat;
        }
        return next++;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};
