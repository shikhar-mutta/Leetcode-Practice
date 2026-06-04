// Link: https://leetcode.com/problems/take-gifts-from-the-richest-pile/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int> &gifts, int k)
    {
        // Create a max heap (priority queue) to store the gifts
        priority_queue<int> pq(gifts.begin(), gifts.end());

        for (int i = 0; i < k; i++)
        {
            int top = pq.top();
            pq.pop();
            pq.push(sqrt(top)); // Replace with sqrt of top element
        }

        long long ans = 0;
        while (!pq.empty())
        {
            ans += pq.top(); // Add the remaining gifts to ans
            pq.pop();
        }

        return ans;
    }
};
