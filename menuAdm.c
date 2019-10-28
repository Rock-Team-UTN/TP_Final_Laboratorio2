#include "menuAdm.h"

void menuAdm(){

    Usuario usuario;
    char nombreUsu[30];
    int confirmacion;
    int opicion;
    Usuario aux;
    char correcNom[50];
    int identificacion;
    int seleccion;
    do{
    system("cls");
    Logo();

    printf("\t\t\t\tIngrese una opcion \n\n");

    printf("\t\t\t\t1:CARGAR VARIOS USUARIOS\n\t\t\t\t2:CARGAR CANCIONES\n\t\t\t\t3:BAJA\n\t\t\t\t4:CONSULTA\n\t\t\t\t5:MOSTRAR USUARIOS\n\t\t\t\t6:MODIFICAR\n\t\t\t\t0:SALIR\n");
    fflush(stdin);
    printf("\t\t\t\t");
    scanf("%i",&opicion);

    switch(opicion){
            case 1:
                system("cls");
                Logo();
                printf("\t\t\t\t<<<<<CARGAR VARIOS USUARIOS>>>>>>\n");
                cargarMasUsuario();
                break;
            case 2:
                system("cls");
                Logo();
                menuPlaylist();
                getch();
                break;
            case 3:
                system("cls");
                Logo();
                printf("\t\t\t\t<<<<<<<<<<<<<BAJA Y ALTA>>>>>>>>>>>>>>>>\n");
                printf("\n\t\t\t\t1:Dar de baja usuario\n\t\t\t\t2:Dar de alta usuario creado\n\t\t\t\t");
                fflush(stdin);
                scanf("%i",&seleccion);
                switch(seleccion){
                    case 1:
                        printf("\t\t\t\tIngrese usuario a dar de baja\n\t\t\t\t");
                        fflush(stdin);
                        gets(nombreUsu);
                        confirmacion=baja(nombreUsu,usuario);
                    break;
                    case 2:
                        printf("\t\t\t\tIngrese usuario a dar de alta\n\t\t\t\t");
                        fflush(stdin);
                        gets(nombreUsu);
                        confirmacion=altaUsuario(nombreUsu,usuario);
                    break;
                }
                break;
            case 4:
                system("cls");
                Logo();
                printf("\t\t\t\t<<<<<<<<<<<CONSULTA>>>>>>>>>>>>>>\n");

                    printf(" \t\t\t\t1:CANTIDAD DE USUARIOS CARGADOSS\n\t\t\t\t2:BUSCAR USUARIO\n\t\t\t\t0:SALIR\n\t\t\t\t");
                    fflush(stdin);
                    scanf("%i",&seleccion);

                    switch(seleccion){
                        case 1:
                            printf("\n\t\t\t\t<<CANTIDAD DE USUARIOS CARGADOS>>\n\n");
                            int pesoDat=sizeof(Usuario);
                            int cant=contarRegistros("archivo",pesoDat);
                            printf("\n\t\t\t\t  cantidad de registros: %i\n",cant);
                            getch();
                           break;
                        case 2:
                           printf("\t\t\t\t<<<<<<<<BUSCAR USUARIO>>>>>>>>>>>\n");
                           printf("\t\t\t\t<<<<<<INGRESE NOMBRE USUARIO>>>>>>\n\n\t\t\t\t\t");
                           fflush(stdin);
                           gets(nombreUsu);
                           confirmacion=buscarUsuario(usuario,nombreUsu);
                           if(confirmacion== -1){
                            printf("\n\t\t\t\tEl usuario ingresado no existe\n");
                            getch();
                           }else{
                            aux=buscar(aux,nombreUsu);
                            mostrarAlumno(aux);
                            getch();

                           }
                           break;
                    }
                break;
            case 5:
                system("cls");
                Logo();
                printf("\t\t\t\t<<<<<<<<<<<<MOSTRAR USUARIOS>>>>>>>>>>>\n");
                printf("\n\t\t\t\t1:Mostrar activos\n\t\t\t\t2:Mostrar todos\n\t\t\t\t");
                fflush(stdin);
                scanf("%i",&seleccion);
                switch(seleccion){
                            case 1:
                                system("cls");
                                Logo();
                                printf("\t\t\t\t<<<<<<<<<<<<MOSTRAR USUARIOS>>>>>>>>>>>\n");
                                mostrarActivos();
                                getch();
                            break;
                            case 2:
                                system("cls");
                                Logo();
                                printf("\t\t\t\t<<<<<<<<<<<<MOSTRAR USUARIOS>>>>>>>>>>>\n");
                                mostrarTodos();
                                getch();
                            break;
                }
                break;
            case 6:
                 system("cls");
                Logo();
                printf("\t\t\t\t<<<<<<<<<<<<MODIFICAR>>>>>>>>>>>\n");

                printf("\t\t\t\tIngrese nombre del usuario que desea modificar\n\t\t\t\t");
                fflush(stdin);
                gets(correcNom);
                identificacion=buscarUsuario(usuario,correcNom);
                if(identificacion!=-1){
                    usuario=buscar(usuario,correcNom);
                    printf(" \t\t\t\t1:CAMBIAR NOMBRE\n\t\t\t\t2:CAMBIAR CONTRASENIA\n\t\t\t\t3:CAMBIAR FECHA DE NACIMIENTO\n\t\t\t\t4:CAMBIAR PAIS\n\t\t\t\t0:SALIR\n\t\t\t\t");
                    fflush(stdin);
                    scanf("%i",&opicion);
                    modificar(usuario,opicion);
                }
    }
}while(opicion!=0);
}
