//Programa principal para sistema de ventas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Estructura para Todas las listas, para el caso de la lista de Departamentos se pierde mucha memoria, pero ni pedo
//me di cuenta muy tarde
typedef struct Producto{
	int cantidad;
	float precio;
	char nombre[20];
	struct Producto *Productosig;
	}Producto;


Producto* insertarinicio(Producto* inicio, int valor,float precio,char *nombre);
Producto* RemoverDepartamento(Producto *inicio, unsigned int indice,char *nombre);
Producto* RemoverProducto(Producto *inicio, unsigned int indice);
Producto* leerinventario(Producto *inicio,char *archnom);
Producto* leerDepartamentos(Producto *inicio);
Producto* BorrarList(Producto *inicio);
float Venta(Producto *inicio,int n, unsigned int indice);
float Compra(Producto *inicio,int n, unsigned int indice);
char* Obtener(Producto *inicio, unsigned int indice);
int ValidarOpcion(int x);
int VerificarDepas(char *departamento);
int VerificarProduct(Producto *inicio,char *producto);
int imprimeInventario(Producto *inicio);
int imprimeDepartamento(Producto *inicio);
void AgregarDepartamento(Producto *inicio);
void AgregarProductos(Producto *inicio,char* nombre);

main(){

	Producto *inicio=NULL;//Aputador para lista de productos
	Producto *cabeza=NULL;//Apuntador para lista de departamentos
	Producto *comienzo=NULL;//Apuntador para posible pila :0

	int accionmenu,accionmenu1,accionmenu2,depnum;//Variables para los switch
	int pronum=0;//Cuenta numero de productos en cada inventario
	int verif;
	char nomdepa[20],nomprodu[20];
	float nuprecio;
	printf("\t\tSistema de ventas\n\n");

	do{
		//system("clear");
		printf("\t\tSistema de ventas\n\n");
		printf("\t\t1. Revisar Inventarios\n\n");
		printf("\t\t2. Realizar Ventas\n\n");
		printf("\t\t3. Realizar Compras\n\n");
		printf("\t\t4. Reportes\n\n");
		printf("\t\t5. Salir\n\n");
		printf("Ingresar el numero de la accion de desea realizar.\n\n");
		accionmenu=ValidarOpcion(5);
			switch(accionmenu){
				case 1:
				
				do{
					
					printf("Es posible realizar las siguientes acciones:\n\n");
					printf("\t\t1. Revisar Productos.\n");
					printf("\t\t2. Crear nuevo Departamento.\n");
					printf("\t\t3. Eliminar un Departamento.\n");
					printf("\t\t4. Agregar un nuevo producto a un Departamento.\n");
					printf("\t\t5. Eliminar un producto.\n");
					printf("\t\t6. Regresar.\n");
					printf("Elige una accion (numero):\n");
					accionmenu1=ValidarOpcion(6);
					switch(accionmenu1){
						case 1:
							//system("clear");
							cabeza=leerDepartamentos(cabeza);
							depnum=imprimeDepartamento(cabeza);
							printf("Que Departamento quieres revisar\n\n");
							accionmenu1=ValidarOpcion(depnum);
							inicio=leerinventario(inicio,Obtener(cabeza,accionmenu1-1));
							imprimeInventario(inicio);
							inicio=BorrarList(inicio);
							cabeza=BorrarList(cabeza);
							break;

						case 2:
							//system("clear");
							cabeza=leerDepartamentos(cabeza);
							imprimeDepartamento(cabeza);
							printf("Ingresa el nombre del nuevo Departamento: \n\n");
							scanf("%s",nomdepa);
							verif=VerificarDepas(nomdepa);
							if(verif==1)
							{
								cabeza=insertarinicio(cabeza,0,0,nomdepa);
								AgregarDepartamento(cabeza);
								imprimeDepartamento(cabeza);
							}
							
							cabeza=BorrarList(cabeza);
							break;

						case 3:
							//system("clear");
							cabeza=leerDepartamentos(cabeza);
							depnum=imprimeDepartamento(cabeza);
							printf("Indique el numero del departamento que quieres borrar.\n\n");
							accionmenu1=ValidarOpcion(depnum);
							cabeza=RemoverDepartamento(cabeza,accionmenu1-1,Obtener(cabeza,accionmenu1-1));//Hay que restarle 1 por que empieza de 0
							printf("El Departamento %s ha sido eliminado.\n\n",Obtener(cabeza,accionmenu1-1));
							AgregarDepartamento(cabeza);
							imprimeDepartamento(cabeza);
							cabeza=BorrarList(cabeza);
							break;

						case 4:
							//system("clear");
							cabeza=leerDepartamentos(cabeza);
							depnum=imprimeDepartamento(cabeza);
							printf("A que Departamento quieres Agregar el nuevo Producto.\n\n");
							accionmenu1=ValidarOpcion(depnum);
							inicio=leerinventario(inicio,Obtener(cabeza,accionmenu1-1));
							printf("Escribe el nombre del nuevo producto.\n\n");
							scanf("%s",nomprodu);
							verif=VerificarProduct(inicio,nomprodu);
							if(verif==0)
							{
							printf("Escribe el precio del nuevo producto.\n\n");
							scanf("%f",&nuprecio);
							inicio=insertarinicio(inicio,0,nuprecio,nomprodu);
							AgregarProductos(inicio,Obtener(cabeza,accionmenu1-1));
							imprimeInventario(inicio);
							}
							else
							{
								printf("No se ha creado el nuevo Producto\n\n");
							}
							inicio=BorrarList(inicio);
							cabeza=BorrarList(cabeza);

							break;
						case 5:
							//system("clear");
							cabeza=leerDepartamentos(cabeza);
							depnum=imprimeDepartamento(cabeza);
							printf("De cual Departamento quieres eliminar un Producto.\n\n");
							accionmenu1=ValidarOpcion(depnum);
							inicio=leerinventario(inicio,Obtener(cabeza,accionmenu1-1));
							pronum=imprimeInventario(inicio);
							printf("Escribe el indice del producto que quieres eliminar.\n\n");
							verif=ValidarOpcion(pronum);	
							inicio=RemoverProducto(inicio,verif);
							AgregarProductos(inicio,Obtener(cabeza,accionmenu1-1));
							imprimeInventario(inicio);
							inicio=BorrarList(inicio);
							cabeza=BorrarList(cabeza);
							break;

						}

				}while(accionmenu1!=6);
					break;
				case 2:
					printf("No hay nada :c\n\n");

					break;
				
				case 3:
					printf("Aqui tampoco :(\n\n");
					break;
				case 4:
					printf("Aqui menos :C\n\n");
					break;
						
		}
	
	}while(accionmenu != 5);

	printf("Acciones Finalizadas.\n\n");
	
}






