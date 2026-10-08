//NAME - MEET KUMAR
//ROLL NO- 25/DA/042
#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    char data;
    int freq;
    Node *left, *right;

    Node(char d, int f)
    {
        data = d;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare
{
    bool operator()(Node* a, Node* b)
    {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code)
{
    if (root == nullptr)
        return;

    if (root->left == nullptr && root->right == nullptr)
    {
        cout << root->data << " : " << code << endl;
        return;
    }

    generateCodes(root->left, code + "0");
    generateCodes(root->right, code + "1");
}

int main()
{
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    int n = 6;

    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (int i = 0; i < n; i++)
        pq.push(new Node(data[i], freq[i]));

    while (pq.size() > 1)
    {
        Node* left = pq.top();
        pq.pop();

        Node* right = pq.top();
        pq.pop();

        Node* newNode = new Node('$', left->freq + right->freq);

        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();

    cout << "Huffman Codes:\n";
    generateCodes(root, "");

    return 0;
}