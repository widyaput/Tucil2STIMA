#include "13519105-modul.hpp"
#include <bits/stdc++.h>
using namespace std;

string trim(const string& str)
{
    size_t first = str.find_first_not_of(" \n\t\r\v");
    size_t last = str.find_last_not_of(" \n\t\r\v");
    return str.substr(first, (last-first+1));
}

bool isMember(const vector<string>& v, const string& str){
    for (auto string : v){
        if (string == str) return true;
    }
    return false;
}

int indexKe(const vector<string>& v, const string& str){
    if (isMember(v,str)){
        int i;
        for (i = 0; i < v.size(); ++i){
            if (v[i] == str) return i; 
        }
    }
    else return -1;
}

string stringKe(const vector<string>& v, const int& i){
    if (i < v.size()) return v[i];
    return "Null";
}
int openFile(vector<string> & graph,ifstream & fin){
    string line;
    if (!fin){
        cout << "Problem opening" << endl;
        return 1;
    }else{
        while(getline(fin,line, '.')){ //ambil setiap line yang diakhiri titik
            graph.emplace_back(trim(line)); //trim agar tidak ada typo di dalamnya
        }
        cout << line;       
    }
    return 0;
}

void listNode(const vector<string> & graph, vector<string>& node){
    for (auto sentence : graph){
        string n00de;
        size_t prekoma = 0;
        size_t koma = sentence.find_first_of(","); //cari posisi koma sebagai pemisah
        if (koma == string::npos){ //jika ternyata tidak ada koma, masukkan sentence ke dalam node jika belum ada
            if (!isMember(node, sentence)){
                node.emplace_back(sentence);
            }
        }
        while (koma != string::npos){ //selama koma masih dapat dicari
            n00de = sentence.substr(prekoma,(koma-prekoma)); //ambil substring dari indeks prekoma sampai koma
            prekoma = koma+1; //cari prekoma baru
            while(sentence[prekoma] == ' ' or sentence[prekoma] == '\t'){
                prekoma++;
            }
            koma = sentence.find_first_of(",", koma+1); //cari koma baru
            if (!isMember(node,n00de)){ //jika sentence belum ada di dalam node, masukkan ke dalam node
                node.emplace_back(n00de);
            }
        }
        n00de = sentence.substr(prekoma,sentence.length()); //ambil kata terakhir dan cek jika dimasukkan atau belum
        if (!isMember(node,n00de)){
            node.emplace_back(n00de);
        }
    }
}

void makeAdjList(const vector<string>  & graph,const vector<string> & node, vector<int> adjlist[]){
    for (auto sentence :graph){
        string head;
        size_t prekoma = 0;
        size_t koma = sentence.find_first_of(","); //cek posisi koma sebagai pemisah
        if (koma == string::npos){ 
            //koma tidak ada, satu line hanya berisi satu node atau string, skip ke sentence selanjutnya
        }else{
            head = sentence.substr(prekoma,(koma-prekoma)); //ambil substring node pertama
            int idxh = indexKe(node,head);//cari indeks node head
            prekoma = koma+1; //cari prekoma baru
            while(sentence[prekoma] == ' ' or sentence[prekoma] == '\t'){
                prekoma++;
            }
            koma = sentence.find_first_of(",", koma+1); //cari koma baru
            string body;
            while (koma != string::npos){ //selama koma masih dapat dicari
                body = sentence.substr(prekoma,(koma-prekoma));
                prekoma = koma+1; //cari prekoma baru
                while(sentence[prekoma] == ' ' or sentence[prekoma] == '\t'){
                    prekoma++;
                }
                koma = sentence.find_first_of(",",koma+1); //cari koma baru
                int idxb = indexKe(node,body); //cari indeks node body
                adjlist[idxb].push_back(idxh); //masukkan node indeks head ke dalam tetangga indeks body
            }
            body = sentence.substr(prekoma,sentence.length()); //ambil kata terakhir
            int idxb = indexKe(node,body); //cari indeksnya
            adjlist[idxb].push_back(idxh);//masukan node indeks head ke dalam tetangganya
        }
        
    }
}

void topoSort(vector<bool> & visited, vector<int>& order, vector<int> adjlist[]){
    for (int i = 0; i < visited.size(); ++i){
        if (visited[i] == false){
            DFSTopo(i,visited,order,adjlist); //jika belum dikunjungi, lakukan dfs
        }
    }

    reverse(order.begin(),order.end()); //reverse order hasil dfs sehingga topological sort terurut
}

void DFSTopo(int node,vector<bool> &visited, vector<int>& order, vector<int> adjlist[]){
    visited[node] = true;
    for (int i = 0; i < adjlist[node].size() ; i++){
        int neighbour = adjlist[node][i];
        if (!visited[neighbour]){
            DFSTopo(neighbour, visited, order, adjlist);
        }
    }
    order.push_back(node);
}

void showSMT(vector<int>Semester[],const vector<int>& order, vector<int>adjlist[], const vector<string>& node){
    int i = 0;
    
    int j = 1;
    Semester[0].push_back(order[0]);
    while(j < order.size()){
        bool found = false;
        for (int k = 0; k < Semester[i].size(); k++){
            for (int l = 0; l < adjlist[Semester[i][k]].size(); l++){
                if (adjlist[Semester[i][k]][l] == order[j]){
                //jika elemen order selanjutnya merupakan tetangga dari salah satu node dalam semester tertentu
                    found = true;
                }
            }
        }
        if (found){
            i++; //maka semester dianggap cukup anggotanya dan pindah ke semester selanjutnya
        }else{
            Semester[i].push_back(order[j]); // jika tidak tambahkan node ke anggota semester itu
            j++; //cek node selanjutnya
        }

    }
    for (int k =0; k <= i; k++){ //print semua node dalam tiap2 elemen semester yang sudah terisi
        cout << "Semester " << k+1 << " : ";
        for (int j = 0; j < Semester[k].size();j++){
            
            cout << stringKe(node,Semester[k][j]);
            if (j == Semester[k].size()-1){
                cout <<endl;
            }else{
                cout  << ", ";
            }
        }
    }
}
