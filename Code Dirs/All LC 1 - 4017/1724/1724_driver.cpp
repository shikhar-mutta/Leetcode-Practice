#include <bits/stdc++.h>
using namespace std;
#include "1724.cpp"

int main() {
    vector<vector<int>> edgeList = {{0,1,2},{1,2,4},{2,0,8},{1,0,16}};
    DistanceLimitedPathsExist obj(3, edgeList);

    cout << "[null,"
         << (obj.query(0,1,2) ? "true" : "false") << ","
         << (obj.query(0,1,3) ? "true" : "false") << ","
         << (obj.query(2,0,3) ? "true" : "false") << ","
         << (obj.query(2,0,4) ? "true" : "false") << "]\n";

    return 0;
}
