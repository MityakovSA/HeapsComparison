#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("merge() must combine two heaps into one with main rule reservation")
{
    GIVEN("Empty heaps")
    {
        BinaryHeap heap1;
        BinaryHeap heap2;
        WHEN("Trying to combine")
        {
            merge(heap1, heap2);
            THEN("Nothing happened")
            {
                REQUIRE_FALSE(heap1.size());
                REQUIRE_FALSE(heap2.size());
            }
        }
    }
    GIVEN("1 - filled, 2 - empty")
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
        BinaryHeap heap1(arr);
        BinaryHeap heap2;
        WHEN("Trying to combine")
        {
            merge(heap1, heap2);
            THEN("Nothing happened")
            {
                REQUIRE(heap1.size() == 7);
                REQUIRE(heap1.extractMin().data == "lvs");
                REQUIRE(heap1.extractMin().data == "def");
                REQUIRE(heap1.extractMin().data == "pvs");
                REQUIRE(heap1.extractMin().data == "kfs");
                REQUIRE(heap1.extractMin().data == "xkp");
                REQUIRE(heap1.extractMin().data == "abc");
                REQUIRE(heap1.extractMin().data == "mcs");
                REQUIRE_FALSE(heap2.size());
            }
        }
    }
    GIVEN("1 - empty, 2 - filled")
    {
        BinaryHeap heap1;
        BinaryHeap::Node node1(10, "abc");
        BinaryHeap::Node node2(-1, "def");
        BinaryHeap::Node node3(5, "kfs");
        BinaryHeap::Node node4(14, "mcs");
        BinaryHeap::Node node5(0, "pvs");
        BinaryHeap::Node node6(-4, "lvs");
        BinaryHeap::Node node7(7, "xkp");
        std::vector<BinaryHeap::Node> arr{node1, node2, node3, node4,
                                          node5, node6, node7};
        BinaryHeap heap2(arr);
        WHEN("Trying to combine")
        {
            merge(heap1, heap2);
            THEN("heap1 must be equal to heap2")
            {
                REQUIRE(heap1.size() == heap2.size());
                REQUIRE(heap1.extractMin().data == heap2.extractMin().data);
                REQUIRE(heap1.extractMin().data == heap2.extractMin().data);
                REQUIRE(heap1.extractMin().data == heap2.extractMin().data);
                REQUIRE(heap1.extractMin().data == heap2.extractMin().data);
                REQUIRE(heap1.extractMin().data == heap2.extractMin().data);
                REQUIRE(heap1.extractMin().data == heap2.extractMin().data);
                REQUIRE(heap1.extractMin().data == heap2.extractMin().data);
            }
        }
    }
    GIVEN("Filled heaps")
    {
        BinaryHeap::Node node1(10, "abc");
        BinaryHeap::Node node2(-1, "def");
        BinaryHeap::Node node3(5, "kfs");
        BinaryHeap::Node node4(14, "mcs");
        BinaryHeap::Node node5(0, "pvs");
        BinaryHeap::Node node6(-4, "lvs");
        BinaryHeap::Node node7(7, "xkp");
        std::vector<BinaryHeap::Node> arr1{node1, node2, node3, node4};
        std::vector<BinaryHeap::Node> arr2{node5, node6, node7};
        BinaryHeap heap1(arr1);
        BinaryHeap heap2(arr2);
        WHEN("Trying to combine")
        {
            merge(heap1, heap2);
            THEN("The correct binary heap must be got")
            {
                REQUIRE(heap1.size() == 7);
                REQUIRE(heap1.extractMin().data == "lvs");
            }
        }
    }
}