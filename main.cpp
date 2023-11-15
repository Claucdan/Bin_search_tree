#include <iostream>
#include "cmake-build-debug/Binary_tree.h"
int main() {
    Binary_tree tree;
    std::string line;
    int key;
    while (std::cin>>line){
        switch (line[0]) {
            case 'i':
                std::cin>>key;
                tree.insert(key);
                break;
            case 'd':
                std::cin>>key;
                tree.deleteT(key);
                break;
            case 'e':
                std::cin>>key;
                std::cout<<tree.search(key)<<"\n";
                break;
            case 'n':
                std::cin>>key;
                std::cout<<tree.next(key)<<"\n";
                break;
            case 'p':
                std::cin>>key;
                std::cout<<tree.prev(key)<<"\n";
                break;
        }
    }
    return 0;
}
