#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *right, *down;
    Node(int x) { 
      data = x; 
      right = down = NULL; 
    }
};

Node* convert(int mat[3][3], int n, int m) {
    Node* nodes[10][10];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            nodes[i][j] = new Node(mat[i][j]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (j + 1 < m) nodes[i][j]->right = nodes[i][j + 1];
            if (i + 1 < n) nodes[i][j]->down = nodes[i + 1][j];
        }

    return nodes[0][0];
}

int main() {
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};

    Node* head = convert(mat, 3, 3);

    cout << head->data;          
    cout << "\n" << head->right->data; 
    cout << "\n" << head->down->data;  

    return 0;
}
