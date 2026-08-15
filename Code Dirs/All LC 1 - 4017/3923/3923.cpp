// Link: https://leetcode.com/problems/minimum-generations-to-target-point/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n^2) SC: O(n^2)
// Approach:
// 1. Convert each point to a single integer using bitwise operations to store x, y, z coordinates in a short (16 bits).
// 2. Use a boolean array to track available points and an integer to track the number of points.
// 3. Check if the target point is already in the input points, if so return 0.
// 4. Check if the target point is reachable by checking the flags for each coordinate.
// 5. Use a loop to generate new points by combining existing points using the combine function, which averages the coordinates of two points.
// 6. If the target point is generated, return the number of generations. If no new points can be generated, return -1.
class Solution
{
public:
    inline constexpr short toIndex(int x, int y, int z)
    {
        return x | (y << 4) | (z << 8);
    }

    inline constexpr short combine(short a, short b)
    {
        return ((a + b) >> 1) & 0x0777;
    }

    int minGenerations(vector<vector<int>> &points, vector<int> &target)
    {
        short coords[4096];
        bool available[4096] = {};
        int coordCount = points.size();
        int tgX = target[0];
        int tgY = target[1];
        int tgZ = target[2];
        short tgt = toIndex(tgX, tgY, tgZ);

        int elemFlags = 0;

        for (int i = 0; i < coordCount; i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            int z = points[i][2];
            short coord = toIndex(x, y, z);
            if (coord == tgt)
                return 0;

            if (x >= tgX)
                elemFlags |= 1;
            if (x <= tgX)
                elemFlags |= 2;
            if (y >= tgY)
                elemFlags |= 4;
            if (y <= tgY)
                elemFlags |= 8;
            if (z >= tgZ)
                elemFlags |= 16;
            if (z <= tgZ)
                elemFlags |= 32;

            available[coord] = true;
            coords[i] = coord;
        }

        if (elemFlags != 63)
            return -1;

        int prevCount = 0;
        for (int i = 1;; i++)
        {
            int newCount = coordCount;

            for (int j = coordCount - 1; j >= prevCount; j--)
            {
                short a = coords[j];
                for (int k = j - 1; k >= 0; k--)
                {
                    short c = combine(a, coords[k]);
                    if (!available[c])
                    {
                        if (c == tgt)
                            return i;

                        available[c] = true;
                        coords[newCount++] = c;
                    }
                }
            }

            if (newCount == coordCount)
                break;

            prevCount = coordCount;
            coordCount = newCount;
        }

        return -1;
    }
};