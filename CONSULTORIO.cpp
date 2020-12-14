#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

FILE*Turnos;
FILE*mascotas;
FILE*veterinario;
FILE*usuario;

struct FechaNacimiento{
	int dd,mm,aa;	
}f;

struct Mascota{
	char ApellidoNombre[60],Domicilio[60],Localidad[60],Telefono[25];
	int Dni;
	struct FechaNacimiento f;
	float Peso;
}mascot;

struct Fecha{
	int dd,mm,aa;
}fech;

struct Turnoss{
	int matricula,dni;
	struct Fecha fech;
	char detalle[380];
}tur;

struct Veterinario{
	char Contras[35],NombreApe[60],Telefono[25]; 
	int Matricula,Dni;	
}vet;

struct Usuario{
	char usuario[10],contr[10],nombreYape[60];
}user;


int z=0,j=0,i=0,opp=0,op1=0,op2=0,op3=0,band=0,validar=0,encontrado=0,val=0;
char op,oppp;

void RegistrarEvolucionMascota(FILE*Turnos);
void VisualizarTurnos(FILE*Turnos);




int main(){//CONSULTORIO
	char password[20],matricula[20];
	

	system("color 5");
	system("cls");
	printf("   Menu consultorio"); 
 	printf("\n 1 - Iniciar Sesion  ");               
	printf("\n 2 - Visualizar Lista de Espera de Turnos (informe)");              
	printf("\n 3 - Registrar Evolución de la Mascota   ");
 	printf("\n 4 - Cerrar la aplicacion");
 	printf("\n\n Ingrese una opcion: ");scanf("%d",&op3);
 	
 	switch(op3){
				case 1:{
					if(validar==0){
						system("cls");
							char pass[20];
							int mat=0,salir=0;
							do{
								system("cls");
								printf("\n Digite la matricula: ");scanf("%d",&mat);
								_flushall();
								printf("\n Digite su contrase%ca: ",164);gets(pass);
								validar=0;
								rewind(veterinario);
								veterinario=fopen("Veterinarios.dat","r+b");
								fread(&vet,sizeof(Veterinario),1,veterinario);
								while(!feof(veterinario)){
									if(vet.Matricula==mat){
										if(strcmp(vet.Contras,pass)==0){
											system("cls");
											printf("\n Sesion iniciada correctamente\n\n");
											system("pause");
											validar=1;
										}
									}
									fread(&vet,sizeof(Veterinario),1,veterinario);	
								}
								fclose(veterinario);
								if(validar==0){
									system("cls");
									printf("\n Error datos erroneos... Pruebe de nuevo");
									getch();
									system("cls");
									_flushall();
									printf("\n Decea volver a intentar(s/n)(S/N): ");scanf("%c",&oppp);
									if(oppp=='s'||oppp=='S'){
										salir=0;
									}else if(oppp=='n'||oppp=='N'){
										salir=1;			
									}	
							}else if(validar==1){
									salir=1;
								}
							}while(salir==0);
						}else{
								system("cls");
								printf("\n Error ya tiene una sesion iniciada");
								getch();
							}									
						break;}
						case 2:{
							if(validar==1){
								VisualizarTurnos(Turnos);
							}else{
								system("cls");
								printf("\n Error aun no se a iniciado sesion");
								getch();
							}
						break;}
						case 3:{
							if(validar==1){
								RegistrarEvolucionMascota(Turnos);
							}else{
								system("cls");
								printf("\n Error aun no se a iniciado sesion");
								getch();
							}
						break;}
						case 4:{
							if(validar==1){			
								system("cls");
								printf("\n Finalizado\n\n");
								system("pause");
								validar=0;
							}else{
								system("cls");
								printf("\n Error usted no a iniciado sesion aun\n\n");
								system("pause");
							}	
						break;}
					}
}

void VisualizarTurnos(FILE*Turnos){
	int encontrado=0,j=0;
	char busN[100];
	_flushall();
	printf("\n Digite el nombre y apellido que decea buscar: ");gets(busN);
	rewind(Turnos);
	rewind(mascotas);
	Turnos=fopen("Turnos.dat","r+b");
	mascotas=fopen("Mascotas.dat","r+b");
	fread(&tur,sizeof(Turnoss),1,Turnos);
	fread(&mascot,sizeof(Mascota),1,mascotas);
	while(!feof(Turnos)){
		while(!feof(mascotas)){
			if(strcmp(busN,mascot.ApellidoNombre)==0){
				printf("\n Turno %d",j+1);
				printf("\n Matricula: %d",tur.matricula);
				printf("\n Fecha actual: %d/%d/%d",tur.fech.dd,tur.fech.mm,tur.fech.aa);
				printf("\n Dni: %d",tur.dni);
				j++;
				encontrado=1;
			}
			fread(&mascot,sizeof(Mascota),1,mascotas);
		}
		fread(&tur,sizeof(Turnoss),1,Turnos);	
	}
	fclose(Turnos);	
	fclose(mascotas);
	if(encontrado==0){
		system("cls");
		printf("\n Turno no registrado");
		getch();
	}
	getch();
}

void RegistrarEvolucionMascota(FILE*Turnos){
	int encontrado=0,j=0;
	char busN[100],detalle[100];
	_flushall();
	printf("\n Digite el nombre y apellido que decea buscar: ");gets(busN);
	rewind(Turnos);
	Turnos=fopen("Turnos.dat","r+b");
	fread(&tur,sizeof(Turnoss),1,Turnos);
	fread(&mascot,sizeof(Mascota),1,mascotas);
	while(!feof(Turnos)){
		if(strcmp(busN,mascot.ApellidoNombre)==0){
			_flushall();
			printf("\n Digite los datos de la evolucion: ");gets(detalle);
			strcpy(tur.detalle,detalle);
			encontrado=1;
		}
		fread(&tur,sizeof(Turnoss),1,Turnos);	
	}
	fclose(Turnos);	
	if(encontrado==0){
		system("cls");
		printf("\n Turno no registrado");
		getch();
	}
	getch();
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
