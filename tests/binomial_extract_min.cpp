#include "catch.hpp"
#include <binomial_heap.hpp>

SCENARIO("extract_min must delete node from heap and return pointer on it")
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
        WHEN("Extracting min node")
        {
            auto node = heap.extract_min();
            THEN("This node must be -4")
            {
                REQUIRE(node->key == -4);
                REQUIRE(heap.find(-4) == nullptr);
            }
            delete node;
        }
    }
    GIVEN("Empty heap")
    {
        BinomialHeap heap;
        WHEN("Trying to extract min node")
        {
            THEN("Method must throw exception about heap is empty")
            {
                REQUIRE_THROWS_AS(heap.extract_min(), std::underflow_error&);
            }
        }
    }
}

