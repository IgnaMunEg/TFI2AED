#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

FILE*Turnos;
FILE*mascotas;
FILE*veterinario;
FILE*usuario;
FILE*bono;

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
	int Matricula,Dni,Atenciones;	
}vet;

struct Usuario{
	char usuario[10],contr[10],nombreYape[60];
}user;

struct Bono{
	int maxAten,MatriculaBono,DniBono;
	char NombreBono[60],TelefonoBono[25];
	
}bon;

int z=0,j=0,i=0,opp=0,op1=0,op2=0,op3=0,band=0,validar=0,encontrado=0,val=0;
char op,oppp;




bool ValidarVeterinario(char cad[]);
void RegistrarVeterinarios(FILE*veterinario,FILE*bono);
void RegistrarUsuario(FILE*usuario);
void VeterinarioBono(FILE*bono);




main(){
	system("color 5");
	system("cls");
	printf("   Menu administracion"); 
 	printf("\n 1 - Registrar Veterinario ");               
	printf("\n 2 - Registrar Usuario Asistente ");              
	printf("\n 3 - Veterinario merecedor del bono ");
 	printf("\n 4 - Cerrar la aplicacion");
 	printf("\n\n Ingrese una opcion: ");scanf("%d",&op1);
 	
 			switch(op1){
						case 1:{
							RegistrarVeterinarios(veterinario,bono);
						break;}	
						case 2:{
							RegistrarUsuario(usuario);
						break;}	
						case 3:{
							VeterinarioBono(bono);
						break;}	
						case 4:{
							printf("\n Finalizado");
							getch();
						break;}		
					}
	return 0;
}

bool ValidarVeterinario(char cad[]){

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

void RegistrarVeterinarios(FILE*veterinario,FILE*bono){
	char cadena[60];
	int listo=0;
	veterinario=fopen("Veterinarios.dat","a+b");
	bono=fopen("Bono.dat","a+b");
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
		printf("\n Digite las atenciones del veterinario: ");scanf("%d",&vet.Atenciones);
			if(vet.Atenciones>bon.maxAten){
				bon.maxAten=vet.Atenciones;
				strcpy(bon.NombreBono,vet.NombreApe);
				strcpy(bon.TelefonoBono,vet.Telefono);
				bon.MatriculaBono=vet.Matricula;
				bon.DniBono=vet.Dni;		
			}
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

void VeterinarioBono(FILE*bono){
	
	bono=fopen("Bono.dat","a+b");
	printf("\n El veterinario merecedor del bono con un total de %d atenciones es: ",bon.maxAten);
	printf("\n -");puts(bon.NombreBono);
	printf("\n DNI: %d",bon.DniBono);
	printf("\n Matricula: %d",bon.MatriculaBono);
	printf("\n Telefono: ");gets(bon.TelefonoBono);	
	
}

