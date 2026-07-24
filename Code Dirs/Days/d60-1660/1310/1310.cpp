// Link: https://leetcode.com/problems/xor-queries-of-a-subarray/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n + m) SC: O(n) where n is the size of the array and m is the number of queries
    //  Approach:
    //    1. We can use a prefix xor approach to solve this problem. We can create a prefix xor array that stores the xor of all elements from the start of the array to the current index for each index in the original array.
    //    2. We can then use the prefix xor array to calculate the xor of the elements in the subarray defined by each query. The xor of the elements in the subarray can be calculated using the formula:
    //       xor = prefix[r2+1] ^ prefix[r1]
    //       where r1 is the starting index of the subarray and r2 is the ending index of the subarray.
    //    3. Finally, we can return the resulting array that contains the xor of the elements in the subarray for each query.
    vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries)
    {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] ^ arr[i];

        vector<int> res;
        for (auto &q : queries)
            res.push_back(prefix[q[1] + 1] ^ prefix[q[0]]);
        return res;
    }
};
