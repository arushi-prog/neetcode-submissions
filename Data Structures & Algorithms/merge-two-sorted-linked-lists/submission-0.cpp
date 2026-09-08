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
        vector<int> arr;
        ListNode* temp = list1;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        temp = list2;
        while(temp != nullptr){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        sort(arr.begin(), arr.end());

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        for (int x : arr) {
            curr->next = new ListNode(x);
            curr = curr->next;
        }

        return dummy->next;

    }
};
