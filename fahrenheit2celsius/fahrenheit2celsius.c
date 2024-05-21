#include <stdio.h>
#include <stdlib.h>

int Fahrenheit (int fah, int cel);

int Celsius (int cel, int fah);


int main ()
{   
    char r;         /*Variable para reiniciar el programa.*/
    int options;
    int fahrenheit;
    int celsius;

    do
    {
        printf ("\nPor favor, ingrese:\n");                             /*Pregunta al usuario qué operación desea realizar.*/
        printf ("\n1 - si desea convertir de Fahrenheit a Celsius\n");
        printf ("\n2 - si desea convertir de Celsius a Fahrenheit\n");    
        printf ("\n");
        scanf ("%d", &options);

        if (options == 1)             /*Si el usuario tipea 1, realiza la conversión de F a C, guarda el resultado en la variable Celsius y la imprime en pantalla.*/ 
        {
            Fahrenheit (fahrenheit, celsius);
        }

        else if (options == 2)      /*Si el usuario tipea 2, realiza la conversión de C a F, guarda el resultado en la variable Fahrenheit y la imprime en pantalla.*/ 
        {
            Celsius (celsius, fahrenheit);   
        }

        else                 /*Si el usuario tipea cualquier otro valor que no sea 1 ni 2, recibirá un mensaje de error.*/
        {
            printf ("\nPor favor, ingrese una opción correcta."); 
        }
        
        printf ("\nDesea reintentar? y/n: ");       /*Se le dá al usuario la opción de reintentar o cerrar el programa.*/
        scanf (" %c", &r);

        printf ("==================================================");
    }
    while (r == 'y');
    
    return 0;
}

int Fahrenheit (int fah, int cel)
{
    printf ("\nIngrese los grados Fahrenheit que desee convertir a Celsius: ");
    scanf ("%d", &fah);

    cel = (fah -32) * 5/9;        

    printf ("\n%d° Fahrenheit equivalen a %d° Celsius.\n", fah, cel);
}

int Celsius (int cel, int fah)
{
    printf ("\nIngrese los grados Celsius que desee convertir a Fahrenheit: ");
    scanf ("%d", &cel);

    fah = (cel * 9/5) + 32;       

    printf ("\n%d° Celsius equivalen a %d° Fahrenheit.\n", cel, fah);
}



