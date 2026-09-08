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

// brute force using a hashset to store values 
// class Solution {
// public:
//     bool hasCycle(ListNode* head) {
//         unordered_set<ListNode*> visited;

//         ListNode* temp = head;
//         while(temp != nullptr){
//             if(visited.find(temp) != visited.end()){
//                 return true;
//             }
//             visited.insert(temp);

//             temp = temp -> next;
//         }
//         return false;
//     }
// };

// Optimal aproach -> fast and slow pointers
class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast != nullptr && fast->next != nullptr){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
