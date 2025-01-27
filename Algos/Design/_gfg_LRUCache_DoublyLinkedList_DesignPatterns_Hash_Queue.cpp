#include <bits/stdc++.h>
using namespace std;

// design the class in the most optimal way

class Node {
public:
    int key;
    int value;
    Node* next;
    Node* prev;

    // Default constructor
    Node() {
        key = 0;
        value = 0;
        next = nullptr;
        prev = nullptr;
    }

    // Parameterized Constructor
    Node(int key, int value) {
        this->key = key;
        this->value = value;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache {
private:
    int capacity;
    Node* head;
    Node* tail;
    unordered_map<int, Node*> mp;

    void insertAtHead(Node* node) {
        Node* temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        if (temp != nullptr) {
            temp->prev = node;
        }
    }

    void deleteNode(Node* node) {
        Node* prevv = node->prev;
        Node* nextt = node->next;
        if (prevv != nullptr) {
            prevv->next = nextt;
        }
        if (nextt != nullptr) {
            nextt->prev = prevv;
        }
    }

public:
    // Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap) {
        capacity = cap;
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
        mp.clear();
    }

    // Function to return value corresponding to the key.
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        deleteNode(node);
        insertAtHead(node);
        return node->value;
    }

    // Function for storing key-value pair.
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            deleteNode(node);
            insertAtHead(node);
        } else {
            if (mp.size() == capacity) {
                Node* nodeToDelete = tail->prev;
                mp.erase(nodeToDelete->key);
                deleteNode(nodeToDelete);
                delete nodeToDelete;
            }
            Node* node = new Node(key, value);
            insertAtHead(node);
            mp[key] = node;
        }
    }
};

int main() {
    int cap = 2; // Cache capacity
    int Q = 8;   // Number of queries

    // Create the cache
    LRUCache lru(cap);

    // Example queries
    vector<pair<string, vector<int>>> queries = {
        {"PUT", {1, 2}}, // Put (1, 2) into the cache
        {"PUT", {2, 3}}, // Put (2, 3) into the cache
        {"PUT", {1, 5}}, // Put (1, 5) into the cache
        {"PUT", {4, 5}}, // Put (4, 5) into the cache
        {"PUT", {6, 7}}, // Put (6, 7) into the cache
        {"GET", {4}},     // Get the value for key 4
        {"PUT", {1, 2}}, // Put (1, 2) into the cache
        {"GET", {3}}, // GET the value for key 3
    };

    // Process each query
    for (auto query : queries) {
        if (query.first == "PUT") {
            int key = query.second[0];
            int value = query.second[1];
            lru.put(key, value);
            cout << "PUT (" << key << ", " << value << ")" << endl;
        } else if (query.first == "GET") {
            int key = query.second[0];
            int result = lru.get(key);
            cout << "GET (" << key << ") -> " << result << endl;
        }
    }

    return 0;
}
