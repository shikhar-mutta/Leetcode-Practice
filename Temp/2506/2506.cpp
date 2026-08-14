// Link: https://leetcode.com/problems/count-pairs-of-similar-strings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int similarPairs(vector<string>& words) {
        unordered_map<int,int> freq;
        int count = 0;
        for (auto &w : words) {
            int mask = 0;
            for (char c : w) mask |= (1 << (c - 'a'));
            count += freq[mask];
            freq[mask]++;
        }
        return count;
    }
};
