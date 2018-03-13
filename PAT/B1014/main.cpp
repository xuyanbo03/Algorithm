#include <iostream>
#include <string>
using namespace std;

int main(){
    string a,b,c,d;
    cin>>a>>b>>c>>d;
    int lena=a.length();
    int lenb=b.length();
    int lenc=c.length();
    int lend=d.length();
    int min1=lena<lenb?lena:lenb;
    int min2=lenc<lend?lenc:lend;
    int p,j;
    int n[2];
    string week[7]={"MON ","TUE ","WED ","THU ","FRI ","SAT ","SUN "};

    for(int i=0;i<=min1;i++){
        if(a[i]==b[i]&&(a[i]>='A'&&a[i]<='G')){
            n[0]=a[i];
            a[i]='#';
            j=i;
            break;
        }
    }
    for(int i=j+1;i<=min1;i++){
        if(a[i]==b[i]&&((a[i]>='0'&&a[i]<='9')||(a[i]>='A'&&a[i]<='N'))){
            n[1]=a[i];
            break;
        }
    }
    for(int i=0;i<=min2;i++){
        if(c[i]==d[i]&&((c[i]>='a'&&c[i]<='z')||(c[i]>='A'&&c[i]<='Z'))){
            p=i;
            break;
        }
    }

    cout<<week[n[0]-'A'];
    if(n[1]>='0'&&n[1]<='9'){
        cout<<0<<n[1]-'0'<<":";
    }else{
        cout<<n[1]-'A'+10<<":";
    }
    if(p>=0&&p<=9){
        cout<<0<<p;
    }else{
        cout<<p;
    }
    return 0;
}