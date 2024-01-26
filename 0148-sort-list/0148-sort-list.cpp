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
 
 ListNode* findMid(ListNode*head){
     ListNode*slow = head;
     ListNode*fast= head->next;
     while(fast && fast->next){
             fast = fast->next->next;
             slow = slow->next;
         
     }
     return slow;
 }

     ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {

        // when list1 is empty then 
        // our output will be same as list2
        if(l1 == NULL) return l2; 

        // when list2 is empty then our output 
        // will be same as list1
        if(l2 == NULL) return l1;

        // pointing l1 and l2 to smallest and greatest one
        if(l1->val > l2->val) std::swap(l1,l2);

        // act as head of resultant merged list
        ListNode* res = l1;

        while(l1 != NULL && l2 != NULL) {
 
            ListNode* temp = NULL;

            while(l1 != NULL && l1->val <= l2->val) {

                temp = l1;//storing last sorted node  
                l1 = l1->next;
            }

            // link previous sorted node with 
            // next larger node in list2
            temp->next = l2;
            std::swap(l1,l2);
        }

        return res;
    }

    ListNode* sortList(ListNode* head) {
    if(head == 0 || head -> next == 0){
        return head;

    }

    //divide LL into two halves;
    ListNode* mid = findMid(head);
    ListNode* left = head;
    ListNode* right = mid->next;
    mid->next = NULL;

    // sort RE
    left = sortList(left);
    right = sortList(right);

    // merge both right nad left

    ListNode* mergeLL = mergeTwoLists(left, right);
    return mergeLL;
    }
};