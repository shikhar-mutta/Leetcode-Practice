// Link: https://leetcode.com/problems/special-array-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n + q), SC: O(n)
// Approach: pre[i] tracks the most recent index where adjacent parity
// "breaks" (nums[i] and nums[i-1] have the same parity), propagated forward;
// pre[i] stays -1 until the first break. A query [l,r] is special iff no
// break occurred within (l, r], i.e. pre[r] <= l.
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>pre(n,-1);

        for(int i=1;i<n;i++){
            if((nums[i]+nums[i-1])&1){
                pre[i]=pre[i-1];
            }
            else
            pre[i]=i;
        }

        vector<bool>ans;

        for(auto &it:queries){
            if(pre[it[1]]<=it[0])ans.push_back(1);
            else ans.push_back(0);
        }

        return ans;

    }
};
