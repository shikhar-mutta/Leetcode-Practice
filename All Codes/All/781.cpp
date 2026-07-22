// Link: https://leetcode.com/problems/rabbits-in-forest/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    //  Approach:
    //  1. Count the occurrences of each answer using a hash map.
    //  2. For each unique answer, calculate the number of groups needed to accommodate all rabbits with that answer.
    //  3. The size of each group is answer + 1, and the number of groups is calculated by dividing the count of rabbits with that answer by the group size, rounding up to the nearest whole number.
    //  4. Multiply the number of groups by the group size to get the total number of rabbits for that answer, and add it to the total count.
    //  5. Return the total count of rabbits in the forest.
    int numRabbits(vector<int> &answers)
    {
        unordered_map<int, int> count;
        for (int a : answers)
            count[a]++;
        int total = 0;
        for (auto &[ans, cnt] : count)
        {
            int groupSize = ans + 1;
            int groups = (cnt + groupSize - 1) / groupSize;
            total += groups * groupSize;
        }
        return total;
    }
};
