// Link: https://leetcode.com/problems/find-beautiful-indices-in-the-given-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + m + p) where n is the length of s, m is the length of a, and p is the length of b
// SC: O(n + m + p) where n is the length of s, m is the length of a, and p is the length of b
// Approach: KMP algorithm to find occurances of a and b in s and then two pointer approach to find beautiful indices
//  KMP algorithm is used to find occurances of a and b in s in O(n + m) time.
class Solution
{
public:
    void constructLPS(vector<int> &lps, string x)
    {
        int i = 1;
        int l = 0;

        while (i < x.size())
        {
            if (x[i] == x[l])
            {
                l++;
                lps[i] = l;
                i++;
            }
            else
            {
                if (l != 0)
                {
                    l = lps[l - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }

    void kmpSearch(string s, string m, vector<int> &lps,
                   vector<int> &indicies)
    {
        int i = 0;
        int j = 0;

        while (i < s.size())
        {
            if (s[i] == m[j])
            {
                i++;
                j++;

                if (j == m.size())
                {
                    indicies.push_back(i - j);
                    j = lps[j - 1];
                }
            }
            else
            {
                if (j != 0)
                {
                    j = lps[j - 1];
                }
                else
                {
                    i++;
                }
            }
        }
    }

    vector<int> beautifulIndices(string s, string a, string b, int k)
    {
        // I need to find occurances of a and b in the string
        // I can do this brute force or string matching in o(n + m) time
        // KMP needs lps and then searching

        vector<int> lps1(a.size(), 0);
        vector<int> lps2(b.size(), 0);

        constructLPS(lps1, a);
        constructLPS(lps2, b);

        vector<int> indiciesA;
        vector<int> indiciesB;
        kmpSearch(s, a, lps1, indiciesA);
        kmpSearch(s, b, lps2, indiciesB);

        // Now both are in sorted order
        // I can either do a binary search or a two pointer approach
        //[16,33] [0,40]

        vector<int> beautifulIndicies;
        int i = 0;
        int j = 0;

        while (i < indiciesA.size() && j < indiciesB.size())
        {
            if (abs(indiciesA[i] - indiciesB[j]) <= k)
            {
                beautifulIndicies.push_back(indiciesA[i]);
                i++;
            }
            else if (indiciesB[j] - indiciesA[i] > k)
            {
                i++;
            }
            else
            {
                j++;
            }
        }

        return beautifulIndicies;
    }
};
