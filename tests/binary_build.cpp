#include "catch.hpp"
#include <binary_heap.hpp>

SCENARIO("buildHeap() must create binary heap from random massive")
{
    GIVEN("Random massive")
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
        WHEN("Creating binary heap from it")
        {
            BinaryHeap heap(arr);
            THEN("In binary heap the main rule must be followed")
            {
                REQUIRE(heap.extractMin()->data == "lvs");
                REQUIRE(heap.extractMin()->data == "def");
                REQUIRE(heap.extractMin()->data == "pvs");
                REQUIRE(heap.extractMin()->data == "kfc");
                REQUIRE(heap.extractMin()->data == "xkp");
                REQUIRE(heap.extractMin()->data == "abc");
                REQUIRE(heap.extractMin()->data == "mcs");
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
}

