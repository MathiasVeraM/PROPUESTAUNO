#include <stdio.h>  //se incluye la biblioteca stdio.h
#include <stdlib.h> //Se incluye la biblioteca stdlib.h para usar puts y gets, leer y escribir cadenas de caracteres.
#include <string.h>
#include <time.h> //Se incluye la biblioteca time.h para añadir la fecha y hora de ingreso de datos.

int main(){
    //inicializacion de la estructura Paciente
    struct Paciente{
        char nombre[30];
        int edad;
        int peso;
        float altura;
        float temperatura;
        int presionD;
        int presionS;
        int pulso;
        int respiracion;
        float masac;
    }a;

    FILE *archivo; //Definicion de la variable archivo como tipo FILE
    archivo = fopen("DatosPaciente.txt","a"); //abrir el archivo para que se ingresen datos en el archivo plano de manera continua, con w es solo una vez

    int opcion = 0, paciente = 0; //Esto es para el menu, para el ingreso de la opcion y numero de pacientes por parte del usuario
    float masa; //variable para almacenar la masa corporal del paciente
    time_t tiempoActual; //Variable de tipo time para tener la hora y fecha de ingreso de datos

    long posicion;
    char datoBuscar;
    char nombreBuscado[20];
    int edadBuscado;
    int pesoBuscado;
    float alturaBuscado;
    float temperaturaBuscado;
    int presionDBuscado;
    int presionSBuscado;
    int pulsoBuscado;
    int respiracionBuscado;
    float masacBuscado;

    do{ //Bucle do while para el menu
        printf("Menu: \n\n 1.Ingreso de Datos de Pacientes\n 2.Buscar Datos de Paciente\n 3.Borrar un dato en la Base de Datos\n 4.Salir\n");
        printf("\nSeleccione una opcion: ");
        scanf("%d",&opcion);
        switch (opcion){
        case 1: printf("Por favor ingrese el numero de pacientes que desea ingresar: "); scanf("%d",&paciente);
                for(int i=0;i<paciente;i++){
                        fflush(stdin);
                        time(&tiempoActual);
                        struct tm *miTiempo = localtime(&tiempoActual);

                        printf("\nIngrese el nombre: "); gets(a.nombre);
                        printf("\nIngrese la edad: "); scanf("%d", &a.edad);
                        printf("\nIngrese el peso(en kilogramos): "); scanf("%d", &a.peso);
                        printf("\nIngrese la altura(en metros): "); scanf("%f", &a.altura);
                        printf("\nIngrese la temperatura(en grados centigrados): "); scanf("%f", &a.temperatura);
                        printf("\nIngrese la presion sistolica: "); scanf("%d", &a.presionS);
                        printf("\nIngrese la presion diastolica: "); scanf("%d", &a.presionD);
                        printf("\nIngrese el pulso: "); scanf("%d", &a.pulso);
                        printf("\nIngrese la frecuencia respiratoria: "); scanf("%d", &a.respiracion);
                        printf("La masa corporal se calculara en base al peso y la altura ingresadas \n"); 
                        masa = (a.peso)/(a.altura*a.altura);
                        a.masac = masa;

                        if(i==0){ //Condicional if para que imprima el dia, mes y año solo una vez; Cada vez que el usuario ingrese nuevos datos en el archivo, se ingresará el día mes y año.
                                fprintf(archivo, "%d/%d/%d\n", miTiempo->tm_mday, miTiempo->tm_mon+1, miTiempo->tm_year+1900);
                        }

                        fprintf(archivo, "%d:%d:%d\t", miTiempo->tm_hour, miTiempo->tm_min, miTiempo->tm_sec); //Para que imprima la hora en la que se inscribieron los datos
                        //Funciones fprintf para escribir en el archivo los datos ingresados por el usuario
                        fprintf(archivo, "%s; %d; %d; %.2f; %.2f; %d; %d; %d; %d; %.3f", a.nombre, a.edad, a.peso, a.altura, a.temperatura, a.presionS, a.presionD, a.pulso, a.respiracion, a.masac);

                        fprintf(archivo,"\n"); //Para que despues de cada ingreso de datos haya un salto de linea

                        fflush(stdin); //Para borrar los datos del caché de ingreso por consola, scanf y gets, para poder ingresar los otros datos y que no falle
                }
                break;
        case 2: //Aquí va la opcion de busqueda de datos
                break;
        case 3: //Aqui va la opcion de borrar el dato encontrado en la base de datos
                break;
        case 4: printf("\nSalio exitosamente del programa\n");
                break;
        default: printf("\nLa opcion no se encuentra en el menu");
                break;
        }
    }while(opcion!=4);

    fclose(archivo); //cerrar el archivo

    return 0;
}