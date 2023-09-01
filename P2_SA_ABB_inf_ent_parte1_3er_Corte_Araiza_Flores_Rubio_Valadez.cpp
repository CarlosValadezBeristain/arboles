#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <locale.h>
#include <regex>

/* Creadores Jose de Jesus Araiza Rodriguez, Bryan Josue Flores Gonzales,
    Julio Leonel Rubio Ramirez, Carlos Ernesto Valadez Berisatin*/
using namespace std;

regex vedad("[0-9]+");  //Validaciones con regex


struct Nodo
{
	int dato;
	Nodo *der;		
	Nodo *izq;
};

typedef struct Cola
{
    Nodo *nodo;
    Cola *siguiente;
}Cola;


char menu(void);
char menure(void);

Nodo *crearNodo(int);

void insertar(Nodo *&, int);
void mostrar(Nodo *,int);
void PreOrden(Nodo *);			//funciones 
void InOrden(Nodo *);
void PostOrden(Nodo *);
void nivel(Nodo *arbol);
bool busqueda(Nodo *, int);
void recorridos();
char YN();
void altura(Nodo *,int);
void recorridoAmplitud(Nodo*dato);
void agregarACola(Cola *&inicio,Cola *&fin, Nodo *nodo);
void recorridoAnchura();
Cola *sacarCola(Cola *&inicio);
void recorrerCola(Cola *inicio);
Cola *inicio1=NULL,*fin1=NULL,*inicio2=NULL,*fin2=NULL;
void BuscarP(Nodo *,int);
void Tipo_Nodo(Nodo *);

void gotoxy(int x,int y)  //Función de gotoxy 
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
}


Nodo *arbol=NULL;
int a=0,bb,p;

main()
{
//	int dato;
	char opc;
	int V=2;
	
	setlocale(LC_CTYPE,"");             //funcion para usar español


	do
	{
	     int contador=0;
	     int bb;
	     int dato;
	     a=0;
	     char data[10];
		opc=menu();                          //menu utilizando rangos con codigo ascci
	
	
		switch(opc)
		{
			
			char o;
			
			case 59:
				
					do{
						
						system("cls");
						do
						{
								
							memset(data,0,sizeof(data)); 
							gotoxy(16,11);
							
							
							
							cout<<"\nIngrese un numero: ";
										          
							fflush(stdin);
							gotoxy(20,12);gets(data);
							
						
							fflush(stdin);
							if(!regex_match(data,vedad))
							{
								Beep(500,500);
								gotoxy(20,12);printf("                                                      ");
								gotoxy(20,12);printf("ERROR");
								Sleep(500);
								gotoxy(20,12);printf("                                                      ");
							}
						}while(!regex_match(data,vedad));
						
						dato=atoi(data);
						V=5;
						insertar(arbol,dato);
						cout<<"\n";
						
						printf("Desea agregar otro Nodo? S/N");
		
						opc=YN();
		
						}while(opc=='s'|| opc=='S');
						//system("pause");
									
						break;
					
			case 60: 
						if(V==5)
						{
							cout<<"Mostrando el Arbol completo: \n\n";
							cout<<"El arbol esta en Horizontal \n\n";
					    	mostrar(arbol,contador);
					    	cout<<"\n";
						}
				    	else
				    	cout<<"INGRESE DATOS \n\n";
				    	
				    	system("pause");
					break;
					
			case 61:
						if(V==5)
						{
							recorridos();
						}
				    	else
				    	cout<<"INGRESE DATOS \n\n";
			
						system("pause");
						break;	

			case 62: 
						if(V==5)
						{
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
							cout<<"\n Recorrido de amplitud es por Niveles \n\n ";
							SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
						    bb++;
							if(bb>1){
					         cout<<"\n\n";
							 cout<<"Cambios o ingresos en el arbol "<< bb<< endl;
							  
							}
							recorridoAnchura();
						    cout<<"\n\n";
						}
				    	else
				    	cout<<"INGRESE DATOS \n\n";
			
						system("pause");
				    break;  	
					
			case 63:
						if(V==5)
						{
						cout<<"\nNumero a Buscar: ";
						cin>>dato;
						if(busqueda(arbol,dato) == true){
						cout<<"El elemento "<<dato<<" SI fue encontrado ";
						if(arbol->dato == dato)
						{
						 cout<<"El elemento es Nodo raiz\n";
						 a=2;	
						}
					
						if(a==0)
						{
								BuscarP(arbol,dato);
				 		if(p == 1 ){
				   		cout<<"El elemento es Nodo Interno"<<endl;
				  		 p=0;
							}
				        
						else{
						cout<<"El elemento es Nodo Hoja"<<endl;
		    		 	}
						}
					
					
		
						}
						else{
							cout<<"Elemento '"<<dato<<"' NO fue encontrado.";
						}
						}
						else
				    		cout<<"INGRESE DATOS \n\n";
				    		system("pause");
						break;
					         
					
					
			case 27: 
					   printf("\nFin del programa\n");
							                             
						system("pause");			
			
			default:
						if(opc !=27)
						{
							
						}
							break;

	}
		
		
		}while(opc!=27);	
	return 0;
	
	
	
	getch();
	return 0;
}



