#include<iostream>
using namespace std;

char** crearMatriz(int);
void printMatrix(char** matrix,int size);
void freeMatrix(char**& matrix,int size);
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
    printMatrix(matrix,size);
    freeMatrix(matrix,size);
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

    matrix[0][4] = 'M';
    matrix[0][4] = 'M';
    matrix[0][4] = 'M';
    matrix[0][4] = 'M';
    matrix[0][4] = 'M';
    matrix[0][4] = 'M';
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
