//
//  AVLTree.cpp
//  AVLTrees
//
//  Created by Udit Samani on 6/3/19.
//  Copyright © 2019 Udit Samani. All rights reserved.
//

#include "AVLTree.hpp"
#include <iostream>

template <class T>
AVLTree<T>::AVLTree(const T & notFound):
    ITEM_NOT_FOUND(notFound), root(nullptr)
{}

/**
 * Function to add element recursively into the AVLTree.
 */
template <class T>
void AVLTree<T>::insert(const T &x)
{
    insert(x, this->root);
}

/**
 * Find the maximum item in the tree.
 * Returns maximum item or ITEM_NOT_FOUND if empty.
 */
template <class T>
const T & AVLTree<T>::findMax()
{
    return elementAt(findMax(this->root));
}

/**
 * Find the minimum item in the tree.
 * Returns maximum item or ITEM_NOT_FOUND if empty.
 */
template <class T>
const T & AVLTree<T>::findMin()
{
    return elementAt(findMin(this->root));
}


/**
 * Find item x in the tree.
 * Return the matching item or ITEM_NOT_FOUND if not found.
 */
template <class T>
const T & AVLTree<T>::find(const T & x)
{
    return elementAt(find(x, this->root));
}


/**
 * Checks whether the tree is empty or not.
 * Returns True if tree us empty or else False.
 */
template <class T>
const bool AVLTree<T>::isEmpty()
{
    return this->root==nullptr;
}

/**
 * Print the contents of tree in the sorted order.
 */
template <class T>
const void AVLTree<T>::printTree()
{
    if (isEmpty())
    {
        std::cout << "Empty Tree." << std::endl;
    }
    else
    {
        printTree(this->root);
    }
}

/**
 * Prints tree indicating the depth.
 */
template <class T>
const void AVLTree<T>::printTreeDepth()
{
    if (isEmpty())
    {
        std::cout << "Empty Tree." << std::endl;
    }
    else
    {
        printTreeDepth(this->root, 0);
    }
}

/**
 * Internal method to get element at node.
 * Returns the element or ITEM_NOT_FOUND if node is nullptr.
 */
template <class T>
const T AVLTree<T>::elementAt(AVLNode<T> *node)
{
    return node==nullptr? ITEM_NOT_FOUND: node->element;
}

/**
 * Internal method to insert node in an AVLTree.
 * x is the item to insert.
 * node is the the root of the tree where the item is to be inserted.
 * DUPLICATES ARE DISCARDED AND NOT CONSIDERED.
 */
template <class T>
const void AVLTree<T>::insert(const T &x, AVLNode<T>* &node)
{
    if(node==nullptr)
    {
        node = new AVLNode<T>(x, nullptr, nullptr);
    }
    else if (x < node->element)
    {
        insert(x, node->lchild);
        if(height(node->lchild)-height(node->rchild)==2)
        {
            if(x < node->lchild->element)
            {
                LLRotation(node);
            }
            else
            {
                LRRotation(node);
            }
        }
    }
    else if (x > node->element)
    {
        insert(x, node->rchild);
        if(height(node->rchild)-height(node->lchild)==2)
        {
            if(x < node->rchild->element)
            {
                RLRotation(node);
            }
            else
            {
                RRRotation(node);
            }
        }
    }
    node->height = std::max(height(node->lchild),height(node->rchild))+1;
}

