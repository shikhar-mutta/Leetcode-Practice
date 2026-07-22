// Link: https://leetcode.com/problems/non-decreasing-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), where n is the size of the input array. We iterate through the array once to check for violations of the non-decreasing property.
    // SC: O(1), as we use a constant amount of extra space for variables
    // Approach:
    //  1. We initialize a count variable to keep track of the number of modifications needed to make the array non-decreasing.
    //  2. We iterate through the array from the second element to the end, comparing each element with its previous element.
    //  3. If we find a violation of the non-decreasing property (i.e., nums[i - 1] > nums[i]), we increment the count and check if it exceeds 1. If it does, we return false, as we can only modify at most one element.
    //  4. If the count is still 1 or less, we check if we can modify the previous element (nums[i - 1]) or the current element (nums[i]) to fix the violation. We do this by checking the values of the elements before and after the current element. If we can modify the previous element, we set nums[i - 1] to nums[i]. Otherwise, we set nums[i] to nums[i - 1].
    //  5. After iterating through the entire array, if the count is still 1 or less, we return true, indicating that it is possible to make the array non-decreasing by modifying at most one element. Otherwise, we return false
    bool checkPossibility(vector<int> &nums)
    {
        int count = 0;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i - 1] > nums[i])
            {
                count++;
                if (count > 1)
                    return false;
                if (i < 2 || nums[i - 2] <= nums[i])
                {
                    nums[i - 1] = nums[i];
                }
                else
                {
                    nums[i] = nums[i - 1];
                }
            }
        }
        return true;
    }
};
