#include "all.h"
#include "support.h"

void Arithmetic(string str,map<string,string>&memory,string registers[],map<char,int>&flag){
	char arr[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	map<char,int>m;
	for(int i=0;i<16;i++)
	m[arr[i]]=i;
	int ns;
	vector<string>v;
	int sum=0,c=0;
	int len=str.length();
	char ch[len];
	strcpy(ch,str.c_str());
	char *temp = strtok (ch," ,");
	while (temp != NULL) 
    { 
        v.push_back(temp); 
        temp = strtok(NULL, " ,"); 
    }
    char ch1[v[1].length()];
	strcpy(ch1,v[1].c_str());
	if(v[0]=="ADD"){
		string str1,str2,str3;
			str1=registers[0];
			str2=registers[ch1[0]-'A'];
			str3="";	    		
		for(int i=str1.length()-1;i>=0;i--){
			sum=m[str1[i]]+m[str2[i]]+c;
			if(sum>15){
				str3+=arr[(sum-15)-1];
				c=1;
			}
			else{
				str3+=arr[sum];
				c=0;	
			}
		}
		flag['C']=c;
		reverse(str3.begin(),str3.end());
		registers[0]=str3;
		if(str3=="00")
		flag['Z']=1;
		else 
		flag['Z']=0;
		
		bitset<4>set1(m[str3[0]]);
		if(set1.test(set1.size()-1))
		flag['S']=1;
		else
		flag['S']=0;
		
		bitset<8>set2(m[str3[0]]);
		bitset<8>set3(m[str3[1]]);
		if((set2.count()+set3.count())%2==0)
		flag['P']=1;
		else
		flag['P']=0;
	}
    
 else if(v[0]=="ADI"){
 	string str1,str2,str3="";
 	str1=registers[0];
 	str2=v[1];
 	for(int i=str1.length()-1;i>=0;i--){
			sum=m[str1[i]]+m[str2[i]]+c;
			if(sum>15){
				str3+=arr[(sum-15)-1];
				c=1;
			}
			else{
				str3+=arr[sum];
				c=0;	
			}
		}
		flag['C']=c;
		reverse(str3.begin(),str3.end());
		registers[0]=str3;
		if(str3=="00")
		flag['Z']=1;
		else 
		flag['Z']=0;
		
		bitset<4>set1(m[str3[0]]);
		if(set1.test(set1.size()-1))
		flag['S']=1;
		else
		flag['S']=0;
		
		bitset<8>set2(m[str3[0]]);
		bitset<8>set3(m[str3[1]]);
		if((set2.count()+set3.count())%2==0)
		flag['P']=1;
		else
		flag['P']=0;
		
 	}
 else if(v[0]=="INR"){
 	string str1,str2,str3="";
 		str1=registers[ch1[0]-'A'];
 		str2="01";
 	for(int i=str1.length()-1;i>=0;i--){
			sum=m[str1[i]]+m[str2[i]]+c;
			if(sum>15){
				str3+=arr[(sum-15)-1];
				c=1;
			}
			else{
				str3+=arr[sum];
				c=0;	
			}
		}
		//flag['C']=c;
		reverse(str3.begin(),str3.end());
		registers[ch1[0]-'A']=str3;
		if(str3=="00")
		flag['Z']=1;
		else 
		flag['Z']=0;
		
		bitset<4>set1(m[str3[0]]);
		if(set1.test(set1.size()-1))
		flag['S']=1;
		else
		flag['S']=0;
		
		bitset<8>set2(m[str3[0]]);
		bitset<8>set3(m[str3[1]]);
		if((set2.count()+set3.count())%2==0)
		flag['P']=1;
		else
		flag['P']=0;
	 }
	 else if(v[0]=="SUB"){
	 	string str1,str2,str3="";
	 		str1=registers[0];
	 		str2=registers[ch1[0]-'A'];
	 		for(int i=str1.length()-1;i>=0;i--){
	 			sum=m[str1[i]]-m[str2[i]]-c;
	 			if(sum<0){
	 			sum=sum+16;
	 			c=1;
	 		}
	 		else
	 		c=0;
	 		str3+=arr[sum];
	 		}
	 		flag['C']=c;
	 		reverse(str3.begin(),str3.end());
	 		registers[0]=str3;
	 		if(str3=="00")
			flag['Z']=1;
			else 
			flag['Z']=0;
			bitset<4>set1(m[str3[0]]);
			if(set1.test(set1.size()-1))
			flag['S']=1;
			else
			flag['S']=0;
			
		bitset<8>set2(m[str3[0]]);
		bitset<8>set3(m[str3[1]]);
		if((set2.count()+set3.count())%2==0)
		flag['P']=1;
		else
		flag['P']=0;
	 }
	 else if(v[0]=="SUI"){
	 	string str1,str2,str3="";
 		str1=registers[0];
 		str2=v[1];
 		for(int i=str1.length()-1;i>=0;i--){
	 			sum=m[str1[i]]-m[str2[i]]-c;
	 			if(sum<0){
	 			sum=sum+16;
	 			c=1;
	 		}
	 		else
	 		c=0;
	 		str3+=arr[sum];
	 		}
	 		flag['C']=c;
	 		reverse(str3.begin(),str3.end());
	 		registers[0]=str3;
	 		if(str3=="00")
			flag['Z']=1;
			else 
			flag['Z']=0;
			
			bitset<4>set1(m[str3[0]]);
			if(set1.test(set1.size()-1))
			flag['S']=1;
			else
			flag['S']=0;
			
		bitset<8>set2(m[str3[0]]);
		bitset<8>set3(m[str3[1]]);
		if((set2.count()+set3.count())%2==0)
		flag['P']=1;
		else
		flag['P']=0;
		}
		else if(v[0]=="DCR"){
		string str1,str2,str3="";
 		str1=registers[ch1[0]-'A'];
 		str2="01";
 		for(int i=str1.length()-1;i>=0;i--){
	 			sum=m[str1[i]]-m[str2[i]]-c;
	 			if(sum<0){
	 			sum=sum+16;
	 			c=1;
	 		}
	 		else
	 		c=0;
	 		str3+=arr[sum];
	 		}
	 		//flag['C']=c;
	 		reverse(str3.begin(),str3.end());
	 		registers[ch1[0]-'A']=str3;
	 		if(str3=="00")
			flag['Z']=1;
			else 
			flag['Z']=0;
			
			bitset<4>set1(m[str3[0]]);
			if(set1.test(set1.size()-1))
			flag['S']=1;
			else
			flag['S']=0;
			
		bitset<8>set2(m[str3[0]]);
		bitset<8>set3(m[str3[1]]);
		if((set2.count()+set3.count())%2==0)
		flag['P']=1;
		else
		flag['P']=0;
		}
		else if(v[0]=="INX"){
		string str1,str2,str3="";
		if(v[1]=="B"||v[1]=="D")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+1];
		else if(v[1]=="H")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+4];
		else
		cout<<"Invalid Register"<<endl;
		//cout<<str1<<endl;
 		str2="0001";
 	for(int i=str1.length()-1;i>=0;i--){
			sum=m[str1[i]]+m[str2[i]]+c;
			if(sum>15){
				str3+=arr[(sum-15)-1];
				c=1;
			}
			else{
				str3+=arr[sum];
				c=0;	
			}
		}
		flag['C']=c;
		reverse(str3.begin(),str3.end());
		//cout<<str3<<endl;
		if(str3=="0000")
		flag['Z']=1;
		else 
		flag['Z']=0;
		registers[ch1[0]-'A']=str3.substr(0,2);
		if(v[1]=="B"||v[1]=="D")
		registers[ch1[0]-'A'+1]=str3.substr(2,2);
		else if(v[1]=="H")
		registers[ch1[0]-'A'+4]=str3.substr(2,2);	
		}
		
		else if(v[0]=="DCX"){
		string str1,str2,str3="";
 		if(v[1]=="B"||v[1]=="D")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+1];
		else if(v[1]=="H")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+4];
		else
		cout<<"Invalid Register"<<endl;
 		str2="0001";
 		for(int i=str1.length()-1;i>=0;i--){
	 			sum=m[str1[i]]-m[str2[i]]-c;
	 			if(sum<0){
	 			sum=sum+16;
	 			c=1;
	 		}
	 		else
	 		c=0;
	 		str3+=arr[sum];
	 		}
	 		flag['C']=c;
	 		reverse(str3.begin(),str3.end());
	 		if(str3=="0000")
			flag['Z']=1;
	 		else 
			flag['Z']=0;
			registers[ch1[0]-'A']=str3.substr(0,2);
	 		if(v[1]=="B"||v[1]=="D")
			registers[ch1[0]-'A'+1]=str3.substr(2,2);
			else if(v[1]=="H")
			registers[ch1[0]-'A'+4]=str3.substr(2,2);	
		}
		else if(v[0]=="DAD"){
		string str1,str2,str3="";
		str1=registers[7]+registers[11];
		if(v[1]=="B" || v[1]=="D")
		str2=registers[ch1[0]-'A']+registers[ch1[0]-'A'+1];
		else if(v[1]=="H")
		str2=registers[7]+registers[11];
		else
		cout<<"Invalid Registers:";
		for(int i=str1.length()-1;i>=0;i--){
			sum=m[str1[i]]+m[str2[i]]+c;
			if(sum>15){
				str3+=arr[(sum-15)-1];
				c=1;
			}
			else{
				str3+=arr[sum];
				c=0;	
			}
		}
		flag['C']=c;
		reverse(str3.begin(),str3.end());
		if(str3=="0000")
		flag['Z']=1;
		else 
		flag['Z']=0;
		registers[7]=str3.substr(0,2);
		registers[11]=str3.substr(2,2);	
		}
		else if(v[0]=="CMP"){
			if(registers[0]<registers[ch1[0]-'A']){
				flag['C']=1;
				flag['Z']=0;
			}
				else if(registers[0]>registers[ch1[0]-'A']){
				flag['C']=0;
				flag['Z']=0;
			}
				else if(registers[0]==registers[ch1[0]-'A']){
				flag['C']=0;
				flag['Z']=1;
			}
		}
		else if(v[0]=="STAX"){
		string str1;
 		if(v[1]=="B"||v[1]=="D")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+1];
		else if(v[1]=="H")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+4];
		else
		cout<<"Invalid Register"<<endl;
		memory[str1]=registers[0];	
		}
		
		else if(v[0]=="LDAX"){
		string str1;
 		if(v[1]=="B"||v[1]=="D")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+1];
		else if(v[1]=="H")
		str1=registers[ch1[0]-'A']+registers[ch1[0]-'A'+4];
		else
		cout<<"Invalid Register"<<endl;
		registers[0]=memory[str1];	
		}
 }

