// Link: https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n) where n is the length of the input array arr
    // SC: O(n) where n is the length of the input array arr
    //  Approach:
    //   1. We can use a stack to keep track of the maximum values in the array.
    //   2. We iterate through the array and for each element, we pop elements from the stack until we find an element greater than the current element.
    //  3. We calculate the cost of the popped elements and add it to the result.
    //  4. We push the current element onto the stack.
    //  5. After iterating through the array, we pop the remaining elements from the stack and calculate their costs.
    //  6. Finally, we return the result which contains the minimum cost of the tree from leaf values
    int mctFromLeafValues(vector<int> &arr)
    {
        int result = 0;
        vector<int> stk = {INT_MAX};
        for (int a : arr)
        {
            while (stk.back() <= a)
            {
                int mid = stk.back();
                stk.pop_back();
                result += mid * min(stk.back(), a);
            }
            stk.push_back(a);
        }
        while (stk.size() > 2)
        {
            int mid = stk.back();
            stk.pop_back();
            result += mid * stk.back();
        }
        return result;
    }
};
