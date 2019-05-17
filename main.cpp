#include<iostream>
#include<string>
#include<sstream>
using namespace std;

char** crearMatriz(int);
void printMatrix(char** matrix,int size);
void freeMatrix(char**& matrix,int size);
int comprobarCoordenada(char** matrix,string coordenada, char fichaActual);
int indicarFila(char coordenada);
int comprobarMover(char** matrix,string coordenada,int filaFicha, int columFicha, char fichaActual);
void Juego();

int main(){
    char respuesta = 'S';
    while (respuesta == 'S' || respuesta == 's'){
    int opcion = 0;
    while(opcion <= 0 || opcion > 4){
        cout << "Menu" <<endl
        << "1)Ejercicio 1" <<endl
        << "2)Salir" <<endl
        << "Ingrese su opcion: ";
        cin >> opcion;
    }
    switch(opcion){
        case 1:
            {
                Juego();
                break;
            }
    }
    cout << "¿Desea volver a hacerlo[s/n]?: ";
    cin >>  respuesta;
    }
    return 0;
}

void Juego(){
    char** matrix = NULL;
    int size = 11;
    matrix = crearMatriz(size);
    cout << "Tablero Inicial"<<endl;
    printMatrix(matrix,size);
    bool turnoMoscovita = true;
    bool terminoJuego = false;
    
    while(!terminoJuego){
        char fichaActual = ' ';
        if (turnoMoscovita){
            fichaActual = 'M';
        } else {
            fichaActual = 'S';
        }
        
        string coordenada = "";
        cout << "Ingrese la coordenada: ";
        cin >> coordenada;

        while (comprobarCoordenada(matrix,coordenada,fichaActual) == 0){
            cout <<"Ingrese la coordenada: ";
            cin >> coordenada;
        }
        int filaFicha = indicarFila(coordenada.at(0));
        stringstream temp;
        int guion = coordenada.find('-');
        for (int i = guion + 1; i < coordenada.length();i++){
            temp << coordenada.at(i);
        }
        int columnaFicha = stoi(temp.str());
        if (matrix[filaFicha][columnaFicha] = 'W'){
            fichaActual = 'W';
        }
        cout << "Ingrese la posicion a donde movera: ";
        string coordenadaMover = "";
        cin >> coordenadaMover;
        while(comprobarMover(matrix,coordenadaMover,filaFicha,columnaFicha,fichaActual) == 0){
            cout << "Ingrese la posicion a donde movera: ";
            cin >> coordenadaMover;
        }
        int filaMover = indicarFila(coordenadaMover.at(0));
        guion = coordenadaMover.find('-');
        for (int i = guion + 1; i < coordenadaMover.length();i++){
            temp << coordenadaMover.at(i);
        }
        int columnaMover = stoi(temp.str());
        if (turnoMoscovita){
            turnoMoscovita = false;
        } else {
            turnoMoscovita = true;
        }
    }

    freeMatrix(matrix,size);
}


