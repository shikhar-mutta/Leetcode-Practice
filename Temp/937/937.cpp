// Link: https://leetcode.com/problems/reorder-data-in-log-files/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        auto isDigitLog = [](const string& log) {
            int sp = log.find(' ');
            return isdigit(log[sp + 1]);
        };
        stable_sort(logs.begin(), logs.end(), [&](const string& a, const string& b) {
            bool da = isDigitLog(a), db = isDigitLog(b);
            if (!da && !db) {
                int spa = a.find(' '), spb = b.find(' ');
                string bodyA = a.substr(spa + 1), bodyB = b.substr(spb + 1);
                if (bodyA != bodyB) return bodyA < bodyB;
                return a.substr(0, spa) < b.substr(0, spb);
            }
            if (!da && db) return true;
            if (da && !db) return false;
            return false;
        });
        return logs;
    }
};
