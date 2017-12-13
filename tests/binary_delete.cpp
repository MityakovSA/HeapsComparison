#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("deleteNode must extract node by its index from heap")
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
        WHEN("Trying to delete node by index 2 in heap (node exist)")
        {
            heap.deleteNode(2);
            THEN("Method must delete node with key 5")
            {
                REQUIRE(heap.find(5) == nullptr);
            }
        }
        WHEN("Trying to delete node by index 10 in heap (node isn't exist)")
        {
            THEN("Method must throw exception about index out of range")
            {
                REQUIRE_THROWS_AS(heap.deleteNode(10), std::out_of_range&);
            }
        }
    }
    GIVEN("Empty heap")
    {
        BinaryHeap heap;
        WHEN("Trying to delete something")
        {
            THEN("Method must throw exception about heap is empty")
            {
                REQUIRE_THROWS_AS(heap.deleteNode(0), std::underflow_error&);
            }
        }
    }
}

