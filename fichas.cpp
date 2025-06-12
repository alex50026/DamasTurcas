#include "fichas.h"
#include "tablero.h"
#define FTOTAl 16

 /*--------------------------------------------------------------------------------------------------------------------------------\
|                                                        TIPO INT                                                                  |
\---------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------
PARA MOVER LA FILA
------------------------------------*/
int muevefila(){
    int retorno=0;
    cout<<"\nAhora digite, en forma de coordenadas, la posiciona a la que desea mover la ficha:\n";
    cout<<"fila: ";
    cin>>retorno;
    retorno -= 1;
    return retorno;
}

/*----------------------------------
PARA MOVER COLUMNA
------------------------------------*/
int muevecol(){
    int retorno=0;
    cout<<"columna: ";
    cin>>retorno;
    retorno -= 1;
    return retorno;
}

/*----------------------------------
PARA ELEGIR LA FILA
------------------------------------*/
int eligefila(t_jugador J){
    
    int retorno=0;
    cout<<"\n"<<J.nombre<<", digita la ficha que deseas mover"<<endl;
    cout<<"fila: ";
    cin>>retorno;
    retorno -= 1;
    return retorno;
}

/*----------------------------------
PARA ELEGIR LA COLUMNA
------------------------------------*/
int eligecol(){
    
    int retorno=0;
    cout<<"columna: ";
    cin>>retorno;
    retorno -= 1;
    return retorno;
}

/*----------------------------------
PARA ELEGIR FILA CUANDO COME
------------------------------------*/
int laFAcomer(){
    int retorno=0;
    cout<<"\nbasado en ello, digite los valores que desea:"<<endl;
    cout<<"fila: ";
    cin>>retorno;
    retorno -= 1;
    return retorno;
}
/*--------------------------------------------------------------------------------------------------------------------------------\
|                                                        TIPO BOOL                                                                  |
\---------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------
¿CUMPLE CON REQUISITOS DE SELECCION?
------------------------------------*/
bool cumpleTodo(int fila, int columna, char tablero[TAM][TAM + 1], char fig, char f2, int restric, char C){
    bool retorno=true;
    bool corono=false;
    int a=fila;
    int b=columna;
    if (restric==1){
        if(((tablero[a][b] != fig) && (tablero[a][b] != C))
        ||((tablero[a - 1][b] != ' ')&&(tablero[a][b + 1] != ' ')&&(tablero[a][b - 1] != ' '))){
            cout<<"No tiene una ficha en esa posicion o esa ficha no puede moverse, intente nuevamente"<<endl;
            retorno=false;
        }
    }
    else{
        if(((tablero[a][b] != fig) && (tablero[a][b] != C))
        ||((tablero[a + 1][b] != ' ')&&(tablero[a][b + 1] != ' ')&&(tablero[a][b - 1] != ' '))){
            cout<<"No tiene una ficha en esa posicion o esa ficha no puede moverse, intente nuevamente"<<endl;
            retorno=false;
        }
    }
    return retorno;
}

/*----------------------------------
¿CUMPLE CON REQUISITOS DE SELECCION AL COMER?
------------------------------------*/
bool cumpleFeo(int fila, int columna, char tablero[TAM][TAM + 1], char fig, char f2, int restric, char C, bool corono){
    bool retorno=true;
    int a=fila;
    int b=columna;
    if(corono==false){
        if (restric==1){
            if(((tablero[a][b] != 'X') && (tablero[a][b] != '+'))||((RevisaEnCruz(tablero, a, b,  'O', 1, 'Q', fig)==false)&&(RevisaEnCruz(tablero, a, b,  'O', 1, 'Q', C)==false))){
                cout<<"Esa ficha no esta entre las disponibles, intente nuevamente:"<<endl;
                retorno=false;
            }
        }
        else{
            if(((tablero[a][b] != 'O') && (tablero[a][b] != 'Q'))||((RevisaEnCruz(tablero, a, b,  'X', -1, '+', fig)==false)&&(RevisaEnCruz(tablero, a, b,  'X', -1, '+', C)==false))){
                cout<<"Esa ficha no esta entre las disponibles, intente nuevamente:"<<endl;
                retorno=false;
            }
        }
    }
    if(corono==true){
        if (restric==1){
            if(((tablero[a][b] != 'X') && (tablero[a][b] != '+'))||(AsesinaEnPto(tablero, a, b,  'O', 1, 'Q', '+')==false))
                retorno=false;
        }
        if (restric==-1){
            if(((tablero[a][b] != 'O') && (tablero[a][b] != 'Q'))||((AsesinaEnPto(tablero, a, b,  'X', -1, '+', 'Q')==false))){
                cout<<"Esa ficha no esta entre las disponibles, intente nuevamente:"<<endl;
                retorno=false;
            }
        }
    }
    return retorno;
}


/*----------------------------------
¿ACASO TODO ENTRE EL PUNTO QUE QUIERES Y EN QUE ESTAS ESTA VACIO?
------------------------------------*/
bool EstaVacio(int fila, int columna, char tablero[TAM][TAM + 1], int Forg, int Corg, int res){
    bool si=true;
    int i=0, p=0;;
    if (res==0){
        p=Forg;
        for(i=Corg + 1; i<columna; i++)
            if(tablero[p][i] != ' '){
                si=false;
            }
    }
    if(res==1){
        p=Corg;
        for(i=Forg + 1; i<fila; i++)
            if(tablero[i][p] != ' ')
                si=false;
    }
    return si;
}

