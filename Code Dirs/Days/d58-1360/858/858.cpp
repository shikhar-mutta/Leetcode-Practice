// Link: https://leetcode.com/problems/mirror-reflection/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log(min(p, q))) where p is the length of the side of the square room and q is the distance from the 0th receptor to the point where the laser ray meets the east wall. This is because we are calculating the greatest common divisor (gcd) of p and q using the Euclidean algorithm, which has a time complexity of O(log(min(p, q))).
    // SC: O(1) as we are using a constant amount of space.
    // Approach:
    //  1. We first calculate the greatest common divisor (gcd) of p and q. This is because the laser ray will meet the east wall at a point that is a multiple of both p and q, and the gcd helps us find the smallest such multiple.
    //  2. We then divide both p and q by their gcd to get the reduced values of p and q. This is because the laser ray will meet the east wall at a point that is a multiple of both p and q, and the reduced values help us find the smallest such multiple.
    //  3. Finally, we check the parity of the reduced values of p and q to determine which receptor the laser ray will meet first. If both p and q are odd, the laser ray will meet receptor 1. If p is even, the laser ray will meet receptor 2. If p is odd and q is even, the laser ray will meet receptor 0. This is because the laser ray will reflect off the walls of the square room, and the parity of the reduced values of p and q determines the direction of the laser ray after each reflection.
    int mirrorReflection(int p, int q)
    {
        int g = gcd(p, q);
        p /= g;
        q /= g;
        if (p % 2 == 1 && q % 2 == 1)
            return 1;
        if (p % 2 == 0)
            return 2;
        return 0;
    }
};
