class TrieNode {
public:
    TrieNode* children[26];
    int cnt;

    TrieNode() {
        cnt = 0;
        for (int i = 0; i < 26; ++i) 
        {
            children[i] = nullptr;
        }
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() { root = new TrieNode(); }

    void insert(string& w) {
        TrieNode* node = root;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
            ++node->cnt;
        }
    }

    int search(string& w) {
        TrieNode* node = root;
        int ans = 0;
        for (char c : w) {
            int idx = c - 'a';
            if (!node->children[idx]) {
                return ans;
            }
            node = node->children[idx];
            ans += node->cnt;
        }
        return ans;
    }
};

class Solution {
public:
    Solution() {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;
        for (auto& w : words) {
            trie.insert(w);
        }
        vector<int> ans;
        for (auto& w : words) {
            ans.push_back(trie.search(w));
        }
        return ans;
    }
};
