#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

FILE*Turnos;
FILE*mascotas;

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

int z=0,j=0,i=0,opp=0,op1=0,op2=0,op3=0,band=0,validar=0,encontrado=0;
char op;

void RegistrarEvolucionMascota(FILE*Turnos);
void VisualizarTurnos(FILE*Turnos);
void VerListaMascotas(FILE*mascotas);
void RegistrarTurnos(FILE*Turnos);  
void RegistrarMascotas(FILE*mascotas);

void MenuGeneral();
void MenuConsultorio();
void MenuAsistente();
void MenuAdministracion();

int main(){
	char password[20],matricula[20];
	do{
		MenuGeneral();
		switch(opp){
			case 1:{
				do{
					MenuConsultorio();
					switch(op3){
						case 1:{
							system("cls");
							_flushall();
							printf("\n Digite su numero de matricula: ");gets(matricula);
							_flushall();
							printf("\n Digite su password: ");gets(password);
							validar=0;
							if(strcmp(matricula,"123")==0){
								if(strcmp(password,"Agus")==0){
									validar=1;
								}
							}
							if(validar==1){
								system("cls");
								printf("\n Sesion iniciada correctamente");
								getch();
							}else{
								system("cls");
								printf("\n Error en la autenticacion... Por favor intente nuevamente");
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
							printf("\n Finalizado");
							getch();
						break;}
					}
				}while(op3!=4);
			break;}
			case 2:{
				do{
					MenuAsistente();
					switch(op2){
						case 1:{
							
						break;}	
						case 2:{
							RegistrarMascotas(mascotas);
						break;}	
						case 3:{
							RegistrarTurnos(Turnos);
							VisualizarTurnos(Turnos);
						break;}	
						case 4:{
							
						break;}	
						case 5:{
							printf("\n Finalizado");
							getch();
						break;}	
					}
				}while(op2!=5);
			break;}
			case 3:{
				do{
					MenuAdministracion();
					switch(op1){
						case 1:{
							
						break;}	
						case 2:{
							
						break;}	
						case 3:{
							
						break;}	
						case 4:{
							
						break;}	
						case 5:{
							printf("\n Finalizado");
							getch();
						break;}	
					}
				}while(op1!=5);
			break;}
			case 4:{
				printf("\n Finalizado");
				getch();
			break;}
		}
	}while(opp!=4);
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
void RegistrarTurnos(FILE*Turnos){
	Turnos=fopen("Turnos.dat","a+b");
	do{
		system("cls");
		printf("\n Turno %d",i+1);
		printf("\n Digite la matricula del veterinario: ");scanf("%d",&tur.matricula);
		printf("\n Digite la fecha actual \n");
		printf(" -Dia: ");scanf("%d",&tur.fech.dd);
		printf(" -Mes: ");scanf("%d",&tur.fech.mm);
		printf(" -A%co: ",164);scanf("%d",&tur.fech.aa);
		printf("\n Digite el dni del due%co: ",164);scanf("%d",&tur.dni);
		fwrite(&tur,sizeof(Turnoss),1,Turnos);
		_flushall();
		printf("\n Decea registrar mas turnos(s/n)(S/N): ");scanf("%c",&op);
		if(op=='s'||op=='S'){
			band=0;
			i++;
		}else if(op=='n'||op=='N'){
			band=1;
		}
	}while(band==0);
	fclose(Turnos);
}
void RegistrarMascotas(FILE*mascotas){
	mascotas=fopen("Mascotas.dat","a+b");
	do{
		system("cls");
		printf("\n Mascota %d",z+1);
		_flushall();
		printf("\n Digite el apellido y nombre: ");gets(mascot.ApellidoNombre);
		_flushall();
		printf("\n Digite el domicilio: ");gets(mascot.Domicilio);
		_flushall();
		printf("\n Digite la localidad: ");gets(mascot.Localidad);
		_flushall();
		printf("\n Digite el telefono: ");gets(mascot.Telefono);
		printf("\n Digite el dni: ");scanf("%d",&mascot.Dni);
		printf("\n Digite la fecha de nacimiento \n");
		printf(" -Dia: ");scanf("%d",&mascot.f.dd);
		printf(" -Mes: ");scanf("%d",&mascot.f.mm);
		printf(" -A%co: ",164);scanf("%d",&mascot.f.aa);
		printf("\n Digite el peso: ");scanf("%f",&mascot.Peso);	
		fwrite(&mascot,sizeof(Mascota),1,mascotas);
		_flushall();
		printf("\n Desea registrar mas mascotas(s/n)(S/N): ");scanf("%c",&op);
		if(op=='s'||op=='S'){
			band=0;
			z++;
		}else if(op=='n'||op=='N'){
			band=1;
		}
	}while(band==0);
	fclose(mascotas);
}
void VisualizarTurnos(FILE*Turnos){
	int encontrado=0,j=0;
	char busN[100];
	_flushall();
	printf("\n Digite el nombre y apellido que desea buscar: ");gets(busN);
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
void VerListaMascotas(FILE*mascotas){
	rewind(mascotas);
	mascotas=fopen("Mascotas.dat","r+b");
	fread(&mascot,sizeof(Mascota),1,mascotas);
	while(!feof(mascotas)){
		printf("\n\n Mascota %d",j+1);
		printf("\n Apellido y nombre: %s",mascot.ApellidoNombre);
		printf("\n Domicilio: %s",mascot.Domicilio);
		printf("\n Localidad: %s",mascot.Localidad);
		printf("\n Telefono: %s",mascot.Telefono);
		printf("\n Dni: %d",mascot.Dni);
		printf("\n Fecha de nacimiento %d/%d/%d",mascot.f.dd,mascot.f.mm,mascot.f.aa);
		printf("\n Peso: %.2f",mascot.Peso);	
		j++;
		fread(&mascot,sizeof(Mascota),1,mascotas);	
	}
	fclose(mascotas);
	getch();
}
void MenuConsultorio(){
	system("color 5");
	system("cls");
	printf("   Menu consultorio"); 
 	printf("\n 1 - Iniciar Sesion  ");               
	printf("\n 2 - Visualizar Lista de Espera de Turnos (informe)");              
	printf("\n 3 - Registrar Evolución de la Mascota   ");
 	printf("\n 4 - Cerrar la aplicacion");
 	printf("\n\n Ingrese una opcion: ");scanf("%d",&op3);
}
void MenuAsistente(){
	system("color 5");
	system("cls");
	printf("   Menu asistente"); 
 	printf("\n 1 - Iniciar Sesion  ");               
	printf("\n 2 - Registrar Mascota ");              
	printf("\n 3 - Registrar Turno  ");
	printf("\n 4 - Listado de Atenciones por Veterinario y Fecha ");
 	printf("\n 5 - Cerrar la aplicacion");
 	printf("\n\n Ingrese una opcion: ");scanf("%d",&op2);
}
void MenuAdministracion(){
	system("color 5");
	system("cls");
	printf("   Menu consultorio"); 
 	printf("\n 1 - Registrar Veterinario ");               
	printf("\n 2 - Registrar Usuario Asistente ");              
	printf("\n 3 - Atenciones por Veterinarios ");
	printf("\n 4 - Ranking de Veterinarios por Atenciones");
 	printf("\n 5 - Cerrar la aplicacion");
 	printf("\n\n Ingrese una opcion: ");scanf("%d",&op1);
}
void MenuGeneral(){
	system("color 5");
	system("cls");
	printf("   Menu principal"); 
 	printf("\n 1 - Modulo consultorio");               
	printf("\n 2 - Modulo asistente");              
	printf("\n 3 - Modulo administracion");
 	printf("\n 4 - Cerrar la aplicacion");
 	printf("\n\n Ingrese una opcion: ");scanf("%d",&opp);
}
