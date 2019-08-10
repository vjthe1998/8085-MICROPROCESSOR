#include "all.h"
#include "support.h"
	string input(){
	string start_add;
	cout<<"Enter a starting address:";
	cin>>start_add;
	if(!check_validity(start_add)){
		cout<<"You have entered an Invalid Address location.Please Enter between (0000H to FFFFH) only.\nThe Program will terminate:";
		exit(0);
	}
	cout<<"Type code below:\n";
	getchar();
	return start_add;
}
