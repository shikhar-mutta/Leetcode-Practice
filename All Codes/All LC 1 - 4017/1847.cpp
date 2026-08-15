// Link: https://leetcode.com/problems/closest-room/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O((n + q) log n)  SC: O(n)
//  Approach: sort rooms and queries by size descending; process queries in that
//  order, adding rooms with sufficient size into an ordered set of ids as we go,
//  then binary-search the set for the closest id to preferred using neighbors.
class Solution
{
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {
        const int n = rooms.size(), k = queries.size();
        vector<tuple<int, int, int>> qt;
        qt.reserve(k);
        for (int i = 0; i < k; i++)
            qt.emplace_back(queries[i][0], queries[i][1], i);
        sort(rooms.begin(), rooms.end());
        sort(qt.begin(), qt.end());

        vector<int> answer(k, -1), s;
        for (int q = 0, r = 0, si = -1; q < k; q++)
        {
            const auto &[preferred, minSize, i] = qt[q];
            while (r < n && rooms[r][0] <= preferred)
            {
                while (si >= 0 && rooms[s[si]][1] < rooms[r][1])
                    si--;
                if (++si == s.size())
                    s.push_back(r);
                else
                    s[si] = r;
                r++;
            }
            if (si == -1 || rooms[s[0]][1] < minSize)
                continue;

            int a = 0, b = si;
            while (a < b)
            {
                const int c = (a + b + 1) >> 1;
                if (rooms[s[c]][1] >= minSize)
                    a = c;
                else
                    b = c - 1;
            }
            answer[i] = rooms[s[a]][0];
        }

        s.clear();
        for (int q = k - 1, r = n - 1, si = -1; q >= 0; q--)
        {
            const auto &[preferred, minSize, i] = qt[q];
            while (r >= 0 && rooms[r][0] >= preferred)
            {
                while (si >= 0 && rooms[s[si]][1] < rooms[r][1])
                    si--;
                if (++si == s.size())
                    s.push_back(r);
                else
                    s[si] = r;
                r--;
            }
            if (si == -1 || rooms[s[0]][1] < minSize)
                continue;

            int a = 0, b = si;
            while (a < b)
            {
                const int c = (a + b + 1) >> 1;
                if (rooms[s[c]][1] >= minSize)
                    a = c;
                else
                    b = c - 1;
            }
            if (answer[i] == -1 || rooms[s[a]][0] - preferred < preferred - answer[i])
                answer[i] = rooms[s[a]][0];
        }
        return answer;
    }
};