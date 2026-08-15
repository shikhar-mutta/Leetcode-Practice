// Link: https://leetcode.com/problems/destination-city/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string destCity(vector<vector<string>> &paths)
    {
        unordered_set<string> sources;// insert all sources into a set
        for (auto &p : paths)// insert all sources into a set
            sources.insert(p[0]);
        for (auto &p : paths)
            if (!sources.count(p[1])) // if the destination is not in the set,it is ans
                return p[1];
        return "";
    }
};
