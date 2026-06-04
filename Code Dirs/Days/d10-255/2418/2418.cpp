// Link: https://leetcode.com/problems/sort-the-people/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // approach 1: use vec of pairs & reverse sort by height
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        vector<pair<int, string>> v;
        int n = names.size();
        for (int i = 0; i < n; i++) // create pairs of (height, name)
            v.push_back({heights[i], names[i]});

        sort(v.rbegin(), v.rend()); // sort by height in descending order

        vector<string> result;
        for (int i = 0; i < v.size(); i++)
            result.push_back(v[i].second);

        return result;
    }

    // approach 2: use hash map. sort heights & map to names
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        unordered_map<int, string> freq;
        int n = heights.size();
        for (int i = 0; i < n; i++)
            freq[heights[i]] = names[i];
        sort(heights.rbegin(), heights.rend()); // sort heights in descending order
        int j = 0;
        for (int i = 0; i < n; i++)
            names[j++] = freq[heights[i]];
        return names;
    }
};
