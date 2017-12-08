#include <binomial_heap.hpp>

BinomialHeap::BinomialHeap() : head(nullptr) {}

Node* BinomialHeap::min() const
{
    if (!head)
        throw std::underflow_error("Heap is empty");
    Node* y = head;
    Node* x = head->sibling;
    int min = head->key;
    while (x)
    {
        if (x->key < min)
        {
            min = x->key;
            y = x;
        }
        x = x->sibling;
    }
    return y;
}


void BinomialHeap::merge(BinomialHeap& other)
{
    BinomialHeap::Node* n1 = head;
    BinomialHeap::Node* n2 = other.head;
    BinomialHeap::Node* n = nullptr;
    if (n1->degree <= n2->degree)
    {
        n = n1;
        n1 = n1->sibling;
    }
    else
    {
        n = n2;
        n2 = n2->sibling;
    }
    BinomialHeap::Node* head_ = n;
    while (n1 && n2)
    {
        if (n1->degree <= n2->degree)
        {
            n->sibling = n1;
            n = n1;
            n1 = n1->sibling;
        }
        else
        {
            n->sibling = n2;
            n = n2;
            n2 = n2->sibling;
        }
    }
    if (n1)
        n->sibling = n1;
    else
        n->sibling = n2;
    head = head_;
}

void BinomialHeap::link(Node *y, Node *z)
{
    y->p = z;
    y->sibling = z->child;
    z->child = y;
    z->degree = z->degree + 1;
}

void BinomialHeap::union_with(BinomialHeap &other)
{
    merge(other);
    other.head = nullptr;
    if (head)
        return;
    Node* prev_x = nullptr;
    Node* x = head;
    Node* next_x = x->sibling;
    while (next_x)
    {
        if ((x->degree != next_x->degree) ||
                ((next_x->sibling) && (next_x->sibling->degree == x->degree)))
        {
            prev_x = x;
            x = next_x;
        }
        else
        {
            if (x->key <= next_x->key)
            {
                x->sibling = next_x->sibling;
                link(next_x, x);
            }
            else
            {
                if (!prev_x)
                    head = next_x;
                else
                    prev_x->sibling = next_x;
                link(x, next_x);
                x = next_x;
            }
        }
        next_x = x->sibling;
    }
}

void BinomialHeap::insert(Node* node)
{
    BinomialHeap heap;
    heap.head = node;
    union_with(heap);
}

Node* BinomialHeap::rotate(Node* head_)
{
    if (!head_)
        return nullptr;
    Node* buf = head_->sibling;
    head_->sibling = nullptr;
    Node* prev = head_;
    prev->p = nullptr;
    Node* cur = buf;
    while (cur)
    {
        buf = cur->sibling;
        cur->sibling = prev;
        prev = cur;
        prev->p = nullptr;
        cur = buf;
    }
    return prev;
}

Node* BinomialHeap::extractMin()
{
    Node* min = min();
    if (min == head)
    {
        head = min->sibling;
        min->sibling = nullptr;
    }
    else
    {
        Node* prev = head;
        while (prev->sibling != min)
        {
            prev = prev->sibling;
        }
        if (min->sibling)
        {
            prev->sibling = min->sibling;
            min->sibling = nullptr;
        }
        else
            prev->sibling = nullptr;
    }
    BinomialHeap heap;
    heap.head = rotate(min->child);
    min->child = nullptr;
    union_with(heap);
    return min;
}