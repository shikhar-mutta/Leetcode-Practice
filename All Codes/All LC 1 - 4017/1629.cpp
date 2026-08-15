// Link: https://leetcode.com/problems/slowest-key/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char slowestKey(vector<int> &releaseTimes, string keysPressed)
    {
        // Initialize max duration with the first key's duration and a set to track keys with max duration
        int mx = releaseTimes[0], n = releaseTimes.size(), prev = releaseTimes[0];

        set<char> st({keysPressed[0]});
        for (int i = 1; i < n; i++)
        {

            int dur = releaseTimes[i] - prev;
            if (mx < dur) // new max duration
            {
                mx = dur;
                st.clear(); // clear previous keys
                st.emplace(keysPressed[i]);
            }
            else if (mx == dur) // tie
            {
                st.emplace(keysPressed[i]); // add to set of keys with max duration
            }
            prev = releaseTimes[i];
        }
        return *st.rbegin(); // return the largest char in case of tie
    }
};
