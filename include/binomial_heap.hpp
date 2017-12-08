#ifndef HEAPSCOMPARISON_BINOMIAL_HEAP_HPP
#define HEAPSCOMPARISON_BINOMIAL_HEAP_HPP

#include <iostream>
#include <stdexcept>

class BinomialHeap
{
public:
    struct Node
    {
        int key;
        const char* data;
        size_t degree;
        Node* p;
        Node* child;
        Node* sibling;

        Node() {}
        Node(int key_, const char* data_) : key(key_), data(data_), degree(0), p(nullptr),
                                            child(nullptr), sibling(nullptr) {}
    };

    //friend Node* merge(BinomialHeap& h1, BinomialHeap& h2);

    BinomialHeap();

    Node* min() const;
    void union_with(BinomialHeap& other);
    void insert(Node* node);
    Node* extractMin();

private:
    Node* head;

    void link(Node* y, Node* z);
    void merge(BinomialHeap& other);
    Node* rotate(Node* head_);
};

#endif //HEAPSCOMPARISON_BINOMIAL_HEAP_HPP
