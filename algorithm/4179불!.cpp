#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

char board[1003][1003];
int answer[1003][1003];
int c, r, estime=0;
queue<pair<int,int> > ji, fi;
bool bfs(){
    while(!ji.empty()){
        //해결점 : 같은 depth(시간)에서의 불나는 것을 다 표시해 줘야지 조건에 맞는 문제 풀이입니다.
        int fs = fi.size();
        for(int f1=0;f1<fs;f1++){
            int fx = fi.front().first;
            int fy = fi.front().second;
            fi.pop();
            for(int i=0;i<4;i++){
                int nx = fx+dx[i];
                int ny = fy+dy[i];
                if(nx>=0 && nx<c && ny>=0 && ny<r && board[nx][ny]!='#' && board[nx][ny]!='F'){
                    board[nx][ny]='F';
                    fi.push(make_pair(nx,ny));
                }
            }
        }
        int js = ji.size();
        for(int j1=0;j1<js;j1++){
            int jx = ji.front().first;
            int jy = ji.front().second;
            ji.pop();
            for(int j=0;j<4;j++){
                int nx = jx+dx[j];
                int ny = jy+dy[j];
                if(nx<0 || nx>=c || ny<0 || ny>=r){
                    estime = answer[jx][jy]+1;
                    return true;
                }
                else{
                    if(board[nx][ny]=='.' && answer[nx][ny]==0){
                        ji.push(make_pair(nx,ny));
                        answer[nx][ny]=answer[jx][jy]+1;
                    }
                }

            }
        }
    }
    return false;
}

int main(){
    cout<<"input:";
    cin>>c>>r;
    for(int i=0;i<c;i++){
        for(int j=0;j<r;j++){
            cin>>board[i][j];
            if(board[i][j]=='F'){
                fi.push(make_pair(i,j));
            }
            if(board[i][j]=='J'){
                ji.push(make_pair(i,j));
            }
        }
    }
    if(!bfs()){
        cout<<"IMPOSSIBLE";
    }
    else{
        cout<<estime;
    }
    return 0;
}
