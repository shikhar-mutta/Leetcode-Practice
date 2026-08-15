// Link: https://leetcode.com/problems/design-auction-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per op SC: O(n)
//  Approach: per item, keep a userId->amount map plus a sorted set of
//  (amount, userId) pairs. Adding/updating removes the old pair (if any)
//  and inserts the new one; the ordered set's max naturally breaks ties
//  by highest userId since pairs compare amount first, then userId.
class AuctionSystem
{
public:
    unordered_map<int, unordered_map<int, int>> bids;
    unordered_map<int, priority_queue<pair<int, int>>> queue;

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount)
    {
        bids[itemId][userId] = bidAmount;
        queue[itemId].push({bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount)
    {
        addBid(userId, itemId, newAmount);
    }

    void removeBid(int userId, int itemId) { bids[itemId].erase(userId); }

    int getHighestBidder(int itemId)
    {
        auto &b = bids[itemId];
        auto &q = queue[itemId];

        while (!q.empty())
        {
            int amt = q.top().first;
            int uid = q.top().second;
            auto it = b.find(uid);
            int cur = (it == b.end() ? -1 : it->second);
            if (cur == amt)
                return uid;
            q.pop();
        }

        return -1;
    }
};