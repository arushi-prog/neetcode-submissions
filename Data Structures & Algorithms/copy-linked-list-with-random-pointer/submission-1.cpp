/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// class Solution {
// public:
//     Node* copyRandomList(Node* head) {

//         if (head == nullptr)
//             return nullptr;

//         unordered_map<Node*, Node*> mp;

//         Node* temp = head;

//         // Step 1: Create copy of every node
//         // and store original -> copy mapping
//         while (temp != nullptr) {

//             mp[temp] = new Node(temp->val);

//             temp = temp->next;
//         }

//         // Step 2: Connect next and random pointers
//         temp = head;

//         while (temp != nullptr) {

//             mp[temp]->next = mp[temp->next];
//             mp[temp]->random = mp[temp->random];

//             temp = temp->next;
//         }

//         return mp[head];
//     }
// };

// Optimal approach
class Solution {
public:
    void insertCopyInBetween(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* nextEle = temp -> next;
            Node* copy = new Node(temp->val);
            copy->next = nextEle;
            temp->next = copy;

            temp = nextEle;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp = head;
        while(temp != nullptr){
            Node* copy = temp->next;
            if(temp->random){
                copy->random = temp->random->next;
            }
            else{
                copy->random = nullptr;
            }
            temp = temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head){
        Node* temp = head;
        Node* dummy = new Node(-1);
        Node* res = dummy;

        while(temp!=nullptr){
            res->next = temp->next;
            res = res->next;

            temp->next = temp->next->next;
            temp = temp->next;
        }
        return dummy -> next;
    }

    Node* copyRandomList(Node* head) {
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};
