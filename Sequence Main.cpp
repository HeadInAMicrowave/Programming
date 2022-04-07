#include "Sequence.h"

int main(){
    Sequence<int, int> a;
    Sequence<int, int> y;
    a.insertAtBeginning(1, 2);
    a.insertAtBeginning(3, 4);
    a.insertAtBeginning(5, 6);
    a.insertAtBeginning(7, 8);
    a.insertAtBeginning(9, 0);

    a.insertAtBeginning(11, 12);
    a.insertAtBeginning(13, 14);
    a.insertAtBeginning(15, 16);
    a.insertAtBeginning(17, 18);
    a.insertAtBeginning(19, 10);

    produce<int, int>(a, 1, 2, y, 4, 1, 5).display(std::cout);
    return 0;
}