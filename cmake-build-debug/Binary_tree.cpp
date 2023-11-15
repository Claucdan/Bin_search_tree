#include "Binary_tree.h"

Node *Binary_tree::max(Node *temp) {
    if(temp->right== nullptr)
        return temp;
    return max(temp->right);
}
Node *Binary_tree::min(Node *temp) {
    if(temp->left== nullptr)
        return temp;
    return min(temp->left);
}
Node *Binary_tree::_search(Node *temp, int data) {
    if(temp== nullptr || data==temp->data)
        return temp;
    if(data< temp->data)
        return _search(temp->left,data);
    else
        return _search(temp->right,data);
}
Node* Binary_tree::_insert(Node *temp, int data) {
    if (temp == NULL)
        return new Node(data, nullptr);
    if (data < temp->data)
        temp->left = _insert(temp->left, data);
    else if (data > temp->data)
        temp->right = _insert(temp->right, data);
    return temp;
}
Node *Binary_tree::_next(int data) {
    Node* current= root,*successor= nullptr;
    while(current!= nullptr){
        if(current->data>data){
            successor=current;
            current=current->left;
        }
        else
            current=current->right;
    }
    return  successor;
}
Node *Binary_tree::_next(Node *temp) {
    if(temp->right!= nullptr)
        return min(temp->right);
    Node* y=temp->parent;
    while(y!= nullptr && temp==y->right){
        temp=y;
        y=y->parent;
    }
    return y;
}
Node *Binary_tree::_prev(int data) {
    Node* current= root,*successor= nullptr;
    while(current!= nullptr){
        if(current->data>=data)
            current=current->left;
        else{
            successor=current;
            current=current->right;
        }

    }
    return  successor;
}
Node* Binary_tree::_delete(Node* root, int data) {
    if (root == NULL)
        return root;
    if (root->data > data) {
        root->left = _delete(root->left, data);
        return root;
    }
    else if (root->data < data) {
        root->right = _delete(root->right, data);
        return root;
    }
    if (root->left == NULL) {
        Node* temp = root->right;
        delete root;
        return temp;
    }
    else if (root->right == NULL) {
        Node* temp = root->left;
        delete root;
        return temp;
    }
    else {
        Node* succParent = root;
        Node* succ = root->right;
        while (succ->left != NULL) {
            succParent = succ;
            succ = succ->left;
        }
        if (succParent != root)
            succParent->left = succ->right;
        else
            succParent->right = succ->right;
        root->data = succ->data;
        delete succ;
        return root;
    }

}





Binary_tree::Binary_tree() {
    root= nullptr;
}

void Binary_tree::insert(int data) {
    if(root== nullptr) {
        root = new Node(data, nullptr);
        return;
    }
    _insert(root,data);
}

void Binary_tree::deleteT(int data) {
    root=_delete(root,data);
}

std::string Binary_tree::search(int data) {
    Node* buffer= _search(root,data);
    if(buffer== nullptr){
        return "false";
    }
    else{
        return "true";
    }
}

std::string Binary_tree::next(int data) {
    Node* buffer= _next(data);
    if(buffer== nullptr){
        return "none";
    }
    else{
        return std::to_string(buffer->data);
    }
}

std::string Binary_tree::prev(int data) {
    Node* buffer= _prev(data);
    if(buffer== nullptr){
        return "none";
    }
    else{
        return std::to_string(buffer->data);
    }
}