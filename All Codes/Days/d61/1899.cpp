// Link: https://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the number of triplets
// SC: O(1)
//  Approach: Greedy
//   1. Iterate through the triplets and check if the triplet can be merged to form the target triplet.
//   2. If the triplet can be merged, check if the triplet has the same value as the target triplet for each element.
//   3. If the triplet has the same value as the target triplet for each element, set the corresponding boolean variable to true.
//   4. If all three boolean variables are true, return true
//   5. If the loop ends and not all three boolean variables are true, return false.
class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        bool a = false, b = false, c = false;
        for (auto &t : triplets)
        {
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2])
                continue;
            if (t[0] == target[0])
                a = true;
            if (t[1] == target[1])
                b = true;
            if (t[2] == target[2])
                c = true;
        }
        return a && b && c;
    }
};
