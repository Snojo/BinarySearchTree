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


template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode() const
{
    return 0;
}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode() const
{
    return 0;
}

template <class T>
void BinarySearchTree<T>::insert(const T& anItem)
{

}

template <class T>
void BinarySearchTree<T>::remove(const T& anItem)
{

}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::maxNode(BinaryNode<T>* node) const
{

}

template <class T>
BinaryNode<T>* BinarySearchTree<T>::minNode(BinaryNode<T>* node) const
{

}

template <class T>
void BinarySearchTree<T>::insertAt(BinaryNode<T>*& node, const T& anItem)
{

}

template <class T>
void BinarySearchTree<T>::removeAt(BinaryNode<T>*& node, const T& anItem)
{

}

template <class T>
void BinarySearchTree<T>::removeNode(BinaryNode<T>*& node)
{

}

template <class T>
T BinarySearchTree<T>::processLeftmost(BinaryNode<T>*& node)
{

}

