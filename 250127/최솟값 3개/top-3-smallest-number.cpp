#include <iostream>
#include <queue>
using namespace std;

priority_queue<int> pq;
int n;
int ans = -1;
void getAns();
int main() {
    
    cin>>n;
    for (int i=0;i<n;i++){
        int tmp; cin>>tmp;
        if (i<3){
            pq.push(tmp);
            if (i==2){
                getAns();
            }
        }
        else{
            if (tmp < pq.top()){
                pq.pop();
                pq.push(tmp);
                getAns();
            }
        }
        cout<<ans<<'\n';
    }

    return 0;
}

void getAns(){
    int tmp=1;
    priority_queue<int> pq_tmp = pq;
    for (int i=0;i<3;i++){
        tmp *= pq_tmp.top();
        pq_tmp.pop();
    }
    ans = tmp;
}