//Obtiene la informacion de los archivos
Producto* leerinventario(Producto *inicio,char *archnom){
	FILE * archivo;
	int valor;
	float precio;
	char nombre[20];
	archivo=fopen(archnom,"r");
	Producto *ProductoActual = inicio;
	if(archivo==NULL){
		printf("Archivo %s.txt no se pudo abrir\n",archnom);
		
	}
	else
	{

		while(!feof(archivo)){

			fscanf(archivo,"%s %f %d",nombre,&precio,&valor);
			
			if(!feof(archivo)){//Evita la repeticion del Ultimo renglon del archivo
				if(inicio==NULL){
						ProductoActual = malloc(sizeof(Producto));
						ProductoActual->cantidad = valor;
						ProductoActual->precio = precio;
						strcpy(ProductoActual->nombre,nombre);
						ProductoActual->Productosig = NULL;
						inicio = ProductoActual;
				}
				else{
						while(ProductoActual->Productosig != NULL){
							ProductoActual = ProductoActual->Productosig;
						}

						Producto *nuevoProducto = malloc(sizeof(Producto));
						nuevoProducto->cantidad = valor;
						nuevoProducto->precio = precio;
						strcpy(nuevoProducto->nombre,nombre);
						nuevoProducto->Productosig = NULL;
						ProductoActual->Productosig = nuevoProducto;
					}
			}
			}
	}
	fclose(archivo);
	return inicio;
}
int ValidarOpcion(int x)//Recibe el rango maximo de opciones de un menu
{
	char dato[20];
	int n=0,numero,i;
	do
	{
		numero=0;
		fflush(stdin);
		scanf("%s",dato);
		n=strlen(dato);
		for(i=0;i<n;i++)
		{
			if(!isdigit(dato[i]))
			{
				numero=numero+1;
			}
			
		}
		if(numero!=0 || atoi(dato)<1 || atoi(dato)>x)
		{
			printf("La opcion no es valida,vuelve a intentarlo\n\n");
		}
	}while(numero!=0 || atoi(dato)<1 || atoi(dato)>x);
	return (numero=atoi(dato));
}
//Lee El archivo de Departamentos disponibles
Producto* leerDepartamentos(Producto *inicio){
	FILE * archivo;
	char nombre[20];
	archivo=fopen("Departamentos","r");
	Producto *ProductoActual = inicio;
	if(archivo==NULL){
		printf("Archivo no se pudo abrir\n");
		
	}
	else
	{

		while(!feof(archivo)){

			fscanf(archivo,"%s",nombre);
			
			if(!feof(archivo)){//Evita la repeticion del Ultimo renglon del archivo
				if(inicio==NULL){
						ProductoActual = malloc(sizeof(Producto));
						strcpy(ProductoActual->nombre,nombre);
						ProductoActual->Productosig = NULL;
						inicio = ProductoActual;
				}
				else{
						while(ProductoActual->Productosig != NULL){
							ProductoActual = ProductoActual->Productosig;
						}

						Producto *nuevoProducto = malloc(sizeof(Producto));
						strcpy(nuevoProducto->nombre,nombre);
						nuevoProducto->Productosig = NULL;
						ProductoActual->Productosig = nuevoProducto;
					}
			}
			}
	}
	fclose(archivo);
	return inicio;
}

