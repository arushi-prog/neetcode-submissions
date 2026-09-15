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

// BRUTE FORCE USING EXTRA MEMORY
class Solution {
public:
    void reorderList(ListNode* head) {

        vector<ListNode*> arr;

        ListNode* temp = head;

        // Store node addresses
        while (temp != nullptr) {
            arr.push_back(temp);
            temp = temp->next;
        }

        int i = 0;
        int j = arr.size() - 1;

        // Rearrange the links
        while (i < j) {

            arr[i]->next = arr[j];
            i++;

            if (i == j) break;

            arr[j]->next = arr[i];
            j--;
        }

        // Very important: terminate the list
        arr[i]->next = nullptr;
    }
};
