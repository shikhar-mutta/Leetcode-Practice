// Link: https://leetcode.com/problems/check-if-n-and-its-double-exist/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {

        unordered_set<int> seen; // Use a hash set to store seen numbers
        for (int x : arr)
        {
            if (seen.count(2 * x) || (x % 2 == 0 && seen.count(x / 2)))
                return true; // Check if double or half (for even numbers) exists in the set
            seen.insert(x);  // Add the current number to the set
        }
        return false; // If no such pair is found, return false
    }
};
