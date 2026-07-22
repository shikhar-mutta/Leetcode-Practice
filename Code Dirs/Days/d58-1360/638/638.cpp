// Link: https://leetcode.com/problems/shopping-offers/description/

#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>

struct VectorHash
{
    template <typename T>
    std::size_t operator()(const std::vector<T> &v) const
    {
        std::size_t seed = v.size();
        for (auto &i : v)
        {
            seed ^= std::hash<T>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

// TC: O(S * N) where S is the number of specials and N is the number of items in needs. In the worst case, we will have to check all specials for each item in needs.
// SC: O(N) where N is the number of items in needs. We are using a memoization table to store the results of previously computed states, which can take up to O(N) space in the worst case.
// Approach:
// 1. We define a helper function shoppingOffersMemoized that takes in the price, special offers, needs, and a memoization table as input.
// 2. We check if the current needs have already been computed and stored in the memoization table. If so, we return the stored value.
// 3. We calculate the cost of buying items without any special offers and store it in the variable out.
// 4. We iterate through each special offer and check if it can be applied to the current needs. If it can, we calculate the cost of applying the special offer and recursively call shoppingOffersMemoized with the updated needs. We update out if the cost of applying the special offer is less than the current value of out.
// 5. We store the computed value of out in the memoization table for the current needs and return it.
// 6. The main function shoppingOffers initializes the memoization table and calls the helper function with the input parameters.
class Solution
{
private:
    int shoppingOffersMemoized(vector<int> &price, vector<vector<int>> &special,
                               vector<int> &needs,
                               std::unordered_map<std::vector<int>, int, VectorHash> &memo)
    {
        auto it = memo.find(needs);
        if (it != memo.end())
            return it->second;

        int n = needs.size(), s = special.size();
        std::vector<int> needsNew = needs;

        // default: no specials
        int out = 0;
        for (int i = 0; i < n; ++i)
        {
            out += price[i] * needs[i];
        }
        if (!out)
            return 0;

        // check each special
        for (auto &sp : special)
        {
            int currVal = sp[n];
            bool fits = true;
            for (int i = 0; i < n; ++i)
            {
                if (needs[i] < sp[i])
                {
                    fits = false;
                    break;
                }
                needsNew[i] = needs[i] - sp[i];
            }
            if (!fits)
                continue;
            currVal += shoppingOffersMemoized(price, special, needsNew, memo);
            if (currVal < out)
                out = currVal;
        }
// Link: https://leetcode.com/problems/shopping-offers/description/

#include <bits/stdc++.h>
using namespace std;

#include <unordered_map>

struct VectorHash
{
    template <typename T>
    std::size_t operator()(const std::vector<T> &v) const
    {
        std::size_t seed = v.size();
        for (auto &i : v)
        {
            seed ^= std::hash<T>{}(i) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
        }
        return seed;
    }
};

class Solution
{
private:
    int shoppingOffersMemoized(vector<int> &price, vector<vector<int>> &special,
                               vector<int> &needs,
                               std::unordered_map<std::vector<int>, int, VectorHash> &memo)
    {
        auto it = memo.find(needs);
        if (it != memo.end())
            return it->second;

        int n = needs.size(), s = special.size();
        std::vector<int> needsNew = needs;

        // default: no specials
        int out = 0;
        for (int i = 0; i < n; ++i)
        {
            out += price[i] * needs[i];
        }
        if (!out)
            return 0;

        // check each special
        for (auto &sp : special)
        {
            int currVal = sp[n];
            bool fits = true;
            for (int i = 0; i < n; ++i)
            {
                if (needs[i] < sp[i])
                {
                    fits = false;
                    break;
                }
                needsNew[i] = needs[i] - sp[i];
            }
            if (!fits)
                continue;
            currVal += shoppingOffersMemoized(price, special, needsNew, memo);
            if (currVal < out)
                out = currVal;
        }

        memo[needs] = out;
        return out;
    }

public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        std::unordered_map<std::vector<int>, int, VectorHash> memo;
        return shoppingOffersMemoized(price, special, needs, memo);
    }
};
        memo[needs] = out;
        return out;
    }

public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
    {
        std::unordered_map<std::vector<int>, int, VectorHash> memo;
        return shoppingOffersMemoized(price, special, needs, memo);
    }
};