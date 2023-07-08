#include <stdio.h>  //se incluye la biblioteca stdio.h
#include <stdlib.h>
#include <time.h>
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

    FILE *archivo;
    archivo = fopen("DatosPaciente.txt","a");

    int opcion = 0, paciente = 0;
    float masa;
    time_t tiempoActual;

    

    do{
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

                        if(i==0){ //Para que imprima el dia, mes y año solo una vez
                                fprintf(archivo, "%d/%d/%d\n", miTiempo->tm_mday, miTiempo->tm_mon+1, miTiempo->tm_year+1900);
                        }

                        fprintf(archivo, "%d:%d:%d\t", miTiempo->tm_hour, miTiempo->tm_min, miTiempo->tm_sec); //Para que imprima la hora en la que se inscribieron los datos
                        fprintf(archivo,"%s; ",a.nombre);
                        fprintf(archivo,"%d; ",a.edad);
                        fprintf(archivo,"%d; ",a.peso); 
                        fprintf(archivo,"%.2f; ",a.altura);
                        fprintf(archivo,"%.2f; ",a.temperatura);
                        fprintf(archivo,"%d; ",a.presionS);
                        fprintf(archivo,"%d; ",a.presionD);
                        fprintf(archivo,"%d; ",a.pulso);
                        fprintf(archivo,"%d; ",a.respiracion);
                        fprintf(archivo,"%.3f; ",a.masac);

                        fprintf(archivo,"\n");

                        fflush(stdin);
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

    puts(a.nombre);
    printf("%d\n",a.edad);
    printf("%d\n",a.peso);
    printf("%.2f\n",a.altura);
    printf("%.2f\n",a.temperatura);
    printf("%d\n",a.presionS);
    printf("%d\n",a.presionD);
    printf("%d\n",a.pulso);
    printf("%d\n",a.respiracion);
    printf("%.3f\n",a.masac);



    fclose(archivo);


    return 0;
}
