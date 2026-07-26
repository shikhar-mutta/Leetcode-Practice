// Link: https://leetcode.com/problems/find-the-substring-with-maximum-cost/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n)
// SC: O(1) (fixed 26-size value table)
// Approach: build a per-character value table (default a=1..z=26, overridden by
// chars/vals), then Kadane's max-subarray-sum over the string's per-char values
// to find the max-cost substring (empty substring, cost 0, is always allowed
// via ans starting at 0).
class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> value(26);
        for(int i = 0;i < 26;i++){
            value[i] = i + 1;
        }
        for(int i = 0;i < chars.size();i++){
            value[chars[i] - 'a'] = vals[i];
        }
        int curr = 0;
        int ans = 0;
        for(char ch : s){
            int x = value[ch - 'a'];
            curr = max(x, curr + x);
            ans = max(ans,curr);
        }
        return ans;

    }
};
