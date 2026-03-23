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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return nullptr;
        while(lists.size() > 1){
            vector<ListNode*> temp;
            for(int i = 0; i < lists.size(); i += 2){
                ListNode* l1 = lists[i];
                ListNode* l2 = (i + 1) >= lists.size()? nullptr : lists[i + 1];
                temp.push_back(mergeTwoLists(l1, l2));
            }
            lists = move(temp);
        }
        return lists[0];
    }

private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
        ListNode dummy;
        ListNode* curr = &dummy;
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val <= l2->val){
                curr->next = l1;
                l1 = l1->next;
            }else{
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        curr->next = l1? l1 : l2;
        return dummy.next;
    }
};