#include <iostream>
#include <bitset>
#include <string>
using namespace std;

void rota(int &bit, int di){
    //시계방향 
    if(di==1){
        int tmp = bit;
        bit <<= 1;
        tmp >>= 7;
        tmp &= ((1<<8)-1);
        bit |= tmp;
    }
    if(di==-1){ //반시계방향.
        int tmp = bit;
        bit >>= 1;
        tmp &= 1;
        tmp <<= 7;
        bit |= tmp;
    }
}

bool left(int bit){
    return bit & (1<<2);
}
bool right(int bit){
    return bit & (1<<6);
}

int main(){
    int bit[5];
    int n, k, num, ro;
    //톱니를 bit로 저장하기 순서는 반대로 저장되고, 12시방향이 0번째자리
    for(int i=1;i<=4;i++){
        cin>>n;
        for(int j=0;j<8;j++){
            bit[i] <<= 1;
            bit[i] += n % 10;
            n/=10;
        }
    }
    
    //톱니의 회전 방향
    int dir[5];
    cin>>k;
    for(int l=0;l<k;l++){
        cin>>num>>ro;
        dir[num]=ro;
        rota(bit[num],dir[num]);
        
        //톱니의 왼쪽으로 움직
        for(int a=num-1;a>0;a--){
            if(right(bit[a])^left(bit[a+1])){
                dir[a]=-dir[a+1];
                rota(bit[a],dir[a]);
            }
            else{
                break;
            }
        }
        //톱니의 오른쪽으로 움직
        for(int b=num+1;b<5;b++){
            if(right(bit[b-1])^left(bit[b])){
                dir[b]=-dir[b-1];
                rota(bit[b],dir[b]);
            }
            else{
                break;
            }
        }
        // for(int c=1;c<5;c++){
        //     cout<<"\n"<<c<<" "<<bit[c]<<"\n";
        // }
    }
    int answer = (bit[1]&1)*1 + (bit[2]&1)*2 + (bit[3]&1)*4 + (bit[4]&1)*8;
    cout<<answer;
    return 0;
}
