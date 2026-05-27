#include <bits/stdc++.h>
using namespace std;

#include "575.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> candyType(n);
        for (int i = 0; i < n; i++)
            cin >> candyType[i];
        Solution sol;
        cout << sol.distributeCandies(candyType) << "\n";
    }
    return 0;
}
