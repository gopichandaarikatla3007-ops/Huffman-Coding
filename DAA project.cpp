#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = NULL;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void generateCodes(Node* root, string code, map<char, string>& huffCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffCodes[root->ch] = code;
        return;
    }

    generateCodes(root->left, code + "0", huffCodes);
    generateCodes(root->right, code + "1", huffCodes);
}

string encodeString(const string& text, map<char, string>& huffCodes) {
    string encoded = "";
    for (int i = 0; i < text.size(); i++) {
        encoded += huffCodes[text[i]];
    }
    return encoded;
}

Node* buildTree(map<char, int>& freq, map<char, string>& huffCodes) {
    priority_queue<Node*, vector<Node*>, Compare> pq;

    for (map<char, int>::iterator it = freq.begin(); it != freq.end(); it++) {
        pq.push(new Node(it->first, it->second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        pq.push(newNode);
    }

    Node* root = pq.top();
    generateCodes(root, "", huffCodes);
    return root;
}

int main() {
    int n;
    map<char, int> freq;
    map<char, string> huffCodes;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        char c;
        int f;
        cin >> c >> f;
        freq[c] = f;
    }

    Node* root = buildTree(freq, huffCodes);

    cout << "\nHuffman Codes:\n";
    for (map<char, string>::iterator it = huffCodes.begin(); it != huffCodes.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }

    cin.ignore();
    string text;

    cout << "\nEnter the text you want to encode: ";
    getline(cin, text);

    string encoded = encodeString(text, huffCodes);

    cout << "\nOriginal Size: " << text.size() * 8 << " bits";
    cout << "\nCompressed Size: " << encoded.size() << " bits\n";
    cout << "\nEncoded Text: " << encoded << endl;

    return 0;
}

