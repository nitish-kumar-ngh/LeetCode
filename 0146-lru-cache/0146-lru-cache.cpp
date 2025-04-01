
class Node {
public:
    pair<int, int> val;
    Node* prev;
    Node* next;

    Node(pair<int, int> val) {
        this->val = val;
        prev = NULL;
        next = NULL;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;

        // Initialize dummy head and tail
        head = new Node({-1, -1});
        tail = new Node({-1, -1});

        // Link head and tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];

            // Remove node from current position
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // Move node to the front (Most Recently Used)
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;

            return temp->val.second; // ✅ Corrected return statement
        }
        return -1; // Key not found
    }

    void put(int key, int value) {
        // If key already exists, update and move to front
        if (mp.find(key) != mp.end()) {
            Node* temp = mp[key];

            // Remove from current position
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            // Move to front
            temp->next = head->next;
            temp->prev = head;
            head->next->prev = temp;
            head->next = temp;

            temp->val.second = value; // ✅ Correct value update
            return;
        }

        // If cache is full, remove the Least Recently Used (LRU) node
        if (mp.size() == capacity) {
            Node* lru = tail->prev; // LRU node is before the tail
            mp.erase(lru->val.first); // ✅ Erase from hashmap

            // Remove LRU node from the list
            lru->prev->next = tail;
            tail->prev = lru->prev;

            delete lru; // Free memory
        }

        // Insert new node at the front (Most Recently Used)
        Node* temp = new Node({key, value});
        temp->next = head->next;
        temp->prev = head;
        head->next->prev = temp;
        head->next = temp;

        // Store in hashmap
        mp[key] = temp;
    }
};