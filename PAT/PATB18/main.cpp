#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    int jwin=0;
    int ywin=0;
    int j[3]={0};
    int y[3]={0};
    char str[4]={"BCJ"};
    for(int i=0;i<n;i++){
        char a,b;
        cin>>a>>b;
        if(a=='C'&& b=='J'){
            jwin++;
            j[1]++;
        }else if(a=='J'&& b=='B'){
            jwin++;
            j[2]++;
        }else if(a=='B'&& b=='C'){
            jwin++;
            j[0]++;
        }else if(a=='C'&& b=='B'){
            ywin++;
            y[0]++;
        }else if(a=='J'&& b=='C'){
            ywin++;
            y[1]++;
        }else if(a=='B'&& b=='J'){
            ywin++;
            y[2]++;
        }
    }
    cout<<jwin<<" "<<n-jwin-ywin<<" "<<ywin<<endl;
    cout<<ywin<<" "<<n-jwin-ywin<<" "<<jwin<<endl;
    int maxj=j[0]>=j[1]?0:1;
    maxj=j[maxj]>=j[2]?maxj:2;
    int maxy=y[0]>=y[1]?0:1;
    maxy=y[maxy]>=y[2]?maxy:2;
    cout<<str[maxj]<<" "<<str[maxy];
    return 0;
}