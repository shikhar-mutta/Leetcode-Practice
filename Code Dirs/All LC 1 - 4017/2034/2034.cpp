// Link: https://leetcode.com/problems/stock-price-fluctuation/description/

#include <bits/stdc++.h>
using namespace std;

class StockPrice {
    unordered_map<int,int> priceAt;
    map<int,int> freq; // price -> count of timestamps with that price
    int latestTime = 0;
public:
    StockPrice() {}

    void update(int timestamp, int price) {
        if (priceAt.count(timestamp)) {
            int old = priceAt[timestamp];
            freq[old]--;
            if (freq[old] == 0) freq.erase(old);
        }
        priceAt[timestamp] = price;
        freq[price]++;
        latestTime = max(latestTime, timestamp);
    }

    int current() {
        return priceAt[latestTime];
    }

    int maximum() {
        return freq.rbegin()->first;
    }

    int minimum() {
        return freq.begin()->first;
    }
};
