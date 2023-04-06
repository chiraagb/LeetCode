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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return NULL;

        int cnt = 0;
        ListNode* curr = head;

        while(curr!=NULL){
            cnt++;
            curr=curr->next;
        }
        if(cnt == n){
            ListNode *temp = head;
            temp= temp->next;
            delete(head);
            return temp;
        }

        int nodeToDelete = cnt - n;
        
        
        cnt = 1;
        ListNode *temp1 = head;
        while(cnt !=nodeToDelete){
            temp1 = temp1->next;
            cnt++;
        }
        ListNode *var = temp1->next;
        temp1->next = temp1->next->next;
        delete(var);
        return head;
        
    }
};