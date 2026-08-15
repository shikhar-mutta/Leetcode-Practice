// Link: https://leetcode.com/problems/destroying-asteroids/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for (int a : asteroids) {
            if (m < a) return false;
            m += a;
        }
        return true;
    }
};
