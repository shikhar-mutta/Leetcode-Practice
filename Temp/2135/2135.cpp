// Link: https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> starts;
        for (auto& w : startWords) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            starts.insert(mask);
        }
        int count = 0;
        for (auto& w : targetWords) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            for (char c : w) {
                int without = mask & ~(1 << (c - 'a'));
                if (starts.count(without)) { count++; break; }
            }
        }
        return count;
    }
};
