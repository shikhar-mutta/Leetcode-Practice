// Link: https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(1)
//  Approach: We can iterate through the target array and for each element, we can check if it is greater than the previous element. If it is, we can add the difference between the current element and the previous element to the answer. Finally, we can return the answer.
class Solution
{
public:
    int minNumberOperations(vector<int> &target)
    {
        int ans = target[0];
        for (int i = 1; i < (int)target.size(); i++)
            if (target[i] > target[i - 1])
                ans += target[i] - target[i - 1];
        return ans;
    }
};
