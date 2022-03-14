enum TipoV {COCHE, MOTO, CAMIONETA};
/*Ahora el parking no tiene capacidad maxima. 
 * Almacena en una lista enlazada solo las plazas ocupadas
*/
typedef struct Plaza *TParking; 

typedef struct Plaza{
    enum TipoV tipo;
    char matricula[10];
    int plaza; //alamacena la plaza
    TParking sig;
} TPlaza; //NOTA: TPlaza * es equivalente a TParking

/* Devuelve un parking vacio */
TParking inicializar();

/* Lee de teclado el tipo y la matricula de un vehículo. 
   Si el usuario no introduce un tipo invalido u una matricula invalida
   devuelve 0. Si todos los datos validos devuelve 1
*/
int leerVehiculo (enum TipoV *t, char *m);

/* Muestra por pantalla los datos de un vehículo */
void mostrarPlaza(const TPlaza *pl); //NOTA: TPlaza * es equivalente a TParking

/* Muestra por pantalla todas las plazas ocupadas del parking y los datos del vehiculo */
void mostrarParking(TParking pk);

/* El vehiculo de tipo t y matricula m quiere aparcar en la plaza pl.
   Si esa plaza está libre devuleve 1, en otro caso devuelve 0 y no modifica el parking.
   (Opcional: La lista de plazas ocupadas se mantiene ordenada).
*/
int entrar(TParking *pk, enum TipoV t, char *m, int pl);

/* Libera todas las plazas ocupadas del parkin.*/
void salirTodos(TParking *pk);

