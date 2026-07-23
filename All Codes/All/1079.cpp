// Link: https://leetcode.com/problems/letter-tile-possibilities/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n!) where n is the length of the string tiles
    // SC: O(n) where n is the length of the string tiles
    //  Approach:
    //   1. We will use a recursive function to generate all the possible combinations of the tiles.
    //   2. We will use a map to keep track of the count of each character in the tiles.
    //   3. We will iterate through the map and for each character, we will decrement its count and call the recursive function again.
    //   4. We will increment the count of the character back after the recursive call.
    //   5. We will keep track of the total number of combinations generated and return it.
    //   6. Finally, we will return the total number of combinations generated.
    int dfs(unordered_map<char, int> &count)
    {
        int total = 0;
        for (auto &[c, cnt] : count)
        {
            if (cnt == 0)
                continue;
            total++;
            cnt--;
            total += dfs(count);
            cnt++;
        }
        return total;
    }

    int numTilePossibilities(string tiles)
    {
        unordered_map<char, int> count;
        for (char c : tiles)
            count[c]++;
        return dfs(count);
    }
};
