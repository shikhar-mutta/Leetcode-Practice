// Link: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int,int> cnt;
        for (int x : deck) cnt[x]++;
        int g = 0;
        for (auto& [k, v] : cnt) g = __gcd(g, v);
        return g >= 2;
    }
};
