#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "TSP.hpp"
#include <stdlib.h>

//fonction main où on teste les fonctions
int main(){
	using namespace std;
	string a;
	int dep, i, *next;
	next = (int*)malloc(6*sizeof(int));
	cout<<"Enter the input file name : ";
	cin>>a;
	TSP p1(a);
	p1.print();
	std::cout<<"Choose a departure city : ";
	std::cin>>dep;
	test_neighbor[dep]=1;
	*(next)=dep;
	for(i=0;i<p1.get_num_cities();i++){
		*(next+i+1) = *(p1.Nearest_Neighbor(next+i));
		test_neighbor[*(next+i+1)]=1;
	}
	for(i=0;i<p1.get_num_cities();i++){
		cout<<*(next+i)<<"-->";
	}
	cout<<dep;
	return 0;
}
