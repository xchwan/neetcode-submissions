/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        queue<Node*> q;
        unordered_map<Node*, Node*> cloneNodeMp;
        cloneNodeMp[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()) {
            Node* cur = q.front();
            q.pop();
            for (Node* neiNode : cur->neighbors) {
                if (!cloneNodeMp.count(neiNode)) {
                    cloneNodeMp[neiNode] = new Node(neiNode->val);
                    q.push(neiNode);
                }
                cloneNodeMp[cur]->neighbors.push_back(cloneNodeMp[neiNode]);
            }
        }
        return cloneNodeMp[node];
    }
};
