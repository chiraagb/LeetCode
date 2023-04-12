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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k==1) return head;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode*curr = dummy;
        ListNode*pre = dummy;
        ListNode*nex = dummy;
        
        int count = 0;
       
        while(curr->next!=NULL){
            count++;
            curr=curr->next;
        }
        // int group = n/k; // For eg 1 : 5/2 = 2 : 2 groups of size 2
        // Reversing k-1 links of each group
        
        while(count>=k){
            curr = pre->next;
            nex = curr->next;
            for(int i=1;i<k;i++){
                curr->next=nex->next;
                nex->next = pre->next;
                pre->next=nex;
                nex= curr->next;
            }
            pre=curr;
            count-=k;
        }
        return dummy->next;
        
    }
};