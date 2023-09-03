#pragma once
#include<iostream>
#include<queue>
#include<limits>
using namespace std;

typedef int ElementaryTyp;

class BST_Node {
    friend class BST;

public:

    BST_Node(ElementaryTyp data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }

private:

    ElementaryTyp data;
    BST_Node* left;
    BST_Node* right;
};

class BST {
public:

    BST(ElementaryTyp data = INT_MIN): root(nullptr) {
        this->root= Insert(root,data);
    }

    BST_Node* getNode() {
        return this->root;
    }

    void Insert(ElementaryTyp data) {
        this->root = Insert(root, data);
    }

    bool Search(ElementaryTyp data) {
        return Search(root, data);
    }

    ElementaryTyp SearchMax() {
        return SearchMax(root);
    }

    ElementaryTyp SearchMin() {
        return SearchMin(root);
    }

    size_t SearchHeight() {
        return SearchHeight(root);
    }

    void LevelOrder() {
        LevelOrder(root);
        cout << endl;
    }

    void Preorder() {
        Preorder(root);
        cout << endl;
    }

    void Inorder() {
        Inorder(root);
        cout << endl;
    }

    void Postorder() {
        Postorder(root);
        cout << endl;
    }

    bool IsBinarySearchTree() {
        return IsBinarySearchTree(root, INT_MIN, INT_MAX);
    }

    BST_Node* Delete(int value) {
        return  Delete(root, value);
    }

    BST_Node* Getsuccessor(int data) {
        return Getsuccessor(root, data);
    }
private:

    BST_Node* getNewNode(ElementaryTyp data) {
        BST_Node* newNode = new BST_Node(data);
        return newNode;
    }

    BST_Node* Insert(BST_Node* root, ElementaryTyp data) {
        if (root == nullptr||root->data==INT_MIN) {
            return getNewNode(data);
            Delete(INT_MIN);
        }
        else if (data <= root->data) {
            root->left = Insert(root->left, data);
        }
        else {
            root->right = Insert(root->right, data);
        }
        return root;
    }

    bool Search(BST_Node* root, ElementaryTyp data) {
        if (root == nullptr) {
            return false;
        }
        else if (root->data == data) {
            return true;
        }
        else if (data <= root->data) {
            return Search(root->left, data);
        }
        else {
            return Search(root->right, data);
        }
    }

    BST_Node* Find(BST_Node* root, ElementaryTyp data) {
        if (root == nullptr) {
            return nullptr;
        }
        else if (root->data = data) {
            return root;
        }
        else if (data <= root->data) {
            return Find(root->left, data);
        }
        else {
            return Find(root->right, data);
        }
    }

    ElementaryTyp SearchMax(BST_Node* root) {
        if (root == nullptr) {
            cout << "ERROR: The tree is empty" << endl;
            return numeric_limits<ElementaryTyp>::min();
        }
        else if (root->right == nullptr) {
            return root->data;
        }
        else {
            return SearchMax(root->right);
        }
    }

    ElementaryTyp SearchMin(BST_Node* root) {
        if (root == nullptr) {
            cout << "ERROR: The tree is empty" << endl;
            return numeric_limits<ElementaryTyp>::max();
        }
        else if (root->left == nullptr) {
            return root->data;
        }
        else {
            return SearchMin(root->left);
        }
    }

    BST_Node* SearchMinAddressAtRightSubtree(BST_Node* root) {
        if (root == nullptr||root->right == nullptr)return root;
        else return SearchMinAddressAtRightSubtree(root->right);
        }

    size_t SearchHeight(BST_Node* root) {
        if (root == nullptr) {
            return 0;
        }
        return max(SearchHeight(root->left), SearchHeight(root->right)) + 1;
    }

    void LevelOrder(BST_Node* root) {
        if (root == NULL)  return;
        queue<BST_Node*>Q;
        Q.push(root);
        while (!Q.empty()) {
            BST_Node* current = Q.front();
            cout << current->data << " ";
            if (current->left != NULL)Q.push(current->left);
            if (current->right != NULL)Q.push(current->right);
            Q.pop();
        }
    }

    void Preorder(BST_Node* root) {
        if (root == NULL)return;
        cout << root->data << " ";
        Preorder(root->left);
        Preorder(root->right);
    }

    void Inorder(BST_Node* root) {
        if (root == NULL)return;
        Inorder(root->left);
        cout << root->data << " ";
        Inorder(root->right);
    }

    void Postorder(BST_Node* root) {
        if (root == NULL)return;
        Postorder(root->left);
        Postorder(root->right);
        cout << root->data << " ";
    }

    bool IsBinarySearchTree(BST_Node* root, int minValue, int maxValue) {
        if (root == NULL)return true;
        if (root->data >= minValue && root->data <= maxValue && IsBinarySearchTree(root->left, minValue, root->data) && IsBinarySearchTree(root->right, root->data, maxValue)) {
            return true;
        }
        else return false;
    }                                            

    BST_Node* Delete(BST_Node*root,int data) {
        if (root == NULL)return root;
        else if (data < root->data) {
            root->left=Delete(root->left, data);
        }
        else if(data > root->data) {
            root->right = Delete(root->right, data);
        }
        else {
            //no child
            if (root->left == NULL && root->right == NULL) {
                delete root;
                root = NULL;
            }
            //one right child
            else if (root->left == NULL) {
                BST_Node* temp = root;
                root = root->right;
                delete temp;
                temp = NULL;
            }
            //ont left child
            else if (root->right == NULL) {
                BST_Node* temp = root;
                root = root->left;
                delete temp;
                temp = NULL;
                return root;
            }
            //two child
            else {
                //将删除节点的右子树中的最小值覆盖当前节点的值，然后将问题简化成删除当前节点的右子树的最小节点
                BST_Node* temp = SearchMinAddressAtRightSubtree(root->right);
                root->data = temp->data;
                root->right = Delete(root->right, temp->data);
            }
        }
        return root;
    }

    BST_Node* Getsuccessor(BST_Node* root, int data) {
        BST_Node* current = Find(root, data);
        if (current == NULL) return NULL;
        //1.The Node has a right subtree
        if (current->right != NULL) {
            return SearchMinAddressAtRightSubtree(current->right);
        }
        //2.No right subtree
        else {
            BST_Node* successor = NULL;
            BST_Node* ancestor = root;
            while (ancestor != successor) {
                if (current->data < ancestor->data) {
                    successor = ancestor;
                    ancestor = ancestor->left;
                }
                else {
                    ancestor = ancestor->right;
                }
                return successor;
            }
        }
    }

    BST_Node* root;
};
