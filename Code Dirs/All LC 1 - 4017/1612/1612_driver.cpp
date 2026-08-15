#include <bits/stdc++.h>
using namespace std;
#include "1612.cpp"

int main() {
    Solution sol;

    // Test 1: a+(b+c) vs (a+b)+c -> true
    {
        Node* bc = new Node('+', new Node('b'), new Node('c'));
        Node* root1 = new Node('+', new Node('a'), bc);
        Node* ab = new Node('+', new Node('a'), new Node('b'));
        Node* root2 = new Node('+', ab, new Node('c'));
        cout << (sol.checkEquivalence(root1, root2) ? "true" : "false") << "\n";
    }

    // Test 2: a+(b+c) vs (a+b)+d -> false
    {
        Node* bc = new Node('+', new Node('b'), new Node('c'));
        Node* root1 = new Node('+', new Node('a'), bc);
        Node* ab = new Node('+', new Node('a'), new Node('b'));
        Node* root2 = new Node('+', ab, new Node('d'));
        cout << (sol.checkEquivalence(root1, root2) ? "true" : "false") << "\n";
    }

    // Test 3: single node x vs x -> true
    {
        Node* root1 = new Node('x');
        Node* root2 = new Node('x');
        cout << (sol.checkEquivalence(root1, root2) ? "true" : "false") << "\n";
    }

    return 0;
}
