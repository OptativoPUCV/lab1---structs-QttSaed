#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Ejercicio 1: Encuentra el Elemento Mayor
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y devuelva el valor más grande del arreglo.
*/
int findMax(int arreglo[], int talla) { 
  int max = arreglo[0];
  for (int i = 0; i < talla; i++)
    if(arreglo[i] > max)
      max = arreglo[i];
  return max;
}


/*
Ejercicio 2: Invertir un Arreglo
Descripción: Escribe una función que tome un arreglo y su tamaño, y luego
invierta el orden de sus elementos.
*/
void reverseArray(int arreglo[], int talla) {
  int temporal;
  for(int i = 0; i < talla / 2; i++) {
    temporal = arreglo[i];
    arreglo[i] = arreglo[talla - i - 1 ];
    arreglo[talla - i - 1] = temporal;
  }
}

/*
Ejercicio 3: Filtrar Números Pares
Descripción: Escribe una función que tome un arreglo de enteros
y su tamaño, y luego devuelva un nuevo arreglo que contenga solo
los números pares del arreglo original.
*/

int *filterEvenNumbers(int arreglo[], int talla, int *newSize) { 
  int *newArr = malloc(sizeof(int) * talla);
  int j = 0;
  for (int i = 0; i < talla; i++)
    if(arreglo[i] % 2 == 0){
      newArr[j] = arreglo[i];
      j++;

    }
  *newSize = j;
  return newArr;}

/*
Ejercicio 4: Fusión de dos Arreglos Ordenados
Descripción: Escribe una función que tome dos arreglos
ordenados y sus tamaños, y luego fusione estos dos
arreglos en un tercer arreglo también ordenado.
*/
void mergeSortedArrays(int arreglo1[], int talla1, int arreglo2[], int talla2,
                       int resultado[]) {
  int i = 0, j = 0, k = 0;
  while (i < talla1 && j < talla2){
    if (arreglo1[i] < arreglo2[j])
      resultado[k++] = arreglo1[i++];
    else
      resultado[k++] = arreglo2[j++];
    
  }
  while (i < talla1)
    resultado[k++] = arreglo1[i++];
  while (j < talla1)
    resultado[k++] = arreglo2[j++];
  
}

/*
Ejercicio 5: Comprobación de Ordenación
Descripción: Escribe una función que tome un arreglo y su tamaño,
y luego devuelva 1 si el arreglo está ordenado en orden ascendente,
  0 si no está ordenado, y -1 si está ordenado en orden descendente.
*/

int checkSorted(int arr[], int size) {
  if (size <= 1) return 1;
  int direction = arr[1] - arr[0];
  for (int i = 2; i < size; i++) {
    if (direction > 0 && arr[i] - arr[i - 1] < 0) return 0;
    if (direction < 0 && arr[i] - arr[i - 1] > 0) return 0;
    if (direction == 0) direction = arr[i] - arr[i - 1];
  }
  if (direction > 0) return 1;
  if (direction < 0) return -1;
  return 1;
}


/*
Ejercicio 6: Información de una Biblioteca
Descripción: Vamos a representar la información de una biblioteca. En la
biblioteca, hay libros, y cada libro tiene un autor. Queremos organizar esta
información utilizando estructuras anidadas en C. Escribe la función para
inicializar la información de un libro.
*/

typedef struct {
  char nombre[50];
  int anioNacimiento;
} Autor;

typedef struct {
  char titulo[100];
  Autor autor;
  int anioPublicacion;
} Libro;


void inicializarLibro(Libro *libro, const char *titulo, const char *nombreAutor, int anioNacimiento, int anioPublicacion) {
  strncpy(libro->titulo, titulo, sizeof(libro->titulo) - 1);
  libro->titulo[sizeof(libro->titulo) - 1] = '\0';
  strncpy(libro->autor.nombre, nombreAutor, sizeof(libro->autor.nombre) - 1);
  libro->autor.nombre[sizeof(libro->autor.nombre) - 1] = '\0';
  libro->autor.anioNacimiento = anioNacimiento;
  libro->anioPublicacion = anioPublicacion;
}



/*
Ejercicio 7: Lista enlazada de números
Descripción: Escribe una función que tome un arreglo de enteros y su tamaño, y
luego cree una lista enlazada usando la estructura Nodo. Cada nodo de la lista
debe contener un número del arreglo, y los nodos deben estar enlazados en el
mismo orden que los números aparecen en el arreglo. El último nodo de la lista
debe apuntar a NULL. La función debe devolver un puntero al primer nodo de la
lista enlazada.
Recuerda reservar memoria dinámica para cada nodo usando malloc.
  */

typedef struct nodo {
  int numero;
  struct nodo *siguiente; // puntero al siguiente nodo
} Nodo;


Nodo *crearListaEnlazada(int arr[], int size) {
  if (size <= 0) return NULL;

  Nodo *head = (Nodo *)malloc(sizeof(Nodo));
  head->numero = arr[0];
  head->siguiente = NULL;

  Nodo *current = head;
  for (int i = 1; i < size; i++) {
    Nodo *newNode = (Nodo *)malloc(sizeof(Nodo));
    newNode->numero = arr[i];
    newNode->siguiente = NULL;
    current->siguiente = newNode;
    current = newNode;
  }

  return head;
}

