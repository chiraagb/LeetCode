/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        /**
        Brute Force O(m+n) || O(n)
        **/
        
        int cntA = 0;
        int cntB = 0;
        ListNode *dummyA = headA;
        ListNode *dummyB = headB;
        
        while(dummyA!=NULL){
            cntA++;
            dummyA = dummyA->next;
        }
        while(dummyB!=NULL){
            cntB++;
            dummyB = dummyB->next;
        }
        
        int diff = abs(cntA-cntB);
        
        
        if(cntA>cntB){
            while(diff){
                headA = headA->next;
                diff--;
            }
        }
        
        else{
            while(diff){
                headB = headB->next;
                diff--;
            }
        }
        
        while(headA && headB){
            if(headA == headB) {
              return headA;  
            } 
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
        
        
    }
};