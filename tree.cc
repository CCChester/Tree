#include "tree.h"
#include <iostream> 

using namespace std;

struct Tree::TreeNode {
    int data;
    TreeNode *left, *right, *parent;
    enum class Kind {Left, Right, Root};
    Kind kind;
    TreeNode(int data, Kind kind, TreeNode *parent, TreeNode *left = nullptr, TreeNode *right = nullptr):
    data{data}, parent{parent}, left{left}, right{right}, kind{kind} {}
    ~TreeNode() {
        delete left;
        delete right;
    }
};

Tree::Tree(): root{nullptr} {}
Tree::~Tree() { delete root; }

void Tree::insert (int data) {
    if (!root) {
        root = new TreeNode(data, TreeNode::Kind::Root, nullptr);
        return;
    }
    TreeNode *cur = root;
    while (true) {
        if (cur->data == data) return;
        if (cur->data < data) {
            if (!cur->right) {
                cur->right = new TreeNode(data, TreeNode::Kind::Right, cur);
                return;
            }
            else {
                cur = cur->right;
            }
        }
        else if (cur->data > data) {
            if (!cur->left) {
                cur->left = new TreeNode(data, TreeNode::Kind::Left, cur);
                return;
            }
            else {
                cur = cur->left;
            }
        }
    }
}

int &Tree::Iterator::operator*(){return p->data;}

bool Tree::Iterator::operator==(const Iterator &other){
    return p == other.p;
}

bool Tree::Iterator::operator!=(const Iterator &other){
    return !(*this == other);
}

Tree::Iterator Tree::begin(){
    TreeNode *p = root;
    return Iterator(p);
}

Tree::Iterator Tree::end(){
    return Iterator(nullptr);
}


Tree::Iterator &Tree::Iterator::operator++(){
    if(p->left){
        p = p->right;
        if(p){
            while(p->left){
                p = p->left;
            }
        }
        else{p = p->parent;}
    }
    else if(p->right){
        p = p->right;
        if(p){
            while(p->left){
                p = p->left;
            }
        }
    }
    return *this;
}
