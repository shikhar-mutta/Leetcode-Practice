// Link: https://leetcode.com/problems/asteroid-collision/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        vector<int> st;

        for (int n : asteroids)
        {
            bool destroyed = false;

            while (!st.empty() && st.back() > 0 && n < 0)
            {
                if (abs(st.back()) < abs(n))
                {
                    st.pop_back(); // stack asteroid destroyed
                }
                else if (abs(st.back()) == abs(n))
                {
                    st.pop_back(); // both destroyed
                    destroyed = true;
                    break;
                }
                else
                {
                    destroyed = true; // incoming asteroid destroyed
                    break;
                }
            }

            if (!destroyed)
            {
                st.push_back(n);
            }
        }

        return st;
    }
};
