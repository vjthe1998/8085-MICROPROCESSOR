#include "all.h"
#include "support.h"
//const int max=7;
class Microprocessor{
private:
	string registers[12];//={"","","","","","",""};
	//vector<string>registers;
	string program_counter;
	map<string,string>program;
	map<char,int>flag;
	map<char,int>::iterator fg;
	map<string,string>memory;
    map<string,string>::iterator it;
public:
	void init(){
		char a[5]={'S','Z','A','P','C'};
		for(int i=0;i<5;i++)
		flag[a[i]]=0;
	}
	void call(){
	program_counter=input();
}
void call2(){
	code(program_counter,memory,registers,flag,program,0);
}
void Set(){
	string str1,str2;
	//Memory=MemSet(Memory);
	cout<<"Enter the memory address:";
	cin>>str1;
	if(!check_validity(str1)){
		cout<<"You have entered an Invalid Address location.Please Enter between (0000H to FFFFH) only.\nThe Program will terminate:";
		exit(0);
	}
	cout<<"Enter the data to be inserted:";
	cin>>str2;
	memory[str1]=str2;
	for(it=memory.begin();it!=memory.end();it++)
	cout<<it->first<<":"<<it->second<<" ";
	cout<<endl;
}
void status(){
	cout<<"Register Status:"<<endl;
	cout<<"value at register A:"<<registers[0]<<endl;
	cout<<"value at register B:"<<registers[1]<<endl;
	cout<<"value at register C:"<<registers[2]<<endl;
	cout<<"value at register D:"<<registers[3]<<endl;
	cout<<"value at register E:"<<registers[4]<<endl;
	cout<<"value at register H:"<<registers[7]<<endl;
	cout<<"value at register L:"<<registers[11]<<endl;
	cout<<endl;
	cout<<"Memory Status:"<<endl;
	for(it=memory.begin();it!=memory.end();it++)
	cout<<it->first<<":"<<it->second<<endl;
	cout<<endl;
	cout<<"Flags Status:"<<endl;
	for(fg=flag.begin();fg!=flag.end();fg++)
	cout<<fg->first<<":"<<fg->second<<endl;
}
 void editing(){
 	code(program_counter,memory,registers,flag,program,1);
 }
 
 void running(){
 	code(program_counter,memory,registers,flag,program,2);
 }
};

int main(){
	cout<<"*********************8085 Microprocessor Emulator************************\n";
	Microprocessor object;
	object.init();
	int ch;
	do{
	cout<<"Enter your choice:\n 1.To Type The Code\n 2.To Store Something in memory locations\n 3.Edit \n 4.Run\n 5.Output\n 6.Exit\n";
	cin>>ch;
	switch(ch){
	case 1:
	object.call();
	object.call2();	
	break;
	case 2:
	object.Set();	
	break;
	case 3:
	object.editing();
	break;
	case 4:
	object.running();
	break;
	case 5:
	object.status();
	break;
	case 6:
	exit(0);
	break;
	default:
	cout<<"Invlid Choice:"<<endl;
	break;
	}
}while(1);

	return 0;
}