/*----------------------------------
¿CUMPLE CON MOVS AL COMER?
------------------------------------*/
bool cumple2movimiento(int filaORG, int columnaORG, int fila, int col, char tablero[TAM][TAM + 1], char fig, char f2, int restric, char C, bool corono){
    //AQUI ENTRARAN TODAS LAS RESTRICCIONES DE MOVIMIENTO AL COMER
    bool retorno=true;
    if(corono==false){
        if(restric==1){
            if (((fila != filaORG) && (col != columnaORG))||(tablero[fila][col] != ' ')
            || (fila>7) || (col>7)||(fila>filaORG)|| (fila<0) || (col<0)|| (col < (columnaORG - 2))
            || (col > (columnaORG + 2))||(fila < (filaORG - 2))||((tablero[fila][col + 1] != 'O')&&(tablero[fila][col - 1] != 'O')&&(tablero[fila + 1][col] != 'O')
            &&(tablero[fila][col + 1] != 'Q')&&(tablero[fila][col - 1] != 'Q')&&(tablero[fila + 1][col] != 'Q'))){
                cout<<"Ese movimiento es ilegal, revise que la posicion deseada este dentro del tablero, que no haya ninguna ficha ahi, y que coma tras moverse"<<endl;
                retorno=false;
                }
        }
        else{
            if (((fila != filaORG) && (col != columnaORG)) || (fila > (filaORG + 2)) || (col < (columnaORG - 2))
            || (col > (columnaORG + 2)) ||(tablero[fila][col] != ' ') || (fila>7) || (col>7)||(fila<filaORG)|| (fila<0)
            || (col<0)||((tablero[fila][col + 1] != 'X')&&(tablero[fila][col - 1] != 'X')&&(tablero[fila - 1][col] != 'X'))
            &&(tablero[fila][col + 1] != '+')&&(tablero[fila][col - 1] != '+')&&(tablero[fila - 1][col] != '+')){
                cout<<"Ese movimiento es ilegal, revise que la posicion deseada este dentro del tablero, que no haya ninguna ficha ahi, y que solo se mueva de a un espacio hacia adelante o a los lados:"<<endl;
                retorno=false;
            }
        }
    }
    if(corono==true){
        if(restric==1){
            if (((fila != filaORG) && (col != columnaORG))||(tablero[fila][col] != ' ')
            || (fila>7) || (col>7)|| (fila<0) || (col<0)
            ||((tablero[fila][col + 1] != 'O')&&(tablero[fila][col - 1] != 'O')&&(tablero[fila + 1][col] != 'O')&&(tablero[fila - 1][col] != 'O')
            &&(tablero[fila][col + 1] != 'Q')&&(tablero[fila][col - 1] != 'Q')&&(tablero[fila + 1][col] != 'Q')&&(tablero[fila - 1][col] != 'Q'))){
                cout<<"Ese movimiento es ilegal, revise que la posicion deseada este dentro del tablero, que no haya ninguna ficha ahi, y que coma tras moverse"<<endl;
                retorno=false;
                }
        }
        else{
            if (((fila != filaORG) && (col != columnaORG))||(tablero[fila][col] != ' ') || (fila>7) || (col>7)|| (fila<0)
            || (col<0)||((tablero[fila][col + 1] != 'X')&&(tablero[fila][col - 1] != 'X')&&(tablero[fila - 1][col] != 'X')&&(tablero[fila + 1][col] != 'X'))
            &&(tablero[fila][col + 1] != '+')&&(tablero[fila][col - 1] != '+')&&(tablero[fila - 1][col] != '+')&&(tablero[fila + 1][col] != '+')){
                cout<<"Ese movimiento es ilegal, revise que la posicion deseada este dentro del tablero, que no haya ninguna ficha ahi, y que solo se mueva de a un espacio hacia adelante o a los lados:"<<endl;
                retorno=false;
            }
        }
    }
    return retorno;
}

/*----------------------------------
¿LA FICHA PUEDE COMER?
------------------------------------*/
bool RevisaEnCruz(char tablero[TAM][TAM + 1], int fila, int columna,  char f2, int restric, char Otro, char fig){
    bool PuedeComer=false;
    if(((tablero[fila][columna + 1]==f2)&&(tablero[fila][columna + 2]==' ')&&(tablero[fila][columna]==fig))
    ||((tablero[fila][columna - 1]==f2)&&(tablero[fila][columna - 2]==' ')&&(tablero[fila][columna]==fig))
    ||((tablero[fila][columna + 1]==Otro)&&(tablero[fila][columna + 2]==' ')&&(tablero[fila][columna]==fig))
    ||((tablero[fila][columna - 1]==Otro)&&(tablero[fila][columna - 2]==' ')&&(tablero[fila][columna]==fig))){
            PuedeComer=true;
    }
    if (restric==1)
        if((tablero[fila - 1][columna]=='O')&&(tablero[fila - 2][columna]==' ')
        ||(tablero[fila - 1][columna]=='Q')&&(tablero[fila - 2][columna]==' ')){
                PuedeComer=true;
        }
    if  (restric==-1)
        if((tablero[fila + 1][columna]=='X')&&(tablero[fila + 2][columna]==' ')||(tablero[fila + 1][columna]=='+')&&(tablero[fila + 2][columna]==' ')){
                PuedeComer=true;
        }
    return PuedeComer;
    /*
    aqui falta la restriccion respecto a fichas coronadas
    */
}

