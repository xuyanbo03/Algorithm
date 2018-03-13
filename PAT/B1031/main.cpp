// #include <iostream>
// #include <string>
// using namespace std;

// int main(){
//     int n,z;
//     cin>>n;
//     string sfz[n];
//     int qz[]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
//     for(int i=0;i<n;i++){
//         cin>>sfz[i];
//     }
//     for(int i=0;i<n;i++){
//         for(int j=0;j<17;j++){
//             z=((string[i][j]-'0')*qz[j])%11;
//         }
//     }
//     return 0;
// }

#include <iostream>
#include <string>
using namespace std;
bool func(string a);
int main() {
    int n;
    int count = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string a;
        cin >> a;
        if (func(a))
            count++;
    }
    if (count == 0)
        cout << "All passed";
    return 0;
}

bool func(string s) {
    int sum = 0;
    int a[18];
    for (int i = 0; i < 17; i++) {
        if(!isdigit(s[i])) {
            cout << s << endl;
            return false;
        }
        a[i] = s[i] - '0';
    }
    if (s[17] == 'X')
        a[17] = 10;
    else
        a[17] = s[17] - '0';
    int b[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    for (int i = 0; i < 17; i++) {
        sum = sum + a[i] * b[i];
    }
    sum = sum % 11;
    int c[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};
    if (c[sum] != a[17]) {
        for (int i = 0; i < 17; i++) {
            cout << s[i];
        }
        if (a[17] != 10)
            cout << a[17] << endl;
        else {
            cout << "X" << endl;
        }
        return true;
    }
    else {
        return false;
    }
}