#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    unordered_map< Node* , Node* > copiedNode;
    Node* copyRandomList(Node* head) {
        if( head == nullptr )
            return nullptr;
        if( !copiedNode[head] ){
            Node* newHead = new Node( head->val );
            copiedNode[head] = newHead;
            newHead->next = copyRandomList( head->next);
            newHead->random = copyRandomList( head->random );
        }
        return copiedNode[head];
    }
};