/*----------------------------------
¿ALGUNA FICHA CORONADA PUEDE COMER?
------------------------------------*/
bool RevisaReinaAsesina(char tablero[TAM][TAM + 1], int fila, int columna,  char f2, int restric, char Otro, char fig){
    bool PuedeComer=false;
    int i=0, p=0, j=0, q=0, l=0, m=0, t=0;
    char PL[TAM]={0};
    //primero las columnas
    for(i=0; i<TAM; i++){
        for(p=0; p<TAM; p++){
            for(j=TAM; j>0; j--){
                if(restric==1)
                    if(((tablero[i][p]=='+')&&(tablero[i][j]=='O')&&(tablero[i][j + 1]==' '))&&(EstaVacio(i, j, tablero, i, p, 0)==true)
                    ||((tablero[i][p]=='O')&&(tablero[i][j]=='+')&&(tablero[i][p - 1]==' '))&&(EstaVacio(i, p, tablero, i, j, 0)==true)
                    ||((tablero[i][p]=='+')&&(tablero[i][j]=='Q')&&(tablero[i][j + 1]==' '))&&(EstaVacio(i, j, tablero, i, p, 0)==true)
                    ||((tablero[i][p]=='Q')&&(tablero[i][j]=='+')&&(tablero[i][p - 1]==' '))&&(EstaVacio(i, p, tablero, i, j, 0)==true)){
                        PuedeComer=true;
                    }
                if(restric==-1)
                    if(((tablero[i][p]=='Q')&&(tablero[i][j]=='X')&&(tablero[i][j + 1]==' '))&&(EstaVacio(i, j, tablero, i, p, 0)==true)
                    ||((tablero[i][p]=='X')&&(tablero[i][j]=='Q')&&(tablero[i][p - 1]==' '))&&(EstaVacio(i, p, tablero, i, j, 0)==true)
                    ||((tablero[i][p]=='Q')&&(tablero[i][j]=='+')&&(tablero[i][j + 1]==' '))&&(EstaVacio(i, j, tablero, i, p, 0)==true)
                    ||((tablero[i][p]=='+')&&(tablero[i][j]=='Q')&&(tablero[i][p - 1]==' '))&&(EstaVacio(i, p, tablero, i, j, 0)==true)){
                        PuedeComer=true;
                    }
                
            }
        }
    }

    return PuedeComer;
}

