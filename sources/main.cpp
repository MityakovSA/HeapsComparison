#include <binary_heap.hpp>
#include <binomial_heap.hpp>
#include <fstream>
//#include <cstring>

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cout << "Wrong number of arguments!" << std::endl;
        return 0;
    }

    std::string com;
    int key;
    std::string data;
    std::ifstream fin(argv[1]);
    if (!fin.is_open())
    {
        std::cout << "File " << argv[1] << " isn't exist!" << std::endl;
        return 0;
    }

    BinomialHeap heapC;
    int cor2 = 0;

    while (fin >> com)
    {
        if (com == "binary")
            cor2 = 1;
        else if (com == "binomial")
            cor2 = 2;
        else if (com == "insert")
        {
            if (!cor2)
            {
                std::cout << "Heap type wasn't specified!" << std::endl;
                return 0;
            }
            fin >> key;
            fin >> data;
            auto node = new BinomialHeap::Node(key, data);
            heapC.insert(node);
        }
        else if (com == "print")
            heapC.print();
        else if (com == "min")
            std::cout << heapC.min()->data << std::endl;
        else if (com == "max")
            std::cout << heapC.max()->data << std::endl;
        else if (com == "find")
        {
            fin >> key;
            auto node = heapC.find(key);
            if (node)
                std::cout << heapC.find(key)->data << std::endl;
            else
                std::cout << "Key not found!" << std::endl;
        }
        else if (com == "extract_min")
        {
            try
            {
                std::cout << "Extracted: " << heapC.extract_min()->key << std::endl;
            }
            catch (std::underflow_error& error)
            {
                std::cout << error.what() << std::endl;
            }
        }
        else if (com == "delete")
        {
            fin >> key;
            auto node = heapC.find(key);
            if (node)
            {
                heapC.delete_node(node);
            }
            else
            {
                std::cout << "There is no node with such key!" << std::endl;
            }
        }
        else
            std::cout << "Unknown command!" << std::endl;
    }

    fin.close();

    return 0;
}