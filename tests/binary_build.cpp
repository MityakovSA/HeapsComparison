#include "catch.hpp"
#include "binary_heap.hpp"

SCENARIO("buildHeap() must create binary heap from random massive")
{
    GIVEN("Random massive")
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
        WHEN("Creating binary heap from it")
        {
            BinaryHeap heap(arr);
            THEN("In binary heap the main rule must be followed")
            {
                REQUIRE(heap.extractMin().data == "lvs");
                REQUIRE(heap.extractMin().data == "def");
                REQUIRE(heap.extractMin().data == "pvs");
                REQUIRE(heap.extractMin().data == "kfc");
                REQUIRE(heap.extractMin().data == "xkp");
                REQUIRE(heap.extractMin().data == "abc");
                REQUIRE(heap.extractMin().data == "mcs");
            }
        }
    }
}

