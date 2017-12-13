#include "catch.hpp"
#include <binomial_heap.hpp>

SCENARIO("find() must return pointer on node with same key in heap")
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
        WHEN("Trying to find node with key 5 in heap (node exist)")
        {
            THEN("Method must return pointer on kfc")
            {
                REQUIRE(heap.find(5)->data == "kfc");
            }
        }
        WHEN("Trying to find node with key 6 in heap (node isn't exist)")
        {
            THEN("Method must return nullptr")
            {
                REQUIRE(heap.find(6) == nullptr);
            }
        }
    }
    GIVEN("Empty heap")
    {
        BinomialHeap heap;
        WHEN("Trying to find something")
        {
            THEN("Method must return nullptr")
            {
                REQUIRE(heap.find(10) == nullptr);
            }
        }
    }
}