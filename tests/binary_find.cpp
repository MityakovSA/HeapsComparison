#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("find must return pointer on node with same key in heap")
{
    GIVEN("Filled heap")
    {
        auto node1 = new BinaryHeap::Node(10, "abc");
        auto node2 = new BinaryHeap::Node(-1, "def");
        auto node3 = new BinaryHeap::Node(5, "kfc");
        auto node4 = new BinaryHeap::Node(14, "mcs");
        auto node5 = new BinaryHeap::Node(0, "pvs");
        auto node6 = new BinaryHeap::Node(-4, "lvs");
        auto node7 = new BinaryHeap::Node(7, "xkp");
        std::vector<BinaryHeap::Node*> arr{node1, node2, node3, node4,
                                           node5, node6, node7};
        BinaryHeap heap(arr);
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
        BinaryHeap heap;
        WHEN("Trying to find something")
        {
            THEN("Method must return nullptr")
            {
                REQUIRE(heap.find(10) == nullptr);
            }
        }
    }
}

