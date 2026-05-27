// Link: https://leetcode.com/problems/distribute-candies/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int distributeCandies(vector<int> &candyType)
    {
        int limit = candyType.size() / 2, cnt = 0;
        unordered_set<int> st;
        st.reserve(limit);
        for (int c : candyType)
        {
            // Insert second value is true if the element was not present in the set before, so we can count unique elements until we reach the limit.
            if (st.insert(c).second && ++cnt == limit)
                return limit;
        }
        return (int)st.size();
    }
};