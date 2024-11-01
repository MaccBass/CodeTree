#include <iostream>
#include <set>
#define MAX 2147000000

using namespace std;
set<int> s;

int main() {

    int n, m;
    int ans = MAX;
    cin >> n >> m;

    while (n) {
        int num; cin >> num; s.insert(num);
        set<int>::iterator it = s.find(num);

        if (it != s.begin()) {
            set<int>::iterator it2 = prev(it);
            for (it2; it2 != s.end(); it2--) {
                int tmp = *it - *it2;
                // m보다 작으면 계속 탐색
                if (tmp < m) continue;

                // ans보다 작지 않으면 탐색 종료
                if (tmp >= ans) break;
                else { ans = tmp; break; }
            }
        }

        if (next(it) != s.end()) {
            set<int>::iterator it2 = next(it);
            for (it2; it2 != s.end(); it2++) {
                int tmp = *it2 - *it;
                if (tmp < m) continue;

                if (tmp >= ans) break;
                else { ans = tmp; break; }
            }
        }

        --n;
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++) {
        for (set<int>::iterator it2 = next(it); it2 != s.end(); it2++) {
            int tmp = *it2 - *it;
            if (tmp < m) continue;
            if (tmp >= ans) {
                break;
            }
            else {
                ans = tmp; break;
            }
        }

        if (m == ans) break;
    }

    if (ans == MAX) cout << -1;
    else cout << ans;

    return 0;
}