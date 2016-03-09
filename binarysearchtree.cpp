#include "binarysearchtree.h"
#include "binarytree.cpp"

template <class T>
BinarySearchTree<T>::BinarySearchTree() : BinaryTree<T>()
{
}

template <class T>
BinarySearchTree<T>::BinarySearchTree(const T& rootItem) : BinaryTree<T>(rootItem)
{
}

template <class T>
BinarySearchTree<T>::~BinarySearchTree()
{
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::findAt(BinaryNode<T> * node, const T& anItem) const
// Retrieves an item starting searching at node
{
    if (node == NULL) {      // Then the item was not found
        return NULL;
    }
    else if (anItem == node->item) { // Then found
        return node;
    }
    else if (anItem < node->item) {  // Search in the left tree
        return (findAt(node->leftChild, anItem));
    }
    else {                            // Search in the right tree
        return (findAt(node->rightChild, anItem));
    }
}


// TODO: Implement!


template <class T>
BinaryNode<T>* BinarySearchTree<T>::find(const T& anItem) const // Retrieves the node corresponding to the item. If not found, returns null
{
    return (findAt(BinaryTree<T>::root, anItem));
}

// Return the node with the highest value
template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode() const
{
    return maxNode(BinaryTree<T>::root);
}

// Return the node with the lowest value
template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode() const
{
    return minNode(BinaryTree<T>::root);
}

//Insert Node -- uses insertat
template <class T>
void BinarySearchTree<T>::insert(const T& anItem)
{
    insertAt(BinaryTree<T>::root, anItem);
}

//Remove node -- uses removeat
template <class T>
void BinarySearchTree<T>::remove(const T& anItem)
{
    removeAt(BinaryTree<T>::root, anItem);
}

// Private!

template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode(BinaryNode<T>* node) const
{
    if(node == NULL){
        return NULL;
    }
    else if (node->rightChild == NULL){
        return (node);
    }
    return maxNode(node->rightChild);
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode(BinaryNode<T>* node) const
{
    if(node == NULL){
        return NULL;
    }
    else if (node->leftChild == NULL){
        return (node);
    }
    return minNode(node->leftChild);
}

template <class T>
void BinarySearchTree<T>::insertAt(BinaryNode<T>*& node, const T& anItem)
{
    if(node == NULL){
        node = new BinaryNode<T>(anItem);
    }
    else if(anItem < node->item){
        return insertAt(node->leftChild, anItem);
    }
    else if(anItem > node->item){
        return insertAt(node->rightChild, anItem);
    }
    
    
}

template <class T>
void BinarySearchTree<T>::removeAt(BinaryNode<T>*& node, const T& anItem)
{
    /*
    if(node->rightChild == NULL && node->leftChild == NULL){
        //delete
    }
    find(anItem);
     */
    if(node == NULL){
        return;
    }
    else if (anItem == node->item) { // Then found
        removeNode(node);
    }
    else if (anItem < node->item) {  // Search in the left tree
        return (removeAt(node->leftChild, anItem));
    }
    else {                            // Search in the right tree
        return (removeAt(node->rightChild, anItem));
    }
}

template <class T>
void BinarySearchTree<T>::removeNode(BinaryNode<T>*& node)
{
    
    //Chase 1
    if(node->isLeaf()){
        BinaryNode<T>* tmp = node;
        delete tmp;
        node = NULL;
    }
    
    //Chase 2
    else if((node->leftChild != NULL && node->rightChild == NULL)||(node->leftChild == NULL && node->rightChild != NULL)){
        
        BinaryNode<T>* tmp = node;
        
        if(node->leftChild == NULL){
            node = tmp->rightChild;
        }
        else{
            node = tmp->leftChild;
        }
        
        delete tmp;
    }
    
    //Chase 3
    else if(!node->isLeaf()){
        node->item = processLeftmost(node->rightChild);
    }
}

template <class T>
T BinarySearchTree<T>::processLeftmost(BinaryNode<T>*& node)
{
    if(node->leftChild == NULL){
        T value = node->item;
        BinaryNode<T>* tmp = node;
        node = tmp->rightChild;
        delete tmp;
        return value;
    }
    else
        return processLeftmost(node->leftChild);
}

