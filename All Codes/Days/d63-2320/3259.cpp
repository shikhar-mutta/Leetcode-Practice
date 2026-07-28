// Link: https://leetcode.com/problems/maximum-energy-boost-from-two-drinks/description/

#include <bits/stdc++.h>
using namespace std;

// TC: O(n), SC: O(n)
// Approach: A[i]/B[i] = max total energy ending at day i while currently on
// drink A/B. Switching drinks costs a one-day gap (no energy that day), so
// A[i] can extend from A[i-1] (stay) or B[i-2] (switch, skipping i-1); same
// symmetrically for B[i].
class Solution {
public:
    long long maxEnergyBoost(vector<int>& energyDrinkA, vector<int>& energyDrinkB) {
        int n= energyDrinkA.size();
        vector<long long> A(n);
        vector<long long> B(n);
        A[0]=energyDrinkA[0];
        B[0]=energyDrinkB[0];
        A[1]=energyDrinkA[1]+ A[0];
        B[1]=energyDrinkB[1]+B[0];
        for(int i=2;i<n;i++){
            A[i]=max(A[i-1], B[i-2]) + energyDrinkA[i];
            B[i]=max(B[i-1],A[i-2]) + energyDrinkB[i];
        }
        return max(A[n-1],B[n-1]);
    }
};
