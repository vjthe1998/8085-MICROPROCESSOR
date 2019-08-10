#include "all.h"

int instruction_size(string str){
	string one[]={"HLT","MOV","STAX","LDAX","XCHG","ADD","SUB","INR","DCR","INX","DCX","DAD","CMA","CMP"};
	string two[]={"MVI","ADI","SUI"};
	string three[]= {"LXI","LDA","STA","SHLD","LHLD","JMP","JC","JNZ","JNC","JZ"};
	int len=str.length();
	char ch[len];
	strcpy(ch,str.c_str());
	char *temp = strtok (ch," ,");
	int length = sizeof(one)/sizeof(one[0]);
	for(int i=0;i<length;i++){
		if(one[i] == temp)
			return 1;
	}
	length = sizeof(two)/sizeof(two[0]);
	for(int i=0;i<length;i++){
		if(two[i] == temp)
			return 2;
	}
	length = sizeof(three)/sizeof(three[0]);
	for(int i=0;i<length;i++){
		if(three[i] == temp)
			return 3;
	}
	return 0;
}
