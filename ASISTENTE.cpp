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


void RegistrarTurnos(FILE*Turnos);  
void RegistrarMascotas(FILE*mascotas);

main(){
	system("color 5");
	system("cls");
	printf("   Menu asistente"); 
 	printf("\n 1 - Iniciar Sesion  ");               
	printf("\n 2 - Registrar Mascota ");              
	printf("\n 3 - Registrar Turno  ");
	printf("\n 4 - Listado de Atenciones por Veterinario y Fecha ");
 	printf("\n 5 - Cerrar la aplicacion");
 	printf("\n\n Ingrese una opcion: ");scanf("%d",&op2);
 	
 		switch(op2){
						case 1:{
							if(val==0){
								system("cls");
								char pass[20],us[20],nom[60];
								int sal=0;
								do{
									system("cls");
									_flushall();
									printf("\n Digite el usuario: ");gets(us);
									_flushall();
									printf("\n Digite su contrase%ca: ",164);gets(pass);
									_flushall();
									printf("\n Digite el nombre y apellido: ");gets(nom);
									val=0;
									rewind(usuario);
									usuario=fopen("Usuarios.dat","r+b");
									fread(&user,sizeof(Usuario),1,usuario);
									while(!feof(usuario)){
										if(strcmp(user.contr,pass)==0){
											if(strcmp(user.usuario,us)==0){
												if(strcmp(user.nombreYape,nom)==0){
													system("cls");
													printf("\n Sesion iniciada correctamente\n\n");
													system("pause");
													val=1;
												}
											}
										}
										fread(&user,sizeof(Usuario),1,usuario);
									}
									fclose(usuario);
									if(val==0){
										system("cls");
										printf("\n Error datos erroneos... Pruebe de nuevo");
										getch();
										system("cls");
										_flushall();
										printf("\n Decea volver a intentar(s/n)(S/N): ");scanf("%c",&oppp);
										if(oppp=='s'||oppp=='S'){
											sal=0;
										}else if(oppp=='n'||oppp=='N'){
											sal=1;			
										}	
									}else if(val==1){
										sal=1;
									}
								}while(sal==0);
							}else{
								system("cls");
								printf("\n Error ya tiene una sesion iniciada");
								getch();
							}
						break;}	
						case 2:{
							if(val==1){
								RegistrarMascotas(mascotas);
							}else{
								system("cls");
								printf("\n Error aun no se a iniciado sesion");
								getch();
							}
						break;}	
						case 3:{
							if(val==1){
								RegistrarTurnos(Turnos);
							}else{
								system("cls");
								printf("\n Error aun no se a iniciado sesion");
								getch();
							}
						break;}	
						case 4:{
							
						break;}	
						case 5:{
							if(val==1){			
								system("cls");
								printf("\n Finalizado\n\n");
								system("pause");
								val=0;
							}else{
								system("cls");
								printf("\n Error usted no a iniciado sesion aun\n\n");
								system("pause");
							}	
						break;}	
					}	
	
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
		printf("\n Decea registrar mas mascotas(s/n)(S/N): ");scanf("%c",&op);
		if(op=='s'||op=='S'){
			band=0;
			z++;
		}else if(op=='n'||op=='N'){
			band=1;
		}
	}while(band==0);
	fclose(mascotas);
}
