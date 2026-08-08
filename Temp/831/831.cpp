// Link: https://leetcode.com/problems/masking-personal-information/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n) SC: O(n)
// Approach: if '@' present, it's an email — lowercase, mask name to first+"*****"+last, keep domain. Otherwise it's a phone number — extract digits, keep last 10 for local number (mask first 6 as "***-***-"+lastfour), prefix remaining digits as country code "+"+stars+"-" if any.
class Solution {
public:
    string maskPII(string s) {
        if (s.find('@') != string::npos) {
            int at = s.find('@');
            string name = s.substr(0, at);
            string domain = s.substr(at+1);
            for (char& c : name) c = tolower(c);
            for (char& c : domain) c = tolower(c);
            return string(1, name[0]) + "*****" + name.back() + "@" + domain;
        } else {
            string digits;
            for (char c : s) if (isdigit(c)) digits += c;
            string local = digits.substr(digits.size()-10);
            string last4 = local.substr(6);
            string masked = "***-***-" + last4;
            int countryLen = digits.size() - 10;
            if (countryLen == 0) return masked;
            return "+" + string(countryLen, '*') + "-" + masked;
        }
    }
};
