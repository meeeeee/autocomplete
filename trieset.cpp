#include <bits/stdc++.h>
using namespace std;
typedef string str;
typedef unsigned long long ll;

unordered_map<char, uint> mp;
const ll p = 31, mod = 1e9 + 9;

ll binex(ll a, ll b, ll m){
	ll ans=1;
	while(b){
		if(b&1) ans=(ans*a)%m;
		b/=2;
		a=(a*a)%m;
	}
	return ans;
}

ll shash(string st){ // rolling variable-string hash
	ll hsh = 0;
	for(int a = 0; a < (int)st.size(); a++) hsh = (hsh + (ll)mp[st[a]]*binex(p, a, mod))%mod;
	return hsh;
}

struct triple{
	string st;
	int cnt;
	ll hash;
	triple(){}
	triple(string ist, int icnt):st(ist),cnt(icnt),hash(shash(ist)){}
};
typedef set<triple, decltype([](triple a, triple b){return a.hash > b.hash;})> sett; // reverse comparator to get largest element not greater than

ll trie[1000][26][26] = {};
int k;
sett autocmpl[1000][26][26], emptyset;

bool chk(str s){ // checks if s has previously been processed
	uint prev = 0;
	for(int a = 0; a < (int)s.size(); prev = mp[s[a]], a++) if(!mp.count(s[a]) || !trie[a][prev][mp[s[a]]]) return false;
	return true;
}

sett traverse(string s){ // return the set associated with the last edge
	if(s.size() == 0 || !mp.count(s[s.size()-1])) return emptyset;
	else if(s.size() == 1 || !mp.count(s[s.size()-2])) return autocmpl[0][0][mp[s[s.size()-1]]];
	else return autocmpl[s.size()-1][mp[s[s.size()-2]]][mp[s.size()-1]];
}

void ins(triple s, sett *st){ // helper function to update edge sets
	if(st -> begin() -> cnt > s.cnt){
		if((int)st -> size() < k) st -> insert(s);
	}
	else{
		st -> erase(st -> lower_bound(s));
		st -> insert(s);
	}
}

void insert(string s){ // update edge counts and update each edge set
	if(s.size() == 0) return;
	uint prev = 0;
	triple *tmp;
	for(int a = 0; a < (int)s.size(); prev = mp[s[a]], a++){
		if(!mp.count(s[a])) return;
		trie[a][prev][mp[s[a]]]++;
		if(a == (int)(s.size()-1)) tmp = new triple(s, trie[a][prev][mp[s[a]]]);
	}
	prev = 0;
	for(int a = 0; a < (int)s.size(); prev = mp[s[a]], a++) ins(*tmp, &(autocmpl[a][prev][mp[s[a]]]));
	// update sets by iterating over each edge and checking conditions before adding to edge
}

int main(){
	return 0;
}
