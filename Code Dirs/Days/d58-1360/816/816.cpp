// Link: https://leetcode.com/problems/ambiguous-coordinates/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n^3), SC: O(n^3)
    //  Approach:
    //  1. We can iterate through the input string and for each index, we can split the string into two parts: the left part and the right part. We can then generate all possible numbers from the left part and the right part using a helper function. We can then combine the left and right parts to form the final coordinates and add them to the result vector. We can return the result vector as the answer.
    //  2. The helper function will take a string as input and generate all possible numbers from the string by adding a decimal point at different positions. We will also need to handle the cases where the string starts with '0' or ends with '0' to ensure that we only generate valid numbers.
    //  3. Finally, we will return the result vector containing all possible coordinates.
    vector<string> makeNumbers(const string &s)
    {
        int n = s.size();
        vector<string> res;
        if (n == 1)
        {
            res.push_back(s);
            return res;
        }
        if (s[0] == '0')
        {
            if (s.back() == '0')
                return res;
            res.push_back("0." + s.substr(1));
            return res;
        }
        if (s.back() == '0')
        {
            res.push_back(s);
            return res;
        }
        res.push_back(s);
        for (int i = 1; i < n; i++)
            res.push_back(s.substr(0, i) + "." + s.substr(i));
        return res;
    }

    vector<string> ambiguousCoordinates(string s)
    {
        string digits = s.substr(1, s.size() - 2);
        int n = digits.size();
        vector<string> result;
        for (int i = 1; i < n; i++)
        {
            auto lefts = makeNumbers(digits.substr(0, i));
            auto rights = makeNumbers(digits.substr(i));
            for (auto &l : lefts)
                for (auto &r : rights)
                    result.push_back("(" + l + ", " + r + ")");
        }
        return result;
    }
};
