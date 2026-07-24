// Link: https://leetcode.com/problems/furthest-building-you-can-reach/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogk) where n is the length of the input array and k is the number of ladders.
    // SC: O(k) for storing the priority queue.
    // Approach:
    //        1. Use a priority queue to store the heights of the buildings that we need to climb.
    //        2. Iterate through the heights array and for each building, calculate the difference between the current building and the next building.
    //        3. If the difference is greater than 0, we need to climb the building. If we have ladders left, we use a ladder to climb the building and push the difference into the priority queue. If we don't have ladders left, we check if the priority queue is empty or if the top of the priority queue is greater than or equal to the difference. If it is, we use bricks to climb the building. If it isn't, we pop the top of the priority queue and use bricks to climb the building. If we don't have enough bricks to climb the building, we return the index of the current building. If we reach the end of the heights array, we return the index of the last building.
    //        4. Return the result.
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < n - 1; ++i)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
            {
                if (pq.size() < ladders)
                {
                    pq.push(diff);
                }
                else
                {
                    if (pq.empty() || pq.top() >= diff)
                    {
                        bricks -= diff;
                    }
                    else
                    {
                        int poll = pq.top();
                        pq.pop();
                        pq.push(diff);
                        bricks -= poll;
                    }
                    if (bricks < 0)
                        return i;
                }
            }
        }
        return n - 1;
    }
};