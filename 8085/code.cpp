#include "all.h"
#include "support.h"
//const int max=7;
void run(map<string,string>&memory,string registers[],map<char,int>&flag,map<string,string>&program){
	map<string,string>::iterator it;
	for(it=program.begin();it!=program.end();it++){
    //cout<<it->first<<":"<<it->second<<endl;
	string str,pre,program_counter;
	int a,x,a1;
L1:	vector<string>v;
	str=it->second;
	program_counter=it->first;
	int len=str.length();
	char ch[len];
	strcpy(ch,str.c_str());
	char *temp = strtok (ch," ,");
	while (temp != NULL) 
    { 
        v.push_back(temp); 
        temp = strtok(NULL, " ,"); 
    }
	if(v[0]=="JNC"){
		if(v[0]=="JNC")
		pre=v[1];
		    if(flag['C']==0){
			while(program_counter!=pre){
			it++;
			program_counter=it->first;
		/*	cout<<">>"<<program_counter<<":";
	        getline(cin,str);*/
			}
			goto L1;
		}
		}
	else if(v[0]=="JC"){
		if(v[0]=="JC")
		pre=v[1];
		    if(flag['C']==1){
			while(program_counter!=pre){
			it++;
			program_counter=it->first;
			/*cout<<">>"<<program_counter<<":";
	        getline(cin,str);*/
			}
			goto L1;
		}
		}
	else if(v[0]=="JNZ"){
		//cout<<registers[0]<<endl;
		//cout<<registers[2]<<endl;
		//cout<<"Hello"<<endl;
		program_counter=v[1];
		//cout<<v[1]<<endl;
		while(flag['Z']!=1){
		vector<string>v1;
		str=program[program_counter];
		int len=str.length();
		char ch[len];
		strcpy(ch,str.c_str());
		char *temp = strtok (ch," ,");
		while (temp != NULL) 
 	    { 
        v1.push_back(temp); 
        temp = strtok(NULL, " ,"); 
    	}
		program_counter=UpdatedAddress(v1[0],program_counter);
		a1=Command(str,memory,registers,flag);
		if(a1==1)
		Arithmetic(str,memory,registers,flag);
		//cout<<registers[0]<<endl;
		//cout<<registers[2]<<endl;
		if(v1[0]=="JNZ")
		program_counter=v1[1];
		//cout<<v[1]<<endl;
		}
		//it++;
		//program_counter=it->first;
		continue; 
	}
	else if(v[0]=="JMP"){
		string add=v[1];
		while(program_counter!=add){
			it++;
			program_counter=it->first;
			}
			goto L1;
	}
	
	else if(v[0]=="JZ"){
		//cout<<registers[0]<<endl;
		//cout<<registers[2]<<endl;
		//cout<<"Hello"<<endl;
		program_counter=v[1];
		//cout<<v[1]<<endl;
		//cout<<"Hello"<<endl;
		while(flag['Z']!=1){
		vector<string>v1;
		str=program[program_counter];
		//cout<<program_counter<<":"<<str<<endl;
		int len=str.length();
		char ch[len];
		strcpy(ch,str.c_str());
		char *temp = strtok (ch," ,");
		while (temp != NULL) 
 	    { 
        v1.push_back(temp); 
        temp = strtok(NULL, " ,"); 
    	}
		program_counter=UpdatedAddress(str,program_counter);
		a=Command(str,memory,registers,flag);
		if(a==1)
		Arithmetic(str,memory,registers,flag);
		//cout<<registers[0]<<endl;
		//cout<<registers[2]<<endl;
		if(v1[0]=="JNZ")
		program_counter=v[1];
		//cout<<v[1]<<endl;
		}
		program_counter=UpdatedAddress(v[0],program_counter);
		continue; 
	}
	if(str=="HLT"){
	cout<<endl;
	/*for(it=program.begin();it!=program.end();it++){
		cout<<it->first<<":"<<it->second<<endl;
	}*/
	break;
    }
    if(str=="XCHG"){
		swap(registers[7],registers[3]);
		swap(registers[11],registers[4]);
		//program_counter=UpdatedAddress(str,program_counter);
		continue;
	}
	if(str=="CMA"){
		registers[0]=complement(registers[0]);
		//program_counter=UpdatedAddress(str,program_counter);
		continue; 
	}
	//program_counter=UpdatedAddress(str,program_counter);
	a=Command(str,memory,registers,flag);
	if(a==1){
	Arithmetic(str,memory,registers,flag);
	}
}
}

void edit(map<string,string>&memory,string registers[],map<char,int>&flag,map<string,string>&program){
    int k;
    map<string,string>::iterator it;
	while(1){
 	string mem,inst;
 	cout<<"Please enter the address you want to update:";
 	cin>>mem;
 	getchar();
 	cout<<"Please Enter the updated instruction:";
	getline(cin,inst);
	transform(inst.begin(), inst.end(), inst.begin(), ::toupper);
 	program[mem]=inst;
 	for(it=program.begin();it!=program.end();it++)
    cout<<it->first<<":"<<it->second<<endl;
    cout<<"Press 1 to continue editing,otherwise press 0:";
    cin>>k;
	if(k==0)
 	break;
 }
}
void code(string program_counter,map<string,string>&memory,string registers[],map<char,int>&flag,map<string,string>&program,int g){
	int choice;	
	if(g==1){
	edit(memory,registers,flag,program);
	return;	
	}
	else if(g==2){
	run(memory,registers,flag,program);
	return;
}
	while(1){
	string str,pre;
	//int a,x;
	vector<string>v2;
	cout<<">>"<<program_counter<<":";
	getline(cin,str);
	transform(str.begin(), str.end(), str.begin(), ::toupper);
	int len=str.length();
	char ch[len];
	strcpy(ch,str.c_str());
	char *temp = strtok (ch," ,");
	while (temp != NULL) 
   { 
    v2.push_back(temp); 
    temp = strtok(NULL, " ,"); 
    }
	program[program_counter]=str;
	if(program[program_counter]=="HLT")
	break;
	program_counter=UpdatedAddress(str,program_counter);
  }
}

