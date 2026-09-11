// Link: https://leetcode.com/problems/check-array-formation-through-concatenation/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces)
    {
        unordered_map<int, vector<int>> m; // value -> piece
        for (auto &p : pieces)
        {
            m[p[0]] = p; // first value of piece -> piece
        }

        int i = 0, n = arr.size(); // index, length of arr
        while (i < n)              // while index is within arr
        {
            if (m.count(arr[i]) == 0)
            { // if first value of piece is not in arr, return false
                return false;
            }

            auto &p = m[arr[i]]; // get the piece corresponding to the first value
            for (int j = 0; j < p.size(); j++)
            {
                if (arr[i + j] != p[j])
                { // if values in piece do not match with arr, return false
                    return false;
                }
            }
            // if values in piece match with arr, move index by the size of the piece
            i += p.size();
        }

        return true;
    }
};
