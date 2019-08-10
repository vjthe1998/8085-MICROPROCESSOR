#include "all.h"
#include "support.h"

bool checkdata(string str){
	int len=str.length(),i;
	if(len==2){
		for(i=0;i<len;i++){
			if((str[i]>='0' && str[i]<='9')||(str[i]>='A' && str[i]<='F'))
			continue;
			else
			return false;
		   }
		   if(i==len)return true;
		}
		return false;
	}
