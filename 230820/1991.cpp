// S1 1991 트리 순회

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Node;

class Node {
public:
  char name;
  Node* left;
  Node* right;

  Node(char inputname) {
    name = inputname;
    left = NULL;
    right = NULL;
  }
};

void preorder(Node* node) {
  cout << node->name;
  if(node->left != NULL)
    preorder(node->left);
  if(node->right != NULL)
    preorder(node->right);
}

void inorder(Node* node) {
  if(node->left != NULL)
    inorder(node->left);
  cout << node->name;
  if(node->right != NULL)
    inorder(node->right);
}

void postorder(Node* node) {
  if(node->left != NULL)
    postorder(node->left);
  if(node->right != NULL)
    postorder(node->right);
  cout << node->name;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  int N;
  char p, l, r;

  cin >> N;

  vector<Node> nodes;

  for(int i = 0; i < N; i++) {
    nodes.push_back(Node(char(i + 'A')));
  }

  for(int i = 0; i < N; i++) {
    cin >> p  >> l >> r;
    if(l != '.')
      nodes[int(p - 'A')].left = &nodes[int(l - 'A')];
    if(r != '.')
      nodes[int(p - 'A')].right = &nodes[int(r - 'A')];
  }

  preorder(&nodes[0]);
  cout << '\n';
  inorder(&nodes[0]);
  cout << '\n';
  postorder(&nodes[0]);
  cout << '\n';
  
  return 0;
}