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
        ListNode *head = nullptr;
        ListNode **pos = nullptr;
        int k = lists.size();
        while(1){
            ListNode **maxi = nullptr;
            for(int i = 0; i < k; i++){
                if(lists[i] != nullptr){
                    if(maxi == nullptr || lists[i]->val < (*maxi)->val){
                        maxi = &lists[i];
                    }
                }
            }
            if(maxi == nullptr)
                break;
            
            if(head == nullptr){
                head = *maxi;
                pos = &((*maxi)->next);
            }
            else{
                *pos = *maxi;
                pos = &((*maxi)->next);
            }

            *maxi = (*maxi)->next;

        }
        return head;
    }
};
