// Link: https://leetcode.com/problems/coupon-code-validator/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) + O(n) ~ O(nlogn). SC: O(n) for answer vector.
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        auto fn1 = [](string s)
        {
            if (s == "")
                return false;
            for (int i = 0; i < s.size(); i++)
            {
                if (!isalnum(s[i]) && s[i] != '_')
                    return false;
            }
            return true;
        };
        auto fn2 = [](string s)
        {
            if (s == "electronics" || s == "grocery" || s == "pharmacy" || s == "restaurant")
                return true;

            return false;
        };

        vector<vector<pair<string, int>>> st(4);

        vector<string> vec; // answer vector
        int n = code.size();
        // store code & index in st according to business line
        for (int i = 0; i < n; i++)
        {

            if (businessLine[i] == "electronics")
                st[0].push_back({code[i], i});
            else if (businessLine[i] == "grocery")
                st[1].push_back({code[i], i});
            else if (businessLine[i] == "pharmacy")
                st[2].push_back({code[i], i});
            else if (businessLine[i] == "restaurant")
                st[3].push_back({code[i], i});
        }
        //  sort each business line according to code
        for (int j = 0; j < 4; j++)
        {
            sort(st[j].begin(), st[j].end());
        }
        // Check Validity & store in answer vector
        for (int j = 0; j < 4; j++)
        {
            n = st[j].size();
            for (int i = 0; i < n; i++)
            {
                int k = st[j][i].second;
                if (fn1(code[k]) && isActive[k])
                    vec.push_back(code[k]);
            }
        }
        return vec;
    }
};