#include <iostream>
#include <list>
#include <map>
using namespace std;

struct Node {
    int id;
    Node* prev;
    Node* next;
    Node(int n) : id(n), prev(nullptr), next(nullptr) {}
};
map<int, Node*> um;

int main() {
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        Node* tmp = new Node(i);
        um[i] = tmp;
    }

    while (q) {
        int method, i, j;
        cin >> method;

        switch (method) {
        case 1:
            cin >> i;
            if (um.find(i) != um.end()) {
                Node* tmp = um[i];
                if (nullptr != tmp->prev) tmp->prev->next = tmp->next;
                if (nullptr != tmp->next) tmp->next->prev = tmp->prev;
                tmp->prev = nullptr;
                tmp->next = nullptr;
            }
            break;

        case 2:
            cin >> i >> j;
            if ((um.find(i) != um.end()) && (um.find(j) != um.end())) {
                Node* ni = um[i];
                Node* nj = um[j];
                nj->next = ni;
                nj->prev = ni->prev;
                if (nullptr != ni->prev) ni->prev->next = nj;
                ni->prev = nj;

            }
            break;

        case 3:
            cin >> i >> j;
            if ((um.find(i) != um.end()) && (um.find(j) != um.end())) {
                Node* ni = um[i];
                Node* nj = um[j];
                nj->prev = ni;
                nj->next = ni->next;
                if (nullptr != ni->next) ni->next->prev = nj;
                ni->next = nj;
            }
            break;

        case 4:
            cin >> i;
            if (um.find(i) != um.end()) {
                if (nullptr != um[i]->prev) {
                    cout << um[i]->prev->id << ' ';
                }
                else cout << "0 ";
                if (nullptr != um[i]->next) {
                    cout << um[i]->next->id << '\n';
                }
                else cout << "0\n";
            }
            break;
        }

        q--;
    }

    for (auto it : um) {
        Node* node = it.second;
        if (nullptr != node->next) {
            cout << node->next->id << ' ';
        }
        else cout << "0 ";
    }
    return 0;
}