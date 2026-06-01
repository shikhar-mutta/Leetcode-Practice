// Link: https://leetcode.com/problems/relative-sort-array/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
    {
        vector<int> ans;            // to store the final answer
        unordered_map<int, int> mp; // to store the frequency of each element in arr1

        for (int i = 0; i < arr1.size(); i++)
        {
            mp[arr1[i]]++; // increment the frequency of the element in the map
        }

        for (int i = 0; i < arr2.size(); i++) // iterate through arr2 and check if the element is present in the map
        {
            while (mp[arr2[i]] > 0)
            {
                ans.push_back(arr2[i]); // if the element is present in the map, add it to the answer vector and decrement its frequency in the map
                mp[arr2[i]]--;
            }
        }

        vector<int> temp; // Remaining elements which are not present in arr2 will be stored in temp vector
        for (auto it : mp)
        {
            while (it.second > 0)
            {
                temp.push_back(it.first);
                it.second--;
            }
        }

        sort(temp.begin(), temp.end()); // sort the remaining elements in ascending order

        for (int i = 0; i < temp.size(); i++)
        {
            ans.push_back(temp[i]);
        }
        return ans;
    }
};
