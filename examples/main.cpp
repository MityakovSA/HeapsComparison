#include "binary_heap.hpp"

int main()
{
    BinaryHeap<std::string>::Node n1(2, "qw");
    BinaryHeap<std::string>::Node n2(14, "er");
    BinaryHeap<std::string>::Node n3(-10, "ty");
    BinaryHeap<std::string>::Node n4(15, "ui");
    BinaryHeap<std::string>::Node n5(6, "op");
    BinaryHeap<std::string>::Node n6(0, "as");
    std::vector<BinaryHeap<std::string>::Node> arr;
    arr.push_back(n1);
    arr.push_back(n2);
    arr.push_back(n3);
    arr.push_back(n4);
    arr.push_back(n5);
    arr.push_back(n6);
    BinaryHeap<std::string> heap1(arr);
    heap1.print();

    BinaryHeap<std::string>::Node n7(1, "df");
    BinaryHeap<std::string>::Node n8(-5, "gh");
    BinaryHeap<std::string>::Node n9(10, "jk");
    BinaryHeap<std::string>::Node n10(-1, "lz");
    BinaryHeap<std::string>::Node n11(0, "xc");
    BinaryHeap<std::string>::Node n12(999, "vb");
    std::vector<BinaryHeap<std::string>::Node> arr2;
    arr2.push_back(n7);
    arr2.push_back(n8);
    arr2.push_back(n9);
    arr2.push_back(n10);
    arr2.push_back(n11);
    arr2.push_back(n12);
    BinaryHeap<std::string> heap2(arr2);
    heap2.print();

    merge<std::string>(heap1, heap2);
    heap1.print();

    std::cout << "Lest's compare!" << std::endl;
    return 0;
}