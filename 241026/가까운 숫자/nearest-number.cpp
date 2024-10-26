#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int n; cin>>n;
    int ans = 9999999;
    s.insert(0);
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;s.insert(tmp);
        for (set<int>::iterator it = s.begin(); it != prev(s.end()); it++){
            int diff=*next(it) - *it;
            if (diff < ans){
                ans = diff;
            }
        }
            cout<<ans<<'\n';
    }
    return 0;
}