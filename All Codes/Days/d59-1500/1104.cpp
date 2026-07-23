// Link: https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(log n) where n is the label of the node
    // SC: O(log n) where n is the label of the node
    //  Approach:
    //   1. We will find the level of the node by taking log2 of the label and adding 1.
    //   2. We will create a vector to store the path from the node to the root.
    //   3. We will iterate until the label is greater than or equal to 1.
    //   4. We will store the label in the path vector at the index level - 1.
    //   5. We will find the maximum and minimum labels at the current level and calculate the mirror label.
    //   6. We will update the label to be the mirror label divided by 2 and decrement the level.
    //   7. Finally, we will return the path vector.
    vector<int> pathInZigZagTree(int label)
    {
        int level = (int)log2(label) + 1;
        vector<int> path(level);

        while (label >= 1)
        {
            path[level - 1] = label;
            int maxAtLevel = (1 << level) - 1;
            int minAtLevel = 1 << (level - 1);
            int mirrorLabel = maxAtLevel + minAtLevel - label;
            label = mirrorLabel / 2;
            level--;
        }
        return path;
    }
};
