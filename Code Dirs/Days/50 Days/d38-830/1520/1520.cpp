// Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-substrings/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    // Approach: The code first finds the first and last occurrence of each character in the string. Then, it constructs intervals for each character and checks if they can be valid substrings. Finally, it sorts the intervals by their right endpoint and selects non-overlapping substrings to maximize the number of substrings returned.
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second < b.second; // sorts by the right endpoint
    }
    pair<int, int> getInterval(int start, string &s, vector<int> &first,
                               vector<int> &last)
    {
        int end = last[s[start] - 'a'];
        for (int i = start; i <= end; i++)
        {
            // scans every character inside the interval.
            int c = s[i] - 'a';
            if (first[c] < start)
                return {-1, -1};
            end = max(end, last[c]);
        }
        return {start, end};
    }
    vector<string> maxNumOfSubstrings(string s)
    {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);

        for (int i = 0; i < n; i++)
        {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = i;
        }
        vector<pair<int, int>> intervals;
        for (int c = 0; c < 26; c++)
        {
            if (first[c] < n)
            {
                pair<int, int> p = getInterval(first[c], s, first, last);

                if (p.first != -1)
                    intervals.push_back(p);
            }
        }
        sort(intervals.begin(), intervals.end(), cmp);

        vector<string> ans;
        int prevEnd = -1;

        for (int i = 0; i < intervals.size(); i++)
        {
            int L = intervals[i].first;
            int R = intervals[i].second;

            if (L > prevEnd)
            {
                ans.push_back(s.substr(L, R - L + 1));
                prevEnd = R;
            }
        }

        return ans;
    }
};