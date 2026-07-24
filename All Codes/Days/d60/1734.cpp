// Link: https://leetcode.com/problems/decode-xored-permutation/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(1)
//  Approach:
//   1. We can use the property of XOR to find the first element of the permutation.
//   2. We can then use the first element to find the rest of the elements of the permutation by XORing it with the elements of the encoded array.
//   3. We can return the permutation array as the result.
// Note: The first element of the permutation can be found by XORing all the numbers from 1 to n and then XORing it with the XOR of all the elements at odd indices of the encoded array.
class Solution
{
public:
    vector<int> decode(vector<int> &a)
    {
        int n = a.size() + 1;
        int xorr = 0;
        for (int i = 1; i <= n; ++i)
        {
            xorr ^= i;
        }
        int ad = 0;
        for (int i = 1; i < a.size(); i += 2)
        {
            ad ^= a[i];
        }
        vector<int> perm(n);
        perm[0] = xorr ^ ad;
        for (int i = 0; i < a.size(); ++i)
        {
            perm[i + 1] = perm[i] ^ a[i];
        }
        return perm;
    }
};