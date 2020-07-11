#include <iostream>
#include "BinaryTree.h"
using namespace std;


void BinaryTree::insert(ElementType data, TreeNode*& tree)
{
    if (tree == NULL)
    {
        tree = new TreeNode(data);
    }
    else if (data < tree->data)
        insert(data, tree->left);
    else if (data > tree->data)
        insert(data, tree->right);
    else if (data == tree->data)
        tree->count++;

}

void BinaryTree::display(TreeNode* tree, ostream& out)
{
    if (tree != NULL)
    {
        display(tree->left, out);
       
        out << tree->data << " ";

        string myVar = tree->data + " ";

        cout << myVar << endl;
        display(tree->right, out);




    }

}


