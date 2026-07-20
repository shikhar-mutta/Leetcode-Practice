// Link: https://leetcode.com/problems/destroying-asteroids/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the number of asteroids
    // SC: O(1)
    // Approach:
    // 1. We will iterate through the asteroids array and check if the current asteroid can be destroyed by the current mass.
    // 2. If it can be destroyed, we will increase the mass by the value of the asteroid and mark the asteroid as destroyed by multiplying it by -1.
    // 3. We will keep track of the number of asteroids destroyed and if it is equal to the total number of asteroids, we will return true.
    // 4. If we have iterated through the asteroids array 7 times and still haven't destroyed all the asteroids,
    //    we will return false.

    bool asteroidsDestroyed(int mass, vector<int> &asteroids)
    {
        int c = 0;
        int n = asteroids.size();
        long long m = mass;
        for (int i = 0; i < 7 * n; i++)
        {
            int idx = i % n;
            if (asteroids[idx] > 0 && asteroids[idx] <= m)
            {
                c++;
                m += asteroids[idx];
                asteroids[idx] = asteroids[idx] * (-1);
            }
            if (c == n)
                return true;
        }
        return false;
    }
};