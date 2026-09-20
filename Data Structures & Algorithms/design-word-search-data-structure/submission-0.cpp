class Node {
    public:
    unordered_map<char,Node*> subtree;
    bool is_end;
};

class WordDictionary {
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for (char c : word) {
            if (node->subtree.find(c) == node->subtree.end()) {
                node->subtree[c] = new Node();
            }
            node = node->subtree[c];
        }
        node->is_end = true;
    }
    
    bool search(string word) {
        return search_recursive(word,root);
    }

    bool search_recursive(string word, Node* start_node) {
        Node* node = start_node;
        for (int i = 0; i < word.size();i++) {
            if (word[i] == '.') {
                bool found = false;
                for (const auto& [c, n] : node->subtree) {
                    found = found || search_recursive(word.substr(i+1,word.size()),n);
                }
                if (found) {
                    return true;
                } else {
                    return false;
                }
            }
            if (node->subtree.find(word[i]) == node->subtree.end()) {
                return false;
            }
            node = node->subtree[word[i]];
        }
        return node->is_end;
    }
};