/*----------------------------------
¿LA FICHA CORONADA PUEDE COMER?
------------------------------------*/
bool AsesinaEnPto(char tablero[TAM][TAM + 1], int fila, int columna,  char f2, int restric, char Otro, char fig){
    bool PuedeComer=false;
    int i=0, p=0, j=0, w=0;
    //primero las columnas
    for(j=0; j<columna; j++){
        if(restric==1)
            if(((tablero[fila][columna]=='+'||tablero[fila][columna]=='X')&&(tablero[fila][j]=='O'||tablero[fila][j]=='Q'))&&(tablero[fila][j - 1]==' ')&&(EstaVacio(fila, j, tablero, fila, columna, 0)==true)){
                PuedeComer=true;
            }
            
        if(restric==-1)
            if(((tablero[fila][columna]=='Q'||tablero[fila][columna]=='O')&&(tablero[fila][j]=='X'||tablero[fila][j]=='+'))&&(tablero[fila][j - 1]==' ')&&(EstaVacio(fila, j, tablero, fila, columna, 0)==true)){
                    PuedeComer=true;
                
            }
    }
    for(p=columna; p<TAM; p++){
        if(restric==1)
            if(((tablero[fila][columna]=='+'||tablero[fila][columna]=='X')&&(tablero[fila][p]=='O'||tablero[fila][p]=='Q'))&&(tablero[fila][p + 1]==' ')&&(EstaVacio(fila, columna, tablero, fila, p, 0)==true)){
                PuedeComer=true;
            }
            
        if(restric==-1)
            if(((tablero[fila][columna]=='Q'||tablero[fila][columna]=='O')&&(tablero[fila][p]=='X'||tablero[fila][p]=='+'))&&(tablero[fila][p + 1]==' ')&&(EstaVacio(fila, columna, tablero, fila, p, 0)==true)){
                    PuedeComer=true;
                
            }
    }
    //filas
    for(i=0; i<fila; i++){
        if(restric==1)
            if(((tablero[fila][columna]=='+'||tablero[fila][columna]=='X')&&(tablero[i][columna]=='O'||tablero[i][columna]=='Q'))&&(tablero[i + 1][columna]==' ')&&(EstaVacio(i, columna, tablero, fila, columna, 1)==true)){
                PuedeComer=true;
                EstaVacio(i, columna, tablero, fila, columna, 1);
            }
            
        if(restric==-1)
            if(((tablero[fila][columna]=='Q'||tablero[fila][columna]=='O')&&(tablero[i][columna]=='X'||tablero[i][columna]=='+'))&&(tablero[i + 1][columna]==' ')&&(EstaVacio(i, columna, tablero, fila, columna, 1)==true)){
                    PuedeComer=true;
                EstaVacio(i, columna, tablero, fila, columna, 1);
            }
    }
    for(w=0; w<fila; w++){
        if(restric==1)
            if(((tablero[fila][columna]=='+'||tablero[fila][columna]=='X')&&(tablero[w][columna]=='O'||tablero[w][columna]=='Q'))&&(tablero[w - 1][columna]==' ')&&(EstaVacio(fila, columna, tablero, w, columna, 0)==true)){
                PuedeComer=true;
                EstaVacio(fila, columna, tablero, w, columna, 0);
            }
            
        if(restric==-1)
            if(((tablero[fila][columna]=='Q'||tablero[fila][columna]=='O')&&(tablero[w][columna]=='X'||tablero[w][columna]=='+'))&&(tablero[w - 1][columna]==' ')&&(EstaVacio(fila, columna, tablero, w, columna, 0)==true)){
                    PuedeComer=true;
                    EstaVacio(fila, columna, tablero, w, columna, 0);
            }
    }
    return PuedeComer;
}
/*----------------------------------
¿ALGUNA FICHA DEL TABLERO COME?
------------------------------------*/
bool SiEsQHay(char tablero[TAM][TAM + 1], int restric){
    int i=0, j=0;
    bool puedeC=false;
    bool corona=false;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            if((restric==1)&&(((RevisaEnCruz(tablero, i, j,  'O', 1, 'Q', 'X')==true)&&(tablero[i][j]=='X'))
            ||((RevisaReinaAsesina(tablero, i, j,  'O', 1, 'Q', '+')==true)&&((tablero[i][j]=='+')||((tablero[i][j]=='X')&&(coronacion(tablero, i, j, '+')==true)))))){
                puedeC=true;
            }
            if((restric==-1)&&(((RevisaEnCruz(tablero, i, j,  'X', -1, '+', 'O')==true)&&(tablero[i][j]=='O'))
            ||((RevisaReinaAsesina(tablero, i, j,  'X', -1, '+', 'Q')==true)&&((tablero[i][j]=='Q')||((tablero[i][j]=='O')&&(coronacion(tablero, i, j, 'Q')==true)))))){
                puedeC=true;
            }
        }
    }
    
    cout<<"\n"<<puedeC<<endl;
    return puedeC;
}

/*----------------------------------
¿ACASO LA FICHA CORONO?
------------------------------------*/
bool coronacion(char tablero[TAM][TAM + 1], int fila, int columna, char figCoro){
    bool coronado=false;
    if((fila==7)||(fila==0)||(tablero[fila][columna]==figCoro)){
        coronado=true;
    }
        
    return coronado;
}

/*----------------------------------
ACASO LA FICHA CORONADA SE PUEDE MOVER ASI?
------------------------------------*/
bool MovRealeza(char tablero[TAM][TAM + 1], int fila, int columna, char figCoro, int restric, int Forg, int Corg){
    bool retorno=true;
    int i=0, j=0;
    if(columna != Corg){
        i=Forg;
        for(j=Corg + 1; j<=columna; j++){
            if (restric==1){
                if((tablero[i][j]=='X')||(tablero[i][j]=='+')||((tablero[i][j]=='O') && (tablero[i][j - 1]!=' '))||((tablero[i][j]=='Q') && (tablero[i][j - 1]!=' '))){
                    retorno=false;
                    cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                }
                if((tablero[i][j]=='X')||(tablero[i][j]=='+')||((tablero[i][j]=='O') && (tablero[i][j + 1]!=' '))||((tablero[i][j]=='Q') && (tablero[i][j + 1]!=' '))){
                    retorno=false;
                    cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                }
            }
            else{
                if((tablero[i][j]=='O')||(tablero[i][j]=='Q')||((tablero[i][j]=='X') && (tablero[i][j - 1]!=' '))||((tablero[i][j]=='+') && (tablero[i][j - 1]!=' '))){
                    retorno=false;
                    cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                }
                if((tablero[i][j]=='O')||(tablero[i][j]=='Q')||((tablero[i][j]=='X') && (tablero[i][j + 1]!=' '))||((tablero[i][j]=='+') && (tablero[i][j + 1]!=' '))){
                    retorno=false;
                    cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                }
            }
        }
    }
    if(fila != Forg){
        j=Corg;
        if(fila>Forg)
            for(i=Forg + 1; i<=fila; i++){
                if (restric==1){
                    if((tablero[i][j]=='X')||(tablero[i][j]=='+')||((tablero[i][j]=='O') && (tablero[i + 1][j]=='O'))||((tablero[i][j]=='Q') && (tablero[i + 1][j]=='Q'))){
                        retorno=false;
                        cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                    }
                }
                if (restric==-1){
                    if((tablero[i][j]=='O')||(tablero[i][j]=='Q')||((tablero[i][j]=='X') && (tablero[i + 1][j]=='X'))||((tablero[i][j]=='+') && (tablero[i + 1][j]=='+'))){
                        retorno=false;
                        cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                    }
                }
            }
        if(fila<Forg)
            for(i=Forg - 1; i>=fila; i--){
                if (restric==1){
                    if((tablero[i][j]=='X')||(tablero[i][j]=='+')||((tablero[i][j]=='O') && (tablero[i - 1][j]=='O'))||((tablero[i][j]=='Q') && (tablero[i - 1][j]=='Q'))){
                            retorno=false;
                            cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                        }
                }
                if (restric==-1){
                    if((tablero[i][j]=='O')||(tablero[i][j]=='Q')||((tablero[i][j]=='X') && (tablero[i][j - 1]=='X'))||((tablero[i][j]=='+') && (tablero[i - 1][j]=='+'))){
                        retorno=false;
                        cout<<endl<<"["<<i + 1<<","<<j + 1<<"]"<<endl;
                    }
                }
            }
    }
    cout<<endl<<retorno<<endl;
    return retorno;
}

 /*--------------------------------------------------------------------------------------------------------------------------------\
|                                                        TIPO VOID                                                                  |
\---------------------------------------------------------------------------------------------------------------------------------*/

