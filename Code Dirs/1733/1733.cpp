// Link: https://leetcode.com/problems/minimum-number-of-people-to-teach/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n*m), SC: O(n*m)
//  Approach:
//   1. We can use a bitset to store the languages known by each person.
//   2. We can then check for each friendship if the two friends can communicate with each other or not. If they cannot communicate, we mark them as not done.
//   3. We can then iterate through all the languages and count how many people need to be taught that language to make all the friendships communicate. We keep track of the minimum number of people that need to be taught and return that as the answer.
//  Note: We can use a bitset to store the languages known by each person. This will allow us to check if two friends can communicate with each other in O(1) time.
class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &languages,
                         vector<vector<int>> &friendships)
    {
        int m = languages.size();
        vector<bool> done(m + 1, true); // True means a person is already
                                        // communicating with all its friends

        vector<bitset<501>> lang(m + 1, 0);
        for (int i = 1; i <= m; i++)
        {
            for (auto &j : languages[i - 1])
            {
                lang[i].set(j);
            }
        }
        for (auto &i : friendships)
        {
            if ((lang[i[0]] & lang[i[1]]) == 0)
            {
                done[i[0]] = false;
                done[i[1]] = false;
            }
        }
        int ans = INT_MAX;
        for (int i = 1; i <= n; i++)
        {
            int curr = 0;
            for (int j = 1; j <= m; j++)
            {
                if ((!done[j]) && (lang[j][i] == 0))
                    curr++;
            }
            ans = min(curr, ans);
        }
        return ans;
    }
};