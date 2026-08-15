// Link: https://leetcode.com/problems/asteroid-collision/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: stack simulation; a right-moving asteroid pushes; a left-moving asteroid collides with the stack top(s) while they're right-moving and smaller, destroying the smaller one(s) until stable or equal-mass mutual destruction.
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> stk;
        for (int a : asteroids) {
            bool alive = true;
            while (alive && a < 0 && !stk.empty() && stk.back() > 0) {
                if (stk.back() < -a) { stk.pop_back(); continue; }
                else if (stk.back() == -a) { stk.pop_back(); alive = false; }
                else alive = false;
            }
            if (alive) stk.push_back(a);
        }
        return stk;
    }
};
