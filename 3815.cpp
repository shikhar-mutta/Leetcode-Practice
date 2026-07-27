// Link: https://leetcode.com/problems/design-auction-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log n) per op SC: O(n)
// Approach: per item, keep a userId->amount map plus a sorted set of
// (amount, userId) pairs. Adding/updating removes the old pair (if any)
// and inserts the new one; the ordered set's max naturally breaks ties
// by highest userId since pairs compare amount first, then userId.
class AuctionSystem {
    unordered_map<int, unordered_map<int, long long>> userBid;
    unordered_map<int, set<pair<long long, int>>> byAmount;

    void setBid(int userId, int itemId, long long amount) {
        auto& m = userBid[itemId];
        auto it = m.find(userId);
        if (it != m.end()) {
            byAmount[itemId].erase({it->second, userId});
            it->second = amount;
        } else {
            m[userId] = amount;
        }
        byAmount[itemId].insert({amount, userId});
    }
public:
    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        setBid(userId, itemId, bidAmount);
    }

    void updateBid(int userId, int itemId, int newAmount) {
        setBid(userId, itemId, newAmount);
    }

    void removeBid(int userId, int itemId) {
        auto& m = userBid[itemId];
        auto it = m.find(userId);
        byAmount[itemId].erase({it->second, userId});
        m.erase(it);
    }

    int getHighestBidder(int itemId) {
        auto it = byAmount.find(itemId);
        if (it == byAmount.end() || it->second.empty()) return -1;
        return it->second.rbegin()->second;
    }
};
