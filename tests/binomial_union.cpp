#include "catch.hpp"
#include <binomial_heap.hpp>

SCENARIO("union_with() must combine two heaps into one with main rule reservation")
{
    GIVEN("Empty heaps")
    {
        BinomialHeap heap1;
        BinomialHeap heap2;
        WHEN("Trying to combine")
        {
            heap1.union_with(heap2);
            THEN("Nothing happened")
            {
                REQUIRE_THROWS_AS(heap1.extract_min(), std::underflow_error&);
            }
        }
    }
    GIVEN("1 - filled, 2 - empty")
    {
        auto node1 = new BinomialHeap::Node(10, "abc");
        auto node2 = new BinomialHeap::Node(-1, "def");
        auto node3 = new BinomialHeap::Node(5, "kfc");
        auto node4 = new BinomialHeap::Node(14, "mcs");
        auto node5 = new BinomialHeap::Node(0, "pvs");
        auto node6 = new BinomialHeap::Node(-4, "lvs");
        auto node7 = new BinomialHeap::Node(7, "xkp");
        BinomialHeap heap1;
        heap1.insert(node1);
        heap1.insert(node2);
        heap1.insert(node3);
        heap1.insert(node4);
        heap1.insert(node5);
        heap1.insert(node6);
        heap1.insert(node7);
        BinomialHeap heap2;
        WHEN("Trying to combine")
        {
            heap1.union_with(heap2);
            THEN("Nothing happened")
            {
                REQUIRE(heap1.extract_min()->data == "lvs");
                REQUIRE(heap1.extract_min()->data == "def");
                REQUIRE(heap1.extract_min()->data == "pvs");
                REQUIRE(heap1.extract_min()->data == "kfc");
                REQUIRE(heap1.extract_min()->data == "xkp");
                REQUIRE(heap1.extract_min()->data == "abc");
                REQUIRE(heap1.extract_min()->data == "mcs");
                REQUIRE_THROWS_AS(heap1.extract_min(), std::underflow_error&);
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
        BinomialHeap heap1;
        auto node1 = new BinomialHeap::Node(10, "abc");
        auto node2 = new BinomialHeap::Node(-1, "def");
        auto node3 = new BinomialHeap::Node(5, "kfc");
        auto node4 = new BinomialHeap::Node(14, "mcs");
        auto node5 = new BinomialHeap::Node(0, "pvs");
        auto node6 = new BinomialHeap::Node(-4, "lvs");
        auto node7 = new BinomialHeap::Node(7, "xkp");
        BinomialHeap heap2;
        heap2.insert(node1);
        heap2.insert(node2);
        heap2.insert(node3);
        heap2.insert(node4);
        heap2.insert(node5);
        heap2.insert(node6);
        heap2.insert(node7);
        WHEN("Trying to combine")
        {
            heap1.union_with(heap2);
            THEN("heap1 must be equal to heap2")
            {
                REQUIRE(heap1.extract_min()->data == "lvs");
                REQUIRE(heap1.extract_min()->data == "def");
                REQUIRE(heap1.extract_min()->data == "pvs");
                REQUIRE(heap1.extract_min()->data == "kfc");
                REQUIRE(heap1.extract_min()->data == "xkp");
                REQUIRE(heap1.extract_min()->data == "abc");
                REQUIRE(heap1.extract_min()->data == "mcs");
                REQUIRE_THROWS_AS(heap1.extract_min(), std::underflow_error&);
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
        auto node1 = new BinomialHeap::Node(10, "abc");
        auto node2 = new BinomialHeap::Node(-1, "def");
        auto node3 = new BinomialHeap::Node(5, "kfc");
        auto node4 = new BinomialHeap::Node(14, "mcs");
        auto node5 = new BinomialHeap::Node(0, "pvs");
        auto node6 = new BinomialHeap::Node(-4, "lvs");
        auto node7 = new BinomialHeap::Node(7, "xkp");
        BinomialHeap heap1;
        heap1.insert(node1);
        heap1.insert(node2);
        heap1.insert(node3);
        BinomialHeap heap2;
        heap2.insert(node4);
        heap2.insert(node5);
        heap2.insert(node6);
        heap2.insert(node7);
        WHEN("Trying to combine")
        {
            heap1.union_with(heap2);
            THEN("The correct binary heap must be got")
            {
                REQUIRE(heap1.extract_min()->data == "lvs");
            }
        }
        delete node6;
    }
}

