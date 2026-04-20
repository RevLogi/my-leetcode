#include <unordered_map>
#include <vector>

class Node {
public:
    int val;
    std::vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = std::vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = std::vector<Node *>();
    }
    Node(int _val, std::vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    std::unordered_map<Node *, Node *> visited;

    Node *cloneGraph(Node *node) {
        if (!node) return nullptr;

        if (visited[node]) {
            return visited[node];
        }

        Node *new_node = new Node(node->val);
        visited[node] = new_node;

        for (Node *neighbor : node->neighbors) {
            new_node->neighbors.push_back(cloneGraph(neighbor));
        }

        return new_node;
    }
};
