// Link: https://leetcode.com/problems/design-movie-rental-system/description/

#include <bits/stdc++.h>
using namespace std;

class MovieRentingSystem {
public:
    unordered_map<int, unordered_map<int,int>> shopMoviePrice;
    unordered_map<int, set<pair<int,int>>> unrented; // movie -> {price, shop}
    set<tuple<int,int,int>> rented; // {price, shop, movie}

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            shopMoviePrice[shop][movie] = price;
            unrented[movie].insert({price, shop});
        }
    }

    vector<int> search(int movie) {
        vector<int> res;
        for (auto& [price, shop] : unrented[movie]) {
            res.push_back(shop);
            if (res.size() == 5) break;
        }
        return res;
    }

    void rent(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        unrented[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }

    void drop(int shop, int movie) {
        int price = shopMoviePrice[shop][movie];
        rented.erase({price, shop, movie});
        unrented[movie].insert({price, shop});
    }

    vector<vector<int>> report() {
        vector<vector<int>> res;
        for (auto& [price, shop, movie] : rented) {
            res.push_back({shop, movie});
            if (res.size() == 5) break;
        }
        return res;
    }
};
