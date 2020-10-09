#include<iostream>
using namespace std;

int R, C, m, r, c, cnt=0;
struct{
    int s=0;
    int d=0;
    int z=0;
} a[102][102], b[102][102];

void atob(int t){
    //낚시
    for(int i=1;i<=R;i++){
        if(a[i][t].z){
            cnt+=a[i][t].z;
            a[i][t].s=0;
            a[i][t].d=0;
            a[i][t].z=0;
            break;
        }
    }
    //상어이동
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){ // <= 해당 위치에 상어 찾기
            if(a[i][j].z){ // 그 칸에 상어 있음
                if(a[i][j].d<=2){// 1위 2아래
                    int now = i; // 상어 위치
                    for(int k=0;k<a[i][j].s;k++){
                        if(a[i][j].d==2){
                            if(now==R){
                                a[i][j].d=1;
                                now--;
                            }
                            else{
                                now++;
                            }
                        }
                        else{
                            if(now==1){
                                a[i][j].d=2;
                                now++;
                            }
                            else{
                                now--;
                            }
                        }
                    }
                    if(b[now][j].z<a[i][j].z){
                        b[now][j].s=a[i][j].s;
                        b[now][j].d=a[i][j].d;
                        b[now][j].z=a[i][j].z;
                    }
                    a[i][j].s=0;a[i][j].d=0;a[i][j].z=0;
                }
                else{//3오른쪽 4왼쪽
                    int now = j; // 상어 위치
                    for(int k=0;k<a[i][j].s;k++){
                        if(a[i][j].d==3){
                            if(now==C){
                                a[i][j].d=4;
                                now--;
                            }
                            else{
                                now++;
                            }
                        }
                        else{
                            if(now==1){
                                a[i][j].d=3;
                                now++;
                            }
                            else{
                                now--;
                            }
                        }
                    }
                    if(b[i][now].z<a[i][j].z){
                        b[i][now].s=a[i][j].s;
                        b[i][now].d=a[i][j].d;
                        b[i][now].z=a[i][j].z;
                    }
                    a[i][j].s=0;a[i][j].d=0;a[i][j].z=0;
                }
            }
        }
    }
}

void btoa(int t){
    //낚시
    for(int i=1;i<=R;i++){
        if(b[i][t].z){
            cnt+=b[i][t].z;
            b[i][t].s=0;
            b[i][t].d=0;
            b[i][t].z=0;
            break;
        }
    }
    //상어이동
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){ // <= 해당 위치에 상어 찾기
            if(b[i][j].z){ // 그 칸에 상어 있음
                if(b[i][j].d<=2){// 1위 2아래
                    int now = i; // 상어 위치
                    for(int k=0;k<b[i][j].s;k++){
                        if(b[i][j].d==2){
                            if(now==R){
                                b[i][j].d=1;
                                now--;
                            }
                            else{
                                now++;
                            }
                        }
                        else{
                            if(now==1){
                                b[i][j].d=2;
                                now++;
                            }
                            else{
                                now--;
                            }
                        }
                    }
                    if(a[now][j].z<b[i][j].z){
                        a[now][j].s=b[i][j].s;
                        a[now][j].d=b[i][j].d;
                        a[now][j].z=b[i][j].z;
                    }
                    b[i][j].s=0;b[i][j].d=0;b[i][j].z=0;
                }
                else{//3오른쪽 4왼쪽
                    int now = j; // 상어 위치
                    for(int k=0;k<b[i][j].s;k++){
                        if(b[i][j].d==3){
                            if(now==C){
                                b[i][j].d=4;
                                now--;
                            }
                            else{
                                now++;
                            }
                        }
                        else{
                            if(now==1){
                                b[i][j].d=3;
                                now++;
                            }
                            else{
                                now--;
                            }
                        }
                    }
                    if(a[i][now].z<b[i][j].z){
                        a[i][now].s=b[i][j].s;
                        a[i][now].d=b[i][j].d;
                        a[i][now].z=b[i][j].z;
                    }
                    b[i][j].s=0;b[i][j].d=0;b[i][j].z=0;
                }
            }
        }
    }
}

int main(){
    cin>>R>>C>>m;
    if(m==0){
        cout<<cnt;
        return 0;
    }
    for(int i=0;i<m;i++){
        cin>>r>>c>>a[r][c].s>>a[r][c].d>>a[r][c].z;
        if(a[r][c].d<=2){
            a[r][c].s %=((R-1)*2);
        }
        else{
            a[r][c].s %=((C-1)*2);
        }
    }
    for(int time=1;time<=C;time++){
       if(time %2==1){
           atob(time);
       } 
       else{
           btoa(time);
       }
    }
    cout<<cnt;
    return 0;
}
