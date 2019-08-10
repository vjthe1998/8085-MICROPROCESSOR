#include "all.h"
#include "support.h"

int binarytodec(string str){
	int sum=0,k=0;
	for(int i=str.length()-1;i>=0;i--){
		sum=sum+(pow(2,i)*int(str[k]-48));
		k++;
	}
	return sum;
}
string complement(string n){
	char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	map<char,int>m;
	string str="";
	for(int i=0;i<16;i++)
	m[arr[i]]=i;
	string str1="";
	//cin>>n;
	int t=2,b=0;
	while(t--){
	bitset<4>set4(m[n[b]]);
	//cout<<set4<<endl;
	str="";
	for (int i = set4.size()-1; i>=0; i--){
		if(set4.test(i))
		str+='0';
		else
		str+='1';
	} 
	//cout<<str<<endl;
	int res=binarytodec(str);
	str1+=arr[res];
	b++;
}
  return str1; 
}