/*----------------------------------
AREA DE FUNCIONAMIENTO DEL JUEGO
------------------------------------*/
void Jugando(char tablero[TAM][TAM + 1]){
    t_jugador J1={" ", false}, J2={" ", false};
    string Nom1=" ", Nom2=" ";
    bool J1W=false, J2W=false;
    int fichasJs[2]={{0}};
    int turnos=0;
    cout<<"\n";
    cout<<"    ___                              _____"<<endl;                         
    cout<<"   /   -__ _ _ __ ____   __ _ ___  /__  __|_   _ _ _ ___  __ _ ___ "<<endl; 
    cout<<"  / __ / _` | '_ ` _  | / _` / __|   / /  | | | '__/| __|/ _` / __|"<<endl; 
    cout<<" / /_// (_| | | | | | || (_| |__ |  / /   | |_| | | | (_| (_| |__ |"<<endl; 
    cout<<"/___,'|___,_|_| |_| |_||__,_ |___/  |/    |__,__|_| |___|__,__|___/"<<endl;
    cout<<"                     Tomas Silva, Alexander Aponte\n"<<endl;
    llenaTablero(tablero);
    ImprimeTablero(tablero);
    cout<<"\n";
    //LLENANDO STRUCTS DE JUGADORES
    cout<<"----------------------------------\n";
    cout<<"Jugador 1, digite su nombre: ";
    cin>>Nom1;
    cout<<"----------------------------------\n";
    cout<<"Jugador 2, digite su nombre: ";
    cin>>Nom2;
    cout<<"----------------------------------\n";
    J1.nombre=Nom1;
    J2.nombre=Nom2;
    //Hora de jugar!
    while(J1.gano==false && J2.gano==false){
        LeeTab(tablero, fichasJs);
        if(fichasJs[1]==0){
            J1W=true;
            J1.gano=J1W;
            cout<<"\n\n             ¡Felicidades: "<<J1.nombre<<", eres el ganador!"<<endl;
            break;
        }
        if(fichasJs[0]==0){
            J2W=true;
            J2.gano=J2W;
            cout<<"\n\n             ¡Felicidades: "<<J2.nombre<<", eres el ganador!"<<endl;
            break;
        }
        if((fichasJs[0]==16)&&(fichasJs[1]==16)&&(turnos>16)){
            cout<<"\n\n             Empate por regla de los 16 movimientos"<<endl;
            break;
        }
        if((fichasJs[0]==1)&&(fichasJs[1]==1)){
            cout<<"\n\n             Empate por falta de piezas"<<endl;
            break;
        }
        realizaJ1(tablero, J1);
        LeeTab(tablero, fichasJs);
        if(fichasJs[1]==0){
            J1W=true;
            J1.gano=J1W;
            cout<<"\n\n             ¡Felicidades: "<<J1.nombre<<", eres el ganador!"<<endl;
            break;
        }
        if(fichasJs[0]==0){
            J2W=true;
            J2.gano=J2W;
            cout<<"\n\n             ¡Felicidades: "<<J2.nombre<<", eres el ganador!"<<endl;
            break;
        }
        
        realizaJ2(tablero, J2);
        LeeTab(tablero, fichasJs);
        if(fichasJs[1]==0){
            J1W=true;
            J1.gano=J1W;
            cout<<"\n\n             ¡Felicidades: "<<J1.nombre<<", eres el ganador!"<<endl;
            break;
        }
        if(fichasJs[0]==0){
            J2W=true;
            J2.gano=J2W;
            cout<<"\n\n             ¡Felicidades: "<<J2.nombre<<", eres el ganador!"<<endl;
            break;
        }
    turnos++;
    }    
}


