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

int FilaDisponible(char Tablero[6][7],int ColumnaSeleccionada,int FilaActual=5){
	
	if(FilaActual<0){
		return -1;
	}
	
	if(Tablero[FilaActual][ColumnaSeleccionada]=='.'){
		return FilaActual;
	}
		
	return FilaDisponible(Tablero,ColumnaSeleccionada,FilaActual-1);
}

bool jugadaValida(char Tablero[6][7], int ColumnaSeleccionada){
	
	if(ColumnaSeleccionada<0 || ColumnaSeleccionada>6){
		return false;
	}
	
	int Fila=FilaDisponible(Tablero,ColumnaSeleccionada);
	
	if(Fila==-1){
		return false;
	}else{
		return true;
	}
	
}

int ColocarFicha(char Tablero[6][7],int columna, char jugador){
	
	int Fila=FilaDisponible(Tablero,columna);
	
	if(Fila!=-1 && (columna>=0 && columna<=6)){
		Tablero[Fila][columna]=jugador;
		return Fila;
	}else{

	}
	
}

int ContarFichas(char Tablero[6][7], int fila, int columna,int DeltaFila,int DeltaColumna,char Jugador){
	
	if(fila<0 || fila>5 || columna<0 || columna>6){
		return 0;
	}
	
	if(Tablero[fila][columna]!=Jugador){
		return 0;
	}
		
	return 1+ContarFichas(Tablero,fila+DeltaFila,columna+DeltaColumna,DeltaFila,DeltaColumna,Jugador);
}


bool verificarGanador(char Tablero[6][7], int fila, int columna, char Jugador){
	
	int Arriba=ContarFichas(Tablero,fila-1,columna,-1,0,Jugador);
	
	int Abajo=ContarFichas(Tablero,fila+1,columna,+1,0,Jugador);
	
	if((1+Arriba+Abajo)==4){
		return true;
	}
	
	int Izquierda=ContarFichas(Tablero,fila,columna-1,0,-1,Jugador);
	
	int Derecha=ContarFichas(Tablero,fila,columna+1,0,+1,Jugador);
	
	if((1+Izquierda+Derecha)==4){
		return true;
	}
	
	int ArribaIzquierda=ContarFichas(Tablero,fila-1,columna-1,-1,-1,Jugador);
	
	int AbajoDerecha=ContarFichas(Tablero,fila+1,columna+1,+1,+1,Jugador);
	
	if((1+ArribaIzquierda+AbajoDerecha)==4){
		return true;
	}
	
	int ArribaDerecha=ContarFichas(Tablero,fila-1,columna+1,-1,+1,Jugador);
	
	int AbajoIzquierda=ContarFichas(Tablero,fila+1,columna-1,+1,-1,Jugador);
	
	if((1+ArribaDerecha+AbajoIzquierda)==4){
		return true;
	}
		
	return false;
	
}

void GuardarInformacion(string rutaArchivoSalida,char JugadorActual, bool gano){
	
	ofstream Archivo(rutaArchivoSalida.c_str(),ios_base::app);
        
    if(gano){
    	Archivo<< "Partida finalizada. " <<JugadorActual<< " gano!" << endl;
	}else{
   		Archivo<< "Partida finalizada. Empate!" << endl;
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
	
	ofstream archivo("Salida/HISTORICOJuegos.txt", ios_base::app);
	
	archivo<<Jugador_1<<"\t"<<Jugador_2<<endl;
			
	while(jugarOtraVez){
		
			InicializarTablero(TableroJuego); 
			
			gano=false;
			
			int TurnosJugados=0;

			while(!gano && TurnosJugados<42){
			        		
        		JugadorActual='#';
        
        		MostrarTablero(TableroJuego);
        		
        		do{      			
        			cout << "Turno: " << Jugador_1<< " seleccione la columna: "<<endl;
        		
        			cin>>Columna;
        			
        			if(!jugadaValida(TableroJuego, Columna)){
        				cout << "Columna inválida o llena. Intente de nuevo." << endl;
   					}
        			
				}while(!jugadaValida(TableroJuego, Columna));
        		
        		int Fila=ColocarFicha(TableroJuego,Columna,JugadorActual);
        			
        		TurnosJugados+=1;
        		
        		gano=verificarGanador(TableroJuego,Fila,Columna,JugadorActual);
        
        		if(!gano){
        			
        			JugadorActual='$';
        
        			MostrarTablero(TableroJuego);
        			
        			do{      			
        			cout << "Turno: " << Jugador_2<< " seleccione la columna: "<<endl;
        		
        			cin>>Columna;
        			
        			if(!jugadaValida(TableroJuego, Columna)){
        				cout << "Columna inválida o llena. Intente de nuevo." << endl;
   					}
        			
					}while(!jugadaValida(TableroJuego, Columna));
        		        		        		
        			int Fila=ColocarFicha(TableroJuego,Columna,JugadorActual);
        			
        			TurnosJugados+=1;
        		
        			gano=verificarGanador(TableroJuego,Fila,Columna,JugadorActual);

        		}
    		}
			
			MostrarTablero(TableroJuego);
						
			cout<<"Partida Finalizada.."<<endl;	
			
			string ArchivoSalida="Salida/HISTORICOJuegos.txt";
			
			GuardarInformacion(ArchivoSalida,JugadorActual,gano);
					
			cout << "¿Desean jugar otra vez? (s/n): ";
			
   			char respuesta;
   			
    		cin >> respuesta;
    		
    		jugarOtraVez =(respuesta == 's');	
				
		}
			
    return 0;
}

