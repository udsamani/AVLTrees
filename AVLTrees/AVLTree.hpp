//
//  AVLTree.hpp
//  AVLTrees
//
//  Created by Udit Samani on 6/3/19.
//  Copyright © 2019 Udit Samani. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

template <class T>
class AVLTree;

template <class T>
class AVLNode
{
private:
    T element;
    AVLNode<T> *lchild;
    AVLNode<T> *rchild;
    int height;
public:
    AVLNode(const T &ele, AVLNode<T> *left, AVLNode<T> *right, int h=0): element(ele), lchild(left), rchild(right), height(h) {}
    friend class AVLTree<T>;
    
};

template <class T>
class AVLTree
{
private:
    AVLNode<T> *root;
    const T elementAt(AVLNode<T>* &node);
    const void insert(const T &x, AVLNode<T>* node);
    const T findMax(AVLNode<T>* node);
    const T findMin(AVLNode<T>* node);
    const T find(const T &x, AVLNode<T>* node);
    const void makeEmpty(AVLNode<T> *node);
    const void printTree(AVLNode<T>* node);
    
    
};

#endif /* AVLTree_hpp */

