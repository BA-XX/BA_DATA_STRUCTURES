#include "header.hpp"

int main()
{

    LinkedList list;

    list.initialize(4, 12);

    list.showList();

    list.insertHead(11);
    list.insertTail(15);

    std::cout << "-----------------------------------------------" << std::endl;
    list.showList();

    list.deleteList();
    std::cout << "-----------------------------------------------" << std::endl;
    list.showList();

    list.insertHead(11);
    list.insertHead(12);
    list.insertHead(15);
    list.insertHead(12);

    std::cout << "-----------------------------------------------" << std::endl;
    list.showList();
    std::cout << "-----------------------------------------------" << std::endl;

    std::cout << "Size : " << list.getSize() << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << "data[3] = " << list.getData(2) << std::endl;

    std::cout << "-----------------------------------------------" << std::endl;
    std::cout << ((list.searchData(15) != nullptr) ? "true" : "false") << std::endl;
}