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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        
        ListNode *curr = head;
        ListNode *pre = NULL;
        
        int count = 1;
        
        while(curr->next!=NULL){
            count++;
            pre = curr;
            curr = curr->next;
        }
        
        if(k>count){
            k=k%count;
        }
        while(k>0){
            curr =head;
            pre = NULL;
            while(curr->next!=NULL){
                pre = curr;
                curr=curr->next;
            }
            curr->next = head;
            pre->next = NULL;
            head = curr;
            k--;
        }
        return head;
    }
};