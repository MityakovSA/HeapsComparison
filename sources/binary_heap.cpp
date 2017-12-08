#include <binary_heap.hpp>


BinaryHeap::BinaryHeap() : heap() {}

BinaryHeap::BinaryHeap(const std::size_t& size) : heap(size) {}

BinaryHeap::BinaryHeap(const std::vector<Node>& arr) : heap(arr) { buildHeap(); }

void BinaryHeap::buildHeap()
{
    for (auto i = std::floor(heap.size() / 2 - 1); i >=0; i--)
        siftDown(i);
}

void BinaryHeap::siftDown(std::size_t i)
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

void BinaryHeap::siftUp(std::size_t i)
{
    while ((i > 0) && (heap.at(i).key < heap.at(std::floor((i - 1) / 2)).key))
    {
        std::swap(heap.at(i), heap.at(std::floor((i - 1) / 2)));
        i = std::floor((i - 1) / 2);
    }
}

BinaryHeap::Node BinaryHeap::extractMin()
{
    if (heap.empty())
        throw std::underflow_error("Heap is empty!");
    Node min = heap.at(0);
    heap.at(0) = heap.at(heap.size() - 1);
    heap.pop_back();
    siftDown(0);
    return min;
}

void BinaryHeap::insert(const Node& node)
{
    heap.push_back(node);
    siftUp(heap.size() - 1);
}

std::size_t BinaryHeap::size() const
{
    return heap.size();
}

void merge(BinaryHeap& first, BinaryHeap& second)
{
    if (second.size())
    {
        for (auto& node : second.heap)
            first.heap.push_back(node);
        first.buildHeap();
    }
}

void BinaryHeap::print() const
{
    for (auto& value : heap)
        std::cout << value.key << ":" << value.data << " ";
    std::cout << std::endl;
}
