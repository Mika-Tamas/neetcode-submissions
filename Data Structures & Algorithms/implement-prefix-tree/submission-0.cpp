
class Node {
    public:
    bool is_end;
    unordered_map<char,Node*> subtree;
};

class PrefixTree {
    Node* roots;
public:
    PrefixTree() {
        roots = new Node();
    }
    
    void insert(string word) {
        Node* node = roots;
        for (int i = 0; i < word.size(); i++) {
            if (node->subtree.find(word[i]) == node->subtree.end()) {
                node->subtree[word[i]] = new Node();
            }
            node = node->subtree[word[i]];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        Node* node = roots;
        for (int i = 0; i < word.size(); i++) {
            if (node->subtree.find(word[i]) == node->subtree.end()) {
                return false;
            }
            node = node->subtree[word[i]];
        }
        return true && node->is_end;
    }
    
    bool startsWith(string prefix) {
        Node* node = roots;
        for (int i = 0; i < prefix.size(); i++) {
            if (node->subtree.find(prefix[i]) == node->subtree.end()) {
                return false;
            }
            node = node->subtree[prefix[i]];
        }
        return true;
    }
};

