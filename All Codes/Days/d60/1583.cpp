// Link: https://leetcode.com/problems/count-unhappy-friends/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^2) SC: O(n^2)
    ///  Approach:
    //   1. We will create a matrix to store the preference of each friend for every other friend. The value at matrix[i][j] will represent how much friend i prefers friend j. A higher value means a higher preference.
    //   2. We will also create a pair array to store the current pair of each friend.
    //   3. We will iterate through each pair and for each friend in the pair, we will check if there exists another friend that they prefer more than their current pair and that friend also prefers them more than their current pair. If such a friend exists, we will mark both friends as unhappy.
    //   4. Finally, we will count the number of unhappy friends and return that count as the result.
    int unhappyFriends(int n, vector<vector<int>> &preferences,
                       vector<vector<int>> &pairs)
    {

        vector<int> unhappy(n, 0);
        vector<int> pair(n, 0);
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n - 1; j++)
            {
                matrix[i][preferences[i][j]] = n - j - 1;
            }
        }
        for (auto &a : pairs)
        {
            int first = a[0];
            int second = a[1];
            pair[first] = second;
            pair[second] = first;
        }
        for (auto &a : pairs)
        {
            int f = a[0];
            int s = a[1];
            for (int i = 0; i < n; i++)
            {
                if (!unhappy[f] && matrix[f][i] > matrix[f][s])
                {
                    if (matrix[i][f] > matrix[i][pair[i]])
                    {
                        unhappy[f] = 1;
                        unhappy[i] = 1;
                    }
                }
                if (!unhappy[s] && matrix[s][i] > matrix[s][f])
                {
                    if (matrix[i][s] > matrix[i][pair[i]])
                    {
                        unhappy[s] = 1;
                        unhappy[i] = 1;
                    }
                }
            }
        }
        int ans = 0;
        for (int s : unhappy)
        {
            if (s == 1)
                ans++;
        }
        return ans;
    }
};
