#include <iostream>
#include <set>

using namespace std;
set<int> s;

int main() {
    
    int n, m;
    int ans = 2147000000;
    cin>>n>>m;
    
    while (n){
        int num; cin>>num; s.insert(num);
        --n;
    }

    for (set<int>::iterator it = s.begin(); it != s.end(); it++){
        for (set<int>::iterator n = next(it); n != s.end(); n++){
            int tmp = *n - *it;
            if (tmp<m) continue;
            if (tmp>=ans) {
                break;
            }
            else {
                ans = tmp; break;
            }
        }

        if (m==ans) break;
    }

    cout<<ans;

    return 0;
}