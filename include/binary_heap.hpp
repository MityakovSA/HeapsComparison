#ifndef HEAPSCOMPARISON_BINARY_HEAP_HPP
#define HEAPSCOMPARISON_BINARY_HEAP_HPP

#include <utility>
#include <vector>
#include <cmath>
#include <string>
#include <iostream>

template <typename T>
class BinaryHeap
{
public:
    struct Node
    {
        int key;
        T data;

        Node() {}
        Node(int key_, const T& data_) : key(key_), data(data_) {}
    };

    friend void merge(BinaryHeap<T>& first, BinaryHeap<T>& second);

    BinaryHeap();
    BinaryHeap(const std::size_t& size);
    BinaryHeap(const std::vector<Node>& arr);

    Node extractMin();
    void insert(const Node& node);
    std::size_t size() const;
    void print();

private:
    std::vector<Node> heap;

    void buildHeap();
    void siftDown(std::size_t i);
    void siftUp(std::size_t i);
};

template <typename T>
BinaryHeap<T>::BinaryHeap() {}

template <typename T>
BinaryHeap<T>::BinaryHeap(const std::size_t& size) : heap(size) {}

template <typename T>
BinaryHeap<T>::BinaryHeap(const std::vector<Node>& arr) : heap(arr) { buildHeap(); }

template <typename T>
void BinaryHeap<T>::buildHeap()
{
    for (auto i = std::floor(heap.size() / 2 - 1); i >=0; i--)
        siftDown(i);
}

template <typename T>
void BinaryHeap<T>::siftDown(std::size_t i)
{
    while (2 * i + 1 < heap.size())
    {
        std::size_t left = 2 * i + 1;
        std::size_t right = 2 * i + 2;
        std::size_t j = left;
        if ((right < heap.size()) && (heap.at(right).key < heap.at(left).key))
            j = right;
        if (heap.at(i).key <= heap.at(j).key)
            break;
        std::swap(heap.at(i), heap.at(j));
        i = j;
    }
}

template <typename T>
void BinaryHeap<T>::siftUp(std::size_t i)
{
    while (heap.at(i).key < heap.at(std::floor((i - 1) / 2)).key)
    {
        std::swap(heap.at(i), heap.at(std::floor((i - 1) / 2)));
        i = std::floor((i - 1) / 2);
    }
}

template <typename T>
typename BinaryHeap<T>::Node BinaryHeap<T>::extractMin()
{
    Node min = heap.at(0);
    heap.at(0) = heap.at(heap.size() - 1);
    heap.pop_back();
    siftDown(0);
    return min;
}

template <typename T>
void BinaryHeap<T>::insert(const Node& node)
{
    heap.push_back(node);
    siftUp(heap.size() - 1);
}

template <typename T>
std::size_t BinaryHeap<T>::size() const
{
    return heap.size();
}

template <typename T>
void merge(BinaryHeap<T>& first, BinaryHeap<T>& second)
{
    for (auto& node : second.heap)
        first.heap.push_back(node);
    first.buildHeap();
}

template <typename T>
void BinaryHeap<T>::print()
{
    for (auto& value : heap)
        std::cout << value.key << ":" << value.data << " ";
    std::cout << std::endl;
}

#endif //HEAPSCOMPARISON_BINARY_HEAP_HPP
