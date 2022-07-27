#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma,sse,sse2,sse3,sse4")
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef string str;
const int MOD = 1e9 + 9;
const int INF = 0x3f3f3f3f;
uint trie[1000][26] = {};
unordered_map<char, uint> mp;

bool chkadd(string s){
	if(!s.size()) return true;
	bool chk = true;
	uint prev = 1;
	for(int a = 0; a < (int)s.size(); a++){
		if(!mp.count(s[a])){
			chk = false;
			break;
		}
		if(!((trie[a][mp[s[a]]] >> (prev-1))&1)){
			trie[a][mp[s[a]]] += 1 << (prev - 1);
			chk = false;
		}
		prev = mp[s[a]];
	}
	return chk;
}

int main(){
	int n;
	string st;
	cin >> n >> st;
	for(int a = 0; a < (int)st.size(); a++) mp[st[a]] = a+1;
	while(n--){
		cin >> st;
		printf(chkadd(st) ? "YES\n" : "NO\n");
	}
	return 0;
}
/* prefix tree/trie --- maintain an array with maximum string size by alphabet size, initialize to 1, traverse nodes by incrementing array position & checking if the next character exists if the kth bit of the number is 1 (note that the array type must contain at least as many bits as there are characters in the alphabet; rather than using a uint or ull, we can use a bitset) */
/* supports checking if a string or prefix exists and adding it to the trie in \Theta(n) */
/* T1 (lowercase alphabet)
 * 10 abcde
 * a
 * b
 * a
 * ab
 * abcde
 * ab
 * ac
 * abcd
 * b
 * bcd
 * ---
 * NO
 * NO
 * YES
 * NO
 * NO
 * YES
 * NO
 * YES
 * YES
 * NO
 */
