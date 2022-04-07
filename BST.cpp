#include <iostream>
#include "BST Functions.h"

int main(){
    node<int> n;
    n.inOrderWalk(30);
    n.inOrderWalk(70);
    n.inOrderWalk(80);
    n.inOrderWalk(10);
    n.inOrderWalk(20);

    n.inOrderWalk();
    return 0;
}
