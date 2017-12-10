#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("extractMin() extract min node from the heap and restore binary heap's main rule")
{
    GIVEN("Empty heap")
    {
        BinaryHeap heap;
        WHEN("Trying to extract min node")
        {
            THEN("Exception must be thrown")
            {
                REQUIRE_THROWS_AS(heap.extractMin(), std::underflow_error&);
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
        WHEN("Extracting min node")
        {
            THEN("Method must delete min node from the heap, restore heap's rule and return min node")
            {
                REQUIRE(heap.extractMin()->data == "lvs");
                REQUIRE(heap.extractMin()->data == "def");
            }
        }
    }
}
