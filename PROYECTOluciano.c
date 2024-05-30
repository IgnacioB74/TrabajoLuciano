// CREADOR DE TORNEOS, UCL, LPF, LIBERTADORES, Copa Aragentina, CSGO, etc... IGNACIO BLANCO 
//para hacer todo en uno la idea de partidos es pasarle por parametros y el parametro en un if ejemplo:
// unpartido(personalizado); if perzonalizado == true, una cosa, sino la otra --> para eso hay que aprender parametros
// COMPILAR Y ENTREGAR, HORRIBLE SINTAXIS, APRENDER PARAMETROS HUBIESE HECHO QUE EL PROGRAMA TENGA MIL LINEAS - Y ESTA MAS LINDO
// MERITOS POR HACERLO SIN SABER TODO ESTO
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define NOMBREMAX 100

/* limpiarPantalla() { //limpieza de pantallas para diferentes s.o
    #ifdef _WIN32
        system("cls"); // Para Windows
    #elif __unix__ || __linux__ || __APPLE__
        system("clear"); // Para Unix/Linux y MacOS
    #else
        for (int i = 0; i < 100; i++) {
            printf("\n");
        }
}*/ 
void Cleanup();
void Torneopersonalizado();
void Torneopreestablecido();
void unicopartido();
void unicopartidoPER();
void idayvuelta();
void idayvueltaPER();
void mejordetres();
void mejordetresPER();
char** Tlibertadores(); 
char** TUCL();
char** TBN();
char** Tesports();
char** Tprimera();
char** cargaequipos();

int main (){
    char menu;
    //int menu = 0;
    do {
    printf("--BIENVENIDO AL CREADOR DE TORNEOS--\n");
    printf("1- CREAR UN TORNEO PERSONALIZADO: \n");
    printf("2- CREAR UN TORNEO PREESTABLECIDO:\n");
    printf("0- SALIR\n");
    printf("seleccione una opcion: ");
    menu = getchar();
    //scanf("%d", &menu);
    system("cls");
    } while (menu != '1' && menu != '2' && menu != '0');//(menu < 0 || menu > 2); //pense en hacerlo con char para que no rompa con letras
    switch (menu) {
        case '1':
        Torneopersonalizado();
        break;
        case '2':
        Torneopreestablecido();
        break;
        case '0':
        exit(-1); //sale del programa 
    }
    return 0;
}
void Cleanup() {
    int *data = NULL;

    
    data = (int *)malloc(sizeof(int) * 10);
    if (data == NULL) {
        goto cleanup;
    }
cleanup:
    if (data != NULL) {
        free(data);
        
    }
}

void Torneopersonalizado() {
    char menuper;
    do {
    printf("--CREA TU PROPIO TORNEO--\n");
    printf("MODALIDAD:\n1- ENCUENTRO UNICO\n2- IDA Y VUELTA\n3- MEJOR DE 3 ENCUENTROS\n0- VOLVER\n");
    printf("opcion: ");
    menuper = getchar();
    system("cls");
    } while (menuper != '1' && menuper != '2' && menuper != '0' && menuper != '3');
    switch(menuper){
        case '1':
        unicopartidoPER();
        break;
        case '2':
        idayvueltaPER();
        break;
        case '3':
        mejordetresPER();
        break;
        case '0':
        main();
        break;
    }
}
void Torneopreestablecido(){
    char menuper;
    do {
    printf("--TORNEOS OFICIALES--\n");
    printf("MODALIDAD:\n1- ENCUENTRO UNICO\n2- IDA Y VUELTA\n3- MEJOR DE 3 ENCUENTROS\n0- VOLVER\n");
    printf("opcion: ");
    menuper = getchar();
    system("cls");
    } while (menuper != '1' && menuper != '2' && menuper != '0' && menuper != '3');
    switch(menuper){
        case '1':
        unicopartido();
        break;
        case '2':
        idayvuelta();
        break;
        case '3':
        mejordetres();
        break;
        case '0':
        main();
        break;
    }

}

