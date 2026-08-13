class Solution {
public:

    struct Node {
        int len;
        int leftLen;
        int rightLen;
        int best;
        char leftChar;
        char rightChar;
    };

    vector<Node> tree;

    Node merge(Node a, Node b) {

        if(a.len == 0)
            return b;

        if(b.len == 0)
            return a;

        Node res;

        res.len = a.len + b.len;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.leftLen = a.leftLen;

        if(a.leftLen == a.len && a.rightChar == b.leftChar)
            res.leftLen = a.len + b.leftLen;

        res.rightLen = b.rightLen;

        if(b.rightLen == b.len && a.rightChar == b.leftChar)
            res.rightLen = b.len + a.rightLen;

        res.best = max(a.best, b.best);

        if(a.rightChar == b.leftChar)
            res.best = max(res.best, a.rightLen + b.leftLen);

        return res;
    }

    void build(string &s, int node, int l, int r) {

        if(l == r) {

            tree[node] = {
                1,
                1,
                1,
                1,
                s[l],
                s[l]
            };

            return;
        }

        int mid = (l + r) / 2;

        build(s, node * 2, l, mid);
        build(s, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    void update(string &s, int node, int l, int r,
                int index, char ch) {

        if(l == r) {

            s[index] = ch;

            tree[node] = {
                1,
                1,
                1,
                1,
                ch,
                ch
            };

            return;
        }

        int mid = (l + r) / 2;

        if(index <= mid)
            update(s, node * 2, l, mid, index, ch);
        else
            update(s, node * 2 + 1, mid + 1, r, index, ch);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.size();

        tree.resize(4 * n);

        build(s, 1, 0, n - 1);

        vector<int> ans;

        for(int i = 0; i < queryCharacters.size(); i++) {

            int index = queryIndices[i];
            char ch = queryCharacters[i];

            update(s, 1, 0, n - 1, index, ch);

            ans.push_back(tree[1].best);
        }

        return ans;
    }
};