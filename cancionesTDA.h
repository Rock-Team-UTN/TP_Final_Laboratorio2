#ifndef CANCIONES_H_INCLUDED
#define CANCIONES_H_INCLUDED

///Estructuras
typedef struct
{
    int idCancion;
    char titulo[30];
    char artista[20];
    int duracion;
    char album[20];
    int anio;
    char genero[20];
    char comentario[100];
    int eliminado;  /// indica 1 o 0 si la canción fue eliminada
}Cancion;

typedef struct{ ///Arbol de clientes
    Cancion song;
    struct nodoArbolCancion * izq;
    struct nodoArbolCancion * der;
}nodoArbolCancion;

///Prototipados de funciones
nodoArbolCancion * InicArbol();
nodoArbolCancion * CrearNodoArbolSong (Cancion song);
nodoArbolCancion * cargarArbolOrdenado (nodoArbolCancion * arbol, Cancion idsong);
void mostrarCancion(Cancion song);
void mostrarPreOrder(nodoArbolCancion* arbol);
void mostrarInOrder(nodoArbolCancion* arbol);
void mostrarPostOrder(nodoArbolCancion* arbol);
nodoArbolCancion * buscarIdEnArbol (nodoArbolCancion * arbol, int idSong);
nodoArbolCancion *NMD(nodoArbolCancion* arbol);
nodoArbolCancion *NMI(nodoArbolCancion* arbol);
nodoArbolCancion * borrarCancionPorID(nodoArbolCancion*arbol,int idSong);



#endif // CANCIONES_H_INCLUDED
