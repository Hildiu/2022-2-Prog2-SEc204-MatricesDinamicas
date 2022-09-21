#include <iostream>
#include <iomanip>
using namespace std;

void imprimir( int *  * pM, int filas, int col );
int hallaMayor(int **pMatriz,int filas,int col);


int main()
{  int filas, col;
    int **pMatriz=nullptr;

    srand(time(nullptr));
    cout << "Numero de filas : " ; cin >> filas;
    cout << "Numero de columnas : "; cin >> col;
    pMatriz = new int*[filas];
    for(int f=0; f<filas; f++)
        pMatriz[f] = new int[col];
    //----llenamos la matriz con datos aleatorios
    for(int f=0; f<filas; f++)
        for(int c=0; c<col; c++)
            pMatriz[f][c]= rand() % 100 + 1;
    imprimir(pMatriz,filas, col);
    cout << "El mayor elemento es " << hallaMayor(pMatriz, filas, col);

    for(int f=0; f<filas; f++)
        delete []pMatriz[f];
    delete pMatriz;
    pMatriz = nullptr;

    return 0;
}

void imprimir( int *  * pM, int filas, int col )
{
    for(int f=0; f<filas; f++)
    {
        for(int c=0; c<col; c++)
            cout << setw(5) << pM[f][c];
        cout << "\n";
    }
}


int hallaMayor(int **pMatriz,int filas,int col)
{
    int mayor = pMatriz[0][0];
    for(int f=0; f<filas; f++)
        for(int c=0; c<col; c++)
            if(pMatriz[f][c]> mayor)
                mayor = pMatriz[f][c];
    return mayor;
}