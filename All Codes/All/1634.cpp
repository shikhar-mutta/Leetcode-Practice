// Link: https://leetcode.com/problems/add-two-polynomials-represented-as-linked-lists/description/

#include <bits/stdc++.h>
using namespace std;

class PolyNode {
public:
    int coefficient, power;
    PolyNode* next;

    PolyNode() : coefficient(0), power(0), next(nullptr) {}
    PolyNode(int x, int y) : coefficient(x), power(y), next(nullptr) {}
    PolyNode(int x, int y, PolyNode* next) : coefficient(x), power(y), next(next) {}
};

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        PolyNode dummy(0, 0);
        PolyNode* tail = &dummy;
        while (poly1 && poly2) {
            if (poly1->power > poly2->power) {
                tail->next = new PolyNode(poly1->coefficient, poly1->power);
                tail = tail->next;
                poly1 = poly1->next;
            } else if (poly2->power > poly1->power) {
                tail->next = new PolyNode(poly2->coefficient, poly2->power);
                tail = tail->next;
                poly2 = poly2->next;
            } else {
                int sum = poly1->coefficient + poly2->coefficient;
                if (sum != 0) {
                    tail->next = new PolyNode(sum, poly1->power);
                    tail = tail->next;
                }
                poly1 = poly1->next;
                poly2 = poly2->next;
            }
        }
        while (poly1) {
            tail->next = new PolyNode(poly1->coefficient, poly1->power);
            tail = tail->next;
            poly1 = poly1->next;
        }
        while (poly2) {
            tail->next = new PolyNode(poly2->coefficient, poly2->power);
            tail = tail->next;
            poly2 = poly2->next;
        }
        return dummy.next;
    }
};
