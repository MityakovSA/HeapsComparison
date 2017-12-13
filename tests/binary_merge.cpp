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
            heap1.merge(heap2);
            THEN("Nothing happened")
            {
                REQUIRE_THROWS_AS(heap1.extractMin(), std::underflow_error&);
            }
        }
    }
    GIVEN("1 - filled, 2 - empty")
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
        BinaryHeap heap1(arr);
        BinaryHeap heap2;
        WHEN("Trying to combine")
        {
            heap1.merge(heap2);
            THEN("Nothing happened")
            {
                REQUIRE(heap1.extractMin()->data == "lvs");
                REQUIRE(heap1.extractMin()->data == "def");
                REQUIRE(heap1.extractMin()->data == "pvs");
                REQUIRE(heap1.extractMin()->data == "kfc");
                REQUIRE(heap1.extractMin()->data == "xkp");
                REQUIRE(heap1.extractMin()->data == "abc");
                REQUIRE(heap1.extractMin()->data == "mcs");
                REQUIRE_THROWS_AS(heap1.extractMin(), std::underflow_error&);
            }
        }
        delete node1;
        delete node2;
        delete node3;
        delete node4;
        delete node5;
        delete node6;
        delete node7;
    }
    GIVEN("1 - empty, 2 - filled")
    {
        BinaryHeap heap1;
        auto node1 = new BinaryHeap::Node(10, "abc");
        auto node2 = new BinaryHeap::Node(-1, "def");
        auto node3 = new BinaryHeap::Node(5, "kfc");
        auto node4 = new BinaryHeap::Node(14, "mcs");
        auto node5 = new BinaryHeap::Node(0, "pvs");
        auto node6 = new BinaryHeap::Node(-4, "lvs");
        auto node7 = new BinaryHeap::Node(7, "xkp");
        std::vector<BinaryHeap::Node*> arr{node1, node2, node3, node4,
                                          node5, node6, node7};
        BinaryHeap heap2(arr);
        WHEN("Trying to combine")
        {
            heap1.merge(heap2);
            THEN("heap1 must be equal to heap2")
            {
                REQUIRE(heap1.extractMin()->data == "lvs");
                REQUIRE(heap1.extractMin()->data == "def");
                REQUIRE(heap1.extractMin()->data == "pvs");
                REQUIRE(heap1.extractMin()->data == "kfc");
                REQUIRE(heap1.extractMin()->data == "xkp");
                REQUIRE(heap1.extractMin()->data == "abc");
                REQUIRE(heap1.extractMin()->data == "mcs");
                REQUIRE_THROWS_AS(heap1.extractMin(), std::underflow_error&);
            }
        }
        delete node1;
        delete node2;
        delete node3;
        delete node4;
        delete node5;
        delete node6;
        delete node7;
    }
    GIVEN("Filled heaps")
    {
        auto node1 = new BinaryHeap::Node(10, "abc");
        auto node2 = new BinaryHeap::Node(-1, "def");
        auto node3 = new BinaryHeap::Node(5, "kfc");
        auto node4 = new BinaryHeap::Node(14, "mcs");
        auto node5 = new BinaryHeap::Node(0, "pvs");
        auto node6 = new BinaryHeap::Node(-4, "lvs");
        auto node7 = new BinaryHeap::Node(7, "xkp");
        std::vector<BinaryHeap::Node*> arr1{node1, node2, node3, node4};
        std::vector<BinaryHeap::Node*> arr2{node5, node6, node7};
        BinaryHeap heap1(arr1);
        BinaryHeap heap2(arr2);
        WHEN("Trying to combine")
        {
            heap1.merge(heap2);
            THEN("The correct binary heap must be got")
            {
                REQUIRE(heap1.extractMin()->data == "lvs");
            }
        }
        delete node6;
    }
}