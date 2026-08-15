// Link: https://leetcode.com/problems/largest-even-number/description/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // TC: O(n), SC: O(1)
    string largestEven(string s)
    {
        // '2' is the only even digit; keep everything up to the last '2'
        // (most digits kept => largest value). No '2' => no even number.
        size_t last = s.find_last_of('2');
        return last == string::npos ? "" : s.substr(0, last + 1);
    }
};
