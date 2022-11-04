#pragma once
const static bool RED = 0;
const static bool BLACK = 1;
struct Node
{
    int val;
    bool color;             //color
    Node* left, * right, * p; // Izquierda, derecha hija, nodo padre        
    Node(const int& v, const bool& c = RED, Node* l = nullptr, Node* r = nullptr, Node* _p = nullptr) :val(v), color(c), left(l), right(r), p(_p) {}
};
