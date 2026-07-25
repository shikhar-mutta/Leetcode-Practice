// Link: https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(nlogn) where n is the number of friends
// SC: O(n) where n is the number of friends
// Approach: Greedy + Priority Queue
//  1. Create a vector of tuples to store the start time, end time and index of each friend.
//  2. Sort the vector of tuples based on the start time.
//  3. Create a priority queue to store the occupied chairs and a priority queue to store the free chairs.
//  4. Iterate through the sorted vector of tuples and for each friend, check if there are any free chairs. If there are, assign the friend to the smallest free chair.
//  If there are no free chairs, assign the friend to the next available chair.
class Solution
{
public:
    int smallestChair(vector<vector<int>> &times, int targetFriend)
    {
        int n = times.size();
        vector<tuple<int, int, int>> friends;

        for (int i = 0; i < n; i++)
            friends.emplace_back(times[i][0], times[i][1], i);

        sort(friends.begin(), friends.end());

        priority_queue<int, vector<int>, greater<>> free;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>
            occupied;

        int chairs = 0;
        for (auto &[start, end, i] : friends)
        {
            while (!occupied.empty() && occupied.top().first <= start)
            {
                free.push(occupied.top().second);
                occupied.pop();
            }

            int c;
            if (free.empty())
            {
                c = chairs;
                occupied.emplace(end, chairs++);
            }
            else
            {
                c = free.top();
                occupied.emplace(end, free.top());
                free.pop();
            }

            if (i == targetFriend)
                return c;
        }

        return -1;
    }
};
