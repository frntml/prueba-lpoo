#include <iostream>
#include <string.h>
#include <conio.h>
#include <time.h>
#define SIZE 15
using namespace std;

char mostrar_tablero(char tablero[SIZE][SIZE], char liebre[SIZE][SIZE], char tortuga[SIZE][SIZE]){ //funcion para imprimir el tablero, la posicion de la tortuga y la liebre
	for(int i=0; i<SIZE; i++){
		for(int j=0; j<SIZE; j++){
			if(liebre[i][j]!='L'){
				if(tortuga[i][j]!='T'){
					cout << "|" << tablero[i][j];
				}
				else cout << "|" << tortuga[i][j];
			}
			else cout << "|" << liebre[i][j];
		}
		cout << "|" << endl;
	}
}

char lado_liebre(char liebre[SIZE][SIZE], int lado, int dado){ //funcion para verificar el lado que eligio el jugador para mover la liebre, y si se puede mover o no
	int i, j;
	for(i=0; i<SIZE; i++){			//este for es para verificar la posicion de la liebre
		for(j=0;j<SIZE; j++){
			if(liebre[i][j]=='L'){
				continue;
			}
		}
	}
	if(lado == 1 && (j-dado)>=0){	//este if es para verificar si se puede mover o no a la izquierda
		liebre[i][j]='\0';
		liebre[i][j-dado]='L';
	}
	if(lado == 2 && (i-dado)>=0){	//este if es para verificar si se puede mover para arriba o no
			liebre[i][j]='\0';
			liebre[i-dado][j]='L';	
	}
	if(lado == 3 && (j+dado)<=SIZE){//este if es lo mismo para la derecha
		liebre[i][j]='\0';
		liebre[i][j+dado]='L';
	}
	if(lado == 4 && (i+dado)<=SIZE){//y este para abajo
		liebre[i][j]='\0';
		liebre[i+dado][j]='L';
	}
}

char lado_tortuga(char tortuga[SIZE][SIZE], int lado, int dado){//funcion para verificar el lado que eligio el jugador para mover la tortuga, y si se puede mover o no
	int i, j;
	for(i=0; i<SIZE; i++){			//este for es igual que el de la liebre pero para la tortuga
		for(j=0;j<SIZE; j++){
			if(tortuga[i][j]=='L'){
				continue;
			}
		}
	}
	if(lado == 1 && (j-dado)>=0){ 	//los mismo if hechos para la tortuga
		tortuga[i][j]='\0';			//y verificar los pasos que da y si puede o no puede
		tortuga[i][j-dado]='T';
	}
	if(lado == 2 && (i-dado)>=0){	
		tortuga[i][j]='\0';
		tortuga[i-dado][j]='T';
	}
	if(lado == 3 && (j+dado)<=SIZE){
		tortuga[i][j]='\0';
		tortuga[i][j+dado]='L';
	}
	if(lado == 4 && (i+dado)<=SIZE){
		tortuga[i][j]='\0';
		tortuga[i+dado][j]='T';
	}
}

int main(){
	char liebre[SIZE][SIZE];
	char tortuga[SIZE][SIZE];
	char pozo[SIZE][SIZE];
	char tablero[SIZE][SIZE];
	for(int i=0; i<SIZE; i++){		//crear el tablero con las X
		for(int j=0; j<SIZE; j++){
			tablero[i][j]='X';
			liebre[i][j]='\0';
		}
	}
	liebre[0][0]='L';
	tortuga[0][0]='T';
	int dado;
	int lado;
	while(1){
		mostrar_tablero(tablero, liebre, tortuga);					//todo este while es el juego
		cout << endl << "-----------------------------" << endl;
		cout << "TURNO DE LA LIEBRE:" << endl;
		srand(time(NULL));											//randomizar el dado
		dado= 1+rand() % (7-1);
		cout << "numero del dado: " << dado << endl;
		cout << "mover hacia [1=izquierda] [2=arriba] [3=derecha] [4=abajo]: ";
		cin >> lado;
		lado_liebre(liebre, lado, dado);							//
		system("cls");
		mostrar_tablero(tablero, liebre, tortuga);
		cout << endl << "-----------------------------" << endl;
		cout << "TURNO DE LA TORTUGA:" << endl;
		srand(time(NULL));
		dado= 1+rand() % (7-1);
		cout << "numero del dado: " << dado << endl;
		cout << "mover hacia [1=izquierda] [2=arriba] [3=derecha] [4=abajo]: ";
		cin >> lado;
		lado_tortuga(tortuga, lado, dado);
		system("cls");
	}
}
