// Link: https://leetcode.com/problems/maximize-distance-to-closest-person/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the number of seats in the room.
    // SC: O(1), as we are using constant space.
    //  Approach:
    //  1. We iterate through the seats array and keep track of the previous occupied seat and the best distance to the closest person.
    //  2. If we encounter an occupied seat, we calculate the distance to the previous occupied seat and update the best distance accordingly.
    //  3. If we reach the end of the array, we calculate the distance to the last occupied seat and update the best distance accordingly.
    //  4. Finally, we return the best distance to the closest person.
    int maxDistToClosest(vector<int> &seats)
    {
        int n = seats.size();
        int prev = -1, best = 0;
        for (int i = 0; i < n; i++)
        {
            if (seats[i] == 0)
                continue;
            int dist = (prev == -1) ? i : (i - prev) / 2;
            best = max(best, dist);
            prev = i;
        }
        best = max(best, n - 1 - prev);
        return best;
    }
};
