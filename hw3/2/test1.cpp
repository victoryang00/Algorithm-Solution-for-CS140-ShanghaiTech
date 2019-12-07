#include<iostream>
#include<algorithm>
using namespace std;
int a[1600];
int main(){
    for(int i=0;i<400*400;i++)
        cin>>a[i];
    sort(a,a+400*400);
        for(int i=0;i<400*400;i++)
        cout<<a[i];
}