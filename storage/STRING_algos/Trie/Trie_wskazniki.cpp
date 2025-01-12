/*
	Drzewo Trie
*/
#include <bits/stdc++.h>
using namespace std;

struct TrieNode
{
	struct TrieNode *children[26];
	bool koniec;
};

struct TrieNode *createNode(void)
{
	struct TrieNode *Node = new TrieNode;
	Node->koniec = 0;
	for (int i=0; i<26; i++)
		Node->children[i] = NULL;
	return Node;
};

void add2Trie(struct TrieNode *root, string s)
{
	struct TrieNode *v = root;
	
	for (char c : s)
	{
		if (!v->children[c-'a'])
			v->children[c-'a'] = createNode();
		
		v = v->children[c-'a'];
	}
	
	v->koniec = 1;
}

bool checkinTrie(struct TrieNode *root, string s)
{
	struct TrieNode *v = root;
	
	for (char c : s)
	{
		if (!v->children[c-'a'])
			return 0;
		
		v = v->children[c-'a'];
	}
	
	return (v->koniec);
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	struct TrieNode *root = createNode();
	
	int n, m; cin >> n >> m;
	
	// tworzenie słownika
	for (int i=0; i<n; i++)
	{
		string s; cin >> s;
		add2Trie(root, s);
	}
	
	// sprawdzanie czy słowo należy do słownika
	for (int i=0; i<m; i++)
	{
		string s; cin >> s;
		cout << (checkinTrie(root, s) ? "TAK\n" : "NIE\n");
	}
	
	return 0;
}
