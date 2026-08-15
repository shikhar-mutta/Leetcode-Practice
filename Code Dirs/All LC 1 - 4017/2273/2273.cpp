// Link: https://leetcode.com/problems/find-resultant-array-after-removing-anagrams/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> res;
        string prevSorted;
        for (auto& w : words) {
            string sorted = w;
            sort(sorted.begin(), sorted.end());
            if (res.empty() || sorted != prevSorted) {
                res.push_back(w);
                prevSorted = sorted;
            }
        }
        return res;
    }
};
