#include <iostream>
#include <set>
#define MAX 2147000000
using namespace std;

set<set<int>> ss;

int main() {

    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m; cin >> n >> m;

    set<int> setinit;
    for (int i = 0; i <= n; i++) {
        setinit.insert(i);
    }
    ss.insert(setinit);

    for (int i = 0; i < m; i++) {
        int tmpsize = 0;

        int numToErase; cin >> numToErase;
        for (auto& itss : ss) {
            set<int> settmp = itss;
            auto it = settmp.find(numToErase);
            if (it != settmp.end()) {
                set<int> setLess, setGreater;
                for (auto& i : settmp) {
                    if (i < numToErase) {
                        setLess.insert(i);
                    }
                    else if (i > numToErase) {
                        setGreater.insert(i);
                    }
                    else continue;
                }
                ss.insert(setLess); ss.insert(setGreater);
                ss.erase(settmp);
                break;
            }
        }

        for (auto& itss : ss) {
            if (tmpsize < itss.size()) {
                tmpsize = itss.size();
            }
        }

        cout << tmpsize << '\n';
    }
    return 0;
}