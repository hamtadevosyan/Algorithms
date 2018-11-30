#include <iostream>

struct Node
{
    Node *m_left;
    Node *m_right;
    int m_value;
    Node(int pVal):m_value(pVal), m_left(NULL), m_right(NULL) {}
};

bool areIdentical(Node *t1, Node *t2) {
    if(t1 == NULL && t2 == NULL)
        return true;
    if(t1 == NULL || t2 == NULL)
        return false;
    return (t1->m_value == t2->m_value && areIdentical(t1->m_left, t2->m_left) && areIdentical(t1->m_right, t2->m_right));
}

bool isSubtree(Node *pTree, Node *pSubT) {
    if(pSubT == NULL)
        return true;
    if(pTree == NULL)
        return false;
    if(areIdentical(pTree, pSubT))
        return true;
    return (isSubtree(pTree->m_left, pSubT) || isSubtree(pTree->m_right, pSubT));
}

bool areEqual(Node *t1, Node * t2) {
    if(!t1 && !t2)
        return true;
    if(t1 && t2) {
        if(t1->m_value == t2->m_value) {
            return (areEqual(t1->m_left, t2->m_left) && areEqual(t1->m_right, t2->m_right));
        } else {
            return false;
        }
    } else {
        return false;
    }
}

int main() 
{
    return 0;
}