Nodo *crearNodo(int n) //crear nuevo nodo 
{
	
	Nodo *nuevo_nodo = new Nodo();
	
	nuevo_nodo->dato = n;
	nuevo_nodo->der = NULL;
	nuevo_nodo->izq = NULL;
	
	return nuevo_nodo;
}

void insertar(Nodo *&arbol, int n)
{
	
	if(arbol == NULL)
	{
		Nodo *nuevo_nodo= crearNodo(n);
		arbol = nuevo_nodo;
	}
	else 
	{
		int valorRaiz = arbol->dato;
		if(n < valorRaiz)
		{
			insertar(arbol->izq,n);
		}
		if(n > valorRaiz)
		{
			insertar(arbol->der,n);
		}
			if(n == valorRaiz)
		{
			printf("Ese digito ya esta ingresado\n");
		}
	}
	
}

void mostrar (Nodo *arbol, int cont)
{
	
	if (arbol == NULL)
	{
		return;
	}
	else 
	{
		mostrar(arbol->der,cont+1);
		for(int i=0; i<cont; i++)
		{
			cout<<"   ";
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrar(arbol->izq,cont+1);
		
	}

}

void PreOrden(Nodo *arbol){
	if(arbol == NULL){
		return ;
	}else{
		cout<<arbol->dato<<" - ";
		PreOrden(arbol->izq);
		PreOrden(arbol->der);
	}
}

void InOrden(Nodo *arbol){
	if(arbol == NULL){
		return ;
	}else{
		InOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		InOrden(arbol->der);
	}
}

void PostOrden(Nodo *arbol){
	int a=0;
	if(arbol == NULL){
		return ;
	}else{

		PostOrden(arbol->izq);
		PostOrden(arbol->der);
		cout<<arbol->dato<<" - ";

	}
}


bool busqueda(Nodo *arbol, int n)
{
	if(arbol == NULL)
	
		return false;
	
	else if(arbol->dato == n)
		
		return true;
	
	else if( n < arbol->dato)

		return busqueda(arbol->izq,n);
	
	else
	
		busqueda(arbol->der,n);
	
}

void nivel(Nodo *arbol){
	
	if(arbol == NULL){
		return ;
	}else{
		cout<<arbol->dato<<" - ";
		nivel(arbol->izq);
		nivel(arbol->der);
		
	}
	system("pause");	
}

void altura(Nodo *arbol, int cont)
{
	
	if (arbol == NULL)
	{
		return;
	}
	else 
	{
		mostrar(arbol->der,cont+1);
		for(int i=0; i<cont; i++)
		{
			cout<<"   ";
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrar(arbol->izq,cont+1);
		
	}

}

void recorridos()
{
	//	int dato;
	char opc;
	int V=2;



	do
	{
	     int contador=0;
	     int dato;
	     char data[10];
		opc=menure();                          //menu utilizando rangos con codigo ascci
	
	
		switch(opc)
		{
			
			char o;
			
			case 59:
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
					cout<<"\n Recorrido de preorden, la raíz se recorre antes que los recorridos de los subárboles izquierdo y derecho \n\n ";
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
					PreOrden(arbol);
					system("pause");				//funciones 			
					break;
					
			case 60: 
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
					cout<<"\n Recorrido de inorden, la raíz se recorre entre los recorridos de los árboles izquierdo y derecho \n\n ";
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
					InOrden(arbol);
					system("pause");	
					break;
					
			case 61:
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
					cout<<"\n Recorrido de postorden, la raíz se recorre después de los recorridos por el subárbol izquierdo y el derecho \n\n ";
					SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
					PostOrden(arbol);
					system("pause");	
					break;	
 	
					
					         
					
					
			case 27: 
				   printf("\nFin de Recorridos\n");						                           			
			
			default:
				if(opc !=27)
				{
					
				}
					break;

	}
		
		
		}while(opc!=27);			
}


char YN() //Funcion para ahorranos lineas de codigo S/N
{
	char opc;
	do{
		opc=getch();
		if(opc!='n' && opc!='N' && opc!='s' && opc!= 'S')
		{
			Beep(500,200);
		}
		
	}while(opc!='n' && opc!='N' && opc!='s' && opc!= 'S');
	
	return opc;
}

//Recorrido por anchura
void recorridoAnchura()
{
	if(arbol == NULL){
		cout<<"ERROR NO INGRESO DATOS"<<endl;
		return;
		
	}
	
	
    if(arbol != NULL)
    {
        agregarACola(inicio1,fin1,arbol);
        while(inicio1 != NULL)
        {
            Cola *cola;
            cola = sacarCola(inicio1);
            Nodo *aux;
            aux = cola->nodo;
            agregarACola(inicio2,fin2,cola->nodo);
            if(aux->izq != NULL)
            {
                agregarACola(inicio1,fin1,aux->izq);
            }
            if(aux->der != NULL)
            {
                agregarACola(inicio1,fin1,aux->der);
            }
        }
       
        recorrerCola(inicio2);
    }
}
//Agregar cola
void agregarACola(Cola *&inicio,Cola *&fin, Nodo *nodo)
{
    Cola *nuevo = new Cola;
    nuevo->nodo = nodo;
    nuevo->siguiente = NULL;
    if(inicio != NULL)
    {
        fin->siguiente = nuevo;
        fin = nuevo;
    }
    else
    {
        inicio = nuevo;
        fin = nuevo;
    }
}
//Sacar de dato de cola
Cola *sacarCola(Cola *&inicio)
{
    Cola *nodo;
    nodo = inicio;
    inicio = inicio->siguiente;
    return nodo;
}

//Recorrido de cola
void recorrerCola(Cola *inicio)
{
    if(bb>0){
         cout<<"\n\n";
		 cout<<"Cambios o ingresos en el arbol "<< bb<< endl;
		  
		}
    
    while(inicio != NULL)
    {
        Nodo *aux;
        aux = inicio->nodo;
        
		cout<<aux->dato;
        
        inicio = inicio->siguiente;
        if(inicio != NULL)
        {
              cout<< " -> ";
              
        }
    }
    
}

void BuscarP(Nodo *arbol,int n){
		
	if(arbol == NULL){
		cout<<"ERROR NO INGRESO DATOS"<<endl;
		return;
	
	}


	else if (n < arbol->dato){
		BuscarP(arbol->izq,n);
	}	
    
	
	
	else if(n > arbol->dato){
	     BuscarP(arbol->der,n);

	}
	
	else{
		
	 Tipo_Nodo(arbol);

	}
}


void Tipo_Nodo(Nodo *Tipo_nodo){
	
	if(Tipo_nodo->izq || Tipo_nodo->der){
		
		p++;
	}
	
	}

char menure()
{
	char opc1='\0';
	system("cls");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
	printf("Menu\n");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	printf("[F1] mostrar recorrido PreOrden\n");
	printf("[F2] mostrar recorrido InOrden\n");
	printf("[F3] mostrar recorrido PostOrden\n");
	printf("ESC. Salir\n");
	printf("Seleccione una opcion: ");

	opc1=getch();                          //validacion del ESC
	
	if(opc1==0)
	{
		opc1 = getch();
	}
	else if(opc1!=27)
	{
		opc1=-1;
	}
	return opc1;
	
}

char menu()
{
	char opc1='\0';
	system("cls");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),9);
	printf("Menu\n");
	SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE),15);
	printf("[F1] Insertar Nuevo Nodo\n");
	printf("[F2] Mostrar arbol\n");	
	printf("[F3] Mostrar Recorridos\n");	
	printf("[F4] Recorrido por amplitud\n");
	printf("[F5] Buscar nodo\n");
	printf("ESC. Salir\n");
	printf("Seleccione una opcion: ");

	opc1=getch();                          //validacion del ESC
	
	if(opc1==0)
	{
		opc1 = getch();
	}
	else if(opc1!=27)
	{
		opc1=-1;
	}
	return opc1;
	
}

	

