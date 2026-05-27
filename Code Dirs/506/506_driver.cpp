#include <bits/stdc++.h>
using namespace std;

#include "506.cpp"

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> score(n);
        for (int i = 0; i < n; i++)
            cin >> score[i];
        Solution sol;
        vector<string> res = sol.findRelativeRanks(score);
        for (int i = 0; i < n; i++) {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << "\n";
    }
    return 0;
}
