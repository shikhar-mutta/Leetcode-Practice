#include <bits/stdc++.h>
using namespace std;

#include "119.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int rowIndex;
        cin >> rowIndex;
        Solution sol;
        vector<int> result = sol.getRow(rowIndex);
        for (int i = 0; i < (int)result.size(); i++) {
            if (i) cout << " ";
            cout << result[i];
        }
        cout << "\n";
    }
    return 0;
}
