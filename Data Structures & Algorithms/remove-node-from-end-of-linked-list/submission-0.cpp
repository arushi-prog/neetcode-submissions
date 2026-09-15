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

// Brute force 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        while(temp != nullptr){
            count++;
            temp = temp -> next;
        }

        if(n == count){
            ListNode* delNode = head;
            head = head -> next;
            delete delNode;
            return head;
        }

        int steps = count - n - 1;
        temp = head;
        while(steps--){
            temp = temp -> next;
        }

        ListNode* delNode = temp -> next;
        temp->next = temp->next->next;
        delete delNode;

        return head;
    }
};
