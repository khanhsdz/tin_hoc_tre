#include <bits/stdc++.h>
#define MAXN 100001
using namespace std;
const int LIM = 430;
int n , gtmax , val , f[MAXN];
bitset<LIM> isprime ;
vector<int> a;
void SangNguyenTo(int N = LIM){
    isprime[2] = 1;
    for(int i=3 ; i<N ; i+=2) isprime.set(i);
    for(int i=3 ; i<N ; i+=2){
        if(isprime[i]==1){
            if(i*i >= N) continue;
            for(int j=i*i ; j<N ; j+=(2*i)) isprime.reset(j);
        }
    }
}
int SumSquare(int x){
    int s = 0;
    while(x>0){
        s+=((x%10)*(x%10));
        x/=10;
    }
    return s;
}
void solution(int n){
    int dem = 0 , i=10;
    while(1){
        if(isprime[SumSquare(i)]){
            dem++;
            f[dem]=i;
            if(dem==n){
                break;
            }
        }
        i++;
    }
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0) ; cout.tie(0) ;
    freopen("beauty.inp" , "r" , stdin);
    freopen("beauty.out" , "w" , stdout);
    SangNguyenTo();
    while(cin >> val){
        a.push_back(val);
    }
    gtmax = *max_element(a.begin(),a.end());
    solution(gtmax);
    for(int i=0 ; i<(int)a.size() ; i++){
        cout << f[a[i]] << endl;
    }
    return 0;
}
