//
// Created by dania on 15.11.2023.
//

#ifndef BIN_SEARCH_TREE_BINARY_TREE_H
#define BIN_SEARCH_TREE_BINARY_TREE_H
#include <string>
struct Node{
    int data;
    Node* left= nullptr;
    Node* right= nullptr;
    Node* parent= nullptr;
    Node(int &data,Node* parent){
        this->data=data;
        this->parent=parent;
    }
};
class Binary_tree {
private:
    Node* root;
    Node* max(Node* temp);
    Node* min(Node* temp);

    Node* _search(Node* temp,int data);
    Node* _insert(Node* temp,int data);
    Node* _next(int data);
    Node* _next(Node* temp);
    Node* _prev(int data);
    Node* _delete(Node* root,int data);
public:
    Binary_tree();
    void insert(int data);
    void deleteT(int data);
    std::string search(int data);
    std::string next(int data);
    std::string prev(int data);
};


#endif //BIN_SEARCH_TREE_BINARY_TREE_H
