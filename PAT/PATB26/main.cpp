#include <iostream>
using namespace std;
#define CLKTCK 100

int main(){
    double c1,c2;
    cin>>c1>>c2;
    double time=((c2-c1)+50)/CLKTCK;
    int hour=time/60/60;
    int minute=(time-hour*60*60)/60;
    int second=(time-hour*60*60-minute*60);
    if(hour<10){
        cout<<"0"<<hour<<":";
    }else{
        cout<<hour<<":";
    }
    if(minute<10){
        cout<<"0"<<minute<<":";
    }else{
        cout<<minute<<":";
    }
    if(second<10){
        cout<<"0"<<second;
    }else{
        cout<<second;
    }
    return 0;
}