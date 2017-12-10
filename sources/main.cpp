#include <binary_heap.hpp>
#include <binomial_heap.hpp>

int main()
{
    BinomialHeap heap;
    auto n1 = new BinomialHeap::Node(10, "zdfb");
    auto n2 = new BinomialHeap::Node(2, "awergh");
    auto n3 = new BinomialHeap::Node(12, "wreb");
    auto n4 = new BinomialHeap::Node(25, "fhm");
    auto n5 = new BinomialHeap::Node(18, "SRH");
    auto n6 = new BinomialHeap::Node(6, "zsrh");
    auto n7 = new BinomialHeap::Node(8, "sdfghnm");
    auto n8 = new BinomialHeap::Node(14, "cvbnhj");
    auto n9 = new BinomialHeap::Node(29, "wedfg");
    auto n10 = new BinomialHeap::Node(11, "werg");
    auto n11 = new BinomialHeap::Node(17, "werthjk");
    auto n12 = new BinomialHeap::Node(38, "oijhg");
    auto n13 = new BinomialHeap::Node(27, "mkiuyt");
    heap.insert(n1);
    heap.insert(n2);
    heap.insert(n3);
    heap.insert(n4);
    heap.insert(n5);
    heap.insert(n6);
    heap.insert(n7);
    heap.insert(n8);
    heap.insert(n9);
    heap.insert(n10);
    heap.insert(n11);
    heap.insert(n12);
    heap.insert(n13);

    std::cout << heap.min()->key << " " << heap.max()->key << std::endl;
    std::cout << heap.find(17)->data << std::endl;
    heap.print();
    std::cout << heap.extractMin()->key << std::endl;
    heap.print();
    heap.delete_node(heap.find(11));
    heap.print();

    std::cout << "Lest's compare!" << std::endl;
    return 0;
}