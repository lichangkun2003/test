#include <stack>
#include <vector>
#include <deque>
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyhead = new ListNode( -1 , head );
        ListNode  * cur = dummyhead , * begin = dummyhead;
        int n = 0 ;
        while( cur != nullptr ){  
            cur = cur->next;
            n++;
            if( cur == nullptr )
                break;
            if( n == k ){
                ListNode * p1 = begin->next, * p2 = p1->next , *next = begin->next;
                while( p1 != cur ){
                    ListNode *tmp = p2->next;
                    p2->next = p1;
                    p1 = p2;
                    p2 = tmp;
                }
                begin->next->next = p2;
                begin->next = cur;
                n = 0;
                begin = cur = next;
            }
        }
        return dummyhead->next;
    }
};