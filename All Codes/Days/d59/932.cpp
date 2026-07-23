// Link: https://leetcode.com/problems/beautiful-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n log n), where n is the input number.
    // SC: O(n), where n is the input number.
    // Approach:
    // 1. We will use a vector to store the beautiful array.
    // 2. We will start with a vector containing only the number 1.
    // 3. We will then generate the next beautiful array by taking the current beautiful array
    //    and generating the next beautiful array by taking the odd numbers and even numbers separately.
    // 4. We will repeat this process until we have generated a beautiful array of size n.
    // 5. We will return the beautiful array.
    // 6. A beautiful array is an array where for every triplet (i, j, k) with i < j < k,
    //    the condition 2 * A[j] != A[i] + A[k] holds.
    vector<int> beautifulArray(int n)
    {
        vector<int> ans = {1};
        while (ans.size() < n)
        {
            vector<int> temp;
            for (int x : ans)
            {
                if (2 * x - 1 <= n)
                {
                    temp.push_back(2 * x - 1);
                }
            }
            for (int x : ans)
            {
                if (2 * x <= n)
                {
                    temp.push_back(2 * x);
                }
            }
            ans = temp;
        }
        return ans;
    }
};