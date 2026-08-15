// Link: https://leetcode.com/problems/distinct-points-reachable-after-substring-removal/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: We can use a sliding window approach to keep track of the distinct points reachable after removing a substring of length k. We maintain a map to store the coordinates of the points and their counts. As we slide the window, we update the coordinates based on the characters in the string and check if the new coordinates are already in the map. If not, we increment our count of distinct points.
class Solution
{
public:
    int distinctPoints(string s, int k)
    {
        long int x = 0;
        long int y = 0;
        for (int i = k; i < s.size(); i++)
        {
            if (s[k] == 'U')
                y++;
            else if (s[k] == 'D')
                y--;
            else if (s[k] == 'L')
                x--;
            else
                x++;
        }
        int c = 1;
        int st = 0;
        int e = k - 1;
        unordered_map<int, int> mp;
        mp[x * 100100 + y] = 1;
        // cout << x << y << endl;
        while (e + 1 < s.size())
        {
            if (s[st] == 'U')
                y++;
            else if (s[st] == 'D')
                y--;
            else if (s[st] == 'L')
                x--;
            else
                x++;
            e++;
            if (s[e] == 'U')
                y--;
            else if (s[e] == 'D')
                y++;
            else if (s[e] == 'L')
                x++;
            else
                x--;
            if (mp.find(x * 100100 + y) == mp.end())
            {
                mp[x * 100100 + y] = 1;
                c += 1;
                // cout << x << " " << y << endl;
            }
            st += 1;
            // cout << x << " " << y <<endl;
        }
        return c;
    }
};