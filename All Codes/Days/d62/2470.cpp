// Link: https://leetcode.com/problems/number-of-subarrays-with-lcm-equal-to-k/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n * d) where d = number of distinct LCM values ending at each
//     position (bounded by the number of divisors of k)
// SC: O(d)
// Approach: maintain a map from "LCM of some subarray ending at the
// previous position" to how many such subarrays produce it. For each new
// element, extend every entry by taking lcm(entry, num) and keep only
// those that still divide k (any LCM not dividing k can never combine
// back down to k), plus the single-element subarray {num}. The count of
// subarrays ending here with LCM exactly k is added to the answer.
class Solution {
public:
    int subarrayLCM(vector<int>& a, int k) {
        unordered_map<int,int> m;
        int ans=0;
        for(auto num:a){
            unordered_map<int,int> curr;
            for(auto i:m){
                int last_lcm=i.first;
                int count=i.second;

                int new_lcm=lcm(num,last_lcm);
                if(k%new_lcm==0) curr[new_lcm]+=count;
            }
            if(k%num==0) curr[num]++;
            m=curr;
            if(m.find(k)!=m.end()) ans+=m[k];
        }
        return ans;
    }
};
