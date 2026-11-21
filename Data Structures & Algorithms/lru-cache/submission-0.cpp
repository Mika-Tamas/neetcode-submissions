struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;

    Node(int k, int v) : key(k), val(v), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    unordered_map<int, Node*> keys;
    Node* head;
    Node* tail;
    int cap;

    void remove(Node* node) {
        Node* prev = node->prev;
        Node* nxt = node->next;
        prev->next = nxt;
        nxt->prev = prev;
    }

    void insert(Node* node) {
        Node* prev = head->prev;
        prev->next = node;
        node->prev = prev;
        node->next = head;
        head->prev = node;
    }

public:
    LRUCache(int capacity) : cap(capacity) {
        keys.clear();
        head = new Node(0,0);
        tail = new Node(0,0);
        head->prev = tail;
        tail->next = head;
    }
    
    int get(int key) {
        if (keys.find(key) == keys.end()) return -1;
        Node* item = keys[key];
        remove(item);
        insert(item);
        return item->val;
    }
    
    void put(int key, int value) {
        if (keys.find(key) != keys.end()) {
            remove(keys[key]);
        }

        Node* item = new Node(key, value);
        keys[key] = item;
        insert(item);

        if (keys.size() > cap) {
            Node* last = tail->next;
            remove(last);
            keys.erase(last->key);
            delete last;
        }
    }
};
