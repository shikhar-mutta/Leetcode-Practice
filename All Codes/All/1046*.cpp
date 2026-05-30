// Link: https://leetcode.com/problems/last-stone-weight/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end()); // Max-heap for the stones

        while (pq.size() > 1)
        {
            int stone1 = pq.top();
            pq.pop(); // Heaviest stone
            int stone2 = pq.top();
            pq.pop(); // Second heaviest stone

            if (stone1 != stone2)
            {
                pq.push(stone1 - stone2); // Push the difference back if they are not equal
            }
            // If they are equal, both stones are destroyed, so we do nothing
        }

        return pq.empty() ? 0 : pq.top(); // Return the weight of the last remaining stone or 0 if none left
    }
};
