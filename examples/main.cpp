#include "binary_heap.hpp"

int main()
{
    BinaryHeap::Node n1(2, "qw");
    BinaryHeap::Node n2(14, "er");
    BinaryHeap::Node n3(-10, "ty");
    BinaryHeap::Node n4(15, "ui");
    BinaryHeap::Node n5(6, "op");
    BinaryHeap::Node n6(0, "as");
    std::vector<BinaryHeap::Node> arr;
    arr.push_back(n1);
    arr.push_back(n2);
    arr.push_back(n3);
    arr.push_back(n4);
    arr.push_back(n5);
    arr.push_back(n6);
    BinaryHeap heap1(arr);
    heap1.print();
    heap1.extractMin();
    heap1.extractMin();
    heap1.print();
    heap1.insert(n3);
    heap1.print();
    heap1.insert(n6);
    heap1.print();

    std::cout << "Lest's compare!" << std::endl;
    return 0;
}