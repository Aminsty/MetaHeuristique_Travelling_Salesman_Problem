#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "TSP.hpp"
#include <stdlib.h>


//constructeur à partir d'un fichier dont le nom est entré, avec la méthode de ifstream et istringstream
TSP::TSP(std::string x){
	distances = (int**)malloc(6*sizeof(int*));
	for (int a=0;a<6;a++){
		distances[a]= (int*)malloc(6*sizeof(int));}
	using namespace std;
	ifstream file(x.c_str());
	int i=0, j;
	if (file.is_open()) {
	    string line;
	    file>>num_cities;
	    getline(file, line);
	    while (getline(file, line)) {
	    	j=i+1;
	    	istringstream row(line);
	    	while (row>> distances[i][j++]){
	    		}
	    	i++;
	    }
	    for(i=0;i<num_cities;i++){
	    	for(j=0;j<num_cities;j++){
	    		distances[j][i] = distances[i][j];
	    		if(i==j)
	    			distances[i][j]=0;
			}
		}
	    file.close();
	}
}

//fonction pour retourner le nombre de villes
int TSP::get_num_cities() const{
	return num_cities;
}

//fonction d'affichage de la matrice
void TSP::print(){
	int i;
	std::cout<<"Number of cities : "<<get_num_cities()<<"\n";
	std::cout<<"Matrix of distances between cities :\n";
	for(int i=0;i<num_cities;i++){
		for(int j=0;j<num_cities;j++){
			std::cout<<distances[i][j]<<" ";
		}
		std::cout<<"\n";
	}
}

//fonction du calcul de la distance entre 2 points donnés
int TSP::get_dist(int x, int y){
	return distances[x][y];
}

int test_neighbor[6]; // variable globale tableau, utilisé pour vérifier si la ville qu'on 
//veut tester a été déja parcouru lors de notre chemin ou non
// si la valeur correspondante à cette ville est 1,
// c'est à dire qu'on l'a parcouru sinon on peut la prendre sans problème

//fonction du voisin le plus proche qui utilise ce tableau qui est une variable globale pour tester
int* TSP::Nearest_Neighbor(int *x){
	int	min=1000, j, *index;
		for (j = 0; j < num_cities; j++){
			if(j==*x || test_neighbor[j]==1)
				continue;
			if (get_dist(*x, j) < min){
				min = get_dist(*x, j);
				*index = j;
			}
		}
	return index;
}

