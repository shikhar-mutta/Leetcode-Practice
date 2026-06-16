// Link: https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(nlogn) + O(nlogn) = O(nlogn). SC: O(n)
    //  prefix sum + binary search
    int maximumWhiteTiles(vector<vector<int>> &tiles, int l)
    {

        vector<pair<int, int>> a;
        for (int i = 0; i < tiles.size(); i++)
            a.push_back({tiles[i][0], tiles[i][1]});

        sort(a.begin(), a.end());
        vector<int> pref(a.size() + 1, 0);

        int ans = 0;
        for (int i = 0; i < a.size(); i++) // prefix sum of the number of tiles covered until index i
            pref[i + 1] = pref[i] + (a[i].second - a[i].first + 1);

        for (int i = 0; i < a.size(); i++)
        {
            int s = i, e = a.size() - 1;
            int target = a[i].first + l - 1;
            int idx = i;
            while (s <= e) // binary search to find the index of the last tile
            {
                int mid = (s + e) / 2;

                if (a[mid].first <= target)
                {
                    idx = mid; // update the index of the last tile
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }

            // target
            int rn = pref[idx] - pref[i]; // add prefix to answer
            if (idx < a.size())
            {
                int val = max(0, min(target, a[idx].second) - a[idx].first + 1);
                rn += val;
            }
            ans = max(ans, rn);
        }

        return ans;
    }
};