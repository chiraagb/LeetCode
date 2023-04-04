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
    ListNode* middleNode(ListNode* head) {
        
        int cnt = 0;
        ListNode *curr = head;
        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        int mid = cnt/2; //0 based indexing
        if(mid==0) return head;
        ListNode *temp = head;
        while(--mid){
            temp=temp->next;
        }
        head = temp->next;
        return head;
        
    }
};