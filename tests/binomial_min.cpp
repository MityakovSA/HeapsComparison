#include "catch.hpp"
#include <binomial_heap.hpp>

SCENARIO("min() must return pointer on minimal node in heap")
{
    GIVEN("Filled heap")
    {
        auto node1 = new BinomialHeap::Node(10, "abc");
        auto node2 = new BinomialHeap::Node(-1, "def");
        auto node3 = new BinomialHeap::Node(5, "kfc");
        auto node4 = new BinomialHeap::Node(14, "mcs");
        auto node5 = new BinomialHeap::Node(0, "pvs");
        auto node6 = new BinomialHeap::Node(-4, "lvs");
        auto node7 = new BinomialHeap::Node(7, "xkp");
        BinomialHeap heap;
        heap.insert(node1);
        heap.insert(node2);
        heap.insert(node3);
        heap.insert(node4);
        heap.insert(node5);
        heap.insert(node6);
        heap.insert(node7);
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
        BinomialHeap heap;
        WHEN("Trying to find min")
        {
            THEN("Method must throw exception that heap is empty")
            {
                REQUIRE_THROWS_AS(heap.min(), std::underflow_error&);
            }
        }
    }
}

