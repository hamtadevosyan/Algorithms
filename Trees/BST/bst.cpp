#include <iostream>

struct Node
{
    Node *m_left;
    Node *m_right;
    int m_value;
    Node(int pVal):m_left(nullptr), m_right(nullptr), m_value(pVal) {}
};

class BST
{
private:
    Node *m_root = nullptr;
    int m_size = 0;
    void addHelper(Node *pRoot, int pVal);
    Node *getNodeHelper(Node *pRoot, int pVal);
    void printTreeHelper(Node *pRoot);
public:
    void addElement(int pVal);
    Node *getNode(int pVal);
    Node *findMinElement(Node *pRoot);
    inline Node *getRoot() { return m_root; }
    Node *removeElement(Node *pRoot, int pVal);
    void printTree();
    inline int getSize() { return m_size; }
};

Node *BST::findMinElement(Node *pRoot) {
    if(pRoot == nullptr)
        return pRoot;
    Node *lResult = pRoot;
    while(lResult->m_left != nullptr)
        lResult = lResult->m_left;
    return lResult;
}

Node *BST::removeElement(Node *pRoot, int pVal) {
    if(pRoot == nullptr)
        return pRoot;
    if(pRoot->m_value > pVal) {
        pRoot->m_left = removeElement(pRoot->m_left, pVal);
    } else if (pRoot->m_value < pVal) {
        pRoot->m_right = removeElement(pRoot->m_right, pVal);
    } else {
        if(pRoot->m_right == nullptr) {
            Node *tmp = pRoot->m_left;
            delete pRoot;
            return tmp;
        } else if(pRoot->m_left == nullptr) {
            Node *tmp = pRoot->m_right;
            delete pRoot;
            return tmp;
        }
        Node *min = findMinElement(pRoot->m_right);
        pRoot->m_value = min->m_value;
        pRoot->m_right = removeElement(pRoot->m_right, min->m_value);
    }
    return pRoot;

}

void BST::addHelper(Node *pRoot, int pVal) {
        if(pRoot->m_value > pVal) {
            if(pRoot->m_left != nullptr) {
                addHelper(pRoot->m_left, pVal);
            } else {
                pRoot->m_left = new Node(pVal);
            }
        } else if(pRoot->m_value < pVal) {
            if(pRoot->m_right != nullptr) {
                addHelper(pRoot->m_right, pVal);
            } else {
                pRoot->m_right = new Node(pVal);
            }
        } else {
            std::cout << "Node with value : " << pVal << " already exists." << std::endl;
            //return;
        }
}

void BST::addElement(int pVal) {
    if(m_root != nullptr) {
        addHelper(m_root, pVal);
    } else {
       m_root = new Node(pVal);
    }
}

Node *BST::getNode(int pVal)
{
    return getNodeHelper(m_root, pVal);
}

Node *BST::getNodeHelper(Node *pRoot, int pVal)
{
    if(pRoot != nullptr) {
        if(pRoot->m_value == pVal) {
            return pRoot;
        } else if(pRoot->m_value > pVal) {
            return getNodeHelper(m_root->m_left, pVal);
        } else if(pRoot->m_value < pVal) {
            return getNodeHelper(m_root->m_right, pVal);
        }
    } else {
        return pRoot;
    }
}
void BST::printTreeHelper(Node *pRoot) 
{
    if(pRoot != nullptr) {
        std::cout << pRoot->m_value << std::endl;
        printTreeHelper(pRoot->m_left);
        printTreeHelper(pRoot->m_right);
    } else {
  //      return;
    }
}

void BST::printTree() 
{
    printTreeHelper(m_root);
}

int main()
{
    Node k(8);
    BST lTree;
    lTree.addElement(5);
    lTree.addElement(4);
    lTree.addElement(3);
    lTree.addElement(2);
    lTree.addElement(1);
    lTree.addElement(6);
    lTree.addElement(7);
    lTree.addElement(8);
    lTree.addElement(0);
    lTree.addElement(9);
    lTree.addElement(5);
    lTree.printTree();
    std::cout << "min element = " << (lTree.findMinElement(lTree.getRoot()))->m_value << std::endl;
    lTree.removeElement(lTree.getRoot(), 5);
    lTree.removeElement(lTree.getRoot(), 8);
    lTree.removeElement(lTree.getRoot(), 0);
    lTree.removeElement(lTree.getRoot(), 1);
    lTree.removeElement(lTree.getRoot(), 7);
    lTree.removeElement(lTree.getRoot(), 9);
    std::cout << "min element = " << (lTree.findMinElement(lTree.getRoot()))->m_value << std::endl;
    lTree.printTree();
    return 0;
}
