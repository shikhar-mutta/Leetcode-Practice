// Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-i/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(|s| * (|a| + |b|)) worst case for the find() scans
// SC: O(1) extra (aside from the result vector)
// Approach: two-pointer walk over the occurrences of a and b in s (each
// found incrementally via find(..., pos+1)). Whenever the current a/b
// occurrence pair is within k, record the a-index and advance a's pointer
// (an a-index is beautiful as soon as ANY qualifying b is found, no need to
// check further b's for it); otherwise advance whichever pointer is behind
// to try closing the gap.
class Solution
{
public:
    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        int apos = s.find(a);
        int bpos = s.find(b);
        vector<int> r;
        while (apos != string::npos && bpos != string::npos)
        {
            if (abs(apos - bpos) <= k)
            {
                r.push_back(apos);
                apos = s.find(a, apos + 1);
            }
            else
            {
                if (apos > bpos)
                {
                    bpos = s.find(b, bpos + 1);
                }
                else
                {
                    apos = s.find(a, apos + 1);
                }
            }
        }
        return r;
    }
};