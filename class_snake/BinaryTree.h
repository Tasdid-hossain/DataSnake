#include <iostream>
#include <string>
#include <fstream>
#include <fstream>

using namespace std;

#ifndef TREENODE_H
#define TREENODE_H

typedef std::string ElementType;

class BinaryTree
{
public:
    class TreeNode
    {
    public:
        ElementType data;
        int count = 0;
        TreeNode* left;
        TreeNode* right;
        TreeNode(ElementType new_data)
        {
            data = new_data; left = NULL; right = NULL;
        };
    };
    TreeNode* root;
    BinaryTree(ElementType root_data)
    {
        root = new TreeNode(root_data);
    };
    ~BinaryTree() { delete root; };
    void insert(ElementType data, TreeNode*& tree);
    void display(TreeNode* tree, ostream& out);
   
};

#endif TREENODE_H

