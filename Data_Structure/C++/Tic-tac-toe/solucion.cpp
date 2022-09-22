#include "constantes.h"
#include "solucion.h"
#include "logica.h"


#include <iostream>
using namespace std;

/*
* Implementar esta función.
* Dependiendo el estado del juego esta debe retornar:  

GANO_X: Si Ha ganado el jugador X
GANO_O: Si Ha ganado el jugador O
EMPATE: Si ya se llenaron todas las casillas y no hay ganador
JUEGO_EN_CURSO: Si el juego aún no se ha terminado.
*/

int CheckHorizontal(char targetPiece, char** board){

    for(short x = 0; x < 3; x++){

       for(short y = 0; y < 3; y++){

           if(board[x][y] == '_' || board[x][y] != targetPiece)
                break;

           if(board[x][2] == targetPiece && y == 2 && targetPiece == 'X')
               return GANO_X;

           if(board[x][2] == targetPiece && y == 2 && targetPiece == 'O')
               return GANO_O;
       }
    }

    return JUEGO_EN_CURSO;
}

int CheckVertical(char targetPiece, char** board){

    for(short x = 0; x < 3; x++){

       for(short y = 0; y < 3; y++){

           if(board[y][x] == '_' || board[y][x] != targetPiece)
                break;

           if(board[2][x] == targetPiece && y == 2 && targetPiece == 'X')
               return GANO_X;

           if(board[2][x] == targetPiece && y == 2 && targetPiece == 'O')
               return GANO_O;
       }
    }

    return JUEGO_EN_CURSO;
}

int CheckLeftDiagonal(char targetPiece, char** board){

    for(short x = 0; x < 3; x++){
        
        if(board[x][x] == '_' || board[x][x] != targetPiece)
            return JUEGO_EN_CURSO;

        if(board[x][x] == targetPiece && x == 2  && targetPiece == 'X')
            return GANO_X;

        if(board[x][x] == targetPiece && x == 2  && targetPiece == 'O')
            return GANO_O;
    }

    return JUEGO_EN_CURSO;
}

int CheckRightDiagonal(char targetPiece, char** board){

 for(short x = 2; x >= 0; x--){
        
        if(board[2-x][x] == '_' || board[2-x][x] != targetPiece)
            return JUEGO_EN_CURSO;

        if(board[2-x][x]  == targetPiece && x == 0  && targetPiece == 'X')
            return GANO_X;

        if(board[2-x][x] == targetPiece && x == 0  && targetPiece == 'O')
            return GANO_O;
    }

    return JUEGO_EN_CURSO;

}


int Tied(char** board){
   
    for(short x  = 0; x < 3; x++){
        for(short y = 0; y < 3; y++ ){
            if(board[x][y] == '_')
              return JUEGO_EN_CURSO;
        }
    }

  return EMPATE;
}


int GetEstado()
{
    /*
    Puedes acceder a las casillas del tablero mediante el arreglo de 
    dos dimensiones tablero.  

    Los índices empiezan en cero, de modo que puedes acceder a la segunda fila, primera columna 
    de la siguiente manera:
    tablero[1][0]
    */
    char** tablero = GetTablero();

    if(CheckHorizontal('X', tablero) != JUEGO_EN_CURSO)
        return GANO_X;
    
    if(CheckHorizontal('O', tablero) != JUEGO_EN_CURSO)
        return GANO_O;

     if(CheckVertical('X', tablero) != JUEGO_EN_CURSO)
        return GANO_X;
    
    if(CheckVertical('O', tablero) != JUEGO_EN_CURSO)
        return GANO_O;

    if(CheckLeftDiagonal('X', tablero) != JUEGO_EN_CURSO)
        return GANO_X;
    
    if(CheckLeftDiagonal('O', tablero) != JUEGO_EN_CURSO)
        return GANO_O;
    
    if(CheckRightDiagonal('X', tablero) != JUEGO_EN_CURSO)
        return GANO_X;
    
    if(CheckRightDiagonal('O', tablero) != JUEGO_EN_CURSO)
        return GANO_O;

    if(Tied(tablero) != JUEGO_EN_CURSO)
        return EMPATE;

    return JUEGO_EN_CURSO;
}