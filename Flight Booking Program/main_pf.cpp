#include <iostream> 
#include <string.h>
#include "Airport.h"
#include "Airline.h"
#include "Flight.h"
#include "Passenger.h"       
using namespace std;

int main(){  
  Airport aeropuerto1("AICM", "01/12/2021", "Ciudad de Mexico", "Mexico", 0, 0);

  Airline aeromexico("Aeromexico", "Ciudad de Mexico", "CDMX");
  Airline aerobus("Viva aerobus", "Ciudad de Mexico", "CDMX");
  Airline interjet("Interjet", "Ciudad de Mexico", "CDMX");

  // vuelos de aeromexico 
  Flight f1(1, "01/12/2021", "20:00", 2000, "Boeing 737", "Leon", 400, "737", 0);
  Flight f2(2, "01/12/2021", "10:00", 4000, "Boeing 737", "Monterrey", 900, "737", 0);
  Flight f3(3, "01/12/2021", "15:00", 3500, "Boeing 737", "Guadalajara", 530, "737", 0);

  // vuelos de viva aerobus 
  Flight f4(4, "01/12/2021", "22:00", 1200, "Boeing 737", "Tampico", 440, "737", 0);
  Flight f5(5, "01/12/2021", "13:00", 800, "Boeing 737", "Leon", 400, "737", 0);
  Flight f6(6, "01/12/2021", "7:00", 1000, "Boeing 737", "Torreon", 980, "737", 0);

  // vuelos de interjet 
  Flight f7(7, "01/12/2021", "10:00", 3000, "Boeing 737", "Monterrey", 900, "737", 0);
  Flight f8(8, "01/12/2021", "23:00", 2000, "Boeing 737", "Los cabos", 1800, "737", 0);
  Flight f9(9, "01/12/2021", "6:00", 1500, "Boeing 737", "Cancun", 1600, "737", 0);

  const int V = 3;
  Flight arrAeromexico[V];
  Flight arrAerobus[V];
  Flight arrInterjet[V];
  Flight vuelo; 

  arrAeromexico[0] = f1;
  arrAeromexico[1] = f2;
  arrAeromexico[2] = f3;
  arrAerobus[0] = f4;
  arrAerobus[1] = f5;
  arrAerobus[2] = f6;
  arrInterjet[0] = f7;
  arrInterjet[1] = f8;
  arrInterjet[2] = f9;

  int menu; 
  const int N = 1000; 
  Passenger arrClientes[N];

  cout << "---Bienvenido al sistema de aeropuerto---" << endl; 
  
  do{
  cout << "1. Agregar usuario.  " << endl 
      << "2. Acceder con usuario existente. " << endl
      << "3. Salir del sistema. " <<endl;

    cin >> menu;

    if (menu == 1){
      string name, r = "no"; 
      int phone;
      float kilometraje;
      int n = 0;  

      do{
      cout << "Cliente " << n+1 << endl; 
      cout << "Nombre del cliente: " << endl;
      cin >> name; 
      cout << "Numero de telefono: " << endl;
      cin >> phone; 
      cout << "Kilometraje: " << endl; 
      cin >> kilometraje; 
      if (kilometraje < 0){
        cout << "Cantidad invalida. " << endl << endl; 
        break;
      }

      arrClientes[n].setName(name);
      arrClientes[n].setPhone(phone);
      arrClientes[n].setKilometraje(kilometraje);

      cout << "¿Desea agregar otro cliente?" << endl; 
      cin >> r; 
      n++;

      } while (r != "no");

    }

    else if (menu == 2){
      int m, num, cl2, menu2;
      string band, cl, res;
    
      do{
        band = "F";
        cout << "Nombre del cliente, introduce (no) para salir. " << endl;
        cin >> cl;
        cout << "Numero del cliente. " << endl;
        cin >> cl2;
        m = 0;

        if (cl!="no"){
          while (band == "F" && (m < N)){
            if (arrClientes[m].getName() == cl && arrClientes[m].getPhone() == cl2){
              band = "V";
              cout << endl << "Has entrado al sistema con el usuario: " << arrClientes[m].getName() << endl; 
              //aqui debe acceder con los datos del usuario 

              do {
              cout << endl << "1. Seleccionar vuelo. " << endl
                  << "2. Imprimir mis datos. " << endl 
                  << "3. Reservar asiento. " << endl 
                  << "4. Cancelar reservacion. " << endl 
                  << "5. Regresar al menu. " << endl; 

                cin >> menu2;

                if (menu2 == 1){
                  int numVuelo, aerolinea;
                  bool invalido = false, found = false; 

                  cout << endl << "Los vuelos de Aeromexico para el dia de hoy son: " << endl; 
                  for (int i = 0; i < V; i++){
                    arrAeromexico[i].imprimirVuelos();
                  }

                  cout << endl << "Los vuelos de Viva Aerobus para el dia de hoy son: " << endl;
                  for (int j = 0; j < V; j++){
                    arrAerobus[j].imprimirVuelos();
                  }

                  cout << endl << "Los vuelos de Interjet para el dia de hoy son: " << endl; 
                  for (int k = 0; k < V; k++){
                    arrInterjet[k].imprimirVuelos();
                  }

                  cout << endl << "Seleccionar la aerolinea (1. Aeromexico, 2. Aerobus, 3. Interjet): " << endl; 
                  cin >> aerolinea; 
                  cout << "Seleccionar numero de vuelo a reservar: " << endl; 
                  cin >> numVuelo; 

                  switch (aerolinea){
                    case 1: 
                      for (int a = 0; a < V; a++){
                        if (arrAeromexico[a].getId() == numVuelo){
                          found = true; 
                          vuelo = arrAeromexico[a];
                        }
                      }
                      break;

                    case 2: 
                      for (int b = 0; b < V; b++){
                        if (arrAerobus[b].getId() == numVuelo){
                          found = true;
                          vuelo = arrAerobus[b]; 
                        }
                      }
                      break;

                    case 3: 
                      for (int c = 0; c < V; c++){
                        if (arrInterjet[c].getId() == numVuelo){
                          found = true; 
                          vuelo = arrInterjet[c];
                        }
                      }
                      break;

                    default: 
                      cout << "Aerolinea invalida. " << endl; 
                      invalido = true; 
                  }

                  if (invalido){
                    break;
                  } 

                  if (!found){
                    cout << "Vuelo invalido. " << endl;
                    break;
                  }
                  
                }
                else if (menu2 == 2){
                  cout << "Nombre: " << arrClientes[m].getName() << endl;
                  cout << "Numero de telefono: " << arrClientes[m].getPhone() << endl;
                  cout << "Kilometraje: " << arrClientes[m].getKilometraje() << endl << endl;
                  
                }
                else if (menu2 == 3){
                  int asiento = -1;

                  cout << "Vuelo #" << vuelo.getId() << " Con destino a: " << vuelo.getFromTo() << endl; 
                  vuelo.imprimirAsientos();
                  cout << endl << "Selecciona el asiento que desea reservar: " << endl; 
                  cin >> asiento; 
                  if (!vuelo.reservar(arrClientes[m], asiento)){
                    break;
                  }
                  

                }
                else if (menu2 == 4){
                  vuelo.cancelReserva(arrClientes[m]);

                }

              } while (menu2 != 5);

            }
          m++;
          }
          if (band != "V"){
            cout << "ERROR: El cliente no existe. " << endl;
          }
        }
      } while (band != "V" && cl != "no");

    }
  
  } while (menu != 3);

  cout << "Has salido del sistema. " << endl; 

  return 0;
}