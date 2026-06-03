// Link: https://leetcode.com/problems/kth-distinct-string-in-an-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string kthDistinct(vector<string> &arr, int k)
    {
        int n = arr.size();
        unordered_map<string, int> freq; // to store the frequency of each string
        for (int i = 0; i < n; i++)
            freq[arr[i]]++;

        // iterate through the array again and check if the frequency of the string is 1
        for (const string &s : arr)
            if (freq[s] == 1)
            {
                k--;
                if (k == 0)
                    return s;
            }

        return "";
    }
};
