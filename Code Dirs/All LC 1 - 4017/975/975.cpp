// Link: https://leetcode.com/problems/odd-even-jump/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> oddNext = makeNext(arr, true);
        vector<int> evenNext = makeNext(arr, false);

        vector<bool> canOdd(n, false), canEven(n, false);
        canOdd[n-1] = canEven[n-1] = true;
        int res = 1;
        for (int i = n - 2; i >= 0; i--) {
            if (oddNext[i] != -1) canOdd[i] = canEven[oddNext[i]];
            if (evenNext[i] != -1) canEven[i] = canOdd[evenNext[i]];
            if (canOdd[i]) res++;
        }
        return res;
    }

private:
    vector<int> makeNext(vector<int>& arr, bool asc) {
        int n = arr.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            if (arr[a] != arr[b]) return asc ? arr[a] < arr[b] : arr[a] > arr[b];
            return asc ? a < b : a < b;
        });
        vector<int> next(n, -1);
        stack<int> st;
        for (int i : idx) {
            while (!st.empty() && st.top() < i) {
                next[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return next;
    }
};
