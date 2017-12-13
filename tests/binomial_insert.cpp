#include "catch.hpp"
#include <binomial_heap.hpp>

SCENARIO("insert() must add node to the heap")
{
    GIVEN("Empty heap")
    {
        BinomialHeap heap;
        auto node = new BinomialHeap::Node(10, "abc");
        WHEN("Adding a node")
        {
            heap.insert(node);
            THEN("Node must be in heap")
            {
                REQUIRE(heap.find(10)->data == "abc");
            }
        }
    }
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
        auto node = new BinomialHeap::Node(3, "!!!");
        WHEN("Adding a node")
        {
            heap.insert(node);
            THEN("Node must be in heap")
            {
                REQUIRE(heap.find(3)->data == "!!!");
            }
        }
    }
}

