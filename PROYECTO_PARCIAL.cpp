/*PROYECTO FINAL
    PROYECTO FINAL GENERAR NUMEROS ALEATOREOS
PRESENTADO POR: JHON ANDERSON SANCHEZ
DOCENTE: CARLOS LONDOÑO
ESTRUCTURAS DE DATOS 2*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Reservar_Memoria (Nodo*)malloc(sizeof(Nodo))

struct Nodo{
	int dato;
	Nodo * Siguiente;
	Nodo * Izquierda;
	Nodo * Derecha;
}nodo;

Nodo* inicio=NULL;
Nodo* arbol=NULL;



void gen_Numeros();
void leer_Numeros();
void inserArchivoLIFO();
void Ordenamiento_Burbuja();
void Ordenamiento_Seleccion();
void Insertar_elementos_lifo(Nodo*&,int);
void insert_Nodo(Nodo *&,int);//Inserat elementos a arbol
void imprimirArbol(Nodo *,int);//mostrar elemntos del arbol
void Mostrar_LIFO();
void Menu();


char numero[7];
FILE *documento;
int i=0,n,cont=0;


int main(){
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    printf("%s\n",output);

	Menu();
	system("pause");

    return 0;
}

void Menu(){
    int opc;
    do{
        system("cls");
        printf("\n\t\t\tMENU PROYECTO FINAL \n\n");
        printf("1-  Generar Numeros.\n");
        printf("2-  Ver Numeros generados\n");
        printf("3-  Ordenar Elementos Por (M.Burbuja)\n");
        printf("4-  Ordenar Elementos Por (M.seleccion)\n");
        printf("5-  Mostrar elementos ordenados\n");
        printf("6-  Mostrar elemEntos del arbol Binario de busqueda\n");
        printf("0). Salir\n");

        printf("Seleccione una opcion: \n\n");
        scanf("%d",&opc);
        switch(opc){
            case 0:
                printf("\nHas Salido del Programa!!!");
                break;
            case 1: printf("\n GENERANDO NUMEROS ALEATOREOS");
                gen_Numeros();
                printf("\n\n");
                break;
            case 2: printf("VER NUMEROS GENERADOS ");
                leer_Numeros();
                printf("\n\n");
                break;
            case 3: printf("METODO DE ORDENAMIENTO POR BURBUJA");
                Ordenamiento_Burbuja();
                printf("\n\n");
                break;
            case 4: printf("METODO DE ORDENAMIENTO POR SELECCION");
                Ordenamiento_Seleccion();
                printf("\n\n");
                break;
            case 5:
                Mostrar_LIFO();
                printf("\n\n");
                break;
            case 6:
                imprimirArbol(arbol,cont);
                system("pause");
                printf("\n\n");
                break;
            default:
                system("pause");
               // system("cls");
                printf("\nValor ingresado no valido");
        }
    }while(opc!=0);
}

void gen_Numeros(){
    FILE *archivo;
	int i = 0, n;
	char numero[7];
    archivo = fopen("Numeros_generados.txt", "w");
	srand(time(NULL));
	while(i < 1000000){
		n = 1 + (rand() % (1999998 + 1)); - 999999;

		Insertar_elementos_lifo(inicio,n);
		//system("pause");
		insert_Nodo(arbol,n);
		//system("pause");
		sprintf(numero, "%d", n);
		fputs(numero, archivo);
		putc(',', archivo);
		i += 1;
	}
	printf("\n\t\t Elemntos ingresados a una lista\n");
	system("pause");
	printf("\n\t\t Elementos ingresados al ARBOL BINARIO DE BUSQUEDA\n");
	system("pause");
	printf("\nGenerados %d numeros", i);
	fclose(archivo);
	system("pause");
}
void leer_Numeros(){
    char num;
    printf("\n\nabrir el archivo...\n\n");
    FILE *archivo;
 	archivo = fopen ( "Numeros_generados.txt", "r" );
        if(archivo == NULL){
        printf("El archivo no existe o no es posible abirlo");
    }else{
        printf( "Contenido del fichero:\n" );
        num= getc(archivo);
        while (feof(archivo)==0) {
            printf( "%c",num );
            num = getc(archivo);
        }
        system("pause");
	}
    fclose(archivo);
}

void Insertar_elementos_lifo(Nodo*&inicio,int n){
	Nodo *nuevo_Nodo = Reservar_Memoria;
    nuevo_Nodo->dato=n;
    nuevo_Nodo->Siguiente=inicio;
    inicio= nuevo_Nodo;
}
void Mostrar_LIFO(){
	Nodo * aux = Reservar_Memoria;
    aux = inicio;
    while(aux != NULL){
        printf("%d,", aux->dato);
        aux=aux->Siguiente;
    }
    system("Pause");
}
void Ordenamiento_Burbuja(){
    FILE *archivo;
    archivo=fopen("Ordenado_burbuja.txt","w");
    if(inicio != NULL){
		Nodo *p=Reservar_Memoria;
		Nodo *j=Reservar_Memoria;
		int aux;
		p = inicio;
		while(p != NULL){
			j = p ->Siguiente;
			while(j != NULL){
				if(p -> dato > j -> dato){
					aux = j -> dato;
					j -> dato = p -> dato;
					p -> dato = aux;
                    fputc(aux,archivo);
                    putc(',',archivo);
				}
				j = j -> Siguiente;
			}
			p = p -> Siguiente;
		}
		fclose (archivo);
	}else{
		printf("La lista esta vacia");
	}
    printf("\nHa finalizado el ordenamiento!!\n\n");
    system("pause");
}

void Ordenamiento_Seleccion(){
    int menor,aux;
    FILE *archivo;
    archivo=fopen("Ordenado_Seleccion.txt","w");
    if(inicio != NULL){
		Nodo *p=Reservar_Memoria;
		Nodo *j=Reservar_Memoria;
		p=inicio;
		while(p!=NULL){
            menor=p->dato;
            j=p;
            while(j!=NULL){
                if(menor>j->dato){
                    menor=j->dato;
                    aux=p->dato;
                    p->dato=menor;
                    j->dato=aux;
                    fputc(aux,archivo);
                    putc(',',archivo);
                }
                j=j->Siguiente;
            }
            p=p->Siguiente;
		}
	}else{
		printf("La lista esta vacia");
	}
    printf("\n\nordenamiento Finalizado!!\n\n");
    system("pause");
}

void inserArchivoLIFO(){
    char num;
    FILE *archivo;
 	archivo = fopen ( "Numeros_generados.txt", "r" );
        if(archivo == NULL){
        printf("El archivo no existe o no es posible abirlo");
    }else{
        num = getc(archivo);
        while (feof(archivo)==0) {
        Insertar_elementos_lifo(inicio,n);
        num = getc(archivo);
        }
	}
    fclose(archivo);
}

void insert_Nodo(Nodo *&arbol, int n){
    if(arbol==NULL){
        Nodo *nuevo_Nodo=Reservar_Memoria;
        arbol=nuevo_Nodo;
        nuevo_Nodo->dato=n;
        nuevo_Nodo->Izquierda=NULL;
        nuevo_Nodo->Derecha=NULL;
    }else{
        int valor=arbol->dato;
        if(n<valor){
            insert_Nodo(arbol->Izquierda,n);
        }else{
            insert_Nodo(arbol->Derecha,n);
        }
    }
}

void imprimirArbol(Nodo *arbol, int cont){
	int i;
	if(arbol == NULL){
		return;
	}else{
		imprimirArbol(arbol -> Derecha, cont += 1);
		for(i = 0; i < cont; i++){
			printf("   ");
		}
		printf("%d\n", arbol -> dato);
		imprimirArbol(arbol -> Izquierda, cont += 1);
	}
}
