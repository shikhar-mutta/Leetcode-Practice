// Link: https://leetcode.com/problems/number-of-orders-in-the-backlog/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn), SC: O(n)
    //  Approach: Priority Queue
    //  1. We can use two priority queues to store the buy and sell orders.
    //  2. For each order, we can check if it can be matched with the existing orders in the backlog. If it can be matched, we can update the amount of the order and remove the matched orders from the backlog. If it cannot be matched, we can add it to the backlog.
    //  3. Finally, we can return the total number of orders in the backlog.
    int getNumberOfBacklogOrders(vector<vector<int>> &orders)
    {
        priority_queue<pair<int, int>> buy_orders;  // max heap
        priority_queue<pair<int, int>> sell_orders; // min heap

        for (const vector<int> &order : orders)
        {
            int price = order[0];
            int amount = order[1];
            int type = order[2];

            if (!type)
            {
                while (amount > 0 && !sell_orders.empty())
                {
                    int lowest_sell = -sell_orders.top().first;

                    if (lowest_sell > price)
                    {
                        break;
                    }

                    auto [sell_price, sell_amt] = sell_orders.top();
                    sell_orders.pop();

                    if (amount >= sell_amt)
                    {
                        amount -= sell_amt;
                    }
                    else
                    {
                        sell_amt -= amount;
                        amount = 0;
                        sell_orders.push({sell_price, sell_amt});
                    }
                }

                if (amount > 0)
                {
                    buy_orders.push({price, amount});
                }
            }
            else
            {
                while (amount > 0 && !buy_orders.empty())
                {
                    int highest_buy = buy_orders.top().first;

                    if (highest_buy < price)
                    {
                        break;
                    }

                    auto [buy_price, buy_amt] = buy_orders.top();
                    buy_orders.pop();

                    if (amount >= buy_amt)
                    {
                        amount -= buy_amt;
                    }
                    else
                    {
                        buy_amt -= amount;
                        amount = 0;
                        buy_orders.push({buy_price, buy_amt});
                    }
                }

                if (amount > 0)
                {
                    sell_orders.push({-price, amount});
                }
            }
        }

        long long total = 0;

        while (!buy_orders.empty())
        {
            total =
                (total + buy_orders.top().second) % static_cast<int>(1e9 + 7);
            buy_orders.pop();
        }

        while (!sell_orders.empty())
        {
            total =
                (total + sell_orders.top().second) % static_cast<int>(1e9 + 7);
            sell_orders.pop();
        }

        return total;
    }
};