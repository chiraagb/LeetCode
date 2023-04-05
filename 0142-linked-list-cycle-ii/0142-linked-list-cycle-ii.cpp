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
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL || head->next==NULL) return NULL ;
        unordered_map<ListNode*,bool> mp;
        
        ListNode *curr = head;
        while(curr!=NULL){
            if(mp[curr] == true){
                return curr;
            }
            mp[curr] = true;
            curr=curr->next;
        }
        return NULL;
    }
};