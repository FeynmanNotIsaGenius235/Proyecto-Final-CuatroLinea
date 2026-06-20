#include <iostream>
#include <fstream>
using namespace std;

void InicializarTablero(char Tablero[6][7]){
	
	for(int i=0;i<6;i++){
		for(int j=0;j<7;j++){
			Tablero[i][j]='.';
		}
	}
}

void MostrarTablero(char Tablero[6][7]){
	
	cout<<"\t";	
	for(int i=1;i<8;i++){
		cout<<i;
	}
	cout<<endl;
	
	for(int i=0;i<6;i++){
		cout<<"\t";

		for(int j=0;j<7;j++){
			cout<<Tablero[i][j];
		}
		cout<<endl;
	}
}

int FilaDisponible(char Tablero[6][7],int ColumnaSeleccionada,int FilaActual=6){
	
	if(FilaActual<0){
		return -1;
	}
	
	if(Tablero[FilaActual][ColumnaSeleccionada]=='.'){
		return FilaActual;
	}
		
	return FilaDisponible(Tablero,ColumnaSeleccionada,FilaActual-1);
}

int ColocarFicha(char Tablero[6][7],int columna, char jugador){
	
	int Fila=FilaDisponible(Tablero,columna);
	
	if(Fila!=-1 && (columna>=0 && columna<=6)){
		Tablero[Fila][columna]=jugador;
		return Fila;
	}else{

	}
	
}

int ContarFichas(char Tablero[6][7], int fila, int columna, char Jugador){
	
	if(fila<0){
		return 0;
	}
	
	if(Tablero[fila][columna]!=Jugador){
		return 0;
	}
		
	return 1+ContarFichas(Tablero,fila-1,columna,Jugador);
}


bool verificarGanador(char Tablero[6][7], int fila, int columna, char Jugador){
	
	int FichasSeguidas=ContarFichas(Tablero,fila,columna,Jugador);
	
	if(FichasSeguidas>=4){
		return true;
	}else{
		return false;
	}
	
}


int main(){
	
	char TableroJuego[6][7];
	
	InicializarTablero(TableroJuego);
	
	MostrarTablero(TableroJuego);
	
	int Fila=ColocarFicha(TableroJuego,0,'#');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila<<endl;
	
	Fila=ColocarFicha(TableroJuego,0,'#');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila<<endl;
	
	Fila=ColocarFicha(TableroJuego,0,'#');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila<<endl;
	
	cout<<verificarGanador(TableroJuego,5,0,'#')<<endl;
	
	Fila=ColocarFicha(TableroJuego,0,'#');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila<<endl;
	
	cout<<verificarGanador(TableroJuego,5,0,'#');
	
	int Fila1=ColocarFicha(TableroJuego,1,'$');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila1<<endl;
	
	Fila1=ColocarFicha(TableroJuego,1,'$');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila1<<endl;
	
	Fila1=ColocarFicha(TableroJuego,1,'$');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila1<<endl;
	
	cout<<verificarGanador(TableroJuego,5,1,'$')<<endl;
	
	Fila1=ColocarFicha(TableroJuego,1,'$');
	
	MostrarTablero(TableroJuego);
	
	cout<<Fila1<<endl;
	
	cout<<verificarGanador(TableroJuego,5,1,'$');
		
    return 0;
}

