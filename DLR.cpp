#include <iostream>
#include "DLR Functions.h"

int main() {
    Ring<int, int> a;
    a.add(1,2);
    a.add(3,4);
    a.add(5,6);
    a.add(7,8);
    a.show(std::cout);

    Ring<int, int>::iterator iter;
    iter = a.begin();
    //testing the methods from class Ring
    a.remove(iter);
    a.show(std::cout);
    a.remove(++iter);
    a.show(std::cout);
    iter = ++iter;
    a.remove(++iter);
    a.show(std::cout);
    a.clear();

    a.add(1,2);
    a.add(3,4);
    a.add(5,6);
    a.add(7,8);

    a.show(std::cout);

    Ring<int,int>::iterator iter2;
    iter2 = a.begin();
    Ring<int,int>::iterator iter3;
    iter3 = a.begin();

    //testing operators from class iterator
    if(*iter2 == 7){
        std::cout << "asterix works" << std::endl;
    }

    if(iter2 == iter3){
        std::cout << "equality works" << std::endl;
    }

    iter2 = ++iter2;

    if(iter2 != iter3){
        std::cout << "inequality works" << std::endl;
    }


    return 0;
}
