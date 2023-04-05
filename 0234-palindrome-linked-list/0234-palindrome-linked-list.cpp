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
    ListNode *reverseList(ListNode*head){
        ListNode *newHead = NULL;
        
        while(head!=NULL){
            ListNode *nextNode = head->next;
            head->next=newHead;
            newHead = head;
            head = nextNode;
        }
        return newHead;
    }
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        ListNode *s = head;
        ListNode*f = head;
        
        while(f->next && f->next->next){
            s=s->next;
            f=f->next->next;
        }
        s->next = reverseList(s->next);
        s = s->next;
        
        while(s!=NULL){
            if(s->val != head->val){
                return false;
            }
            s = s->next;
            head =head->next;
        }
        return true;
    }
};