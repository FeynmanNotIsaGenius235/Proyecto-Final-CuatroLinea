#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void leerReglas(string rutaArchivoEntrada){
	
	string linea;
	
	ifstream ArchivoEntrada(rutaArchivoEntrada.c_str());
	
	if(ArchivoEntrada.is_open()){		
		while(getline(ArchivoEntrada,linea)){
			cout<<linea<<endl;
		}
		
		cin.get();

    	system("cls");
		
	}
	
}

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
		
	return 1+ContarFichas(Tablero,fila+1,columna,Jugador);
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
	
	char JugadorActual;
	
	int Columna;
	
	string Jugador_1,Jugador_2;
	
	bool jugarOtraVez = true,gano;
	
	leerReglas("Entrada/INSTRUCCIONES.txt");
	
	cout<<"Bienvenido a la interfaz del juego Cuatro en linea"<<endl;
			
	cout<<"Para continuar escriba el nombre del jugador 1:"<<endl;
		
	cin>>Jugador_1;
		
	cout<<"Para continuar escriba el nombre del jugador 2:"<<endl;
		
	cin>>Jugador_2;
			
	while(jugarOtraVez){
		
			InicializarTablero(TableroJuego); 
			
			gano=false;

			while(!gano){
				
				JugadorActual='#';
        
        		MostrarTablero(TableroJuego);
        		
        		cout << "Turno: " << Jugador_1<< " seleccione la columna: "<<endl;
        		
        		cin>>Columna;
        		
        		int Fila=ColocarFicha(TableroJuego,Columna,JugadorActual);
        		
        		gano=verificarGanador(TableroJuego,Fila,Columna,JugadorActual);
        
        		if(!gano){
        			
        			JugadorActual='$';
        
        			MostrarTablero(TableroJuego);
        		
        			cout << "Turno: " << Jugador_2<< " seleccione la columna: "<<endl;
        		
        			cin>>Columna;
        		
        			int Fila=ColocarFicha(TableroJuego,Columna,JugadorActual);
        		
        			gano=verificarGanador(TableroJuego,Fila,Columna,JugadorActual);

        		}
    		}
			
			MostrarTablero(TableroJuego);
						
			cout<<"Partida Finalizada.."<<endl;	
			
			cout << "¡Jugador " << JugadorActual<< " ganó!" << endl;

			
			cout << "¿Desean jugar otra vez? (s/n): ";
			
   			char respuesta;
   			
    		cin >> respuesta;
    		
    		jugarOtraVez =(respuesta == 's');	
				
		}
			
    return 0;
}

