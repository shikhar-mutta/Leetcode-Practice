// Link: https://leetcode.com/problems/permutations-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n! * n) where n is the length of the input array. The number of unique permutations can be up to n!, and for each permutation, we may need to copy it to the result vector, which takes O(n) time.
// SC: O(n) for the recursion stack and the used array, where n is the length of the input array. The result vector can also take up to O(n! * n) space.
//  Approach: Backtracking with sorting and used array to avoid duplicates. The input array is sorted to ensure that duplicate numbers are adjacent. A boolean array is used to track which elements have been included in the current permutation. When generating permutations, if the current number is the same as the previous number and the previous number has not been used in the current permutation, we skip it to avoid generating duplicate permutations.
class Solution
{
public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res;
        vector<int> cur;
        vector<bool> used(n, false);

        function<void()> bt = [&]()
        {
            if ((int)cur.size() == n)
            {
                res.push_back(cur);
                return;
            }
            for (int i = 0; i < n; i++)
            {
                if (used[i])
                    continue;
                // skip duplicate values at the same depth
                if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                    continue;
                used[i] = true;
                cur.push_back(nums[i]);
                bt();
                cur.pop_back();
                used[i] = false;
            }
        };
        bt();
        return res;
    }
};
