#include <iostream>
#include <set>
using namespace std;

int main() {
    set<int> s;
    int n; cin>>n;
    int ans = 2100000000;
    s.insert(0);
    for(int i=0;i<n;i++){
        int tmp;cin>>tmp;s.insert(tmp);
        int diff;
        auto it=s.find(tmp);
        
        if (next(it) != s.end()){
            diff = *(next(it)) - *it;
            if (diff<ans) ans=diff;
        }
        if (it != s.begin()){
            diff=*it - *(prev(it));
            if(diff<ans) ans=diff;
        }

        cout<<ans<<'\n';
    }
    return 0;
}