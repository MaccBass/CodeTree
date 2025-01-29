#include <iostream>
#include <list>
#include <string>

using namespace std;
list<string> l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string s_init; cin >> s_init;
    l.push_back(s_init);
    auto cur = l.begin();
    int n; cin >> n;

    while (n) {

        int method; cin >> method;
        string s_value;
        switch (method) {
        case 1:
            cin >> s_value;
            if (cur != l.begin()) {
                l.insert(cur, s_value);
            }
            else {
                l.push_front(s_value);
            }
            break;

        case 2:
            cin >> s_value;
            l.insert(next(cur), s_value);
            break;

        case 3:
            if (cur != l.begin()) {
                cur = prev(cur);
            }
            break;

        case 4:
            if (next(cur) != l.end()) {
                cur = next(cur);
            }
        }

        if (cur != l.begin()) {
            cout << *prev(cur) << ' ';
        }
        else {
            cout << "(Null) ";
        }
        cout << *cur << ' ';
        if (next(cur) != l.end()) {
            cout << *next(cur) << '\n';
        }
        else {
            cout << "(Null)\n";
        }
        n--;
    }
    return 0;
}