//Imprime Los productos en inventario
int imprimeInventario(Producto *inicio){
	Producto *ProductoActual = inicio;
	int i=0;
	if(ProductoActual==NULL)
	{
		printf("No hay nada en el inventario.\n");
	}
	else
	{
	printf("\tNombre de Producto");
		printf("\t\tPrecio");
		printf("\t\tEn existencia\n");
		printf("\t-------------------------------------------------------------\n\n");
	while(ProductoActual != NULL){
		i++;
		printf("%d)\t%s",i,ProductoActual->nombre);
		printf("\t\t%.2f",ProductoActual->precio);
		printf("\t\t\t%d\n",ProductoActual->cantidad);
		
		
		ProductoActual = ProductoActual->Productosig;
	}
	printf("\n\n");
	}
	return i;
}

//Imprime los Departamentos disponibles
int imprimeDepartamento(Producto *inicio){
	Producto *ProductoActual = inicio;
	int i=0;
	if(ProductoActual==NULL)
	{
		printf("No hay ningun departamento.\n");
	}
	printf("\n\tLos Departamentos disponibles son los siguientes:\n\n");
		
	while(ProductoActual != NULL){

		i++;
		printf("\t\t%d)%s\n\n",i,ProductoActual->nombre);
		ProductoActual = ProductoActual->Productosig;
	}
	return i;
}
//Adquiere valores
Producto* insertarinicio(Producto* inicio, int valor,float precio,char *nombre){
	
	Producto *ProductoActual = inicio;
	if(inicio==NULL){
		ProductoActual = malloc(sizeof(Producto));
		ProductoActual->cantidad = valor;
		ProductoActual->precio = precio;
		strcpy(ProductoActual->nombre,nombre);
		ProductoActual->Productosig = NULL;
		inicio = ProductoActual;
	}
	else{
		while(ProductoActual->Productosig != NULL){
			ProductoActual = ProductoActual->Productosig;
		}
		Producto *nuevoProducto = malloc(sizeof(Producto));
		nuevoProducto->cantidad = valor;
		nuevoProducto->precio = precio;
		strcpy(nuevoProducto->nombre,nombre);
		nuevoProducto->Productosig = NULL;
		ProductoActual->Productosig = nuevoProducto;
	}
	return inicio;
}

//Agrega Departamentos al achivo de departamentos existentes
void AgregarDepartamento(Producto *inicio)
{
	FILE *archivo;
	Producto *ProductoActual = inicio;
	archivo=fopen("Departamentos","w");
	if(archivo==NULL){
		printf("Ha ocurrido un error\n\n");
	}
	else
	{
		
		while(ProductoActual != NULL){

		fprintf(archivo,"%s\n",ProductoActual->nombre);
		ProductoActual = ProductoActual->Productosig;
	}
	}
	fclose(archivo);

}

//Agrega Productos al archivo de departamentos existentes
void AgregarProductos(Producto *inicio,char* nombre)
{
	FILE *archivo;
	Producto *ProductoActual = inicio;
	archivo=fopen(nombre,"w");
	if(archivo==NULL){
		printf("Ha ocurrido un error\n\n");
	}
	else
	{

		while(ProductoActual != NULL){

		fprintf(archivo,"%s %.2f %d\n",ProductoActual->nombre,ProductoActual->precio,ProductoActual->cantidad);
		ProductoActual = ProductoActual->Productosig;
	}
	}
	fclose(archivo);

}

