#include <iostream>
#include <set>
#define MAX 2147000000

using namespace std;
set<int> s;

int main() {
    
    int n, m;
    int ans = MAX;
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

    if (ans == MAX) cout<<-1;
    cout<<ans;

    return 0;
}