/*----------------------------------
MOVIMIENTO SIN COMER
------------------------------------*/
void mueveficha(char tablero[TAM][TAM + 1], int a, int b, char fig,  char f2, int restric, bool corono, char C){
    int fila=0, columna=0, p=0;
    cout<<"Ahora digite, en forma de coordenadas, la posiciona a la que desea mover la ficha:\n";
    cout<<"fila: ";
    cin>>fila;
    fila -= 1;
    cout<<"columna: ";
    cin>>columna;
    columna -= 1;
    //AQUI ENTRARAN TODAS LAS RESTRICCIONES DEL JUEGO
    if(corono==true){
        if(restric==1){
            while (((fila != a) && (columna != b))
            ||(tablero[fila][columna] != ' ') || (fila>7) || (columna>7)|| (fila<0) || (columna<0)
            ||(MovRealeza(tablero, fila, columna, '+', 1, a, b)==false)){
                cout<<"Ese movimiento es ilegal, asegurese de que el movimiento no sea diagonal, que no salte a sus propias fichas y que pueda caer ahi, y que no salga del tablero:"<<endl;
                cout<<"Por favor digite nuevamente:"<<endl;
                cout<<"fila: ";
                cin>>fila;
                fila -= 1;
                cout<<"columna: ";
                cin>>columna;
                columna -= 1;
            }
        }
        else{
            while (((fila != a) && (columna != b))
            ||(tablero[fila][columna] != ' ') || (fila>7) || (columna>7)|| (fila<0) || (columna<0)
            ||(MovRealeza(tablero, fila, columna, 'Q', -1, a, b)==false)){
                cout<<"Ese movimiento es ilegal, revise que la posicion deseada este dentro del tablero, que no haya ninguna ficha ahi, y que solo se mueva de a un espacio hacia adelante o a los lados:"<<endl;
                cout<<"Por favor digite nuevamente:"<<endl;
                cout<<"fila: ";
                cin>>fila;
                fila -= 1;
                cout<<"columna: ";
                cin>>columna;
                columna -= 1;
            }
        }
    }
    else{
        if(restric==1){
            while (((fila != a) && (columna != b))||(tablero[fila][columna] != ' ') || (fila>7) || (columna>7)||(fila>a)|| (fila<0) || (columna<0)|| (columna < (b - 1))|| (columna > (b + 1))||(fila < (a - 1))){
                    cout<<"Ese movimiento es ilegal, revise que la posicion deseada este dentro del tablero, que no haya ninguna ficha ahi, y que solo se mueva de a un espacio hacia adelante o a los lados:"<<endl;
                    cout<<"Por favor digite nuevamente:"<<endl;
                    cout<<"fila: ";
                    cin>>fila;
                    fila -= 1;
                    cout<<"columna: ";
                    cin>>columna;
                    columna -= 1;

                }
        }
        else{
            while (((fila != a) && (columna != b)) || (fila > (a + 1)) || (columna < (b - 1))|| (columna > (b + 1)) ||(tablero[fila][columna] != ' ') || (fila>7) || (columna>7)||(fila<a)|| (fila<0) || (columna<0)){
                cout<<"Ese movimiento es ilegal, revise que la posicion deseada este dentro del tablero, que no haya ninguna ficha ahi, y que solo se mueva de a un espacio hacia adelante o a los lados:"<<endl;
                cout<<"Por favor digite nuevamente:"<<endl;
                cout<<"fila: ";
                cin>>fila;
                fila -= 1;
                cout<<"columna: ";
                cin>>columna;
                columna -= 1;
            }
        }
    }
//La ficha al llegar al borde se vera igual, pero al moverla cambiara a su version coronada, donde tendra distintas opciones de movimiento
    if(corono==true){
        tablero[fila][columna]=C;
        tablero[a][b]=' ';
        intercambio(tablero, a, b, fila, columna, restric, C, true, C);
    }
    else{
        tablero[fila][columna]=fig;
        tablero[a][b]=' ';
    }
}


/*----------------------------------
INTERCAMBIO AL COMER
------------------------------------*/
void intercambio(char tablero[TAM][TAM + 1], int f1, int c1, int f2, int c2, int restric, char fig, bool corona, char C){
    /*if(corono==true){
        tablero[fila][columna]=C;
        tablero[a][b]=' ';
    }
    else{
        */
        if(corona==false){
            tablero[f2][c2]=fig;
            tablero[f1][c1]=' ';
            if(c2==c1 + 2)
                tablero[f1][c1 + 1]=' ';
            if(c2==c1 - 2)
                tablero[f1][c1 - 1]=' ';
            
            if(f2==f1 - 2)
                tablero[f1 - 1][c1]=' ';
            
            if(f2==f1 + 2)
                tablero[f1 + 1][c1]=' ';
        }
        if(corona==true){
            tablero[f2][c2]=C;
            tablero[f1][c1]=' ';
            if(c2>c1 && ((restric==1&&((tablero[f1][c2 - 1]=='O')||(tablero[f1][c2 - 1]='Q')))||(restric==-1&&((tablero[f1][c2 - 1]='+')||(tablero[f1][c2 - 1]='X'))))){
                tablero[f1][c2 - 1]=' ';
            }
            if(c2<c1 && ((restric==1&&((tablero[f1][c2 + 1]=='O')||(tablero[f1][c2 + 1]='Q')))||(restric==-1&&((tablero[f1][c2 + 1]='+')||(tablero[f1][c2 + 1]='X'))))){
                tablero[f1][c2 + 1]=' ';
            }
            if(f2<f1 && ((restric==1&&((tablero[f2 + 1][c1]=='O')||(tablero[f2 + 1][c1]='Q')))||(restric==-1&&((tablero[f2 + 1][c1]='+')||(tablero[f2 + 1][c1]='X'))))){
                tablero[f2 + 1][c1]=' ';
            }
            if(f2>f1 && ((restric==1&&((tablero[f2 - 1][c1]=='O')||(tablero[f2 - 1][c1]='Q')))||(restric==-1&&((tablero[f2 - 1][c1]='+')||(tablero[f2 - 1][c1]='X'))))){
                tablero[f2 - 1][c1]=' ';
            }
        }
    //}
}

