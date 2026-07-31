// Link: https://leetcode.com/problems/design-movie-rental-system/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(log(n*m)) per operation using ordered sets  SC: O(n*m)
//  Approach: maintain a set of (price,shop) per movie for unrented copies, a
//  global set of (price,shop,movie) for rented copies, and a price map keyed by (shop,movie) for quick lookup during rent/drop.
class MovieRentingSystem
{
private:
    // (movie, shop) -> price
    unordered_map<int, unordered_map<int, int>> price;

    // movie -> available shops sorted by (price, shop)
    unordered_map<int, set<pair<int, int>>> available;

    // rented sorted by (price, shop, movie)
    set<tuple<int, int, int>> rented;

public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        for (auto &entry : entries)
        {
            int shop = entry[0];
            int movie = entry[1];
            int p = entry[2];

            price[movie][shop] = p;
            available[movie].insert({p, shop});
        }
    }

    vector<int> search(int movie)
    {
        vector<int> result;

        if (!available.count(movie))
        {
            return result;
        }

        for (auto [p, shop] : available[movie])
        {
            if (result.size() == 5)
                break;
            result.push_back(shop);
        }

        return result;
    }

    void rent(int shop, int movie)
    {
        int p = price[movie][shop];

        available[movie].erase({p, shop});
        rented.insert({p, shop, movie});
    }

    void drop(int shop, int movie)
    {
        int p = price[movie][shop];

        rented.erase({p, shop, movie});
        available[movie].insert({p, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> result;

        for (auto [p, shop, movie] : rented)
        {
            if (result.size() == 5)
                break;
            result.push_back({shop, movie});
        }

        return result;
    }
};