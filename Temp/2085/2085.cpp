// Link: https://leetcode.com/problems/count-common-words-with-one-occurrence/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string,int> c1, c2;
        for (auto& w : words1) c1[w]++;
        for (auto& w : words2) c2[w]++;
        int count = 0;
        for (auto& [w, c] : c1) {
            if (c == 1 && c2.count(w) && c2[w] == 1) count++;
        }
        return count;
    }
};
