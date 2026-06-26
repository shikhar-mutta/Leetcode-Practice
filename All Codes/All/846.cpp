// Link: https://leetcode.com/problems/hand-of-straights/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isNStraightHand(vector<int> &hand, int groupSize)
    {
        if (hand.size() % groupSize != 0)
            return false;

        // Ordered map so we always start a group from the smallest remaining card.
        map<int, int> cnt;
        for (int x : hand)
            cnt[x]++;

        for (auto &[card, freq] : cnt)
        {
            if (freq == 0)
                continue;
            int need = freq; // groups that must start at this card
            for (int c = card; c < card + groupSize; c++)
            {
                if (cnt[c] < need) // not enough to extend the run
                    return false;
                cnt[c] -= need;
            }
        }
        return true;
    }
};
