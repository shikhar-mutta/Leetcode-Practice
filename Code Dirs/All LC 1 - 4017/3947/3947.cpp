// Link: https://leetcode.com/problems/maximum-number-of-items-from-sale-ii/description/

#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>
#include <unordered_map>
#include <cmath>
using namespace std;

// TC: O(n log n + n * log n) ~ O(n log n)
// SC: O(n)
// Approach:
//  1. Find the minimum price among all items.
//  2. For each item, compute the number of bonus slots (d_i) it can provide based on the factors of other items.
//  3. Aggregate the bonus slots for items with the same price and store them in a map.
//  4. Use the budget to buy items in the following order:
//     a. Buy as many bonus-eligible copies of the cheapest item (price = min_price) as possible.
//     b. Buy bonus-eligible copies of other items with price in the range (min_price, 2 * min_price) if budget allows.
//     c. Spend any remaining budget on non-bonus copies of the cheapest item (price = min_price).
//  5. Return the total utility obtained from the purchased items.
class Solution
{
public:
    int maximumSaleItems(vector<vector<int>> &items, int budget)
    {
        int n = items.size();

        // Step 1: Find minimum price
        long long min_price = 1e18;
        for (auto &item : items)
        {
            if (item[1] < min_price)
                min_price = item[1];
        }

        // Step 2: Compute factor frequencies and multiples count
        vector<int> freq(n + 1, 0);
        for (auto &item : items)
        {
            int factor = item[0];
            if (factor <= n)
                freq[factor]++;
        }

        vector<int> multiples_count(n + 1, 0);
        for (int f = 1; f <= n; ++f)
        {
            if (freq[f] == 0)
                continue;
            for (int multiple = f; multiple <= n; multiple += f)
            {
                multiples_count[f] += freq[multiple];
            }
        }

        // Step 3: Compute d_i for each item and aggregate bonus quantities
        unordered_map<long long, long long> bonus_by_price; // price -> total bonus slots (d_i sum)
        long long total_bonus_min = 0;                      // sum of d_i for items with price == min_price

        for (auto &item : items)
        {
            int factor = item[0];
            long long price = item[1];
            // d_i = count of items j (j != i) with factor_i divides factor_j
            long long d_i = multiples_count[factor] - 1;
            if (d_i <= 0)
                continue;

            if (price == min_price)
            {
                total_bonus_min += d_i;
            }
            else if (price < 2 * min_price)
            {
                bonus_by_price[price] += d_i;
            }
            // Items with price >= 2*min_price are never beneficial for bonus slots
        }

        long long total_utility = 0;
        long long remaining_budget = budget;

        // Phase 1: Use budget on bonus-eligible copies of cheapest items (price = min_price)
        if (min_price <= remaining_budget && total_bonus_min > 0)
        {
            long long can_buy = min(remaining_budget / min_price, total_bonus_min);
            total_utility += 2 * can_buy; // each gives 2 utility
            remaining_budget -= can_buy * min_price;
        }

        // Phase 2: Process other beneficial bonus slots (price in (min_price, 2*min_price))
        if (!bonus_by_price.empty() && remaining_budget > 0)
        {
            // Extract and sort prices
            vector<pair<long long, long long>> price_slots;
            for (auto &kv : bonus_by_price)
            {
                price_slots.emplace_back(kv.first, kv.second);
            }
            sort(price_slots.begin(), price_slots.end());

            for (auto &[price, total_bonus] : price_slots)
            {
                if (remaining_budget < price || price >= 2 * min_price)
                    break;
                long long can_buy = min(remaining_budget / price, total_bonus);
                if (can_buy > 0)
                {
                    total_utility += 2 * can_buy;
                    remaining_budget -= can_buy * price;
                }
            }
        }

        // Phase 3: Spend remaining budget on non-bonus copies of cheapest item
        if (remaining_budget >= min_price)
        {
            long long extra_copies = remaining_budget / min_price;
            total_utility += extra_copies; // each gives 1 utility
        }

        return (int)total_utility;
    }
};