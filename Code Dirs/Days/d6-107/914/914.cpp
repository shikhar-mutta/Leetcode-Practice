// Link: https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool hasGroupsSizeX(vector<int> &deck)
    {
        unordered_map<int, int> count;
        // Count the frequency of each card in the deck
        for (auto it : deck)
            count[it]++;

        int g = 0;
        //  Find the GCD of all counts
        for (auto it : count)
            g = __gcd(g, it.second);

        // If the GCD is greater than or equal to 2, we can divide the deck into groups of that size
        return g >= 2;
    }
};
