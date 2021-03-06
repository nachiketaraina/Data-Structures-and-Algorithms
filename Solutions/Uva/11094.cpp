// Created on 19-06-2019 11:37:44 by necronomicon
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <ctime>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;

#define MP make_pair
#define PB push_back
#define ARR_MAX (int)1e5 //Max array length
#define INF (int)1e9 //10^9
#define EPS 1e-9 //10^-9
#define MOD 1000000007 //10^9+7
#define PI 3.1415926535897932384626433832795
typedef long int int32;
typedef unsigned long int uint32;
typedef long long int int64;
typedef unsigned long long int  uint64;
typedef pair<int, int> Pii;
typedef vector<int> Vi;
typedef vector<string> Vs;
typedef vector<Pii> VPii;
typedef vector<Vi> VVi;
typedef map<int,int> Mii;
typedef set<int> Si;
typedef multimap<int,int> MMii;
typedef multiset<int> MSi;
typedef unordered_map<int,int> UMii;
typedef unordered_set<int> USi;
typedef unordered_multimap<int,int> UMMii;
typedef unordered_multiset<int> UMSi;
typedef priority_queue<int> PQi;
typedef queue<int> Qi;
typedef deque<int> DQi;
int n, m, x, y, arr2[1000][1000], colour, mapa[100000];
string arr[1000], temp;
void flood(int i, int j){
    if(i < 0 || i > n) return;
    if(j < 0) j+=m;
    if(j >= m) j-=m;
    if(arr[i][j] != arr[x][y] || arr2[i][j] != 0) return;
    arr2[i][j] = colour;
    flood(i+1,j);
    flood(i-1,j);
    flood(i,j+1);
    flood(i,j-1);
}
int main () {
	while(cin >> n >> m && n && m){
         colour = 1;
         for (int i = 0; i < n; i++)
         {
             cin >> temp;
             arr[i] = temp;
             for (int j = 0; j < m; j++) arr2[i][j] = 0;
         }
         cin >> x >> y;
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++)
             {
                 if(arr2[i][j] == 0 && arr[i][j] == arr[x][y]){
                     flood(i, j);
                     colour++;
                 }
             }
         }
         for (int i = 0; i < colour; i++)
         {
             mapa[i] = 0;
         }
         for (int i = 0; i < n; i++)
         {
             for (int j = 0; j < m; j++)
             {
                 
                 if(arr2[i][j] != arr2[x][y]){
                     mapa[arr2[i][j]]++;
                 }
             }
         }
         int mx = 0;
         for (int i = 1; i < colour; i++)
         {
             mx = max(mx, mapa[i]);
         }
         cout << mx << endl;
    }
    return EXIT_SUCCESS;
}
