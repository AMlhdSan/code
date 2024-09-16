#include<bits/stdc++.h> 

using namespace std; 

int n; 

struct node 

{ 

  int fz,fm;	 

}a[160*160+3]; 

int gcd0(int x,int y) 

{ 

    int r=x%y; 

while(r!=0) 

{ 

  x=y; 

  y=r; 

  r=x%y; 

    } 

    return y; 

} 

int gcd(int x,int y) 

{ 

  if(x%y==0) return y; 

  else return gcd(y,x%y); 

} 

 

bool mycmp(node x, node y) 

{ 

    return x.fz*y.fm<x.fm*y.fz;	 

} 

int main() 

{ 

cin>>n; 

int cnt=0; 

for(int i=2;i<=n;i++) 

for(int j=1;j<i;j++) 

{ 

  if(gcd(i,j)==1){ 

  cnt++; 

  a[cnt].fz=j;a[cnt].fm=i;	 

      } 

} 

sort(a+1,a+1+cnt,mycmp); 

cout<<"0/1"<<endl; 

    for(int i=1;i<=cnt;i++) 

        cout<<a[i].fz<<"/"<<a[i].fm<<endl; 

    cout << "1/1"; 
    return 0;
} 