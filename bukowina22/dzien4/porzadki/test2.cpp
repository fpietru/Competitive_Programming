#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

constexpr int base = (1<<17);
ll seg[2*base];
ll lazy[2*base];
void up(int in,int l,int r,int sl,int sr)
{
    if(lazy[in]!=0)
    {
        seg[in]=(sr-sl+1)-seg[in];
        if(sl!=sr){
            lazy[2*in]=!lazy[2*in];
            lazy[2*in+1]=!lazy[2*in+1];
        }
        lazy[in]=0;
    }
    if(r<sl || l>sr || l>r)return;
    if(sl>=l && sr<=r)
    {
        seg[in]=(sr-sl+1)-seg[in];
        if(sl!=sr){
            lazy[2*in]=!lazy[2*in];
            lazy[2*in+1]=!lazy[2*in+1];
        }
        return;
    }
    int mid=sl+(sr-sl)/2;
    up(in*2,l,r,sl,mid);
    up(in*2+1,l,r,mid+1,sr);
    seg[in]=seg[in*2]+seg[in*2+1];
}
ll sum(int in,int l,int r,int sl,int sr)
{
    if(lazy[in]!=0)
    {
        seg[in]=(sr-sl+1)-seg[in];
        if(sl!=sr){
            lazy[2*in]=!lazy[2*in];
            lazy[2*in+1]=!lazy[2*in+1];
        }
        lazy[in]=0;
    }
    if(r<sl || l>sr || l>r)return 0;
    if(sl>=l && sr<=r)
     return seg[in];
    int mid=sl+(sr-sl)/2;
    return sum(in*2,l,r,sl,mid) + sum(in*2+1,l,r,mid+1,sr);
}
int main(){
    // ios_base::sync_with_stdio(0);
    // cin.tie(0);
	
	char op;
	while (cin >> op)
	{
		if (op == 'U')
		{
			int a, b; cin >> a >> b;
			up(1, a, b, 0, base-1);
		}
		else if (op == 'Q')
		{
			int a, b; cin >> a >> b;
			cout << sum(1, a, b, 0, base-1) << "\n";
		}
	}	
		
    return 0;
}
