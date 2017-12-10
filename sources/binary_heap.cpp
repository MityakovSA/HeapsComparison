#include <binary_heap.hpp>

BinaryHeap::Node::Node(int key_, const std::string& data_) : key(key_), data(data_) {}

BinaryHeap::BinaryHeap() : heap() {}

BinaryHeap::BinaryHeap(const std::vector<Node*>& arr) : heap(arr) { buildHeap(); }

void BinaryHeap::buildHeap()
{
    for (auto i = std::floor(heap.size() / 2 - 1); i >=0; i--)
        this->siftDown(i);
}

void BinaryHeap::siftDown(std::size_t i)
{
    while (2 * i + 1 < heap.size())
    {
        std::size_t left = 2 * i + 1;
        std::size_t right = 2 * i + 2;
        std::size_t j = left;
        if ((right < heap.size()) && (heap.at(right)->key < heap.at(left)->key))
            j = right;
        if (heap.at(i)->key <= heap.at(j)->key)
            break;
        std::swap(heap.at(i), heap.at(j));
        i = j;
    }
}

void BinaryHeap::siftUp(std::size_t i)
{
    while ((i > 0) && (heap.at(i)->key < heap.at(std::floor((i - 1) / 2))->key))
    {
        std::swap(heap.at(i), heap.at(std::floor((i - 1) / 2)));
        i = std::floor((i - 1) / 2);
    }
}

BinaryHeap::Node* BinaryHeap::extractMin()
{
    if (heap.empty())
        throw std::underflow_error("Heap is empty!");
    Node* min = heap.at(0);
    heap.at(0) = heap.at(heap.size() - 1);
    heap.pop_back();
    this->siftDown(0);
    return min;
}

void BinaryHeap::insert(Node* node)
{
    heap.push_back(node);
    this->siftUp(heap.size() - 1);
}

void BinaryHeap::merge(BinaryHeap& second)
{
    if (!second.heap.empty())
    {
        for (auto node : second.heap)
        {
            heap.push_back(node);
        }
        this->buildHeap();
        for (auto i = 0; i < second.heap.size(); i++)
        {
            second.heap.at(i) = nullptr;
        }
    }
}

void BinaryHeap::print(std::ofstream& fout) const
{
    for (auto node : heap)
        fout << node->key << ":" << node->data << " ";
    fout << std::endl;
}

BinaryHeap::Node* BinaryHeap::min() const
{
    if (heap.empty())
        throw std::underflow_error("Heap is empty!");
    return heap.at(0);
}

BinaryHeap::Node* BinaryHeap::max() const
{
    if (heap.empty())
        throw std::underflow_error("Heap is empty!");
    Node* max = heap.at(0);
    for (auto node : heap)
        if (node->key > max->key)
            max = node;
    return max;
}

BinaryHeap::Node* BinaryHeap::find(int key) const
{
    for (auto node : heap)
        if (node->key == key)
            return node;
    return nullptr;
}

int BinaryHeap::find_i(int key) const
{
    for (size_t i = 0; i < heap.size(); i++)
        if (heap.at(i)->key == key)
            return (int)i;
    return -1;
}

void BinaryHeap::decreaseKey(size_t i, int key)
{
    if (key > heap.at(i)->key)
        throw std::logic_error("New key is lesser than current");
    heap.at(i)->key = key;
    this->siftUp(i);
}

void BinaryHeap::deleteNode(size_t i)
{
    this->decreaseKey(i, -2147483648);
    this->extractMin();
}

BinaryHeap::~BinaryHeap()
{
    for (auto node : heap)
        delete node;
}