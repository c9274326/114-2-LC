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
        ListNode* dummy = head;
        for(int i = 0; i < k; i++){
            if(dummy == nullptr) return head;
            dummy = dummy->next;
        }
        ListNode* curr = head;
        ListNode* prev = nullptr;
        ListNode* next = nullptr;
        for(int i = 0; i < k; i++){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            
        }
        head->next = reverseKGroup(curr, k);
        return prev;
    }
};