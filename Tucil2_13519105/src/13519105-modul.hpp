#ifndef __MODUL_HPP
#define __MODUL_HPP
#include <bits/stdc++.h>
using namespace std;

static string trim(const string& str);

static bool isMember(const vector<string>& v, const string& str);

static int indexKe(const vector<string>& v, const string& str);

static string stringKe(const vector<string>& v, const int& i);


int openFile(vector<string> & graph, ifstream & fin);

void listNode(const vector<string> & graph, vector<string>& node);

void makeAdjList(const vector<string>  & graph, const vector<string> & node, vector<int> adjlist[]);

void topoSort(vector<bool> &visited, vector<int>& order, vector<int> adjlist[]);

void DFSTopo(int node, vector<bool> & visited, vector<int> & order, vector<int>adjlist[]);

void showSMT(vector<int>Semester[],const vector<int>& order, vector<int>adjlist[], const vector<string> & node);
#endif
