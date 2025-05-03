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
        ListNode head;
        ListNode* current = &head;

        // while either pointer is valid
        while(list1 || list2){
            
            int nextVal;
            if(list1 && list2){
                if(list1->val < list2->val){
                    nextVal = list1->val;
                    list1 = list1->next;
                } else {
                    nextVal = list2->val;
                    list2 = list2->next;
                }
                    
            } 
            
            // if just list1
            else if (list1){
                nextVal = list1->val;
                list1 = list1->next;
            } 
            
            // if just list2
            else {
                nextVal = list2->val;
                list2 = list2->next;
            }

            // write new node then switch current to point to that new node
            current->next = new ListNode(nextVal);
            current = current->next;

        }


        return head.next;
    }
};
