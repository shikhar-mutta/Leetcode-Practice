// Link: https://leetcode.com/problems/exam-room/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) for both seat() and leave() operations, where n is the number of students in the room.
// SC: O(n) for both seat() and leave() operations, where n is the number of students in the room.
// Approach:
// 1. We use a set to keep track of the occupied seats in the room.
// 2. We use another set to keep track of the available seats in the room, where each available seat is represented as a pair of integers (distance, seat number).
// 3. When a student enters the room, we find the seat with the maximum distance from the nearest occupied seat by looking at the first element of the available seats set. We then update the occupied seats set and the available seats set accordingly.
// 4. When a student leaves the room, we update the occupied seats set and the available seats set accordingly by removing the seat from the occupied seats set and adding the new available seats to the available seats set.
// 5. The seat() and leave() operations both take O(log n) time due to the use of sets, and the space complexity is O(n) for both operations as we store the occupied and available seats in sets.
class ExamRoom
{
    set<int> s;
    set<pair<int, int>> s2;
    int n;

public:
    ExamRoom(int n) : n(n), s{}, s2{} { upd(-1, -1, 1); }

    void upd2(int x, int y, int k)
    {
        if (k == 1)
            s2.emplace(-x, y);
        else
            s2.erase({-x, y});
    }

    void upd(int l, int r, int k)
    {
        if (l == -1 && r == -1)
        {
            upd2(0, 0, k);
        }
        else if (l == -1)
        {
            if (r == 0)
                return;
            upd2(r, 0, k);
        }
        else if (r == -1)
        {
            if (l == n - 1)
                return;
            upd2(n - 1 - l, n - 1, k);
        }
        else
        {
            if (l + 1 == r)
                return;
            upd2((r - l) / 2, l + (r - l) / 2, k);
        }
    }

    int seat()
    {
        auto p = *s2.begin();
        s.insert(p.second);
        auto it = s.lower_bound(p.second);
        int l = (it == s.begin() ? -1 : *prev(it));
        int r = (next(it) == s.end() ? -1 : *next(it));
        upd(l, r, -1);
        upd(l, p.second, 1);
        upd(p.second, r, 1);
        return p.second;
    }

    void leave(int p)
    {
        auto it = s.lower_bound(p);
        int l = (it == s.begin() ? -1 : *prev(it));
        int r = (next(it) == s.end() ? -1 : *next(it));
        upd(l, *it, -1);
        upd(*it, r, -1);
        upd(l, r, 1);
        s.erase(it);
    }
};
