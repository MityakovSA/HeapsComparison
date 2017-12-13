#include <binomial_heap.hpp>

BinomialHeap::Node::Node(int key_, const std::string& data_) : key(key_), data(data_),
                                                        degree(0), p(nullptr),
                                                        child(nullptr), sibling(nullptr) {}

BinomialHeap::Node::~Node()
{
    delete this->sibling;
    delete this->child;
}

BinomialHeap::BinomialHeap() : head(nullptr) {}

BinomialHeap::Node* BinomialHeap::min() const
{
    if (!head)
        throw std::underflow_error("Heap is empty!");
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

BinomialHeap::Node* BinomialHeap::list_max(Node* cur, Node* max) const
{
    while (cur)
    {
        if (cur->key > max->key)
            max = cur;
        if (cur->child)
            max = list_max(cur->child, max);
        cur = cur->sibling;
    }
    return max;
}

BinomialHeap::Node* BinomialHeap::max() const
{
    if (!head)
        throw std::underflow_error("Heap is empty!");
    Node* max = head;
    return list_max(head, max);
}

BinomialHeap::Node* BinomialHeap::list_find(Node *cur, int key) const
{
    Node* node = nullptr;
    while (cur)
    {
        if (cur->key == key)
            return cur;
        if ((cur->key < key) && cur->child)
            node = list_find(cur->child, key);
        if (node)
            return node;
        cur = cur->sibling;
    }
    return node;
}

BinomialHeap::Node* BinomialHeap::find(int key) const
{
    return list_find(head, key);
}

void BinomialHeap::merge(BinomialHeap& other)
{
    if (!head)
    {
        head = other.head;
        return;
    }
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
    if (!other.head)
        return;
    this->merge(other);
    other.head = nullptr;
    if (!head)
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
    this->union_with(heap);
}

BinomialHeap::Node* BinomialHeap::rotate(Node* head_)
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

BinomialHeap::Node* BinomialHeap::extract_min()
{
    Node* min = this->min();
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
    this->union_with(heap);
    return min;
}

void BinomialHeap::decrease_key(Node* x, int k)
{
    if (k > x->key)
        throw std::logic_error("New key is lesser than current");
    x->key = k;
    Node* y = x;
    Node* z = y->p;
    while (z && (y->key < z->key))
    {
        int key_ = y->key;
        std::string data_ = y->data;
        y->key = z->key;
        y->data = z->data;
        z->key = key_;
        z->data = data_;
        y = z;
        z = y->p;
    }
}

void BinomialHeap::delete_node(Node* x)
{
    decrease_key(x, -2147483648);
    delete this->extract_min();
}

void BinomialHeap::list_print(Node *cur, std::ofstream& fout) const
{
    while (cur)
    {
        fout << cur->key << ":" << cur->data << ":";
        if (cur->p)
            fout << cur->p->key;
        fout << " ";
        list_print(cur->child, fout);
        cur = cur->sibling;
    }
}

void BinomialHeap::print(std::ofstream& fout) const
{
    list_print(head, fout);
    fout << std::endl;
}

BinomialHeap::~BinomialHeap()
{
    delete head;
}