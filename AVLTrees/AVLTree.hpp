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
    const T ITEM_NOT_FOUND;
    const T elementAt(const AVLNode<T>* node);
    const void insert(const T &x, AVLNode<T>* &node);
    const AVLNode<T>* findMax(AVLNode<T>* node);
    const AVLNode<T>* findMin(AVLNode<T>* node);
    const AVLNode<T>* find(const T &x, AVLNode<T>* node);
    const void makeEmpty(AVLNode<T> *node);
    const void printTree(AVLNode<T>* node);
    const void printTreeDepth(AVLNode<T>* node, int depth);
    int height(AVLNode<T>* Node);
    const void LLRotation(AVLNode<T>* &node);
    const void LRRotation(AVLNode<T>* &node);
    const void RLRotation(AVLNode<T>* &node);
    const void RRRotation(AVLNode<T>* &node);
public:
    AVLTree(const T &notFound);
    const T & findMax();
    const T & findMin();
    const T & find(const T & x);
    const bool isEmpty();
    const void printTree();
    const void printTreeDepth();
    void makeEmpty();
    void insert(const T &x);
    void remove(const T &x);
    
    
};

#endif /* AVLTree_hpp */

