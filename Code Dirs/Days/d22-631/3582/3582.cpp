// Link: https://leetcode.com/problems/generate-tag-for-video-caption/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(n)
    string generateTag(string caption)
    {
        string tag = "#";
        bool first = true; // first word stays fully lowercase
        stringstream ss(caption);
        string w;
        while (ss >> w)
        { // split on whitespace
            for (int i = 0; i < (int)w.size(); ++i)
                w[i] = tolower(w[i]);
            if (!first)
                w[0] = toupper(w[0]); // capitalize subsequent words
            tag += w;
            first = false;
        }
        if (tag.size() > 100)
            tag = tag.substr(0, 100); // cap length at 100
        return tag;
    }
};
