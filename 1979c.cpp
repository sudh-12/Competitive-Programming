/*You have come so far from the day 1, and someday you are gonna reach your destination :)*/

/* SUDHANSHU_CODE _/\_ */

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fl(i,a,b) for(int i=a;i<b;++i)
#define ip(str) getline(cin, str)
#define vt(d,v) vector <d> v
#define arr(n) vector<int> arr(n)
#define mp(d1,d2,m) map<d1,d2> m
#define endl "\n"
#define py cout<<"YES"<<endl
#define pn cout<<"NO"<<endl
#define pw cout<<"-1"<<endl
#define ff first
#define ss second
#define all(x) x.begin(),x.end()
//#define INT_MAX 1e19
//#define INT_MIN -1e18
#define um(d1,d2,m) unordered_map<d1,d2> m
#define pb push_back
#define pq_max(x) priority_queue<int> x
#define pq_min(x) priority_queue<int, vector <int>, greater<int>> x
#define bl(i,a,b) for(int i=a;i>=b;--i)
#define speed cin.tie(nullptr); ios::sync_with_stdio(false);
const int mod=1e9+7;
const int M=998244353;

const int N=1e5;

void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
//void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

//-----------------------------------------Make_Functions---------------------------------------------------//

//seive algo to check and store (pre computation) res of prime of each number from 1 to 1e5 -> Tc -> log(log(n))
//vector<bool> prime(N,1); //is prime or not?
//vector<int> hp(N,0); //highest pf among the pfs of a number until 1e5
//vector<int> lp(N,0); // lowest pf among the pfs of a number until 1e5
/*prime[0]=prime[1]=false; // c st
fl (i,2,N){
if (prime[i]==true) {
lp[i]=hp[i]=i; //for hp,lp
for (int j=2*i; j<N; j+=i){
prime[j]=false;
hp[j]=i; // for hp,lp
if (lp[j]==0) for hp,lp
lp[j]=i; for hp,lp
}
}
}*/ //c end

//seive alogo for prime factors of a number n using highest prime TC-> log(n) ->> pre computation
/*vector<int> prime_factors;
while(n>1){
int prf=hp[n];
while(n%prf==0){
n/=prf;
prime_factors.pb(prf);
}
}*/

//pre computation of divisors of every nmbr till 1e5 using seive algo TC-> nlog(n);
//vector<int> divisors[N];
/*fl(i,2,N){
for (int j=i; j<N; j+=i){
divisors[j].pb(i);
}
}*/

//digit sum of a number TC-> O(log(n))
int getSum(int n)
{
int sum = 0;
while (n != 0) {
sum = sum + n % 10;
n = n / 10;
}
return sum;
}

/*prime factors of a number */ //TC-->O(sqrt(n))//
 vector<int> pf(int n) {
 vt(int,ans);
 while(n%2==0){
ans.pb(2);
n/=2;
}
for(int i=3;i<=sqrt(n);i+=2){
while(n%i==0){
ans.pb(i);
n/=i;
}
}
if(n>2)
ans.pb(n);
return ans;
}
// next greater element using stack -> tc O(n)//
vector<int> nge(vector<int> NGE){
stack<int> st;
int l=NGE.size();
vector<int> val(l,-1);
fl (i,0,l){
while (!st.empty() && NGE[i]>NGE[st.top()]) {
val[st.top()]=NGE[i];
st.pop();
}
st.push(i);
}
return val;
}
// comperator func in sorting of pairs in vectors
bool comp (pair<int,int> a, pair<int,int>  b) {
if (a.ff!=b.ff)
return b.ff<a.ff;
return a.ss>b.ss;
}
//print binary -> 32 length
string printBin(int a){
string str;
while(a){
if (a&1)
str+='1';
else
str+='0';
a>>=1;
}
/*while (str.size()!=32){  //for 32 length
str+='0';
}*/
reverse(all(str));
return str;
}
//Binary expon (power of an int number) -> tc(log(no of bits of a number in the power))
int binpow(int a, int b){
int ans=1;
while (b){
if (b&1)
ans=(ans*a)%mod;
b>>=1;
a=(a*a)%mod;
}
return ans;
}
// bin string to decimal numbr tc-< O(k)
int bin2dec(string str){
int s=str.size();
int num=0;
int pow=0;
while(s){
if (str[s-1]=='1')
num+=(1<<pow);
pow++;
s--;
}
return num;
}

//--------------------------------------Solution-----------------------------------------------------------//
void solve () {

int n;
cin>>n;

arr(n);
int mul=1;

fl(i,0,n){
   
    cin>>arr[i];
}

mp(int,int,mp);

for(auto &x: arr)
mp[x]++;


auto lcmm= [&] (vector<int> arr, int n){
    int ans=arr[0];


    fl(i,1,n){
        ans=(arr[i]*ans)/(__gcd(arr[i],ans));

    }

    return ans;
};

vector<int> ans;
int sum=0;
int res= lcmm(arr,n);
fl(i,0,n){
    ans.pb(res/arr[i]);
    sum=sum+(res/arr[i]);
}

fl(i,0,n){
    if(sum>=ans[i]*arr[i]){
        pw;
        return;
    }
}

fl(i,0,n){
    cout<<ans[i]<<" ";
}

cout<<endl;

}
//---------------------------------------------------------------------------------------------------------//
signed main() {
speed
int t;
cin>>t;
cin.ignore();

while (t--) {
solve();
}
return 0;
}

/* _/\_ Jai Mata Di _/\_ */