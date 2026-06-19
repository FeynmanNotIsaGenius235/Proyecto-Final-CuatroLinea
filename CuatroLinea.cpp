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

int FilaDisponible(char Tablero[6][7],int ColumnaSeleccionada,int FilaActual=5){
	
	if(FilaActual<0){
		return -1;
	}
	
	if(Tablero[FilaActual][ColumnaSeleccionada]=='.'){
		return FilaActual;
	}
	
	return FilaDisponible(Tablero,ColumnaSeleccionada,FilaActual-1);
}

bool jugadaValida(char Tablero[6][7],int ColumnaSeleccionada){
	
}


void ColocarFicha(char Tablero[6][7],int columna, char jugador){
	
	int fila=FilaDisponible(Tablero,columna);
	
	if(columna<7 && fila!=-1){
		
		Tablero[fila][columna-1]=jugador;
		
	}else{
		cout<<"\n\n"<<"Jugada Inválida.Columna Fuera de Rango o Columna Llena"<<"\n\n";
	}
				
}
int main() {
	char TableroJuego[6][7];
	
	InicializarTablero(TableroJuego);
	
	MostrarTablero(TableroJuego);
	
	ColocarFicha(TableroJuego,3,'#');
	
	MostrarTablero(TableroJuego);
	
	ColocarFicha(TableroJuego,7,'#');
	
	MostrarTablero(TableroJuego);



    return 0;
}

