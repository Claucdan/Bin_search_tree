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
void Binary_tree::_insert(Node *temp, int data) {
    if(te)
    while(temp!=nullptr)){
        if(temp->data<data){
            if(temp->right!= nullptr)
                temp=temp->right;
            else{
                Node* _new=new Node(data,temp);
                temp->right=_new;
                break;
            }
        }
        else{
            if(temp->left!= nullptr)
                temp=temp->left;
            else{
                Node* _new=new Node(data,temp);
                temp->left=_new;
                break;
            }
        }

    }
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
void Binary_tree::_delete( int data) {
    Node* buffer= _search(this->root,data);
    if(buffer== nullptr)
        return;
    Node*parent =buffer->parent;
    if(buffer->left== nullptr && buffer->right== nullptr){
        if(parent->right==buffer){
            delete buffer;
            parent->right= nullptr;
        }
        else{
            delete buffer;
            parent->left= nullptr;
        }
    }


    else if(buffer->left== nullptr || buffer->right== nullptr){
        if(buffer->left== nullptr){
            if(parent->right==buffer)
                parent->right=buffer->right;
            else
                parent->left=buffer->right;
            buffer->right->parent=buffer->parent;
            delete buffer;
        }
        else{
            if(parent->right==buffer)
                parent->right=buffer->left;
            else
                parent->left=buffer->left;
            buffer->left->parent=buffer->parent;
            delete buffer;
        }
    }

    else{
        Node* successor = _next(buffer);
        buffer->data=successor->data;
        if(successor->parent->left==successor){
            successor->parent->left=successor->right;
            if(successor->right!= nullptr)
                successor->right->parent=successor->parent;
        }
        else{
            successor->parent->right=successor->right;
            if(successor->right!= nullptr)
                successor->right->parent=successor->parent;
        }

    }

}





Binary_tree::Binary_tree() {
    root= nullptr;
}

void Binary_tree::insert(int data) {
    _insert(root,data);
}

void Binary_tree::deleteT(int data) {
    _delete(data);
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