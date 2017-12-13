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
    int key;
    std::string data;

    BinaryHeap heap2;
    BinomialHeap heapC;
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
            fin >> key;
            fin >> data;
            if (cor2 == 1)
            {
                auto node = new BinaryHeap::Node(key, data);
                heap2.insert(node);
            }
            if (cor2 == 2)
            {
                auto node = new BinomialHeap::Node(key, data);
                heapC.insert(node);
            }
        }
        else if (com == "print")
        {
            if (unspec(cor2, fout))
                return 0;
            if (cor2 == 1)
                heap2.print(fout);
            if (cor2 == 2)
                heapC.print(fout);
        }
        else if (com == "min")
        {
            if (unspec(cor2, fout))
                return 0;
            try
            {
                if (cor2 == 1)
                    fout << heap2.min()->data << std::endl;
                if (cor2 == 2)
                    fout << heapC.min()->data << std::endl;
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
            try
            {
                if (cor2 == 1)
                    fout << heap2.max()->data << std::endl;
                if (cor2 == 2)
                    fout << heapC.max()->data << std::endl;
            }
            catch (std::underflow_error &error) {
                fout << error.what() << std::endl;
            }
        }
        else if (com == "find")
        {
            if (unspec(cor2, fout))
                return 0;
            fin >> key;
            if (cor2 == 1)
            {
                auto node = heap2.find(key);
                if (node)
                    fout << "Found: " << node->data << std::endl;
                else
                    fout << "Key not found!" << std::endl;
            }
            if (cor2 == 2)
            {
                auto node = heapC.find(key);
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
            try
            {
                if (cor2 == 1)
                    fout << "Extracted: " << heap2.extractMin()->key << std::endl;
                if (cor2 == 2)
                    fout << "Extracted: " << heapC.extract_min()->key << std::endl;
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
            fin >> key;
            if (cor2 == 1)
            {
                auto i = heap2.find_i(key);
                if (i != -1)
                    heap2.deleteNode(i);
                else
                    fout << "There is no node with such key!" << std::endl;
            }
            if (cor2 == 2)
            {
                auto node = heapC.find(key);
                if (node)
                    heapC.delete_node(node);
                else
                    fout << "There is no node with such key!" << std::endl;
            }
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