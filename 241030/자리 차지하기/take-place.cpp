#include <iostream>
#include <unordered_set>

using namespace std;
unordered_set<int> seats;

int main() {
    int n, m;
    int cnt=0; bool chk=false;
    cin>>n>>m;

    for (int i=0;i<n;i++) {
        if (chk==true) break;

        int seat; cin>>seat;
        for (int j=seat; j>=0; j--){
            if (j!=0){
                if (seats.find(j) == seats.end()){
                    seats.insert(j);
                    cnt++;
                    break;
                }
            }
            else{
                chk=true;
            }
        }
    }

    cout<<cnt;
    
    return 0;
}