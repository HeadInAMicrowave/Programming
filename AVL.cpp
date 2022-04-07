#include "AVL_dictionary.h"

int main() {
    Dictionary<int, int> a;
    a.insert(10, 10);
    a.insert(20, 20);
    a.insert(30, 30);
    a.insert(40, 40);
    a.insert(50, 50);
    a.dispIn();
    a.remove(30);
    a.dispPre();
    a.insert(50, 90);
    a.dispIn();
    std::cout << std::endl;
    if(a.find(10) == true) std::cout << "node with key 10 does exist" << std::endl;
    if (a.find(30) == false) std::cout << "node with key 30 does not exist" << std::endl;
    return 0;
}
