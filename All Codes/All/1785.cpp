// Link: https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    //  Approach: Math
    //    1. We can calculate the sum of the elements in the array.
    //    2. We can then calculate the difference between the goal and the sum.
    //    3. We can then divide the difference by the limit and round up to the nearest integer to get the minimum number of elements needed to be added to form the given sum.
    //    4. Finally, we can return the minimum number of elements needed to be added to form the given sum.
    int minElements(vector<int> &nums, int limit, int goal)
    {
        long long s = 0;
        for (int n : nums)
            s += n;
        long long diff = abs(goal - s);
        //  cout << s << " " << goal << "\n";
        return ceil((double)diff / limit);
    }
};