//12
//12
//12
//12
#include<bits/stdc++.h>
using namespace std;
 
#define EMPTY_STRING ""
struct Nde
{
    char character;int frequency;Nde *left_node, *right_node;
};
Nde* getNode(char character, int frequency, Nde* left_node, Nde* right_node)
{
    Nde* nde = new Nde();
    nde->character = character;nde->frequency = frequency;nde->left_node = left_node;nde->right_node = right_node;
 
    return nde;
}
struct compare
{
    bool operator()(const Nde* l, const Nde* r) const
    {
        return l->frequency > r->frequency;
    }
};
bool isLeaf(Nde* root) {
    return root->left_node == nullptr && root->right_node == nullptr;
}
void Encoding(Nde* root, string str, map<char, string> &huffmanCode)
{
    if (root == nullptr) return;
    if (isLeaf(root)) huffmanCode[root->character] = (str != EMPTY_STRING) ? str : "1";
    Encoding(root->left_node, str + "0", huffmanCode);Encoding(root->right_node, str + "1", huffmanCode);
}
void Decoding(Nde* root, int &index, string str)
{
    if (root == nullptr) {
        return;
    }
    if (isLeaf(root))
    {
        cout << root->character;
        return;
    }
 
    index++;
 
    if (str[index] == '0') {
        Decoding(root->left_node, index, str);
    }
    else {
        Decoding(root->right_node, index, str);
    }
}
void solution()
{
    unordered_map<char, int> frequency;
    int n;
    cin>>n;
    while(n--){
        char c;
        int fr;
        cin>>c>>fr;
        frequency[c]=fr;
    }
    priority_queue<Nde*, vector<Nde*>, compare> pq;
    for (auto pair: frequency) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    while (pq.size() != 1)
    {
 
        Nde* left_node = pq.top(); pq.pop();
        Nde* right_node = pq.top();    pq.pop();
        int sum = left_node->frequency + right_node->frequency;
        pq.push(getNode('\0', sum, left_node, right_node));
    }
    Nde* root = pq.top();
    
    map<char, string> huffmanCode;
    Encoding(root, EMPTY_STRING, huffmanCode);
    for (auto pa: huffmanCode) {
        cout << pa.first << " " << pa.second << endl;
    }
}
int main()
{
    solution();
    return 0;
}