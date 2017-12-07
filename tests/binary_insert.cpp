#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("insert() must add node to the heap and do heapify")
{
    GIVEN("Empty heap")
    {
        BinaryHeap heap;
        BinaryHeap::Node node(10, "abc");
        WHEN("Adding a node")
        {
            heap.insert(node);
            THEN("Node must be in the root")
            {
                REQUIRE(heap.size() == 1);
                REQUIRE(heap.extractMin().data == "abc");
            }
        }
    }
    GIVEN("Filled heap")
    {
        BinaryHeap::Node node1(10, "abc");
        BinaryHeap::Node node2(-1, "def");
        BinaryHeap::Node node3(5, "kfs");
        BinaryHeap::Node node4(14, "mcs");
        BinaryHeap::Node node5(0, "pvs");
        BinaryHeap::Node node6(-4, "lvs");
        BinaryHeap::Node node7(7, "xkp");
        std::vector<BinaryHeap::Node> arr{node1, node2, node3, node4,
                                          node5, node6, node7};
        BinaryHeap heap(arr);
        BinaryHeap::Node node(3, "!!!");
        WHEN("Adding a node")
        {
            heap.insert(node);
            THEN("Node must be on the correct place")
            {
                REQUIRE(heap.size() == 8);
                for (auto i = 0; i < 3; i++)
                    heap.extractMin();
                REQUIRE(heap.extractMin().data == "!!!");
            }
        }
    }
}