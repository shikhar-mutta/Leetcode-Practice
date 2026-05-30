// Link: https://leetcode.com/problems/find-the-town-judge/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> indegree(n + 1, 0);  // Create a vector to store the indegree of each person
        vector<int> outdegree(n + 1, 0); // Create a vector to store the outdegree of each person

        for (const auto &t : trust)
        {                      // Iterate through the trust relationships
            outdegree[t[0]]++; // Increment the outdegree of the person who trusts someone
            indegree[t[1]]++;  // Increment the indegree of the person who is trusted
        }

        for (int i = 1; i <= n; i++)
        { // Iterate through all people to find the judge
            if (indegree[i] == n - 1 && outdegree[i] == 0)
            {             // The judge should be trusted by everyone else and should not trust anyone
                return i; // Return the label of the judge
            }
        }

        return -1; // If no judge is found, return -1
    }
};
