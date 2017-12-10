#ifndef HEAPSCOMPARISON_BINARY_HEAP_HPP
#define HEAPSCOMPARISON_BINARY_HEAP_HPP

#include <utility>
#include <vector>
#include <cmath>
#include <string>
#include <stdexcept>
#include <fstream>

class BinaryHeap
{
public:
    struct Node
    {
        int key;
        std::string data;

        Node(int key_, const std::string& data_);
    };

    BinaryHeap();
    explicit BinaryHeap(const std::vector<Node*>& arr);

    Node* min() const;
    Node* max() const;
    Node* find(int key) const;
    int find_i(int key) const;
    Node* extractMin();
    void insert(Node* node);
    void print(std::ofstream& fout) const;
    void merge(BinaryHeap& second);
    void deleteNode(size_t);

    ~BinaryHeap();

private:
    std::vector<Node*> heap;

    void buildHeap();
    void siftDown(std::size_t i);
    void siftUp(std::size_t i);
    void decreaseKey(size_t , int key);
};

#endif //HEAPSCOMPARISON_BINARY_HEAP_HPP
