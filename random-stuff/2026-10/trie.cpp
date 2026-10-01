#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Trie {
  struct Node {
    int next[26] = {};
    int count = 0;
  };

  vector<Node> nodes;

  Trie() { nodes.emplace_back(); }

  void insert(const string& s) {
    int u = 0;
    for (char c : s) {
      int i = c - 'a';
      if (!nodes[u].next[i]) {
        nodes[u].next[i] = nodes.size();
        nodes.emplace_back();
      }
      u = nodes[u].next[i];
      ++nodes[u].count;
    }
  }

  int count_prefix(const string &s) const {
    int u = 0;
    for (char c : s) {
      int i = c - 'a';
      if (!nodes[u].next[i]) return 0;
      u = nodes[u].next[i];
    }
    return nodes[u].count;
  }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("application");

    cout << "Prefix 'app': " << trie.count_prefix("app") << "\n";
    cout << "Prefix 'appl': " << trie.count_prefix("appl") << "\n";
    cout << "Prefix 'cat': " << trie.count_prefix("cat") << "\n";

    return 0;
}
