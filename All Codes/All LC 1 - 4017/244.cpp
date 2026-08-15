// Link: https://leetcode.com/problems/shortest-word-distance-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) init, O(a+b) per query  SC: O(n)
// Approach: precompute a list of indices per word; two-pointer merge over the two sorted index
// lists to find the minimum absolute difference
class WordDistance {
public:
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < (int)wordsDict.size(); i++) pos[wordsDict[i]].push_back(i);
    }

    int shortest(string word1, string word2) {
        auto& a = pos[word1];
        auto& b = pos[word2];
        int i = 0, j = 0, best = INT_MAX;
        while (i < (int)a.size() && j < (int)b.size()) {
            best = min(best, abs(a[i] - b[j]));
            if (a[i] < b[j]) i++;
            else j++;
        }
        return best;
    }

private:
    unordered_map<string, vector<int>> pos;
};
