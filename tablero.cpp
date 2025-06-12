#include "tablero.h"
void llenaTablero(char tablero[TAM][TAM + 1]){
    int i=0, p=0;

    for(i=0; i<TAM; i++){
        for(p=0; p<=TAM; p++){
            if(i>0 && i<3)
                tablero[i][p]='O';
            else if(i<7 && i>4)
                tablero[i][p]='X';
            else
                tablero[i][p]=' ';
            if(p==TAM)
                tablero[i][p]='L';

        }
    }

}
void ImprimeTablero(char tablero[TAM][TAM + 1]){
        int i=0, p=0;
    cout<<"                        ";
    cout<<"1 2 3 4 5 6 7 8";
    cout<<endl;
    
    cout<<"                      "<<" ╔---------------╗"<<endl;
    for(i=0; i<TAM; i++){
        cout<<"                      "<<i+1<<"|"; 
        for(p=0; p<TAM; p++)
            cout<<tablero[i][p]<<"|";
    cout<<"\n"; 
    }
    cout<<"                      "<<" ╚---------------╝";
}

int letra2num(char letra){
    int numletra=0;
    numletra=(int) letra;
    if(numletra > 64 && numletra < 91)
        numletra -= 65;
    else if(numletra > 96 && numletra < 173)
        numletra -= 97;
    else
        numletra=-1;
    return numletra;
}