/*----------------------------------
LECTURA PARA ENCONTRAR # DE FICHAS
------------------------------------*/
void LeeTab(char tablero[TAM][TAM + 1], int ARR[2]){
    int i=0, j=0;
    ARR[0] = 0;
    ARR[1] = 0;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            if((tablero[i][j]=='X')||((tablero[i][j]=='+')))
                ARR[0] += 1;
            if((tablero[i][j]=='O')||((tablero[i][j]=='Q')))
                ARR[1] += 1;    
        }
    }
}

/*----------------------------------
MOVIMIENTO CUANDO NO COME
------------------------------------*/
void MOV(char tablero[TAM][TAM + 1], int fila, int columna, char fig,  char f2, int restric, char C, bool corono){
    mueveficha(tablero, fila, columna, fig, f2, restric, corono, C);
    system("clear");
    cout<<"    ___                              _____"<<endl;                         
    cout<<"   /   -__ _ _ __ ____   __ _ ___  /__  __|_   _ _ _ ___  __ _ ___ "<<endl; 
    cout<<"  / __ / _` | '_ ` _  | / _` / __|   / /  | | | '__/| __|/ _` / __|"<<endl; 
    cout<<" / /_// (_| | | | | | || (_| |__ |  / /   | |_| | | | (_| (_| |__ |"<<endl; 
    cout<<"/___,'|___,_|_| |_| |_||__,_ |___/  |/    |__,__|_| |___|__,__|___/\n"<<endl;
    ImprimeTablero(tablero);
}

/*----------------------------------
MOVIMIENTO AL COMER
------------------------------------*/
void MOVC(char tablero[TAM][TAM + 1], int aux1, int aux2, int M1, int M2, char fig,  char f2, int restric, char C, bool corona){
    if(restric==1)
        intercambio(tablero, aux1, aux2, M1, M2, 1,'X', corona, '+');
    else
        intercambio(tablero, aux1, aux2, M1, M2, 1,'O', corona, 'Q');
    system("clear");
    cout<<"    ___                              _____"<<endl;                         
    cout<<"   /   -__ _ _ __ ____   __ _ ___  /__  __|_   _ _ _ ___  __ _ ___ "<<endl; 
    cout<<"  / __ / _` | '_ ` _  | / _` / __|   / /  | | | '__/| __|/ _` / __|"<<endl; 
    cout<<" / /_// (_| | | | | | || (_| |__ |  / /   | |_| | | | (_| (_| |__ |"<<endl; 
    cout<<"/___,'|___,_|_| |_| |_||__,_ |___/  |/    |__,__|_| |___|__,__|___/\n"<<endl;
    ImprimeTablero(tablero);
}

