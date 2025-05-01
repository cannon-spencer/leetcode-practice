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
    // you could reconstruct the numbers then find the solution and put that into a new linked list
    // but you can also algorithmicly reconstruct the addition by summing both elemetns at the same time
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        // create listnode, we need to hold onto the head for submission
        ListNode head(0);
        ListNode* current = &head;

        int carry = 0, sum = 0;

        // loop if any linked list isnt at the end or if we have a carry
        while(l1 != nullptr || l2 != nullptr || carry != 0){
            sum = carry; // reset sum
            
            // add each index to the sum, then the carry from the prev answer
            if(l1 != nullptr){
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != nullptr){
                sum += l2->val;
                l2 = l2->next;
            }

            // add the 0-9 digit of sum
            current->next = new ListNode(sum % 10);
            current = current->next;

            // collect whatever is leftover in the carry
            carry = sum / 10; 
        }

        return head.next;
    }
};
