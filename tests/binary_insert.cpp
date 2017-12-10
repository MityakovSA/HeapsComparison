#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("insert() must add node to the heap and do heapify")
{
    GIVEN("Empty heap")
    {
        BinaryHeap heap;
        auto node = new BinaryHeap::Node(10, "abc");
        WHEN("Adding a node")
        {
            heap.insert(node);
            THEN("Node must be in the root")
            {
                REQUIRE(heap.extractMin()->data == "abc");
            }
        }
    }
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
        auto node = new BinaryHeap::Node(3, "!!!");
        WHEN("Adding a node")
        {
            heap.insert(node);
            THEN("Node must be on the correct place")
            {
                for (auto i = 0; i < 3; i++)
                    heap.extractMin();
                REQUIRE(heap.extractMin()->data == "!!!");
            }
        }
    }
}