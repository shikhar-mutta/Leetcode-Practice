// Link: https://leetcode.com/problems/number-of-orders-in-the-backlog/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<pair<int,long long>> buy; // max-heap by price
        priority_queue<pair<int,long long>, vector<pair<int,long long>>, greater<>> sell; // min-heap by price

        for (auto& o : orders) {
            long long price = o[0], amount = o[1], type = o[2];
            if (type == 0) {
                while (amount > 0 && !sell.empty() && sell.top().first <= price) {
                    auto [sp, sa] = sell.top(); sell.pop();
                    long long matched = min(amount, sa);
                    amount -= matched;
                    sa -= matched;
                    if (sa > 0) sell.push({sp, sa});
                }
                if (amount > 0) buy.push({(int)price, amount});
            } else {
                while (amount > 0 && !buy.empty() && buy.top().first >= price) {
                    auto [bp, ba] = buy.top(); buy.pop();
                    long long matched = min(amount, ba);
                    amount -= matched;
                    ba -= matched;
                    if (ba > 0) buy.push({bp, ba});
                }
                if (amount > 0) sell.push({(int)price, amount});
            }
        }

        const long long MOD = 1e9 + 7;
        long long total = 0;
        while (!buy.empty()) { total += buy.top().second; buy.pop(); }
        while (!sell.empty()) { total += sell.top().second; sell.pop(); }
        return (int)(total % MOD);
    }
};
