// Link: https://leetcode.com/problems/reorder-data-in-log-files/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        auto isDigitLog = [](const string &s)
        {
            return isdigit(s[s.find(' ') + 1]);
        };
        stable_sort(logs.begin(), logs.end(), [&](const string &a, const string &b)
                    {
            bool da = isDigitLog(a), db = isDigitLog(b);
            if (da || db)
                return !da && db; // letter-logs before digit-logs; digit order kept
            int pa = a.find(' '), pb = b.find(' ');
            string ca = a.substr(pa + 1), cb = b.substr(pb + 1);
            if (ca != cb)
                return ca < cb;
            return a.substr(0, pa) < b.substr(0, pb); });
        return logs;
    }
};
