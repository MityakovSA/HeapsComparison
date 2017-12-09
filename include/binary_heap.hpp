#ifndef HEAPSCOMPARISON_BINARY_HEAP_HPP
#define HEAPSCOMPARISON_BINARY_HEAP_HPP

#include <utility>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>
#include <stdexcept>

class BinaryHeap
{
public:
    struct Node
    {
        int key;
        const char* data;

        Node() = default;
        Node(int key_, const char* data_);
        ~Node();
    };

    friend void merge(BinaryHeap& first, BinaryHeap& second);

    BinaryHeap();
    BinaryHeap(const std::size_t& size);
    BinaryHeap(const std::vector<Node>& arr);

    Node extractMin();
    void insert(const Node& node);
    std::size_t size() const;
    void print() const;

private:
    std::vector<Node> heap;

    void buildHeap();
    void siftDown(std::size_t i);
    void siftUp(std::size_t i);
};

#endif //HEAPSCOMPARISON_BINARY_HEAP_HPP
