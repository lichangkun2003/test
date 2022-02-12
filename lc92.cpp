#include <iostream>
#include <vector>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if( left >= right )
            return head;
        ListNode* dummyhead = new ListNode( 0 , head );
        ListNode * l = dummyhead , * beforel ;
        while( left ){
            beforel = l;
            l = l->next;
            left--;
            right--;
        }
        ListNode* r = l->next , * afterr = r->next; 
        while( right - 1 > 0 ){
            r->next = l ;
            l = r;
            r = afterr;
            afterr = r->next;
            right--;
        }
        r->next = l;
        beforel->next->next = afterr;
        beforel->next = r;
        return dummyhead->next;
    }
};