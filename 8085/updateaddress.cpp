#include "all.h"
#include "support.h"

string UpdatedAddress(string str,string pc){
	char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	map<int,char>m;
	for(int i=0;i<16;i++)
	m[i]=arr[i];
	
	int a=instruction_size(str);
	int i=3;
	while(i>=0){
		pc[i]=pc[i]+a;
		if(pc[i]>57 && pc[i]<65){
			pc[i]=64+(pc[i]-'9');
			break;
		}
		else if(pc[i]>70){
			pc[i]=47+(pc[i]-'F');
			i--;
			a=1;
		}
		else
		break;
	}
  return pc;
}
