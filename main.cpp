#include<iostream>
using namespace std;

char** crearMatriz(int);
void printMatrix(char** matrix,int size);
void freeMatrix(char**& matrix,int size);

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
                Juego
                break;
            }
    }
    cout << "¿Desea volver a hacerlo[s/n]?: ";
    cin >>  respuesta;
    }
    return 0;
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
    return matrix;
}

void printMatrix(char** matrix,int size){
    for (int i = 0; i < size; i++){
        for  (int j = 0; j < size; j++){
            cout << matrix[i][j] << " ";
        }
        cout<<endl;
    }
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
