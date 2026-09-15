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
// class Solution {
// public:
//     void reorderList(ListNode* head) {

//         vector<ListNode*> arr;

//         ListNode* temp = head;

//         // Store node addresses
//         while (temp != nullptr) {
//             arr.push_back(temp);
//             temp = temp->next;
//         }

//         int i = 0;
//         int j = arr.size() - 1;

//         // Rearrange the links
//         while (i < j) {

//             arr[i]->next = arr[j];
//             i++;

//             if (i == j) break;

//             arr[j]->next = arr[i];
//             j--;
//         }

//         // Very important: terminate the list
//         arr[i]->next = nullptr;
//     }
// };

// OPTIMAL APPROACH
class Solution {
public:
    void reorderList(ListNode* head) {

        if (head == nullptr || head->next == nullptr)
            return;

        // Step 1: Find the middle
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse the second half
        ListNode* prev = nullptr;
        ListNode* curr = slow->next;

        slow->next = nullptr;  // Break the list

        while (curr != nullptr) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;
            curr = next;
        }

        // prev is the head of reversed second half
        ListNode* second = prev;

        // Step 3: Merge alternatively
        ListNode* first = head;

        while (second != nullptr) {

            ListNode* firstNext = first->next;
            ListNode* secondNext = second->next;

            first->next = second;
            second->next = firstNext;

            first = firstNext;
            second = secondNext;
        }
    }
};
