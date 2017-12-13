#include <binary_heap.hpp>
#include <binomial_heap.hpp>
#include <chrono>
#include <ctime>

bool unspec(int cor2, std::ofstream& fout)
{
    if (cor2 == 0)
    {
        fout << "Heap type wasn't specified!" << std::endl;
        return true;
    }
    return false;
}

int main(int argc, char* argv[])
{
    if (argc != 3)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 0;
    }

    std::string nin = "../tests/";
    nin += argv[1];

    std::ifstream fin(nin);
    if (!fin.is_open())
    {
        std::cout << "File " << argv[1] << " isn't exist!" << std::endl;
        return 0;
    }

    std::string nout = "../tests/";
    nout += argv[2];

    std::ofstream fout(nout);

    std::string com;
    int which;
    int key;
    std::string data;

    BinaryHeap heaps2[2];
    BinomialHeap heapsC[2];
    int cor2 = 0;

    std::chrono::time_point<std::chrono::system_clock> start, end;
    start = std::chrono::system_clock::now();

    while (fin >> com)
    {
        if (com == "binary")
            cor2 = 1;
        else if (com == "binomial")
            cor2 = 2;
        else if (com == "insert")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> which;
            fin >> key;
            fin >> data;
            if (cor2 == 1)
            {
                auto node = new BinaryHeap::Node(key, data);
                heaps2[which-1].insert(node);
            }
            if (cor2 == 2)
            {
                auto node = new BinomialHeap::Node(key, data);
                heapsC[which-1].insert(node);
            }
        }
        else if (com == "print")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> which;
            if (cor2 == 1)
                heaps2[which-1].print(fout);
            if (cor2 == 2)
                heapsC[which-1].print(fout);
        }
        else if (com == "min")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> which;
            try
            {
                if (cor2 == 1)
                    fout << heaps2[which-1].min()->data << std::endl;
                if (cor2 == 2)
                    fout << heapsC[which-1].min()->data << std::endl;
            }
            catch (std::underflow_error& error)
            {
                fout << error.what() << std::endl;
            }
        }
        else if (com == "max")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> which;
            try
            {
                if (cor2 == 1)
                    fout << heaps2[which-1].max()->data << std::endl;
                if (cor2 == 2)
                    fout << heapsC[which-1].max()->data << std::endl;
            }
            catch (std::underflow_error &error) {
                fout << error.what() << std::endl;
            }
        }
        else if (com == "find")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> which;
            fin >> key;
            if (cor2 == 1)
            {
                auto node = heaps2[which-1].find(key);
                if (node)
                    fout << "Found: " << node->data << std::endl;
                else
                    fout << "Key not found!" << std::endl;
            }
            if (cor2 == 2)
            {
                auto node = heapsC[which-1].find(key);
                if (node)
                    fout << "Found: " << node->data << std::endl;
                else
                    fout << "Key not found!" << std::endl;
            }
        }
        else if (com == "extract_min")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> which;
            try
            {
                if (cor2 == 1)
                {
                    auto min = heaps2[which - 1].extractMin();
                    fout << "Extracted: " << min->key << std::endl;
                    delete min;
                }
                if (cor2 == 2)
                {
                    auto min = heapsC[which - 1].extract_min();
                    fout << "Extracted: " << min->key << std::endl;
                    delete min;
                }
            }
            catch (std::underflow_error& error)
            {
                fout << error.what() << std::endl;
            }
        }
        else if (com == "delete")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> which;
            fin >> key;
            if (cor2 == 1)
            {
                auto i = heaps2[which-1].find_i(key);
                if (i != -1)
                    heaps2[which-1].deleteNode(i);
                else
                    fout << "There is no node with such key!" << std::endl;
            }
            if (cor2 == 2)
            {
                auto node = heapsC[which-1].find(key);
                if (node)
                    heapsC[which-1].delete_node(node);
                else
                    fout << "There is no node with such key!" << std::endl;
            }
        }
        else if (com == "merge")
        {
            if (unspec(cor2, fout))
                return 0;
            if (cor2 == 1)
                heaps2[0].merge(heaps2[1]);
            if (cor2 == 2)
                heapsC[0].union_with(heapsC[1]);
        }
        else
            fout << "Unknown command!" << std::endl;
    }

    end = std::chrono::system_clock::now();
    int elapsed_seconds = std::chrono::duration_cast<std::chrono::microseconds>(end-start).count();
    //std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    fout << "Runtime: " << elapsed_seconds << "us\n";

    fin.close();
    fout.close();

    return 0;
}