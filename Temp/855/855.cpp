// Link: https://leetcode.com/problems/exam-room/description/

#include <bits/stdc++.h>
using namespace std;

class ExamRoom {
    set<int> seats;
    int N;
public:
    ExamRoom(int n) : N(n) {}

    int seat() {
        if (seats.empty()) { seats.insert(0); return 0; }
        int best = 0, bestDist = -1;
        int prev = -1;
        for (int s : seats) {
            if (prev == -1) {
                if (s > bestDist) { bestDist = s; best = 0; }
            } else {
                int d = (s - prev) / 2;
                if (d > bestDist) { bestDist = d; best = prev + d; }
            }
            prev = s;
        }
        int lastDist = N - 1 - prev;
        if (lastDist > bestDist) best = N - 1;
        seats.insert(best);
        return best;
    }

    void leave(int p) {
        seats.erase(p);
    }
};
