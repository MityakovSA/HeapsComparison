#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("min must return pointer on minimal node in heap")
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
        WHEN("Trying to find min")
        {
            THEN("Method must return pointer on -4")
            {
                REQUIRE(heap.min()->key == -4);
            }
        }
    }
    GIVEN("Empty heap")
    {
        BinaryHeap heap;
        WHEN("Trying to find min")
        {
            THEN("Method must throw exception that heap is empty")
            {
                REQUIRE_THROWS_AS(heap.min(), std::underflow_error&);
            }
        }
    }
}
