// Link: https://leetcode.com/problems/alternating-groups-ii/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n+k), SC: O(1)
// Approach: Walk around the circular array (extending (n-1)+(k-1) steps
// past index 0 to cover every possible k-length window wrapping around),
// tracking the current alternating run length l. Whenever l reaches k, the
// window ending here is a valid alternating group of size k.
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n=colors.size();
        int count=0;
        int l=1;
        for (int i=1;i<=(n-1)+(k-1);i++){
            if (colors[i%n]!=colors[(i-1)%n]){
                l++;
            }else{
                l=1;
            }
            if (l>=k){
                count++;
            }
        }
        return count;
    }
};
