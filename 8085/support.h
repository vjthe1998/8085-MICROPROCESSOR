#ifndef _SUPPORT_H
#define _SUPPORT_H
#include "all.h"

bool check_validity(string);
string UpdatedAddress(string,string);
void code(string,map<string,string>&,string [],map<char,int>&,map<string,string>&,int);
int instruction_size(string str);
string input();
int Command(string,map<string,string>&,string [],map<char,int>&);
void Arithmetic(string,map<string,string>&,string [],map<char,int>&);
string complement(string);
int binarytodec(string);
bool checkregister(string);
bool checkdata(string);
#endif
