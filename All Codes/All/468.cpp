// Link: https://leetcode.com/problems/validate-ip-address/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) where n is the length of the input string queryIP.
// SC: O(1) since we are using a constant amount of extra space.
// Approach:
// 1. We can check if the input string queryIP is a valid IPv4 or IPv6 address by checking the format of the string.
// 2. For IPv4, we check if the string contains exactly 3 dots and 4 parts, each part is a number between 0 and 255, and does not have leading zeros.
// 3. For IPv6, we check if the string contains exactly 7 colons and 8 parts, each part is a hexadecimal number between 0 and FFFF, and does not have leading zeros.
// 4. If the input string is a valid IPv4 address, we return "IPv4". If it is a valid IPv6 address, we return "IPv6". Otherwise, we return "Neither".
class Solution
{
public:
    string validIPAddress(string queryIP)
    {
        if (isIPv4(queryIP))
            return "IPv4";
        if (isIPv6(queryIP))
            return "IPv6";
        return "Neither";
    }

private:
    bool isIPv4(const string &ip)
    {
        if (count(ip.begin(), ip.end(), '.') != 3)
            return false;
        vector<string> parts;
        stringstream ss(ip);
        string tok;
        while (getline(ss, tok, '.'))
            parts.push_back(tok);
        if (parts.size() != 4)
            return false;
        for (auto &p : parts)
        {
            if (p.empty() || p.size() > 3)
                return false;
            for (char c : p)
                if (!isdigit((unsigned char)c))
                    return false;
            if (p.size() > 1 && p[0] == '0')
                return false;
            int val = stoi(p);
            if (val < 0 || val > 255)
                return false;
        }
        return true;
    }

    bool isIPv6(const string &ip)
    {
        if (count(ip.begin(), ip.end(), ':') != 7)
            return false;
        vector<string> parts;
        stringstream ss(ip);
        string tok;
        while (getline(ss, tok, ':'))
            parts.push_back(tok);
        if (parts.size() != 8)
            return false;
        for (auto &p : parts)
        {
            if (p.empty() || p.size() > 4)
                return false;
            for (char c : p)
                if (!isxdigit((unsigned char)c))
                    return false;
        }
        return true;
    }
};
