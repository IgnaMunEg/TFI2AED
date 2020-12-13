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
void VerListaMascotas(FILE*mascotas);
void RegistrarTurnos(FILE*Turnos);  
void RegistrarMascotas(FILE*mascotas);
bool ValidarVeterinario(char cad[]);
void RegistrarVeterinarios(FILE*veterinario);
void RegistrarUsuario(FILE*usuario);

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
				}while(op3!=4);
			break;}
			case 2:{
				do{
					MenuAsistente();
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
				}while(op2!=5);
			break;}
			case 3:{
				do{
					MenuAdministracion();
					switch(op1){
						case 1:{
							RegistrarVeterinarios(veterinario);
						break;}	
						case 2:{
							RegistrarUsuario(usuario);
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
bool ValidarVeterinario(char cad[]){
	//Aqui deben colocar las otras validaciones que se piden
	int ban=0;
	if(strlen(cad)>=6&&strlen(cad)<=32){
		ban=1;
	}
	if(ban==1){
		return true;	
	}else if(ban==0){
		return false;
	}
}
void RegistrarUsuario(FILE*usuario){
	int lista=0;
	usuario=fopen("Usuarios.dat","a+b");
	do{
		system("cls");
		_flushall();
		printf("\n Digite el usuario : ");gets(user.usuario);
		_flushall();
		printf("\n Digite la contrase%ca : ",164);gets(user.contr);
		_flushall();
		printf("\n Digite el nombre y apellido: ");gets(user.nombreYape);
		fwrite(&user,sizeof(Usuario),1,usuario);
		_flushall();
		printf("\n Decea registrar otro usuario(s/n)(S/N): ");scanf("%c",&opp);
		if(opp=='s'||opp=='S'){
			lista=0;
		}else if(opp=='n'||opp=='N'){
			lista=1;			
		}
	}while(lista==0);
	fclose(usuario);
}
void RegistrarVeterinarios(FILE*veterinario){
	char cadena[60];
	int listo=0;
	veterinario=fopen("Veterinarios.dat","a+b");
	do{
		system("cls");
		_flushall();
		printf("\n Digite el nombre y apellido: ");gets(vet.NombreApe);
		_flushall();
		printf("\n Digite el telefono : ");gets(vet.Telefono);
		_flushall();
		printf("\n Digite dni: ");scanf("%d",&vet.Dni);
		_flushall();
		printf("\n Digite la matricula: ");scanf("%d",&vet.Matricula);
		do{
			_flushall();
			printf("\n Digite la contrase%ca: ",164);gets(cadena);
			if(!ValidarVeterinario(cadena)){
				system("cls");
				printf("\n Error en el password solo debe contener 6 a 32 digitos");
			}
		}while(!ValidarVeterinario(cadena));
		if(ValidarVeterinario(cadena)){
			system("cls");
			printf("\n Veterinario registrado correctamente\n");
			system("pause");
			strcpy(vet.Contras,cadena);
		}
		fwrite(&vet,sizeof(Veterinario),1,veterinario);
		_flushall();
		printf("\n Decea registrar otro veterinario(s/n)(S/N): ");scanf("%c",&oppp);
		if(oppp=='s'||oppp=='S'){
			listo=0;
		}else if(oppp=='n'||oppp=='N'){
			listo=1;			
		}
	}while(listo==0);
	fclose(veterinario);
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
