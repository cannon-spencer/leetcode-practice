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
        bool hasCycle(ListNode *head) {
            // we could use a hash map to keep track of visited nodes but this requires
            // O(n) extra space. So instead we will use a two pointer solution with a fast
            // and slow pointer. If they ever meet there is a cycle.
    
            /*
            if(head == nullptr) return false;
    
            ListNode* slow = head;
            ListNode* fast = head->next;
    
            while(fast != nullptr && fast->next != nullptr && fast->next->next != nullptr){
                if(fast == slow)
                    return true;
                
                slow = slow->next;
                fast = fast->next->next;
            }
    
            return false;
            */
    
    
            unordered_map<ListNode*, int> visitedNodes;
    
            while(head != nullptr){
                // check if node has been visited before, post inc
                if(visitedNodes[head]++ > 1)
                    return true;
                    
                head = head->next;
    
            }
    
            return false;
        }
    };