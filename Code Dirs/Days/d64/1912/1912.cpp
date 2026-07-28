// Link: https://leetcode.com/problems/design-movie-rental-system/description/

#include <bits/stdc++.h>
using namespace std;

// Added
// TC: O(log(n*m)) per operation using ordered sets  SC: O(n*m)
// Approach: maintain a set of (price,shop) per movie for unrented copies, a
// global set of (price,shop,movie) for rented copies, and a price map keyed
// by (shop,movie) for quick lookup during rent/drop.
class MovieRentingSystem {
    map<pair<int,int>, int> priceOf; // (shop,movie) -> price
    unordered_map<int, set<pair<int,int>>> unrented; // movie -> {(price,shop)}
    set<tuple<int,int,int>> rented; // (price,shop,movie)
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceOf[{shop, movie}] = price;
            unrented[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        if (!unrented.count(movie)) return res;
        int cnt = 0;
        for (auto& [price, shop] : unrented[movie]) {
            res.push_back(shop);
            if (++cnt == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = priceOf[{shop, movie}];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = priceOf[{shop, movie}];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto& [price, shop, movie] : rented) {
            res.push_back({shop, movie});
            if (++cnt == 5) break;
        }
        return res;
    }
};
