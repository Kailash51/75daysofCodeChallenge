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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == 0) return list2;
         if(list2 == 0) return list1;
        
        ListNode* ans = new ListNode(-1);
       ListNode* mergePtr = ans;

        while(list1 && list2){
            if(list1->val <= list2->val){
                mergePtr->next = list1;
                list1 = list1->next;
            }
            else{
                mergePtr->next = list2;
                list2 = list2->next;
            }
            mergePtr = mergePtr ->next;
        }

        while(list1){
            mergePtr->next = list1;
            // mergePtr = list1;
            list1 = list1->next;
            mergePtr = mergePtr ->next;
        }
        while(list2){
            mergePtr->next = list2;
            // mergePtr = list2;
            list2 = list2->next;
            mergePtr = mergePtr ->next;
        }
        return ans->next;
        
    }
};