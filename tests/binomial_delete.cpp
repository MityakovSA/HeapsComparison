#include "catch.hpp"
#include <binomial_heap.hpp>

SCENARIO("delete_node must delete node from the heap")
{
    GIVEN("Filled heap")
    {
        auto node1 = new BinomialHeap::Node(10, "abc");
        auto node2 = new BinomialHeap::Node(-1, "def");
        auto node3 = new BinomialHeap::Node(5, "kfc");
        auto node4 = new BinomialHeap::Node(14, "mcs");
        auto node5 = new BinomialHeap::Node(0, "pvs");
        auto node6 = new BinomialHeap::Node(-4, "lvs");
        auto node7 = new BinomialHeap::Node(7, "xkp");
        BinomialHeap heap;
        heap.insert(node1);
        heap.insert(node2);
        heap.insert(node3);
        heap.insert(node4);
        heap.insert(node5);
        heap.insert(node6);
        heap.insert(node7);
        WHEN("Deleting node node3")
        {
            heap.delete_node(node3);
            THEN("Node mustn't be in heap")
            {
                REQUIRE(heap.find(5) == nullptr);
            }
        }
    }
}
