/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Write in the form of an integer
        ListNode *head = new ListNode(-1);
        ListNode *temp = head;
        
        int c=0;
        while(l1!=NULL || l2!=NULL || c){
            int s = 0;
            if(l1!=NULL){
                s = s+l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                s = s+l2->val;
                l2 = l2->next;
            }
           
            s = s+c;
            c = s/10;
            
            ListNode *sum = new ListNode(s%10);
           
            temp->next = sum ;
            temp = temp->next;
        }
        return head->next;
    }
};