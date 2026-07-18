// Link: https://leetcode.com/problems/reorder-data-in-log-files/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(nlogn) where n is the number of logs. We sort the logs using a custom comparator, which takes O(nlogn) time.
    // SC: O(n) for storing the logs in a vector.
    // Approach: We can use a custom comparator to sort the logs. We first check if the log is a digit-log or a letter-log. If both logs are letter-logs, we compare their contents (excluding the identifier) lexicographically. If the contents are the same, we compare their identifiers. If one log is a letter-log and the other is a digit-log, we place the letter-log before the digit-log. If both logs are digit-logs, we maintain their original order.
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
