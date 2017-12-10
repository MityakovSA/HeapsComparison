#ifndef HEAPSCOMPARISON_BINOMIAL_HEAP_HPP
#define HEAPSCOMPARISON_BINOMIAL_HEAP_HPP

#include <iostream>
#include <stdexcept>
#include <utility>
#include <string>
#include <fstream>

class BinomialHeap
{
public:
    struct Node
    {
        int key;
        std::string data;
        size_t degree;
        Node* p;
        Node* child;
        Node* sibling;

        //Node() = default;
        Node(int key_, const std::string& data_);
        ~Node();
    };

    BinomialHeap();

    Node* min() const;
    Node* max() const;
    Node* find(int key) const;
    void union_with(BinomialHeap& other);
    void insert(Node* node);
    Node* extract_min();
    void delete_node(Node* x);
    void print(std::ofstream& fout) const;

    ~BinomialHeap();

private:
    Node* head;

    Node* list_max(Node* cur, Node* max) const;
    Node* list_find(Node* cur, int key) const;
    void link(Node* y, Node* z);
    void merge(BinomialHeap& other);
    Node* rotate(Node* head_);
    void decrease_key(Node* x, int k);
    void list_print(Node* cur, std::ofstream& fout) const;
};

#endif //HEAPSCOMPARISON_BINOMIAL_HEAP_HPP
