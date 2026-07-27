// Link: https://leetcode.com/problems/maximum-points-tourist-can-earn/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(k * n^2), SC: O(n)
// Approach: DP backward over days: res[j] = max score achievable from day i
// onward starting in city j. Each day, either stay (stayScore[i][j] +
// res[j]) or travel to the best city m (travelScore[j][m] + res[m]); take
// the max of both options. Final answer is the best starting city's score.
class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<int>res=vector<int>(n);
        vector<int>temp=vector<int>(n);
        for(int i=k-1;i>=0;i--)
        {
            for(int j=0;j<n;j++)
            {
                //if stay
                int stay=stayScore[i][j]+res[j];
                //if go
                int go=travelScore[j][0]+res[0];
                for(int m=0;m<n;m++)
                {
                    if(go<travelScore[j][m]+res[m])
                    {
                        go=travelScore[j][m]+res[m];
                    }
                }
                if(stay>go)
                {
                    temp[j]=stay;
                }
                else
                {
                    temp[j]=go;
                }
            }
            res=temp;
        }
        int max=res[0];
        for(int m:res)
        {
            if(m>max)
            {
                max=m;
            }
        }
        return max;
    }
};
