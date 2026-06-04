// Link: https://leetcode.com/problems/best-poker-hand/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Approach: Hashing. TC: O(n), SC: O(n).
    string bestHand(vector<int> &ranks, vector<char> &suits)
    {
        unordered_map<int, pair<int, vector<char>>> freq;
        bool isSameSuit = true;
        char su = suits[0];
        // Push cards
        for (int i = 0; i < 5; i++)
        {
            freq[ranks[i]].first++;
            freq[ranks[i]].second.push_back(suits[i]);
            if (isSameSuit && su != suits[i])
                isSameSuit = false;
        }
        // Flush
        if (isSameSuit)
            return "Flush";
        // Three of a Kind
        for (auto it : freq)
        {
            if (it.second.first >= 3)
                return "Three of a Kind";
        }
        // Pair
        for (auto it : freq)
            if (it.second.first >= 2)
                return "Pair";
        return "High Card";
    };
};