#include <iostream>
#include <queue>
#include <iomanip>

using namespace std;

int N;
// 입력배열
int arr[100000];
// 누적합
int prefix[100000];
// 해당시점 최솟값
int minimum[100000];
// 우선순위큐
priority_queue<double> pq;

/*
아이디어: N개의 정수를 입력받을 때 누적합을 구하기.

모든 정수의 합에서 맨 앞에서부터 누적합을 뺀 다음,
해당 시점의 최솟값도 빼고 평균을 구한다.
그 평균을 pq에 넣고 마지막에 pq top을 출력하면 됨.

*/

int main() {
    cin >> N;

    int sumall;
    for (int i = 0; i < N; i++) {
        cin >> arr[i];

        if (i==0){
            prefix[i]=arr[i];
        }
        else{
            prefix[i]=prefix[i-1]+arr[i];
        }
    }
    sumall = prefix[N-1];

    for (int i=N-1; i>=0; i--){
        if (i==N-1){
            minimum[i] = arr[i];
        }
        else{
            if (minimum[i+1] > arr[i+1]){
                minimum[i] = arr[i+1];
            }
            else{
                minimum[i] = minimum[i+1];
            }
        }
    }

    for (int i=0; i<N-1; i++){
        int sum = sumall - prefix[i] - minimum[i];
        double avg = sum / (double)(N-i-2);
        pq.push(avg);
    }

    cout<<fixed<<setprecision(2);
    cout<<pq.top();
    return 0;
}