//Verifica si ya existe un Departamento, envia 1 si no existe y envia 0 si ya existe
int VerificarDepas(char *departamento)
{
	FILE * archivo;
	int i;
	archivo=fopen(departamento,"r");
	if(archivo==NULL){
		printf("Se ha creado el Departamento de %s\n\n",departamento);
		archivo=fopen(departamento,"w");
		i=1;
	}
	else
	{
		printf("Ese Departamento ya existe\n\n");
		i=0;
	}
	fclose(archivo);
	return i;

}
//Verificar Productos,si manda 0 si no existe y manda 1 si si existe
int VerificarProduct(Producto *inicio,char* producto){
	Producto *ProductoActual = inicio;
	int i=0;
	
	while(ProductoActual != NULL){
		if(strcmp(ProductoActual->nombre,producto)==0)
		{
			printf("El producto ya existe.\n\n");
			i=i+1;
		}
		ProductoActual = ProductoActual->Productosig;
	}
	return i;
}
//Remueve Productos de algun Departamento
Producto* RemoverProducto(Producto *inicio, unsigned int indice){
	Producto *ProductoActual = inicio;
	if(inicio==NULL){
		return NULL;
	}
	else if(indice == 0){
		ProductoActual = inicio->Productosig;
		free(inicio);
		return ProductoActual;
	}
	else{
		Producto *anterior = inicio;
		int i = 0;
		while(i<indice && ProductoActual->Productosig != NULL){
			anterior = ProductoActual;
			ProductoActual = ProductoActual->Productosig;
			i++;
		}
		anterior->Productosig = ProductoActual->Productosig;
		free(ProductoActual);
		if(i==0){
			return NULL;
		}
	}
	return inicio;
}
//Remueve un departamento y su archivo respectivo
Producto* RemoverDepartamento(Producto *inicio, unsigned int indice,char *nombre){
	Producto *ProductoActual = inicio;
	remove(nombre);
	int i=0;
	if(inicio==NULL){
		return NULL;
	}
	else if(indice == 0){
		ProductoActual = inicio->Productosig;
		free(inicio);
		return ProductoActual;
	}

	else{
		Producto *anterior = inicio;
		int i = 0;
		while(i<indice && ProductoActual->Productosig != NULL){
			anterior = ProductoActual;
			ProductoActual = ProductoActual->Productosig;
			i++;
		}
		anterior->Productosig = ProductoActual->Productosig;
		free(ProductoActual);
		if(i==0){
			return NULL;
		}
	}
	return inicio;
}
//Obtener departamento para usar o borrar
char* Obtener(Producto *inicio, unsigned int indice){
	Producto *ProductoActual = inicio;
	int i = 0;
	if(inicio==NULL){
		return 0;
	}
	while(i<indice && ProductoActual->Productosig != NULL){
		ProductoActual = ProductoActual->Productosig;
		i++;
	}
	return ProductoActual->nombre;
}

//Venta de Producto
float Venta(Producto *inicio,int n, unsigned int indice){
	Producto *ProductoActual = inicio;
	int i = 0;//n es la cantidad que el cliente quiere comprar
	char eleccion;//Elige si acepta comprar la cantidad disponible
	float ganancia=0;//La ganancia que se obtendra de la venta

	if(inicio==NULL){
		return 0;
	}
	while(i<indice && ProductoActual->Productosig != NULL){
		ProductoActual = ProductoActual->Productosig;
		i++;
	}
	if((ProductoActual->cantidad)-n<0)
	{
		printf("No hay suficientes productos en inventario.\n\n");
	
		while((ProductoActual->cantidad)-n<0)
		{
			n=n-1;
		}
			printf("Solo es posible comprar %d %s, ¿Deseas adquirir tal cantidad? [S/N]",n,ProductoActual->nombre);
			scanf("%c",&eleccion);
			if(eleccion=='S' || eleccion=='s')
			{
				ganancia=n*(ProductoActual->precio);
				ProductoActual->cantidad=(ProductoActual->cantidad)-n;
			}
			else
			{
				printf("No se ha realizado la compra.");
				ganancia=0;
			}
	}
	else{
		ganancia=n*(ProductoActual->precio);
		ProductoActual->cantidad=(ProductoActual->cantidad)-n;

	}	

	return ganancia;
}

//Compra de Producto
float Compra(Producto *inicio,int n, unsigned int indice){
	Producto *ProductoActual = inicio;
	int i = 0;//n es la cantidad que el cliente quiere comprar
	char eleccion;//Elige si acepta comprar la cantidad disponible
	float perdida=0;//La perdida en dinero que se obtendra de la compra

	if(inicio==NULL){
		return 0;
	}
	while(i<indice && ProductoActual->Productosig != NULL){
		ProductoActual = ProductoActual->Productosig;
		i++;
	}

	printf("Usted ha dicho que quiere %d %s, ¿Es correcta tal cantidad? [S/N]",n,ProductoActual->nombre);
	scanf("%c",&eleccion);
			if(eleccion=='S' || eleccion=='s')
			{
				perdida=n*(ProductoActual->precio);
				ProductoActual->cantidad=(ProductoActual->cantidad)+n;
			}
			else
			{
				printf("No se ha realizado la compra de mercancia.");
				perdida=0;
			}
			return perdida;
}

//Libera memoria de toda la lista

Producto* BorrarList(Producto *inicio){
	if(inicio==NULL){
		return NULL;
	}
	Producto *ProductoActual = inicio;
	Producto *nodoSig = inicio->Productosig;
	while(nodoSig != NULL){
		free(ProductoActual);
		ProductoActual = nodoSig;
		nodoSig = ProductoActual->Productosig;
	}
	free(ProductoActual);
	return NULL;
}
