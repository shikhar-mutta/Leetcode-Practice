// Link: https://leetcode.com/problems/validate-ip-address/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)  SC: O(1)
// Approach: split on '.' or ':' and validate each segment per IPv4/IPv6 rules
class Solution {
    vector<string> split(const string& s, char delim) {
        vector<string> parts;
        string cur;
        for (char c : s) {
            if (c == delim) { parts.push_back(cur); cur = ""; }
            else cur += c;
        }
        parts.push_back(cur);
        return parts;
    }

    bool isIPv4Segment(const string& seg) {
        if (seg.empty() || seg.size() > 3) return false;
        if (seg.size() > 1 && seg[0] == '0') return false;
        for (char c : seg) if (!isdigit(c)) return false;
        int val = stoi(seg);
        return val >= 0 && val <= 255;
    }

    bool isIPv6Segment(const string& seg) {
        if (seg.empty() || seg.size() > 4) return false;
        for (char c : seg) {
            if (!isxdigit(c)) return false;
        }
        return true;
    }

public:
    string validIPAddress(string queryIP) {
        if (queryIP.find('.') != string::npos) {
            auto parts = split(queryIP, '.');
            if (parts.size() != 4) return "Neither";
            for (auto& p : parts) if (!isIPv4Segment(p)) return "Neither";
            return "IPv4";
        }
        if (queryIP.find(':') != string::npos) {
            auto parts = split(queryIP, ':');
            if (parts.size() != 8) return "Neither";
            for (auto& p : parts) if (!isIPv6Segment(p)) return "Neither";
            return "IPv6";
        }
        return "Neither";
    }
};
