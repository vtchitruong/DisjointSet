#include <bits/stdc++.h>

#define inputFile "fc3.inp"
#define outputFile "fc3.out"

using namespace std;

int n; // number of queries
vector<pair<int, int>> query;

map<int, int> friendship; // 2 people shake hands each other, something like partition or connected component
map<int, int> sz; // size of a friend circle (of a connected component)
int maxSize = 0; // maxSize of all friend circles

void Input()
{
    ifstream f;
    f.open(inputFile);

    f >> n;

    for (int i = 0; i < n; ++i)
    {
        int a, b;        
        f >> a >> b;
        query.push_back({a, b});
    }

    f.close();
}

int root(int v) // root of friendship
{
    // if v not found, then init v
    if (sz.find(v) == sz.end()) // not found
    {
        friendship[v] = v;
        sz[v] = 1;
    }

    return (friendship[v] == v) ? v : friendship[v] = root(friendship[v]);
}

void shakeHands(int a, int b) // union
{
    a = root(a);
    b = root(b);

    if (a == b) return; // a and b are already friends

    if (a > b) swap(a, b);

    friendship[a] = b;
    sz[b] += sz[a];
    maxSize = max(maxSize, sz[b]);
}

vector<int> maxCircle()
{
    vector<int> res; /// max size of all friend circles

    for (int i = 0; i < n; ++i)
    {
        int a = query[i].first;
        int b = query[i].second;
        
        shakeHands(a, b);
        res.push_back(maxSize);
    }

    return res;
}

void Output() // result
{
    vector<int> r = maxCircle();

    ofstream f;
    f.open(outputFile);

    for (int i = 0; i < r.size(); ++i)
    {
        f << r[i];
        if (!(i == r.size() - 1)) f << '\n';
    }

    f.close();
}

int main()
{
    Input();
    
    Output();

    return 0;
}