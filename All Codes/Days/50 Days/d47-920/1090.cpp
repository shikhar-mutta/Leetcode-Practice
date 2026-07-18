// Link: https://leetcode.com/problems/largest-values-from-labels/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) for sorting the values and labels
    // SC: O(n) for storing the values and labels in a vector of pairs
    // Approach:
    //   1. Create a vector of pairs to store the values and labels.
    //   2. Sort the vector of pairs in descending order based on the values.
    //   3. Iterate through the sorted vector and select the values based on the useLimit and numWanted constraints.
    //   4. Keep track of the count of each label using a vector and update the answer accordingly.
    //   5. Return the final answer.
    int largestValsFromLabels(vector<int> &values, vector<int> &labels, int numWanted, int useLimit)
    {
        vector<pair<int, int>> vec;
        int n = values.size();
        for (int i = 0; i < n; i++)
        {
            vec.push_back({values[i], labels[i]});
        }
        sort(vec.begin(), vec.end());
        reverse(vec.begin(), vec.end());
        vector<int> vis(20001, 0);
        int ans = 0;
        for (int i = 0; i < vec.size(); i++)
        {
            if (numWanted > 0)
            {
                if (vis[vec[i].second] < useLimit)
                {
                    ans += vec[i].first;
                    numWanted--;
                    vis[vec[i].second]++;
                }
            }
        }
        return ans;
    }
};