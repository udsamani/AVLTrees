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
const T AVLTree<T>::elementAt(const AVLNode<T> *node)
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


/**
 * Internal function to find the maximum item in a subtree with root node.
 * Return node containing the largest item.
 */
template <class T>
const AVLNode<T>* AVLTree<T>::findMax(AVLNode<T> *node)
{
    if(node==nullptr)
        return node;
    
    while(node->rchild!=nullptr)
    {
        node = node->rchild;
    }
    return node;
}


/**
 * Internal function to find the minimum item in a subtree with root node.
 * Return node containing the smallest item.
 */
template <class T>
const AVLNode<T> * AVLTree<T>::findMin(AVLNode<T> *node)
{
    if(node==nullptr)
        return node;
    
    while(node->lchild!=nullptr)
        node = node->lchild;
    
    return node;
}

/**
* Internal function to find an element.
* x is the element to be found.
* node is the root of the tree.
* Return node containing the element.
*/
template <class T>
const AVLNode<T> * AVLTree<T>::find(const T &x, AVLNode<T> *node)
{
    if(node==nullptr)
        return node;
    
    while(node!=nullptr)
    {
        if(x > node->element)
            node = node->rchild;
        else if (x == node->element)
            break;
        else
            node = node->lchild;
    }
    
    return node;
}

/**
 * I
 */
template <class T>
const void AVLTree<T>::printTree(AVLNode<T> *node)
{
    if (node!=nullptr)
    {
        printTree(node->lchild);
        std::cout << node->element << std::endl;
        printTree(node->rchild);
    }
}

/**
 * Internal function to print a subtree, indicating the depth.
 */
template <class T>
const void AVLTree<T>::printTreeDepth(AVLNode<T> *node, int depth)
{
    if (node!=nullptr)
    {
        printTreeDepth(node->rchild, depth+1);
        for(int i = 0; i < depth ; ++i)
        {
            std::cout << " ";
        }
        std::cout << node->element << std::endl;
        printTreeDepth(node->lchild, depth+1);
    }
}

/**
 * Internal function to perform LL Rotation.
 */
template <class T>
const void AVLTree<T>::LLRotation(AVLNode<T>* &node)
{
    AVLNode<T> *nodeLChild = node->lchild;
    node->lchild = nodeLChild->rchild;
    nodeLChild->rchild = node;
    node->height = std::max(height(node->lchild),height(node->rchild))+1;
    nodeLChild->height = std::max(height(nodeLChild->lchild), height(nodeLChild->rchild))+1;
    node = nodeLChild;
    
}

/**
 * Internal function to perform RR Rotation.
 */
template <class T>
const void AVLTree<T>::RRRotation(AVLNode<T>* &node)
{
    AVLNode<T> *nodeRChild = node->rchild;
    node->rchild = nodeRChild->lchild;
    nodeRChild->lchild = node;
    node->height = std::max(height(node->lchild),height(node->rchild))+1;
    nodeRChild->height = std::max(height(nodeRChild->lchild), height(nodeRChild->rchild))+1;
    node = nodeRChild;

}
/**
 * Internal function to perform RL Rotation.
 */

template <class T>
const void AVLTree<T>::RLRotation(AVLNode<T>* &node)
{
    RRRotation(node->lchild);
    LLRotation(node);
}

/**
 * Internal function to perform LR Rotation.
 */
template <class T>
const void AVLTree<T>::LRRotation(AVLNode<T>* &node)
{
    LLRotation(node->rchild);
    RRRotation(node);
}

/**
 * Internal function to return the height of the tree.
 * Returns -1 if node is nullptr or else the height.
 */
template <class T>
int AVLTree<T>::height(AVLNode<T> *node)
{
    return node==nullptr? -1 : node->height;
}
