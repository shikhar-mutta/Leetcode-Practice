// Link: https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countTriplets(vector<int> &arr)
    {
        int n = arr.size(), ans = 0;
        // O(n^2) solution: for each pair (i, k), check if XOR of arr[i..k] is 0
        for (int i = 0; i < n; ++i)
        {
            int x = 0;
            for (int k = i; k < n; ++k)
            {
                x ^= arr[k];
                if (x == 0)       // a^b = 0 => a = b
                    ans += k - i; // split any j between i and k, so add (k - i) to the answer
            }
        }
        return ans;
    }
};