void unicopartido(){
    char menupartido;
    do{
    printf("COMPETICIONES: \n");
    printf("1- COPA LIBERTADORES\n2- CHAMPIONS LEAGUE\n3- COPA B NACIONAL ARGENTINA\n4- ESPORTS\n5- PRIMERA DIVISION FUTBOL ARGENTINO\n0- VOLVER\nMAS COMPETENCIAS EN CONSTRUCCION...\n ");
    printf("opcion: ");
    menupartido = getchar();  
    system("cls");
    } while (menupartido != '1' && menupartido != '2' && menupartido != '0' && menupartido != '3' && menupartido !='4' && menupartido != '5');
    switch(menupartido){
        case '1':
        Cleanup();
        char** liber = Tlibertadores();
        int local = 0;
        int visitante = 0;

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", liber[i]);
        }

        int equipos_disponibles = 16;
        for (int ronda = 0; equipos_disponibles > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponibles / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", liber[j * 2], liber[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", liber[j * 2]);
                    scanf("%d", &local);
                    printf("Ingrese el resultado de %s: ", liber[j * 2 + 1]);
                    scanf("%d", &visitante);
                    if (local > visitante) {
                        pasaronda[j] = liber[j * 2];
                    } else {
                        pasaronda[j] = liber[j * 2 + 1];
                    }
                } while(local == visitante);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                liber[k] = pasaronda[k];
            }

            equipos_disponibles /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la Copa Libertadores es: %s\n", liber[0]);
        free(liber);
        system("pause");
        system("cls");
        Torneopreestablecido();

        break;
        case '2':
        Cleanup();
        char** champs = TUCL();
        int local1 = 0;
        int visitante1 = 0;  

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", champs[i]);
        }

        int equipos_disponiblesc = 16;
        for (int ronda = 0; equipos_disponiblesc > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesc / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", champs[j * 2], champs[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", champs[j * 2]);
                    scanf("%d", &local1);
                    printf("Ingrese el resultado de %s: ", champs[j * 2 + 1]);
                    scanf("%d", &visitante1);
                    if (local1 > visitante1) {
                        pasaronda[j] = champs[j * 2];
                    } else {
                        pasaronda[j] = champs[j * 2 + 1];
                    }
                } while(local1 == visitante1);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                champs[k] = pasaronda[k];
            }

            equipos_disponiblesc /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la UEFA Champions League es: %s\n", champs[0]);
        free(champs);
        system("pause");
        system("cls");
        Torneopreestablecido();


        break;
        case '3':
        Cleanup();
        char** B = TBN();
        int descenso1 = 0;
        int descenso2 = 0; 

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", B[i]);
        }

        int equipos_disponiblesB = 16;
        for (int ronda = 0; equipos_disponiblesB > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesB / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", B[j * 2], B[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", B[j * 2]);
                    scanf("%d", &descenso1);
                    printf("Ingrese el resultado de %s: ", B[j * 2 + 1]);
                    scanf("%d", &descenso2);
                    if (descenso1 > descenso2) {
                        pasaronda[j] = B[j * 2];
                    } else {
                        pasaronda[j] = B[j * 2 + 1];
                    }
                } while(descenso1 == descenso2);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                B[k] = pasaronda[k];
            }

            equipos_disponiblesB /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la B NACIONAL es: %s\n", B[0]);
        free(B); 
        system("pause");
        system("cls");
        Torneopreestablecido();      
       
        break;
        case '4':
        Cleanup();
        char** electro = Tesports();
        int esports1 = 0;
        int esports2 = 0;     

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", electro[i]);
        }

        int equipos_disponiblesE = 16;
        for (int ronda = 0; equipos_disponiblesE > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesE / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", electro[j * 2], electro[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", electro[j * 2]);
                    scanf("%d", &esports1);
                    printf("Ingrese el resultado de %s: ", electro[j * 2 + 1]);
                    scanf("%d", &esports2);
                    if (esports1 > esports2) {
                        pasaronda[j] = electro[j * 2];
                    } else {
                        pasaronda[j] = electro[j * 2 + 1];
                    }
                } while(esports1 == esports2);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                electro[k] = pasaronda[k];
            }

            equipos_disponiblesE /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la COPA E-SPORTS es: %s\n", electro[0]);
        free(electro);        
        system("pause");
        system("cls");
        Torneopreestablecido();  

        break;
        case '5':
        Cleanup();
        char** primera = Tprimera();
        int local3 = 0;
        int visitante4 = 0;  

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", primera[i]);
        }

        int equipos_disponiblesP = 16;
        for (int ronda = 0; equipos_disponiblesP > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesP / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", primera[j * 2], primera[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", primera[j * 2]);
                    scanf("%d", &local3);
                    printf("Ingrese el resultado de %s: ", primera[j * 2 + 1]);
                    scanf("%d", &visitante4);
                    if (local3 > visitante4) {
                        pasaronda[j] = primera[j * 2];
                    } else {
                        pasaronda[j] = primera[j * 2 + 1];
                    }
                } while(local3 == visitante4);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                primera[k] = pasaronda[k];
            }

            equipos_disponiblesP /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la PRIMERA DIVISION DEL FUTBOL ARGENTINO es: %s\n", primera[0]);
        free(primera);     
        system("pause");
        system("cls");
        Torneopreestablecido();  
        
        break;
        case '0':
        Torneopreestablecido(); // torneo pre
        break;

    }

}
void unicopartidoPER(){
    char menu;
        do{
        printf("COMPETICIONES:");
        printf("\n1- 32avos\n2- 16avos\n3- 8avos\n4- 4tos\n5- semis\n6- GRAN FINAL\n0- VOLVER");
        menu = getchar();
        system("cls");
    } while(menu != '1' && menu != '2' && menu != '0' && menu != '3' && menu !='4' && menu != '5' && menu != '6');
    switch(menu){
        case '1':
        Cleanup();
        int cantequipos = 64;
        char** treintidosavos = cargaequipos(cantequipos);
        int local = 0;
        int visitante = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequipos; j++){
            printf("%s \n", treintidosavos[j]);                
        }

        int equipos_disponibles = cantequipos;
        for (int ronda = 0; equipos_disponibles > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponibles / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", treintidosavos[j * 2], treintidosavos[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", treintidosavos[j * 2]);
                    scanf("%d", &local);
                    printf("Ingrese el resultado de %s: ", treintidosavos[j * 2 + 1]);
                    scanf("%d", &visitante);
                    if (local > visitante) {
                        pasaronda[j] = treintidosavos[j * 2];
                    } else {
                        pasaronda[j] = treintidosavos[j * 2 + 1];
                    }
                } while(local == visitante);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                treintidosavos[k] = pasaronda[k];
            }

            equipos_disponibles /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", treintidosavos[0]);
        for (int i = 1; i < cantequipos; i++) {
        free(treintidosavos[i]);
        }
        free(treintidosavos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '2':
        Cleanup();
        int cantequiposT = 32;
        char** dieciseis = cargaequipos(cantequiposT);
        int perlocal = 0;
        int pervisitante = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposT; j++){
            printf("%s \n", dieciseis[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesper = cantequiposT;
        for(int ronda = 0; equiposdisponiblesper > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesper / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", dieciseis[j * 2], dieciseis[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", dieciseis[j * 2]);
                    scanf("%d", &perlocal);
                    printf("Ingrese el resultado de %s: ", dieciseis[j * 2 + 1]);
                    scanf("%d", &pervisitante);
                    if (perlocal > pervisitante) {
                        pasaronda[j] = dieciseis[j * 2];
                    } else {
                        pasaronda[j] = dieciseis[j * 2 + 1];
                    }
                } while(perlocal == pervisitante);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                dieciseis[k] = pasaronda[k];
            }

            equiposdisponiblesper /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", dieciseis[0]);
        for(int i = 1; i < cantequiposT; i++) {
        free(dieciseis[i]);
        }
        free(dieciseis);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '3':
        Cleanup();
        int cantequiposD = 16;
        char** octavos = cargaequipos(cantequiposD);
        int localoctavos = 0;
        int visitanteoctavos = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposD; j++){
            printf("%s \n", octavos[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesoctavos = cantequiposD;
        for (int ronda = 0; equiposdisponiblesoctavos > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesoctavos / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", octavos[j * 2], octavos[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", octavos[j * 2]);
                    scanf("%d", &localoctavos);
                    printf("Ingrese el resultado de %s: ", octavos[j * 2 + 1]);
                    scanf("%d", &visitanteoctavos);
                    if (localoctavos > visitanteoctavos) {
                        pasaronda[j] = octavos[j * 2];
                    } else {
                        pasaronda[j] = octavos[j * 2 + 1];
                    }
                } while(localoctavos == visitanteoctavos);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                octavos[k] = pasaronda[k];
            }

            equiposdisponiblesoctavos /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", octavos[0]);
        for (int i = 1; i < cantequiposD; i++) {
        free(octavos[i]);
        }
        free(octavos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '4':
        Cleanup();
        int cantequiposcuartos = 8;
        char** cuartos = cargaequipos(cantequiposcuartos);
        int localcuartos = 0;
        int visitantecuartos = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposcuartos; j++){
            printf("%s \n", cuartos[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblescuartos = cantequiposcuartos;
        for(int ronda = 0; equiposdisponiblescuartos > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblescuartos / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", cuartos[j * 2], cuartos[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", cuartos[j * 2]);
                    scanf("%d", &localcuartos);
                    printf("Ingrese el resultado de %s: ", cuartos[j * 2 + 1]);
                    scanf("%d", &visitantecuartos);
                    if (localcuartos > visitantecuartos) {
                        pasaronda[j] = cuartos[j * 2];
                    } else {
                        pasaronda[j] = cuartos[j * 2 + 1];
                    }
                } while(localcuartos == visitantecuartos);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                cuartos[k] = pasaronda[k];
            }

            equiposdisponiblescuartos /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", cuartos[0]);
        for(int i = 1; i < cantequiposcuartos; i++) {
        free(cuartos[i]);
        }
        free(cuartos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '5':
        Cleanup();
        int cantequipossemis = 4;
        char** semis = cargaequipos(cantequipossemis);
        int localsemis = 0;
        int visitantesemis = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for(int j = 0; j < cantequipossemis; j++){
            printf("%s \n", semis[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblessemis = cantequipossemis;
        for (int ronda = 0; equiposdisponiblessemis > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblessemis / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", semis[j * 2], semis[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", semis[j * 2]);
                    scanf("%d", &localsemis);
                    printf("Ingrese el resultado de %s: ", semis[j * 2 + 1]);
                    scanf("%d", &visitantesemis);
                    if (localsemis > visitantesemis) {
                        pasaronda[j] = semis[j * 2];
                    } else {
                        pasaronda[j] = semis[j * 2 + 1];
                    }
                } while(localsemis == visitantesemis);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                semis[k] = pasaronda[k];
            }

            equiposdisponiblessemis /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", semis[0]);
        for(int i = 1; i < cantequipossemis; i++) {
        free(semis[i]);
        }
        free(semis);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '6':
        Cleanup();
        int cantequiposfinal = 2;
        char** final = cargaequipos(cantequiposfinal);
        int localfinal = 0;
        int visitantefinal = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposfinal; j++){
            printf("%s \n", final[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesfinal = cantequiposfinal;
        for(int ronda = 0; equiposdisponiblesfinal > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesfinal / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                do{
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", final[j * 2], final[j * 2 + 1]);
                    printf("Ingrese el resultado de %s: ", final[j * 2]);
                    scanf("%d", &localfinal);
                    printf("Ingrese el resultado de %s: ", final[j * 2 + 1]);
                    scanf("%d", &visitantefinal);
                    if (localfinal > visitantefinal) {
                        pasaronda[j] = final[j * 2];
                    } else {
                        pasaronda[j] = final[j * 2 + 1];
                    }
                } while(localfinal == visitantefinal);
            }

            for (int k = 0; k < enfrentamientos; k++) {
                final[k] = pasaronda[k];
            }

            equiposdisponiblesfinal /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", final[0]);
        for (int i = 1; i < cantequiposfinal; i++) {
        free(final[i]);
        }
        free(final);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break; 
        case '0':
        Torneopersonalizado(); 
        break;
    }

}

void idayvuelta(){
    char menupartido;
    do{
    printf("COMPETICIONES: \n");
    printf("1- COPA LIBERTADORES\n2- CHAMPIONS LEAGUE\n3- COPA B NACIONAL ARGENTINA\n4- ESPORTS\n5- PRIMERA DIVISION FUTBOL ARGENTINO\n0- VOLVER\nMAS COMPETENCIAS EN CONSTRUCCION...\n ");
    printf("opcion: ");
    menupartido = getchar(); 
    system("cls");
    } while (menupartido != '1' && menupartido != '2' && menupartido != '0' && menupartido != '3' && menupartido !='4' && menupartido != '5');
    switch(menupartido){
        case '1':
        Cleanup();
        char** liber = Tlibertadores();
        int IVliber1 = 0;
        int IVliber2 = 0;

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", liber[i]);
        }

        int equipos_disponibles = 16;
        for (int ronda = 0; equipos_disponibles > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponibles / 2;
            char** pasaronda = malloc(enfrentamientos * sizeof(char*));

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", liber[j * 2], liber[j * 2 + 1]);
                IVliber1 = 0;
                IVliber2 = 0;
                for (int l = 0; l < 2; l++){
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", liber[j * 2]);
                    scanf("%d", &IVliber1);
                    IVliber1 = IVliber1 + IVliber1;
                    printf("Ingrese el resultado de %s: ", liber[j * 2 + 1]);
                    scanf("%d", &IVliber2);
                    IVliber2 = IVliber2 + IVliber2;
                    int diferencia_total = (IVliber1 - IVliber2);

                    if (diferencia_total > 0) {
                        pasaronda[j] = liber[j * 2];
                    } else {
                        pasaronda[j] = liber[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                liber[k] = pasaronda[k];
            }

            equipos_disponibles /= 2;
            free(pasaronda);
        }

        printf("\nEl equipo ganador de la Copa Libertadores es: %s\n", liber[0]);
        free(liber);
        system("pause");
        system("cls");
        Torneopreestablecido();

        break;
        case '2':
        Cleanup();
        char** champs = TUCL();
        int IVchamps1 = 0;
        int IVchamps2 = 0;  

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", champs[i]);
        }

        int equipos_disponiblesc = 16;
        for (int ronda = 0; equipos_disponiblesc > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesc / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", champs[j * 2], champs[j * 2 + 1]);
                IVchamps1 = 0;
                IVchamps2 = 0;
                for (int l = 0; l < 2; l++){
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", champs[j * 2]);
                    scanf("%d", &IVchamps1);
                    IVchamps1 = IVchamps1 + IVchamps1;
                    printf("Ingrese el resultado de %s: ", champs[j * 2 + 1]);
                    scanf("%d", &IVchamps2);
                    IVchamps2 = IVchamps2 + IVchamps2;
                    int diferencia_total = (IVchamps1 - IVchamps2);

                    if (diferencia_total > 0) {
                        pasaronda[j] = champs[j * 2];
                    } else {
                        pasaronda[j] = champs[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                champs[k] = pasaronda[k];
            }

            equipos_disponiblesc /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la UEFA Champions League es: %s\n", champs[0]);
        free(champs);
        system("pause");
        system("cls");
        Torneopreestablecido();


        break;
        case '3':
        Cleanup();
        char** B = TBN();
        int IVdescenso1 = 0;
        int IVdescenso2 = 0; 

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", B[i]);
        }

        int equipos_disponiblesB = 16;
        for (int ronda = 0; equipos_disponiblesB > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesB / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", B[j * 2], B[j * 2 + 1]);
                IVdescenso1 = 0;
                IVdescenso2 = 0;
                for(int l = 0; l < 2; l++){
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", B[j * 2]);
                    scanf("%d", &IVdescenso1);
                    IVdescenso1 = IVdescenso1 + IVdescenso1;
                    printf("Ingrese el resultado de %s: ", B[j * 2 + 1]);
                    scanf("%d", &IVdescenso2);
                    IVdescenso2 = IVdescenso2 + IVdescenso2;
                    int diferencia_total = (IVdescenso1 - IVdescenso2);
                    if (diferencia_total > 0) {
                        pasaronda[j] = B[j * 2];
                    } else {
                        pasaronda[j] = B[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                B[k] = pasaronda[k];
            }

            equipos_disponiblesB /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la B NACIONAL es: %s\n", B[0]);
        free(B); 
        system("pause");
        system("cls");
        Torneopreestablecido();   
        break;
        case '4':
        Cleanup();
        char** electro = Tesports();
        int IVesports1 = 0;
        int IVesports2 = 0;     

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", electro[i]);
        }

        int equipos_disponiblesE = 16;
        for (int ronda = 0; equipos_disponiblesE > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesE / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", electro[j * 2], electro[j * 2 + 1]);
                IVesports1 = 0;
                IVesports2 = 0;
                for(int l = 0; l < 2; l++){
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", electro[j * 2]);
                    scanf("%d", &IVesports1);
                    IVesports1 = IVesports1 + IVesports1;
                    printf("Ingrese el resultado de %s: ", electro[j * 2 + 1]);
                    scanf("%d", &IVesports2);
                    IVesports2 = IVesports2 + IVesports2;
                    int diferencia_total = (IVesports1 - IVesports2);
                    if (diferencia_total > 0) {
                        pasaronda[j] = electro[j * 2];
                    } else {
                        pasaronda[j] = electro[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                electro[k] = pasaronda[k];
            }

            equipos_disponiblesE /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la COPA E-SPORTS es: %s\n", electro[0]);
        free(electro);        
        system("pause");
        system("cls");
        Torneopreestablecido();  
        break;
        case '5':
        Cleanup();
        char** primera = Tprimera();
        int IVprimera1 = 0;
        int IVprimera2 = 0;  

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", primera[i]);
        }

        int equipos_disponiblesP = 16;
        for (int ronda = 0; equipos_disponiblesP > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesP / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", primera[j * 2], primera[j * 2 + 1]);
                IVprimera1 = 0;
                IVprimera2 = 0;
                for(int l = 0; l < 2; l++){
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", primera[j * 2]);
                    scanf("%d", &IVprimera1);
                    IVprimera1 = IVprimera1 + IVprimera1;
                    printf("Ingrese el resultado de %s: ", primera[j * 2 + 1]);
                    scanf("%d", &IVprimera2);
                    IVprimera2 = IVprimera2 + IVprimera2;
                    int diferencia_total = (IVprimera1 - IVprimera2);
                    if (diferencia_total > 0) {
                        pasaronda[j] = primera[j * 2];
                    } else {
                        pasaronda[j] = primera[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                primera[k] = pasaronda[k];
            }

            equipos_disponiblesP /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la PRIMERA DIVISION DEL FUTBOL ARGENTINO es: %s\n", primera[0]);
        free(primera);     
        system("pause");
        system("cls");
        Torneopreestablecido();  
        break;
        case '0':
        Torneopreestablecido();
        break;

    }

}
void idayvueltaPER(){
    char menu;
    do{
        printf("COMPETICIONES:");
        printf("\n1- 32avos\n2- 16avos\n3- 8avos\n4- 4tos\n5- semis\n6- GRAN FINAL\n0- VOLVER");
        menu = getchar();
        system("cls");
    } while(menu != '1' && menu != '2' && menu != '0' && menu != '3' && menu !='4' && menu != '5' && menu != '6');
    switch(menu){
        case '1':
        Cleanup();
        int cantequipos = 64;
        char** treintidosavos = cargaequipos(cantequipos);
        int IVlocalper64 = 0;
        int IVvisitanteper64 = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequipos; j++){
            printf("%s \n", treintidosavos[j]);                
        }

        int equipos_disponibles = cantequipos;
        for (int ronda = 0; equipos_disponibles > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponibles / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", treintidosavos[j * 2], treintidosavos[j * 2 + 1]);
                IVlocalper64 = 0;
                IVvisitanteper64 = 0;
                for(int l = 0; l < 2; l++){
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", treintidosavos[j * 2]);
                    scanf("%d", &IVlocalper64);
                    IVlocalper64 = IVlocalper64 + IVlocalper64;
                    printf("Ingrese el resultado de %s: ", treintidosavos[j * 2 + 1]);
                    scanf("%d", &IVvisitanteper64);
                    IVvisitanteper64 = IVvisitanteper64 + IVvisitanteper64;
                    int diferenciatotal64 = (IVlocalper64 - IVvisitanteper64);
                    if (diferenciatotal64 > 0) {
                        pasaronda[j] = treintidosavos[j * 2];
                    } else {
                        pasaronda[j] = treintidosavos[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                treintidosavos[k] = pasaronda[k];
            }

            equipos_disponibles /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", treintidosavos[0]);
        for (int i = 1; i < cantequipos; i++) {
        free(treintidosavos[i]);
        }
        free(treintidosavos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '2':
        Cleanup();
        int cantequiposT = 32;
        char** dieciseis = cargaequipos(cantequiposT);
        int IVlocalper32 = 0;
        int IVvisitanteper32 = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposT; j++){
            printf("%s \n", dieciseis[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesper = cantequiposT;
        for(int ronda = 0; equiposdisponiblesper > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesper / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", dieciseis[j * 2], dieciseis[j * 2 + 1]);
                IVlocalper32 = 0;
                IVvisitanteper32 = 0;
                for(int l = 0; l < 2; l++){
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", dieciseis[j * 2]);
                    scanf("%d", &IVlocalper32);
                    IVlocalper32 = IVlocalper32 + IVlocalper32;
                    printf("Ingrese el resultado de %s: ", dieciseis[j * 2 + 1]);
                    scanf("%d", &IVvisitanteper32);
                    IVvisitanteper32 = IVvisitanteper32 + IVvisitanteper32;
                    int diferenciatotal32 = (IVlocalper32 - IVvisitanteper32);
                    if (diferenciatotal32 > 0) {
                        pasaronda[j] = dieciseis[j * 2];
                    } else {
                        pasaronda[j] = dieciseis[j * 2 + 1];
                    }
                
                }
            }   

            for (int k = 0; k < enfrentamientos; k++) {
                dieciseis[k] = pasaronda[k];
            }

            equiposdisponiblesper /= 2; 
            free(pasaronda);
        }

        
        printf("\nEl equipo ganador del torneo es: %s\n", dieciseis[0]);
        for(int i = 1; i < cantequiposT; i++) {
        free(dieciseis[i]);
        
        free(dieciseis);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '3':
        Cleanup();
        int cantequiposD = 16;
        char** octavos = cargaequipos(cantequiposD);
        int IVlocaloctavos = 0;
        int IVvisitanteoctavos = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposD; j++){
            printf("%s \n", octavos[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesoctavos = cantequiposD;
        for (int ronda = 0; equiposdisponiblesoctavos > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesoctavos / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", octavos[j * 2], octavos[j * 2 + 1]);
                IVlocaloctavos = 0;
                IVvisitanteoctavos = 0;
                for(int l = 0; l < 2; l++){
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", octavos[j * 2]);
                    scanf("%d", &IVlocaloctavos);
                    IVlocaloctavos = IVlocaloctavos + IVlocaloctavos;
                    printf("Ingrese el resultado de %s: ", octavos[j * 2 + 1]);
                    scanf("%d", &IVvisitanteoctavos);
                    IVvisitanteoctavos = IVvisitanteoctavos + IVvisitanteoctavos;
                    int diferenciatotaloctavos = (IVlocaloctavos - IVvisitanteoctavos);
                    if (diferenciatotaloctavos > 0) {
                        pasaronda[j] = octavos[j * 2];
                    } else {
                        pasaronda[j] = octavos[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                octavos[k] = pasaronda[k];
            }

            equiposdisponiblesoctavos /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", octavos[0]);
        for (int i = 1; i < cantequiposD; i++) {
        free(octavos[i]);
        }
        free(octavos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '4':
        Cleanup();
        int cantequiposcuartos = 8;
        char** cuartos = cargaequipos(cantequiposcuartos);
        int IVlocalcuartos = 0;
        int IVvisitantecuartos = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposcuartos; j++){
            printf("%s \n", cuartos[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblescuartos = cantequiposcuartos;
        for(int ronda = 0; equiposdisponiblescuartos > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblescuartos / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", cuartos[j * 2], cuartos[j * 2 + 1]);
                IVlocalcuartos = 0;
                IVvisitantecuartos = 0;
                for(int l = 0; l < 2; l++){
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", cuartos[j * 2]);
                    scanf("%d", &IVlocalcuartos);
                    IVlocalcuartos = IVlocalcuartos + IVlocalcuartos;
                    printf("Ingrese el resultado de %s: ", cuartos[j * 2 + 1]);
                    scanf("%d", &IVvisitantecuartos);
                    IVvisitantecuartos = IVvisitantecuartos + IVvisitantecuartos;
                    int diferenciatotalcuartos = (IVlocalcuartos - IVvisitantecuartos);
                    if (diferenciatotalcuartos > 0) {
                        pasaronda[j] = cuartos[j * 2];
                    } else {
                        pasaronda[j] = cuartos[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                cuartos[k] = pasaronda[k];
            }

            equiposdisponiblescuartos /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", cuartos[0]);
        for(int i = 1; i < cantequiposcuartos; i++) {
        free(cuartos[i]);
        }
        free(cuartos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '5':
        Cleanup();
        int cantequipossemis = 4;
        char** semis = cargaequipos(cantequipossemis);
        int IVlocalsemis = 0;
        int IVvisitantesemis = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for(int j = 0; j < cantequipossemis; j++){
            printf("%s \n", semis[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblessemis = cantequipossemis;
        for (int ronda = 0; equiposdisponiblessemis > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblessemis / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", semis[j * 2], semis[j * 2 + 1]);
                IVlocalsemis = 0;
                IVvisitantesemis = 0;
                for(int l = 0; l < 2; l++){
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", semis[j * 2]);
                    scanf("%d", &IVlocalsemis);
                    IVlocalsemis = IVlocalsemis + IVlocalsemis;
                    printf("Ingrese el resultado de %s: ", semis[j * 2 + 1]);
                    scanf("%d", &IVvisitantesemis);
                    IVvisitantesemis = IVvisitantesemis + IVvisitantesemis;
                    int diferenciatotalsemis = (IVlocalsemis - IVvisitantesemis);
                    if (diferenciatotalsemis > 0) {
                        pasaronda[j] = semis[j * 2];
                    } else {
                        pasaronda[j] = semis[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                semis[k] = pasaronda[k];
            }

            equiposdisponiblessemis /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", semis[0]);
        for(int i = 1; i < cantequipossemis; i++) {
        free(semis[i]);
        }
        free(semis);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '6':
        Cleanup();
        int cantequiposfinal = 2;
        char** final = cargaequipos(cantequiposfinal);
        int IVlocalfinal = 0;
        int IVvisitantefinal = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposfinal; j++){
            printf("%s \n", final[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesfinal = cantequiposfinal;
        for(int ronda = 0; equiposdisponiblesfinal > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesfinal / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", final[j * 2], final[j * 2 + 1]);
                IVlocalfinal = 0;
                IVvisitantefinal = 0;
                for(int l = 0; l < 2; l++){
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", final[j * 2]);
                    scanf("%d", &IVlocalfinal);
                    IVlocalfinal = IVlocalfinal + IVlocalfinal;
                    printf("Ingrese el resultado de %s: ", final[j * 2 + 1]);
                    scanf("%d", &IVvisitantefinal);
                    IVvisitantefinal = IVvisitantefinal + IVvisitantefinal;
                    int diferenciatotalfinal = (IVlocalfinal - IVvisitantefinal);
                    if (diferenciatotalfinal > 0) {
                        pasaronda[j] = final[j * 2];
                    } else {
                        pasaronda[j] = final[j * 2 + 1];
                    }
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                final[k] = pasaronda[k];
            }

            equiposdisponiblesfinal /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", final[0]);
        for (int i = 1; i < cantequiposfinal; i++) {
        free(final[i]);
        }
        free(final);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break; 
        case '0':
        Torneopersonalizado(); 
        break;
    }
}
}

void mejordetres(){
    char menupartido;
    do{
    printf("COMPETICIONES: \n");
    printf("1- COPA LIBERTADORES\n2- CHAMPIONS LEAGUE\n3- COPA B NACIONAL ARGENTINA\n4- ESPORTS\n5- PRIMERA DIVISION FUTBOL ARGENTINO\n0- VOLVER\nMAS COMPETENCIAS EN CONSTRUCCION...\n ");
    printf("opcion: ");
    menupartido = getchar();  
    system("cls");
    } while (menupartido != '1' && menupartido != '2' && menupartido != '0' && menupartido != '3' && menupartido !='4' && menupartido != '5');
     switch(menupartido){
        case '1':
        Cleanup();
        char** liber = Tlibertadores();
        int M3liber1 = 0;
        int M3liber2 = 0;
        int contliber1 = 0;
        int contliber2 = 0;

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", liber[i]);
        }

        int equipos_disponibles = 16;
        for (int ronda = 0; equipos_disponibles > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponibles / 2;
            char** pasaronda = malloc(enfrentamientos * sizeof(char*));

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", liber[j * 2], liber[j * 2 + 1]);
                M3liber1 = 0;
                M3liber2 = 0;
                contliber1 = 0;
                contliber2 = 0;
                while (contliber1 < 2 && contliber2 < 2 ){
                    M3liber1 = 0;
                    M3liber2 = 0;
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", liber[j * 2]);
                    scanf("%d", &M3liber1);
                    printf("Ingrese el resultado de %s: ", liber[j * 2 + 1]);
                    scanf("%d", &M3liber2);
                    if(M3liber1 > M3liber2){
                        contliber1++;   
                    } else {
                        contliber2++;
                    }
                }
                if (contliber1 > contliber2) {
                    pasaronda[j] = liber[j * 2];
                } else {
                    pasaronda[j] = liber[j * 2 + 1];
                }
                
            }

            for (int k = 0; k < enfrentamientos; k++) {
                liber[k] = pasaronda[k];
            }

            equipos_disponibles /= 2;
            free(pasaronda);
        }

        printf("\nEl equipo ganador de la Copa Libertadores es: %s\n", liber[0]);
        free(liber);
        system("pause");
        system("cls");
        Torneopreestablecido();

        break;


        case '2':
        Cleanup();
        char** champs = TUCL();
        int M3champs1 = 0;
        int M3champs2 = 0;  
        int contchamps1 = 0;
        int contchamps2 = 0;

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", champs[i]);
        }

        int equipos_disponiblesc = 16;
        for (int ronda = 0; equipos_disponiblesc > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesc / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", champs[j * 2], champs[j * 2 + 1]);
                M3champs1 = 0;
                M3champs2 = 0;
                contchamps1 = 0;
                contchamps2 = 0;
                while (contchamps1 < 2 && contchamps2 < 2 ){
                    M3champs1 = 0;
                    M3champs2 = 0;
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", champs[j * 2]);
                    scanf("%d", &M3champs1);
                    printf("Ingrese el resultado de %s: ", champs[j * 2 + 1]);
                    scanf("%d", &M3champs2);

                    if(M3champs1 > M3champs2){
                        contchamps1++;   
                    } else {
                        contchamps2++;
                    }
                }
                if (contchamps1 > contchamps2) {
                    pasaronda[j] = champs[j * 2];
                } else {
                    pasaronda[j] = champs[j * 2 + 1];
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                champs[k] = pasaronda[k];
            }

            equipos_disponiblesc /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la UEFA Champions League es: %s\n", champs[0]);
        free(champs);
        system("pause");
        system("cls");
        Torneopreestablecido();


        break;


        case '3':
        Cleanup();
        char** B = TBN();
        int M3descenso1 = 0;
        int M3descenso2 = 0; 
        int contdescenso1 = 0;
        int contdescenso2 = 0;
        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", B[i]);
        }

        int equipos_disponiblesB = 16;
        for (int ronda = 0; equipos_disponiblesB > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesB / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", B[j * 2], B[j * 2 + 1]);
                M3descenso1 = 0;
                M3descenso2 = 0;
                contdescenso1 = 0;
                contdescenso2 = 0;
                while(contdescenso1 < 2 && contdescenso2 < 2 ){
                    M3descenso1 = 0;
                    M3descenso2 = 0;
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", B[j * 2]);
                    scanf("%d", &M3descenso1);
                    printf("Ingrese el resultado de %s: ", B[j * 2 + 1]);
                    scanf("%d", &M3descenso2);
                    if(M3descenso1 > M3descenso2){
                        contdescenso1++;   
                    } else {
                        contdescenso2++;
                    }
                }
                if (contdescenso1 > contdescenso2) {
                    pasaronda[j] = B[j * 2];
                } else {
                    pasaronda[j] = B[j * 2 + 1];
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                B[k] = pasaronda[k];
            }

            equipos_disponiblesB /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la B NACIONAL es: %s\n", B[0]);
        free(B); 
        system("pause");
        system("cls");
        Torneopreestablecido();   
        break;

        case '4':
        Cleanup();
        char** electro = Tesports();
        int M3esports1 = 0;
        int M3esports2 = 0;  
        int contesport1 = 0;
        int contesport2 = 0;   

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", electro[i]);
        }

        int equipos_disponiblesE = 16;
        for (int ronda = 0; equipos_disponiblesE > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesE / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", electro[j * 2], electro[j * 2 + 1]);
                M3esports1 = 0;
                M3esports2 = 0;
                contesport1 = 0;
                contesport2 = 0;
                while(contesport1 < 2 && contesport2 < 2 ){
                    M3esports1 = 0;
                    M3esports2 = 0;
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", electro[j * 2]);
                    scanf("%d", &M3esports1);
                    printf("Ingrese el resultado de %s: ", electro[j * 2 + 1]);
                    scanf("%d", &M3esports2);
                   if(M3esports1 > M3esports2){
                        contesport1++;   
                    } else {
                        contesport2++;
                    }
                }
                if (contesport1 > contesport2) {
                    pasaronda[j] = electro[j * 2];
                } else {
                    pasaronda[j] = electro[j * 2 + 1];
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                electro[k] = pasaronda[k];
            }

            equipos_disponiblesE /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la COPA E-SPORTS es: %s\n", electro[0]);
        free(electro);        
        system("pause");
        system("cls");
        Torneopreestablecido();  
        break;

        case '5':
        Cleanup();
        char** primera = Tprimera();
        int M3primera1 = 0;
        int M3primera2 = 0;
        int contprimera1 = 0;
        int contprimera2= 0;  

        printf("Los equipos que juegan son:\n");
        for (int i = 0; i < 16; i++) {
            printf("%s\n", primera[i]);
        }

        int equipos_disponiblesP = 16;
        for (int ronda = 0; equipos_disponiblesP > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponiblesP / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", primera[j * 2], primera[j * 2 + 1]);
                M3primera1 = 0;
                M3primera2 = 0;
                contprimera1 = 0;
                contprimera2 = 0;
                while(contprimera1 < 2 && contprimera2 < 2){
                    M3primera1 = 0;
                    M3primera2 = 0;
                    printf("Partido:\n");
                    printf("Ingrese el resultado de %s: ", primera[j * 2]);
                    scanf("%d", &M3primera1);
                    printf("Ingrese el resultado de %s: ", primera[j * 2 + 1]);
                    scanf("%d", &M3primera2);
                    if(M3primera1 > M3primera2){
                        contprimera1++;   
                    } else {
                        contprimera2++;
                    }
                }
                 if (contprimera1 > contprimera2) {
                    pasaronda[j] = primera[j * 2];
                } else {
                    pasaronda[j] = primera[j * 2 + 1];
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                primera[k] = pasaronda[k];
            }

            equipos_disponiblesP /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador de la PRIMERA DIVISION DEL FUTBOL ARGENTINO es: %s\n", primera[0]);
        free(primera);     
        system("pause");
        system("cls");
        Torneopreestablecido();  
        break;
        case '0':
        Torneopreestablecido();
        break;

    }

}
void mejordetresPER(){
    char menu;
    do{
        printf("COMPETICIONES:");
        printf("\n1- 32avos\n2- 16avos\n3- 8avos\n4- 4tos\n5- semis\n6- GRAN FINAL\n0- VOLVER");
        menu = getchar();
        system("cls");
    } while(menu != '1' && menu != '2' && menu != '0' && menu != '3' && menu !='4' && menu != '5' && menu != '6');
    switch(menu){
        case '1':
        Cleanup();
        int cantequipos = 64;
        char** treintidosavos = cargaequipos(cantequipos);
        int M3localper64 = 0;
        int M3visitanteper64 = 0;
        int contlocal64 = 0;
        int contvisitante64 = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequipos; j++){
            printf("%s \n", treintidosavos[j]);                
        }

        int equipos_disponibles = cantequipos;
        for (int ronda = 0; equipos_disponibles > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equipos_disponibles / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", treintidosavos[j * 2], treintidosavos[j * 2 + 1]);
                M3localper64 = 0;
                M3visitanteper64 = 0;
                contlocal64 = 0;
                contvisitante64 = 0;
                while (contlocal64 < 2 && contvisitante64 < 2 ){
                    M3localper64 = 0;
                    M3visitanteper64 = 0;
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", treintidosavos[j * 2]);
                    scanf("%d", &M3localper64);
                    printf("Ingrese el resultado de %s: ", treintidosavos[j * 2 + 1]);
                    scanf("%d", &M3visitanteper64);
                    if(M3localper64 > M3visitanteper64){
                        contlocal64++;   
                    } else {
                        contvisitante64++;
                    }
                }
                if (contlocal64 > contvisitante64) {
                    pasaronda[j] = treintidosavos[j * 2];
                } else {
                    pasaronda[j] = treintidosavos[j * 2 + 1];
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                treintidosavos[k] = pasaronda[k];
            }

            equipos_disponibles /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", treintidosavos[0]);
        for (int i = 1; i < cantequipos; i++) {
        free(treintidosavos[i]);
        }
        free(treintidosavos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;


        case '2':
        Cleanup();
        int cantequiposT = 32;
        char** dieciseis = cargaequipos(cantequiposT);
        int M3localper32 = 0;
        int M3visitanteper32 = 0;
        int contlocal32 = 0;
        int contvisitante32 = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposT; j++){
            printf("%s \n", dieciseis[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesper = cantequiposT;
        for(int ronda = 0; equiposdisponiblesper > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesper / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", dieciseis[j * 2], dieciseis[j * 2 + 1]);
                M3localper32 = 0;
                M3visitanteper32 = 0;
                while (contlocal32 < 2 && contvisitante32 < 2 ){
                    M3localper32 = 0;
                    M3visitanteper32 = 0;
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", dieciseis[j * 2]);
                    scanf("%d", &M3localper32);
                    printf("Ingrese el resultado de %s: ", dieciseis[j * 2 + 1]);
                    scanf("%d", &M3visitanteper32);
                    if(M3localper32 > M3visitanteper32){
                        contlocal32++;   
                    } else {
                        contvisitante32++;
                    }
                }
                if (M3localper32 > M3visitanteper32) {
                    pasaronda[j] = dieciseis[j * 2];
                } else {
                    pasaronda[j] = dieciseis[j * 2 + 1];
                }
            }

            for (int k = 0; k < enfrentamientos; k++) {
                dieciseis[k] = pasaronda[k];
            }

            equiposdisponiblesper /= 2; 
            free(pasaronda);
        }
        printf("\nEl equipo ganador del torneo es: %s\n", dieciseis[0]);
        for(int i = 1; i < cantequiposT; i++) {
        free(dieciseis[i]);
        }
        
        free(dieciseis);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;


        case '3':
        Cleanup();
        int cantequiposD = 16;
        char** octavos = cargaequipos(cantequiposD);
        int M3localoctavos = 0;
        int M3visitanteoctavos = 0;
        int contlocal8 = 0;
        int contvisitante8 = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposD; j++){
            printf("%s \n", octavos[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblesoctavos = cantequiposD;
        for (int ronda = 0; equiposdisponiblesoctavos > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblesoctavos / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", octavos[j * 2], octavos[j * 2 + 1]);
                M3localoctavos = 0;
                M3visitanteoctavos = 0;
                while (contlocal8 < 2 && contvisitante8 < 2 ){
                    M3localoctavos = 0;
                    M3visitanteoctavos = 0;
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", octavos[j * 2]);
                    scanf("%d", &M3localoctavos);                  
                    printf("Ingrese el resultado de %s: ", octavos[j * 2 + 1]);
                    scanf("%d", &M3visitanteoctavos);
                   if(M3localoctavos > M3visitanteoctavos){
                        contlocal8++;   
                    } else {
                        contvisitante8++;
                    }
                }
                if (contlocal8 > contvisitante8) {
                    pasaronda[j] = octavos[j * 2];
                } else {
                    pasaronda[j] = octavos[j * 2 + 1];
                }
                
            }

            for (int k = 0; k <  enfrentamientos; k++) {
                octavos[k] = pasaronda[k];
            }

            equiposdisponiblesoctavos /= 2; 
            free(pasaronda);
        }
        
        printf("\nEl equipo ganador del torneo es: %s\n", octavos[0]);
        for (int i = 1; i < cantequiposD; i++) {
        free(octavos[i]);
        }

        free(octavos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;
        case '4':
        Cleanup();
        int cantequiposcuartos = 8;
        char** cuartos = cargaequipos(cantequiposcuartos);
        int M3localcuartos = 0;
        int M3visitantecuartos = 0;
        int contlocal4 = 0;
        int contvisitante4 = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for (int j = 0; j < cantequiposcuartos; j++){
            printf("%s \n", cuartos[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblescuartos = cantequiposcuartos;
        for(int ronda = 0; equiposdisponiblescuartos > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblescuartos / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", cuartos[j * 2], cuartos[j * 2 + 1]);
                M3localcuartos = 0;
                M3visitantecuartos = 0;
                while (contlocal4 < 2 && contvisitante4 < 2 ){
                    M3localcuartos = 0;
                    M3visitantecuartos = 0;
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", cuartos[j * 2]);
                    scanf("%d", &M3localcuartos);
                    printf("Ingrese el resultado de %s: ", cuartos[j * 2 + 1]);
                    scanf("%d", &M3visitantecuartos);
                    if(M3localcuartos > M3visitantecuartos){
                        contlocal4++;   
                    } else {
                        contvisitante4++;
                    }
                }
                if (contlocal4 > contvisitante4) {
                    pasaronda[j] = cuartos[j * 2];
                } else {
                    pasaronda[j] = cuartos[j * 2 + 1];
                }
                
            }

            for (int k = 0; k < enfrentamientos; k++) {
                cuartos[k] = pasaronda[k];
            }

            equiposdisponiblescuartos /= 2; 
            free(pasaronda);
        }
        
        printf("\nEl equipo ganador del torneo es: %s\n", cuartos[0]);
        for(int i = 1; i < cantequiposcuartos; i++) {
        free(cuartos[i]);
        }
        free(cuartos);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;


        case '5':
        Cleanup();
        int cantequipossemis = 4;
        char** semis = cargaequipos(cantequipossemis);
        int M3localsemis = 0;
        int M3visitantesemis = 0;
        int contlocal2 = 0;
        int contvisitante2 = 0;

        printf("EQUIPOS ANOTADOS:\n");
        for(int j = 0; j < cantequipossemis; j++){
            printf("%s \n", semis[j]);                
        }
        //printf("presione cualquier tecla para continuar...");

        int equiposdisponiblessemis = cantequipossemis;
        for (int ronda = 0; equiposdisponiblessemis > 1; ronda++) {
            printf("\n-- RONDA %d --\n", ronda + 1);
            int enfrentamientos = equiposdisponiblessemis / 2; 
            char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

            for (int j = 0; j < enfrentamientos; j++) {
                printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                printf("%s vs %s\n", semis[j * 2], semis[j * 2 + 1]);
                M3localsemis = 0;
                M3visitantesemis = 0;
                while (contlocal2 < 2 && contvisitante2 < 2 ){
                    M3localsemis = 0;
                    M3visitantesemis = 0;
                    printf("partido:");
                    printf("Ingrese el resultado de %s: ", semis[j * 2]);
                    scanf("%d", &M3localsemis);
                    printf("Ingrese el resultado de %s: ", semis[j * 2 + 1]);
                    scanf("%d", &M3visitantesemis);
                    if(M3localsemis > M3visitantesemis){
                        contlocal2++;   
                    } else {
                        contvisitante2++;
                    }
                }
                if (contlocal2 > contvisitante2) {
                    pasaronda[j] = semis[j * 2];
                } else {
                    pasaronda[j] = semis[j * 2 + 1];
                }
                
            }

            for (int k = 0; k < enfrentamientos; k++) {
                semis[k] = pasaronda[k];
            }

            equiposdisponiblessemis /= 2; 
            free(pasaronda);
        }
        
        printf("\nEl equipo ganador del torneo es: %s\n", semis[0]);
        for(int i = 1; i < cantequipossemis; i++) {
        free(semis[i]);
        }
        free(semis);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break;


        case '6':
            Cleanup();
            int cantequiposfinal = 2;
            char** final = cargaequipos(cantequiposfinal);
            int M3localfinal = 0;
            int M3visitantefinal = 0;
            int contlocalf = 0;
            int contvisitantef = 0;

            printf("EQUIPOS ANOTADOS:\n");
            for (int j = 0; j < cantequiposfinal; j++){
                printf("%s \n", final[j]);                
            }
            //printf("presione cualquier tecla para continuar...");

            int equiposdisponiblesfinal = cantequiposfinal;
            for(int ronda = 0; equiposdisponiblesfinal > 1; ronda++) {
                printf("\n-- RONDA %d --\n", ronda + 1);
                int enfrentamientos = equiposdisponiblesfinal / 2; 
                char** pasaronda = malloc(enfrentamientos * sizeof(char*)); 

                for (int j = 0; j < enfrentamientos; j++) {
                    printf("-- ENFRENTAMIENTO %d --\n", j + 1);
                    printf("%s vs %s\n", final[j * 2], final[j * 2 + 1]);
                    M3localfinal = 0;
                    M3visitantefinal = 0;
                    while (contlocalf < 2 && contvisitantef < 2 ){
                        M3localfinal = 0;
                        M3visitantefinal = 0;
                        printf("partido:");
                        printf("Ingrese el resultado de %s: ", final[j * 2]);
                        scanf("%d", &M3localfinal);
                        printf("Ingrese el resultado de %s: ", final[j * 2 + 1]);
                        scanf("%d", &M3visitantefinal);
                        if(M3localfinal > M3visitantefinal){
                            contlocalf++;   
                        } else {
                            contvisitantef++;
                        }
                    }
                    if (contlocalf > contvisitantef) {
                        pasaronda[j] = final[j * 2];
                    } else {
                        pasaronda[j] = final[j * 2 + 1];
                    }
                }
                for (int k = 0; k < enfrentamientos; k++) {
                    final[k] = pasaronda[k];
                }

                equiposdisponiblesfinal /= 2; 
                free(pasaronda);
            }
            
            printf("\nEl equipo ganador del torneo es: %s\n", final[0]);
            for (int i = 1; i < cantequiposfinal; i++) {
            free(final[i]);
            }
        free(final);
        system("pause");
        system("cls");
        Torneopersonalizado(); 
        break; 
        case '0':
        Torneopersonalizado(); 
        break;
    }
}

char** cargaequipos(int cantidad){  
    Cleanup();
    int c;
    while ((c = getchar()) != '\n') { 
        //limpia entrada antes de ingresar los equipos, si no lo hace la primera vuelta del for pasa de largo
    }
    char** mitorneo = malloc(cantidad * sizeof(char*));
    //printf("ESCRIBA EL NOMBRE DEL EQUIPO:\n");
    for (int i = 0; i < cantidad; i++){
        printf("ESCRIBA EL NOMBRE DEL EQUIPO:\n"); 
        mitorneo[i] = malloc(NOMBREMAX * sizeof(char*));
        fgets(mitorneo[i], NOMBREMAX, stdin);
        mitorneo[i][strcspn(mitorneo[i], "\n")] = 0;
    }
    
    return mitorneo;

}

char** Tlibertadores(){
    char* libertadores[27] = {"Newell's", "River Plate", "Talleres de Córdoba", "San Lorenzo", "Estudiantes de La Plata", "The Strongest", "Bolívar", "Fluminense", "San Pablo", "Palmeiras", "Gremio", "Atlético Mineiro", "Flamengo", "Huachipato", "Cobresal", "Millonarios", "Junior", "Liga de Quito", "Independiente del Valle", "Barcelona de Guayaquil", "Olimpia", "Cerro Porteño", "Universitario", "Alianza Lima", "Liverpool", "Peñarol", "Deportivo Táchira", "Caracas"};
    srand(time(NULL));
    char** liber = malloc(16 * sizeof(char*)); // Reservar memoria para el arreglo de punteros a char
    if (liber == NULL) {
        printf("Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }
    int equiposdisponibles = 27; 
    for (int i = 0; i < 16; i++) {
        int rango = rand() % equiposdisponibles; 
        liber[i] = libertadores[rango];
        libertadores[rango] = libertadores[equiposdisponibles - 1];
        equiposdisponibles--;
    }
    
    

    return liber;

}

char** TUCL(){
    char* UCL[28] = {"Arsenal", "Man City", "Liverpool", "Aston Villa", "Real Madrid", "Barcelona", "Girona", "Atlético de Madrid", "Leverkusen", "Bayern", "Stuttgart", "Leipzig", "Inter", "Milan", "Juventus", "Bolonia", "Paris Saint-Germain", "Mónaco", "Brest", "PSV Eindhoven", "Feyenoord", "Sporting CP", "Anderlecht", "Celtic", "Sturm Graz", "Roma", "Dortmund", "Shakhtar Donetsk", "Benfica"};
    srand(time(NULL));
    char** champs = malloc(16 * sizeof(char*));
    if (champs == NULL) {
        printf("Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }
    int equiposdisponibles = 28; 
    for (int i = 0; i < 16; i++) {
        int rango = rand() % equiposdisponibles; 
        champs[i] = UCL[rango];
        UCL[rango] = UCL[equiposdisponibles - 1];
        equiposdisponibles--;
    }
    
    //getch();
    return champs;

    

}

char** TBN(){
    char* BNAC[30] = {"Atlético de Rafaela", "Belgrano", "All Boys", "Barracas Central", "Brown de Adrogué", "Almirante Brown", "Deportivo Morón", "Estudiantes de Río Cuarto", "Ferro Carril Oeste", "Gimnasia y Esgrima de Mendoza", "Guillermo Brown de Puerto Madryn", "Independiente Rivadavia", "Instituto de Córdoba", "Mitre de Santiago del Estero", "Nueva Chicago", "Platense", "Quilmes", "Riestra", "San Martín de San Juan", "Santamarina de Tandil", "Temperley", "Tigre", "Villa Dálmine", "Atlanta", "San Martín de Tucumán", "Defensores de Belgrano", "Chacarita Juniors", "Atlético de Güemes", "Agropecuario", "Estudiantes de Caseros"};
    srand(time(NULL));
    char** B = malloc(16 * sizeof(char*));
    if (B == NULL) {
        printf("Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }
    int equiposdisponibles = 30; 
    for (int i = 0; i < 16; i++) {
        int rango = rand() % equiposdisponibles; 
        B[i] = BNAC[rango];
        BNAC[rango] = BNAC[equiposdisponibles - 1];
        equiposdisponibles--;
    }
   
    //getch();
    return B;
    


}

char** Tesports(){
    char* esports[49] = {"Astralis", "Team Liquid", "Natus Vincere", "Fnatic", "FaZe Clan", "G2 Esports", "Evil Geniuses", "Team Vitality", "Ninjas in Pyjamas (NiP)", "Complexity Gaming", "MIBR (Made in Brazil)", "Team Envy", "Cloud9", "OG Esports", "Team Spirit", "Team Heroic", "BIG", "Gambit Esports", "Virtus.pro", "FURIA Esports", "Team Dignitas", "Team Endpoint", "OG", "GODSENT", "MAD Lions", "Team SoloMid (TSM)", "mousesports", "Team LDLC", "Renegades", "Team Heretics", "Sprout", "HellRaisers", "Copenhagen Flames", "Team Secret", "Movistar Riders", "Tyloo", "Team FATE", "Team Unique", "Team Singularity", "Illuminar Gaming", "Winstrike Team", "forZe", "AGO Esports", "Izako Boars", "Virtus.pro (Polar Ace)", "Nexus Gaming", "Sinners Esports", "ex-Space Soldiers", "Wisla Krakow", "Lyngby Vikings"};
    srand(time(NULL));
    char** electro = malloc(16 * sizeof(char*));
    if (electro == NULL) {
        printf("Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }
    int equiposdisponibles = 49; 
    for (int i = 0; i < 16; i++) {
        int rango = rand() % equiposdisponibles; 
        electro[i] = esports[rango];
        esports[rango] = esports[equiposdisponibles - 1];
        equiposdisponibles--;
    }
    
   
    //getch();
    return electro;


}

char** Tprimera(){
    char* LPF[19] = {"River Plate", "Boca Juniors", "Independiente", "Racing Club", "San Lorenzo", "Huracán", "Vélez Sarsfield", "Argentinos Juniors", "Lanús", "Defensa y Justicia", "Estudiantes de La Plata", "Gimnasia y Esgrima La Plata", "Rosario Central", "Newells Old Boys", "Central Córdoba", "Colón de Santa Fe", "Banfield", "Arsenal", "Talleres de Córdoba", "Godoy Cruz"};
    srand(time(NULL));
    char** primera = malloc(16 * sizeof(char*));
    if (primera == NULL) {
        printf("Error de asignación de memoria\n");
        exit(EXIT_FAILURE);
    }
    int equiposdisponibles = 19; 
    for (int i = 0; i < 16; i++) {
        int rango = rand() % equiposdisponibles; 
        primera[i] = LPF[rango];
        LPF[rango] = LPF[equiposdisponibles - 1];
        equiposdisponibles--;
    }

    //getch();
    return primera;


}
