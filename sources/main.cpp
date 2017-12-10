#include <binary_heap.hpp>
#include <binomial_heap.hpp>

int main(int argc, char* argv[])
{
    if (argc != 3)
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

    std::ofstream fout(argv[2]);

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
                fout << "Heap type wasn't specified!" << std::endl;
                return 0;
            }
            fin >> key;
            fin >> data;
            auto node = new BinomialHeap::Node(key, data);
            heapC.insert(node);
        }
        else if (com == "print")
            heapC.print(fout);
        else if (com == "min")
        {
            fout << heapC.min()->data << std::endl;
        }
        else if (com == "max")
            fout << heapC.max()->data << std::endl;
        else if (com == "find")
        {
            fin >> key;
            auto node = heapC.find(key);
            if (node)
                fout << heapC.find(key)->data << std::endl;
            else
                fout << "Key not found!" << std::endl;
        }
        else if (com == "extract_min")
        {
            try
            {
                fout << "Extracted: " << heapC.extract_min()->key << std::endl;
            }
            catch (std::underflow_error& error)
            {
                fout << error.what() << std::endl;
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
                fout << "There is no node with such key!" << std::endl;
            }
        }
        else
            fout << "Unknown command!" << std::endl;
    }

    fin.close();
    fout.close();

    return 0;
}