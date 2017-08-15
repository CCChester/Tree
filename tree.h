#ifndef _TREE_H_
#define _TREE_H_

class Tree{
    struct TreeNode;
    TreeNode *root;
public:
    Tree();
    ~Tree();
    void insert (int data);
    class Iterator {
        TreeNode *p;
        public:
            explicit Iterator(TreeNode *p): p{p} {}
            bool operator==(const Iterator &other);
            bool operator != (const Iterator &other);
            Iterator &operator++();
            int &operator*();
            friend class Tree;
    };
    Iterator begin(); 
    Iterator end();
};

#endif
