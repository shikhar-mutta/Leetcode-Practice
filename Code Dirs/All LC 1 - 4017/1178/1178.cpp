// Link: https://leetcode.com/problems/number-of-valid-words-for-each-puzzle/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findNumOfValidWords(vector<string>& words, vector<string>& puzzles) {
        unordered_map<int,int> cnt;
        for (auto& w : words) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            cnt[mask]++;
        }

        vector<int> res;
        for (auto& p : puzzles) {
            int first = 1 << (p[0] - 'a');
            int full = 0;
            for (char c : p) full |= (1 << (c - 'a'));
            int total = 0;
            int sub = full;
            while (true) {
                if (sub & first) {
                    if (cnt.count(sub)) total += cnt[sub];
                }
                if (sub == 0) break;
                sub = (sub - 1) & full;
            }
            res.push_back(total);
        }
        return res;
    }
};