int comprobarMover(char** matrix,string coordenada,int filaFicha, int columFicha, char fichaActual){
    int acum = 0;
    int fila = 0;
    int guion = coordenada.find('-');
    if (coordenada.length() < 4){
        for (int i = 0; i < coordenada.length();i++){
            if (coordenada.at(i) == '-'){
                i = coordenada.length();
            } else {
                acum++;
            }
        }
        if (acum > 1){
            return 0;
        } else{
            if (coordenada.at(0) != 'A' && coordenada.at(0) != 'B' && coordenada.at(0) != 'C' && coordenada.at(0) != 'D' && coordenada.at(0) != 'E' && coordenada.at(0) != 'F' && coordenada.at(0) != 'G' && coordenada.at(0) != 'H' && coordenada.at(0) != 'I' && coordenada.at(0) != 'J' && coordenada.at(0) != 'K'){
                return 0;
            } else {
                stringstream numero;
                for (int i = guion + 1; i < coordenada.length();i++){
                    numero << coordenada.at(i);
                }
                int numeroComprobar = stoi(numero.str());
                if (numeroComprobar > 10){
                    return 0;
                } else {
                    if (matrix[fila][numeroComprobar] == ' ' ||  matrix[fila][numeroComprobar] == 'X'){
                        int filaMover = fila;
                        int columMover = numeroComprobar;
                        if (filaMover != filaFicha && columMover != columFicha){
                            return 0;
                        }
                        int inicio = 0;
                        int fin = 0;
                        if (filaMover == filaFicha){
                            if (columMover > columFicha){
                                inicio = columFicha+1;
                                fin = columMover;
                            } else {
                                inicio = columMover;
                                fin = columFicha-1;
                            }
                            for (int i = inicio; i <= fin; i++){
                                if (matrix[filaFicha][i] != ' '){
                                    return 0;
                                }
                            }
                        } else {
                            if (columMover = columFicha){
                                if (filaMover > filaFicha){
                                    inicio = filaFicha+1;
                                    fin = filaMover;
                                } else {
                                    inicio = filaMover;
                                    fin = filaFicha-1;
                                }
                            }
                            for (int i = inicio; i <= fin; i++){
                                if (matrix[i][columFicha] != ' '){
                                    i = fin + 1;
                                    return 0;
                                }
                            }
                        }
                        if ((filaMover == 0 && columMover == 0) || (filaMover == 0 && columMover == 10) || (filaMover == 10 && columMover == 0) || (filaMover == 10 && columMover == 10) && fichaActual != 'W'){
                            return 0;
                        }
                        return 1;
                    } else {
                        return 0;
                    }
                }
            }
        }
    } else {
        return 0;
    }            
}

int indicarFila(char coordenada){
    if (coordenada == 'A'){
            return  0;
    }
    if (coordenada == 'B'){
        return 1;
    }
    if (coordenada == 'C'){
        return 2;
    }
    if (coordenada == 'D'){
        return 3;
    }
    if (coordenada == 'E'){
        return 4;
    }
    if (coordenada == 'F'){
        return 5;
    }
    if (coordenada == 'G'){
        return 6;
    }
    if (coordenada == 'H'){
        return 7;
    }
    if (coordenada == 'I'){
        return 8;
    }
    if (coordenada == 'J'){
        return 9;
    }
    if (coordenada == 'K'){
        return 10;
    }
}

int comprobarCoordenada(char** matrix,string coordenada, char fichaActual){
    int acum = 0;
    int fila = 0;
    int guion = coordenada.find('-');
    if (coordenada.length() < 4){
        for (int i = 0; i < coordenada.length();i++){
            if (coordenada.at(i) == '-'){
                i = coordenada.length();
            } else {
                acum++;
            }
        }
        if (acum > 1){  
            return 0;
        } else{
            if (coordenada.at(0) != 'A' && coordenada.at(0) != 'B' && coordenada.at(0) != 'C' && coordenada.at(0) != 'D' && coordenada.at(0) != 'E' && coordenada.at(0) != 'F' && coordenada.at(0) != 'G' && coordenada.at(0) != 'H' && coordenada.at(0) != 'I' && coordenada.at(0) != 'J' && coordenada.at(0) != 'K'){
                return 0;
            } else{
                stringstream numero;
                for (int i = guion + 1; i < coordenada.length();i++){
                    numero << coordenada.at(i);                    
                }
                int numeroComprobar = stoi(numero.str());
                if (numeroComprobar > 10){
                    return 0;
                } else {
                    if (coordenada.at(0) == 'A'){
                        fila = 0;
                    }
                    if (coordenada.at(0) == 'B'){
                        fila = 1;
                    }
                    if (coordenada.at(0) == 'C'){
                        fila = 2;
                    }
                    if (coordenada.at(0) == 'D'){
                        fila = 3;
                    }
                    if (coordenada.at(0) == 'E'){
                        fila = 4;
                    }
                    if (coordenada.at(0) == 'F'){
                        fila = 5;
                    }
                    if (coordenada.at(0) == 'G'){
                        fila = 6;
                    }
                    if (coordenada.at(0) == 'H'){
                        fila = 7;
                    }
                    if (coordenada.at(0) == 'I'){
                        fila = 8;
                    }
                    if (coordenada.at(0) == 'J'){
                        fila = 9;
                    }
                    if (coordenada.at(0) == 'K'){
                        fila = 10;
                    }
                    if (matrix[fila][numeroComprobar] != fichaActual){
                        return 0;
                    } else{
                        int filaFicha = fila;
                        int columFicha = numeroComprobar;
                        if (filaFicha == 0){
                            if (matrix[0][columFicha+1] != ' ' && matrix[0][columFicha-1] != ' ' && matrix[1][columFicha] != ' '){
                                return 0;
                            }
                        } else {
                            if (filaFicha == 10){
                                if (matrix[10][columFicha+1] != ' ' && matrix[10][columFicha-1] != ' ' && matrix[9][columFicha] != ' '){
                                    return 0;
                                }
                            }else{
                                if (columFicha == 0){
                                    if (matrix[filaFicha+1][0] != ' ' && matrix[filaFicha-1][0] != ' ' && matrix[filaFicha][1] != ' '){
                                        return 0;
                                    }
                                }else{
                                    if (columFicha == 10){
                                        if (matrix[filaFicha+1][10] != ' ' && matrix[filaFicha-1][10] != ' ' && matrix[filaFicha][9] != ' '){
                                            return 0;
                                        }
                                    } else {
                                        if (matrix[filaFicha+1][columFicha] != ' ' && matrix[filaFicha][columFicha+1] != ' '  && matrix[filaFicha-1][columFicha] != ' ' && matrix[filaFicha][columFicha-1] != ' ' && matrix[filaFicha+1][columFicha+1] != ' ' && matrix[filaFicha-1][columFicha+1] != ' ' && matrix[filaFicha-1][columFicha-1] != ' ' && matrix[filaFicha+1][columFicha-1] != ' '){
                                            return 0;
                                        }
                                    }
                                }
                            }
                        }
                        return 1;
                    }
                }
            }
        }
    } else {
        return 0;
    }
}

