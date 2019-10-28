///Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "canciones.h"


///Funciones
nodoArbolCancion * InicArbol(){
    return NULL;
}

///1.Hacer una función que permita ingresar nuevos nodos manteniendo el árbol ordenado (por IdCancion).

nodoArbolCancion * CrearNodoArbolSong (Cancion song){
    nodoArbolCancion * aux = (nodoArbolCancion*)malloc(sizeof(nodoArbolCancion));
    aux->song=song;
    aux->izq=NULL;
    aux->der=NULL;

    return aux;
}

nodoArbolCancion * cargarArbolOrdenado (nodoArbolCancion * arbol, Cancion idsong){
    if (arbol==NULL)
    {
        arbol= CrearNodoArbolSong(idsong);
    }
    else
    {
        if (strcmpi(arbol->song.idCancion,idsong.idCancion)<0)
        {
            arbol->izq= cargarArbolOrdenado(arbol->izq,idsong);
        }
        else
        {
            arbol->der= cargarArbolOrdenado(arbol->der,idsong);
        }
    }
    return arbol;
}

void mostrarCancion(Cancion song){
    ///printf("\nID Cancion:  %i\n",song.idCancion);
    printf("Titulo: %s\n",song.titulo);
    printf("Artista: %s\n",song.artista);
    printf("Duraci%cn: %i\n",162,song.duracion);
    printf("A%co: %i\n",164,song.anio);
    printf("Genero: %c\n",song.genero);
    printf("Comentario: %s\n",song.comentario);
}

void mostrarPreOrder(nodoArbolCancion* arbol){
    if(arbol)
    {

        mostrarCancion(arbol->song);
        mostrarPreOrder(arbol->izq);
        mostrarPreOrder(arbol->der);

    }

}

void mostrarInOrder(nodoArbolCancion* arbol){
    if(arbol)
    {

        mostrarInOrder(arbol->izq);
        mostrarCancion(arbol->song);
        mostrarInOrder(arbol->der);
    }

}

void mostrarPostOrder(nodoArbolCancion* arbol){
    if(arbol)
    {

        mostrarPostOrder(arbol->izq);
        mostrarPostOrder(arbol->der);
        mostrarCancion(arbol->song);
    }

}

nodoArbolCancion * buscarIdEnArbol (nodoArbolCancion * arbol, int idSong){
    nodoArbolCancion * rta = NULL;
    if (arbol!=NULL)
    {
        if (strcmpi(idSong, arbol->song.idCancion)==0)
        {
            rta= arbol;
        }
        else
        {
            if (strcmpi(idSong, arbol->song.idCancion)>0)
            {
                rta= buscarIdEnArbol(arbol->izq, idSong);
            }
            else
            {
                rta= buscarIdEnArbol(arbol->der, idSong);
            }
        }
    }
    return rta;
}

nodoArbolCancion *NMD(nodoArbolCancion* arbol){
    nodoArbolCancion * aux = arbol;
    if(aux->der != NULL)
    {
        aux = NMD(aux->der);
    }
    return aux;

}

nodoArbolCancion *NMI(nodoArbolCancion* arbol){
    nodoArbolCancion * aux = arbol;
    if(aux->izq != NULL)
    {
        aux = NMI(aux->izq);
    }
    return aux;

}

nodoArbolCancion * borrarCancionPorID(nodoArbolCancion*arbol,int idSong){
    nodoArbolCancion * ante;
    if(arbol!=NULL)
    {
        if(idSong == arbol->song.idCancion)
        {
            if(arbol->izq != NULL)
            {
                nodoArbolCancion * masDer = NMD(arbol->izq);
                arbol->song =masDer->song;
                arbol->izq = borrarCancionPorID(arbol->izq,masDer->song.idCancion);
            }
            else if(arbol->der != NULL)
            {
                nodoArbolCancion *masIzq = NMI(arbol->der);
                arbol->song = masIzq ->song;
                arbol->der = borrarCancionPorID(arbol->der,masIzq->song.idCancion);
            }
            else
            {
                free(arbol);
                arbol = NULL;
            }



        }
        else if(idSong > arbol->song.idCancion)
        {
            arbol->der = borrarCancionPorID(arbol->der,idSong);

        }
        else
        {
            arbol->izq = borrarCancionPorID(arbol->izq,idSong);
        }

    }
 return arbol;
}



