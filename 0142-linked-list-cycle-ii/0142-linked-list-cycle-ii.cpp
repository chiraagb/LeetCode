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
    ListNode *floydDetectionLoop(ListNode *head){
        if(head == NULL || head->next==NULL) return NULL;
        
        ListNode*s = head;
        ListNode*f = head;
        
        while(f->next && f->next->next){
            s = s->next;
            f = f->next->next;
            if(s==f){
                return s;
            }
        }
        return NULL;
    }
    ListNode *detectCycle(ListNode *head) {
         // Step 1: find s==f
        // Step 2: find entry==s //this is a cycle
        
        if(head == NULL || head->next==NULL) return NULL;
        
        ListNode *s = floydDetectionLoop(head);
        if(s == NULL) return NULL;
        ListNode *entry = head;
        while(s != entry){
            s = s->next;
            entry=entry->next;
        }
        return s;
        
    }
};