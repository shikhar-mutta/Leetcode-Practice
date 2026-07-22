// Link: https://leetcode.com/problems/subdomain-visit-count/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n * m), where n is the number of cpdomains and m is the average length of the domain string.
    // SC: O(n * m), for storing the counts of each subdomain in the unordered_map.
    // Approach:
    // 1. Initialize an unordered_map to store the counts of each subdomain.
    // 2. Iterate through each cpdomain in the input vector.
    // 3. For each cpdomain, find the space character to separate the count and the domain.
    // 4. Convert the count substring to an integer and extract the domain substring.
    // 5. Iterate through the domain string and for each '.' character, extract the subdomain and update its count in the unordered_map.
    // 6. After processing all cpdomains, create a result vector and populate it with the counts and corresponding subdomains from the unordered_map.
    // 7. Return the result vector.
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        unordered_map<string, int> count;
        for (auto &cp : cpdomains)
        {
            int space = cp.find(' ');
            int cnt = stoi(cp.substr(0, space));
            string domain = cp.substr(space + 1);
            for (int i = 0; i < (int)domain.size(); i++)
            {
                if (domain[i] == '.')
                    count[domain.substr(i + 1)] += cnt;
            }
            count[domain] += cnt;
        }
        vector<string> res;
        for (auto &[d, c] : count)
            res.push_back(to_string(c) + " " + d);
        return res;
    }
};
