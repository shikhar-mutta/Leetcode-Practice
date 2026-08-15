// Link: https://leetcode.com/problems/random-pick-index/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach:
//  1. Store the input array in a member variable of the Solution class.
//  2. In the pick function, generate a random index within the range of the array
//  3. Check if the value at the random index matches the target value.
//  4. If it matches, return the index. If not, generate a new random index and repeat the process until a matching index is found.
//  5. This approach ensures that each index of the target value has an equal probability of being selected, as the random index is generated uniformly across the entire array.
class Solution
{
public:
    vector<int> arr;
    Solution(vector<int> &nums)
    {
        arr = nums;
    }

    int pick(int target)
    {
        int len = arr.size();
        int random = 0 + (rand() % len);
        while (arr[random] != target)
            random = 0 + (rand() % len);

        return random;
    }
};