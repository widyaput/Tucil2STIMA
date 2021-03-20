#include <bits/stdc++.h>
#include "13519105-modul.hpp"
using namespace std;

int main(){
    string namafile;
    getline(cin,namafile);
    namafile = "../test/" + namafile;
    ifstream fin(namafile);
    vector<string> graph;
    openFile(graph,fin); //buka isifile kedalam vector graph, satu barisnya sebagai 1 elemen

    vector<string> node;
    listNode(graph,node); //list node-node yang ada dalam graph
    vector<int> adjlist [node.size()];
    makeAdjList(graph,node,adjlist); //buat adjacency list dari tiap-tiap node
    
    vector<int> order;
    vector<bool> visited; //set semua node belum dikunjungi
    for(int i = 0; i < node.size(); ++i){
        visited.push_back(false);
    }
    topoSort(visited,order,adjlist); //lakukan topological sort

    vector<int> Semester[node.size()];
    showSMT(Semester,order,adjlist,node); //tampilkan hasilnya
    cout<< endl;
    fin.close();
    return 0;
}
