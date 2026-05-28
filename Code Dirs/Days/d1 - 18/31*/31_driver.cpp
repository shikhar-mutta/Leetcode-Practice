#include <bits/stdc++.h>
using namespace std;

#include "31.cpp"


struct TeeBuf : std::streambuf {
    std::streambuf *orig, *echo;
    TeeBuf(std::streambuf* o, std::streambuf* e) : orig(o), echo(e) {}
    int_type uflow() override {
        int_type c = orig->sbumpc();
        if (c != traits_type::eof()) echo->sputc(c);
        return c;
    }
    int_type underflow() override { return orig->sgetc(); }
    std::streamsize xsgetn(char* s, std::streamsize n) override {
        std::streamsize got = orig->sgetn(s, n);
        echo->sputn(s, got);
        return got;
    }
};

int main() {
    int t;
    cin >> t;
    cin.ignore();
    cin.rdbuf(new TeeBuf(cin.rdbuf(), cerr.rdbuf()));
    while (t--) {
        struct Guard { ~Guard() { cerr << "\n---\n"; } } _guard;
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        Solution sol;
        sol.nextPermutation(nums);
        for (int i = 0; i < n; i++) cout << nums[i] << " \n"[i == n - 1];
    }
    return 0;
}