/*----------------------------------
PARA EL JUGADOR 1
------------------------------------*/
void realizaJ1(char tablero[TAM][TAM + 1], t_jugador J1){
    int filaJ1=0, colJ1=0, Mfila1=0, Mcol1=0;
    int aux1=0, aux2=0;
    bool comeJ1=false;
    bool coronoJ1=false;
        //Jugador 1
    if(SiEsQHay(tablero, 1)==true){
        SiHayImp(tablero, 1);
        do{
            filaJ1=laFAcomer();
            colJ1=eligecol();
            coronoJ1=coronacion(tablero, filaJ1, colJ1, '+');
        }while(!cumpleFeo(filaJ1, colJ1, tablero, 'X',  'O', 1, '+', coronoJ1)); 
    }
    else{
        do{
            filaJ1=eligefila(J1);
            colJ1=eligecol();
        }while(!cumpleTodo(filaJ1, colJ1, tablero, 'X',  'O', 1, '+'));
    }    
    coronoJ1=coronacion(tablero, filaJ1, colJ1, '+');
    if((RevisaEnCruz(tablero, filaJ1, colJ1,  'O', 1, 'Q','X')==true) || ((AsesinaEnPto(tablero, filaJ1, colJ1, 'O', 1, 'Q','X')==true)&&(coronoJ1==true)))
        comeJ1=true;
    //ESTO HACE MOVIMIENTO DE J1
    if(comeJ1==true){
        aux1=filaJ1;
        aux2=colJ1; 
        coronoJ1=coronacion(tablero, aux1, aux2, '+');
        while(comeJ1==true){
            cout<<"\nficha seleccionada: ["<<aux1 + 1<<","<<aux2 + 1<<"]"<<endl;
            do{
                    Mfila1=muevefila();
                    Mcol1=muevecol();
            }while(!cumple2movimiento(aux1, aux2, Mfila1, Mcol1, tablero, 'X', 'O', 1, 'Q', coronoJ1));
            MOVC(tablero, aux1, aux2, Mfila1, Mcol1, 'X',  'O', 1, 'Q', coronoJ1);
            aux1=Mfila1;
            aux2=Mcol1;
            coronoJ1=coronacion(tablero, aux1, aux2, '+');
            comeJ1=RevisaEnCruz(tablero, aux1, aux2,  'O', 1, 'Q','X');
        }
    }
    else
        MOV(tablero, filaJ1, colJ1, 'X',  'O', 1, '+', coronoJ1);
}
/*----------------------------------
PARA EL JUGADOR 2
------------------------------------*/
void realizaJ2(char tablero[TAM][TAM + 1], t_jugador J2){
    int filaJ2=0, colJ2=0, Mfila2=0, Mcol2=0;
    int aux3=0, aux4=0;
    bool comeJ2=false;
    bool coronoJ2=false;
    if(SiEsQHay(tablero, -1)==true){
        SiHayImp(tablero, -1);
        do{
            filaJ2=laFAcomer();
            colJ2=eligecol();
            coronoJ2=coronacion(tablero, filaJ2, colJ2, 'Q');
        }while(!cumpleFeo(filaJ2, colJ2, tablero, 'O',  'X', -1, 'Q', coronoJ2)); 
    }
    else{
        do{
            filaJ2=eligefila(J2);
            colJ2=eligecol();
        }while(!cumpleTodo(filaJ2, colJ2, tablero, 'O',  'X', -1, 'Q'));
    }    
    coronoJ2=coronacion(tablero, filaJ2, colJ2, 'Q');
    if((RevisaEnCruz(tablero, filaJ2, colJ2,  'X', -1, '+','O')==true) || ((AsesinaEnPto(tablero, filaJ2, colJ2,  'X', -1, '+','O')==true)&&(coronoJ2==true)))
        comeJ2=true;

    //ESTO HACE MOVIMIENTO DE J2
    if(comeJ2==true){
        aux3=filaJ2;
        aux4=colJ2; 
        while(comeJ2==true){
            cout<<"\nficha seleccionada: ["<<aux3 + 1<<","<<aux4 + 1<<"]"<<endl;
            do{
                Mfila2=muevefila();
                Mcol2=muevecol();
            }while(!cumple2movimiento(aux3, aux4, Mfila2, Mcol2, tablero, 'X', 'O', -1, 'Q', coronoJ2));
            MOVC(tablero, aux3, aux4, Mfila2, Mcol2, 'O',  'X', -1, '+', coronoJ2);
            aux3=Mfila2;
            aux4=Mcol2;
            comeJ2=RevisaEnCruz(tablero, aux3, aux4,  'X', -1, '+', 'O');
        }
    }
    else
        MOV(tablero, filaJ2, colJ2, 'O',  'X', -1, 'Q', coronoJ2);
}
/*----------------------------------
PARA IMPRIMIR LAS OPCIONES DE MOVIMIENTO
cuando hay dos o mas al comer
------------------------------------*/
void SiHayImp(char tablero[TAM][TAM + 1], int restric){
    int i=0, j=0;
    cout<<"Actualmente solo puede mover estas fichas: "<<endl;
    for(i=0; i<TAM; i++){
        for(j=0; j<TAM; j++){
            if((restric==1)&&(((RevisaEnCruz(tablero, i, j,  'O', 1, 'Q', 'X')==true)&&(tablero[i][j]=='X'))
            ||((RevisaReinaAsesina(tablero, i, j,  'O', 1, 'Q', '+')==true)&&(tablero[i][j]=='+')))){
                cout<<"["<<i + 1<<","<<j + 1<<"]";
            }
            if((restric==-1)&&(((RevisaEnCruz(tablero, i, j,  'X', -1, '+','O')==true)&&(tablero[i][j]=='O'))
            ||((RevisaReinaAsesina(tablero, i, j,  'X', -1, '+', 'Q')==true)&&(tablero[i][j]=='Q')))){
                cout<<"["<<i + 1<<","<<j + 1<<"]";
            }
        }
    }
}

/*
reestricciones para esta entrega y la siguiente:

1. CORONAR y sus reglas []
 for(ficha elegida hasta la posicion que quiere con ++) (tocaria hacer uno para fila y uno para columna)
 si hay 1 y vacio hasta ya no poder(cuando llega al lim del tablero o si hay dos consecutivas)
 
 "Las damas tienen mayor libertad de movimientos:

 Pueden moverse en cualquier dirección, también retrocediendo.
 Son voladoras: pueden moverse saltando varias casillas vacías a lo largo de una línea horizontal o vertical.
 Pueden capturar piezas enemigas mediante saltos sobre una o varias casillas,
 siempre que una de las casillas ellas esté ocupada por una pieza enemiga y el resto de las casillas estén vacías."


1. q si puede comer 2 veces solo lo revise una revise una vez 
2. q pueda comer en filas (o ps q oblige en filas)

*/