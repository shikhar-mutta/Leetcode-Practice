// Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n)
    // SC: O(1)
    // Approach:
    // 1. Use two pointers to iterate through the array.
    // 2. The first pointer (k) keeps track of the position to insert the next unique element.
    // 3. The second pointer (x) iterates through the array.
    // 4. If the current element (x) is different from the element at position k-2, it means we can keep this element, so we assign nums[k] = x and increment k.
    // 5. If the current element (x) is the same as the element at position k-2, we skip it to ensure that each element appears at most twice.
    // 6. Finally, return k, which represents the length of the modified array with duplicates removed.
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() <= 2)
            return nums.size();

        int k = 2;
        for (int i = 2; i < nums.size(); i++)
        {
            if (nums[i] != nums[k - 2])
            {
                nums[k] = nums[i];
                k++;
            }
        }
        return k;
    }
};