char** crearMatriz(int size){
    char** matrix = NULL;
    matrix = new char*[size];
    for (int i = 0; i < size; i++){
        matrix[i] = new char[size];
    }
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            matrix[i][j] = ' ';
        }
    }
    matrix[0][0] = 'X';
    matrix[0][10] = 'X';
    matrix[10][0] = 'X';
    matrix[10][10] = 'X';
    matrix[0][4] = 'M';
    matrix[0][5] = 'M';
    matrix[0][6] = 'M';
    matrix[1][4] = 'M';
    matrix[1][6] = 'M';
    matrix[2][5] = 'M';
    
    matrix[4][0] = 'M';
    matrix[5][0] = 'M';
    matrix[6][0] = 'M';
    matrix[4][1] = 'M';
    matrix[6][1] = 'M';
    matrix[5][2] = 'M';

    matrix[4][10] = 'M';
    matrix[5][10] = 'M';
    matrix[6][10] = 'M';
    matrix[4][9] = 'M';
    matrix[6][9] = 'M';
    matrix[5][8] = 'M';

    matrix[10][4] = 'M';
    matrix[10][5] = 'M';
    matrix[10][6] = 'M';
    matrix[9][4] = 'M';
    matrix[9][6] = 'M';
    matrix[8][5] = 'M';

    matrix[4][4] = 'S';
    matrix[4][5] = 'S';
    matrix[4][6] = 'S';
    matrix[3][5] = 'S';
    
    matrix[5][4] = 'S';
    matrix[6][4] = 'S';
    matrix[5][3] = 'S';

    matrix[6][5] = 'S';
    matrix[6][6] = 'S';
    matrix[7][5] = 'S';

    matrix[5][6] = 'S';
    matrix[5][7] = 'S';
    
    matrix[5][5] = 'W';
    return matrix;
}

void printMatrix(char** matrix,int size){
    for (int i = 0; i < size; i++){
        for  (int j = 0; j < size; j++){
            cout << "[" << matrix[i][j] << "] ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void freeMatrix(char**& matrix,int size){
    for (int i = 0; i < size; i++){
        if (matrix[i] != NULL){
            delete[] matrix[i];
            matrix[i] = NULL;
        }
    }
    if (matrix != NULL){
        delete[] matrix;
        matrix = NULL;
    }
}
