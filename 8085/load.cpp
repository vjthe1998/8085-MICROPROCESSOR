#include "all.h"
#include "support.h"

int Command(string str,map<string,string>&memory,string registers[],map<char,int>&flag){
	int i;
	vector<string>v;
	int len=str.length();
	char ch[len];
	strcpy(ch,str.c_str());
	char *temp = strtok (ch," ,");
	while (temp != NULL) 
    { 
        v.push_back(temp); 
        temp = strtok(NULL, " ,"); 
    } 

    string s1,s2;
    s1=v[1];
    char ch1[v[1].length()];
	strcpy(ch1,s1.c_str());
	
    if(v[0]=="MVI"){
    	registers[ch1[0]-'A']=v[2];
    	return 0;
	}  
     else if(v[0]=="MOV"){
     	s2=v[2];
    	char ch2[v[2].length()];
		strcpy(ch2,s2.c_str());
     	registers[ch1[0]-'A']=registers[ch2[0]-'A'];
		 return 0;
	 }
     else if(v[0]=="LDA"){
     	registers[0]=memory[v[1]];
		 return 0;
	 }
	 else if(v[0]=="LXI"){
	 		string s3=v[2],s4="";
	 		if(v[1]=="B"||v[1]=="D"){
			registers[ch1[0]-'A']=s4+s3[0]+s3[1];
			s4="";
			registers[ch1[0]-'A'+1]=s4+s3[2]+s3[3];
	 	    }
			else if(v[1]=="H"){
				registers[ch1[0]-'A']=s4+s3[0]+s3[1];
				s4="";
				registers[ch1[0]-'A'+4]=s4+s3[2]+s3[3];
	 		}
	 		else
	 		cout<<"Invalid Register:"<<endl;
		return 0;
	 }
	 else if(v[0]=="LHLD"){
	 	registers[11]=memory[v[1]];
	 	string str=v[1];
	 	str=UpdatedAddress("MOV",str);
		registers[7]=memory[str];
		return 0;	
	 }
	 else if(v[0]=="STA"){
	 	memory[v[1]]=registers[0];
		 return 0;
	 }
	 else if(v[0]=="SHLD"){
	 	string str=v[1];
	 	memory[v[1]]=registers[11];
	 	str=UpdatedAddress("MOV",str);
		 memory[str]=registers[7];
	 	 return 0;
		 }
	 return 1;
}
