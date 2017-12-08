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
                REQUIRE_THROWS_AS(heap.extractMin(), std::underflow_error);
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
        WHEN("Extracting min node")
        {
            THEN("Method must delete min node from the heap, restore heap's rule and return min node")
            {
                REQUIRE(heap.extractMin().data == "lvs");
                REQUIRE(heap.size() == 6);
                REQUIRE(heap.extractMin().data == "def");
            }
        }
    }
}
