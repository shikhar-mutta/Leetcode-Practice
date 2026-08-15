// Link: https://leetcode.com/problems/decode-xored-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        vector<int> ans(encoded.size() + 1);
        ans[0] = first; // Initialize the first element of the decoded array
        for (int i = 0; i < encoded.size(); i++)
        {
            ans[i + 1] = ans[i] ^ encoded[i]; // XOR operation to decode the next element
        }
        return ans;
    }
};
