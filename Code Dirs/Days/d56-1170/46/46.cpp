// Link: https://leetcode.com/problems/permutations/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*n!) where n is the number of elements in the input array
// SC: O(n) where n is the number of elements in the input array
// Approach:
//  1. We will use backtracking to generate all the permutations of the input array.
//  2. We will keep track of the visited elements in the input array using a boolean vector.
//  3. We will use a temporary vector to store the current permutation and add it to the answer vector when we reach the base case.
//  4. We will iterate through the input array and for each unvisited element, we will mark it as visited, add it to the temporary vector, and recursively call the function to generate the next permutation.

class Solution
{
public:
    int n;
    vector<bool> vis;
    vector<vector<int>> ans;

    vector<vector<int>> permute(vector<int> &nums)
    {
        n = nums.size();

        vis.assign(n, false);

        vector<int> temp;
        solve(0, nums, temp);
        return ans;
    }

    void solve(int i, vector<int> &nums, vector<int> &temp)
    {
        if (temp.size() == n)
        {
            ans.push_back(temp);
            return;
        }

        for (int j = 0; j < n; j++)
        {
            if (vis[j])
                continue;

            vis[j] = true;
            temp.push_back(nums[j]);
            solve(j + 1, nums, temp);
            temp.pop_back();
            vis[j] = false;
        }
    }
};