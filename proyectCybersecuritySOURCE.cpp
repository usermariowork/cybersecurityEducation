//PROYECTO EDUCATIVO CIBERSEGURIDAD

#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

void read(); //funcion para realizar la lectura del diccionario Case 3 WEP



int main() {
	
	srand(time(0));
	//Variables para menu
	int op = 0;
	//Variables para case 2
	int passLong = 0;
	const int PASS = 64;
	char character[PASS];
	//Variables para case 3
	int opCase3 = 0;
	int opCase31 = 0;
	int aux = 0;
	//Variables case 4
	int opCase4 = 0;
	int contador = 0;

	cout << "Programa realizado por Mario Ochoa de 4to semestre de Ingenieria Cibernetica" << endl << endl;
	cout << "Este es un proyecto con fines educativos para que el estudiente aprenda sobre" << endl;
	cout << "cuestiones de seguridad informatica en general, ademas de redes inalambricas." << endl;
	cout << "WiFi. No me hago responsable por el mal uso que le puedan dar." << endl << endl;


	while (1) {
		system("pause");
		system("cls");

		cout << "MENU DE OPCIONES" << endl<<endl;
		cout << "Escoge una de las opciones y da ENTER" << endl;
		cout << "1. Generador de contrasenas seguras para redes WiFi" << endl;
		cout << "2. Hackear contrasena WiFi" << endl;
		cout << "3. Salir" << endl << endl;
		cin >> op;

		system("cls");

		switch (op) {
		case 1:
			
			cout << "Antes que nada, hay que especificar que la mayoria de las redes WiFi aceptan" << endl;
			cout << "contraseñas en un rango de 8 a 63 caracteres, pueden ser números, letras en" << endl;
			cout << "mayuscula y minuscula, carateres especiales como +*$#, etc. Una contraseña" << endl;
			cout << "segura debe de tener por lo menos uno de cada elemento mencionado anteriormente" << endl;
			cout << "para considerarse seguro." << endl << endl;
			system("cls");

			cout << "Esta harramienta esta hecha para crear contrasenas mas seguras de las que" << endl;
			cout << "una persona utilizaria normalmente." << endl << endl;
			cout << "Cual sera la longitud de tu contrasena (8-63)? ";
			cin >> passLong;

			if (passLong < 8 || passLong > 63) {
				cout << "VALOR INCORRECTO" << endl;
				return system("pause");
			}
			
			cout << endl;
			cout << "Contrasena generada: ";

			//srand(time(0));
			for (int x = 0; x < passLong; x++) { // ciclo para crear la contraseña a partir de numeros aleatorios gracias a la tabla ascii
				//seria de 33 a 126 porque 126-33 = 93
				character[x] = rand() % 93 + 33;
			}

			for (int x = 0; x < passLong; x++) { //ciclo para imprimir el arreglo
				cout << character[x];
			}

			for (int x = 0; x < passLong; x++) { //cilo para reiniciar los valores del arreglo
				character[x] = NULL;
			}

			cout << endl<< endl;
			
			break;
		case 2:
			cout << "Existen distintos tipos de protocolos de seguridad, por favor escoge el "<<endl;
			cout << "que quieras: "<<endl<<endl;
			cout << "1. WEP" << endl;
			cout << "2. WPA" << endl;
			cout << "3. WPS" << endl<<endl;
			cin >> opCase3;

			system("cls");

			//SWITCH CASE 3 
			switch (opCase3) {
				case 1: //REDES WEP

					cout << "Wired Equivalent Privacy(WEP) es un protocolo de seguridad que se convirtio en" << endl;
					cout << "un modelo estandar en 1999 con un limite de 64 bits de encriptacion, aunque hoy" << endl;
					cout << "en dia el estandar es de 128 bits, en el cual se pueden utilizar contrasenas con" << endl;
					cout << "caracteres alfanuméricos, es decir, del 0 al 9 y de la A a la Z en mayuscula y" << endl;
					cout << "minuscula.Normalmente viene como predeterminada una contrasena de 8 caracteres" << endl;
					cout << "alfanumericos, solo que utiliza unicamente numeros del 0 al 9 y letras minusculas." << endl;
					system("pause");
					system("cls");

					cout << "Es por todo lo anterior que son contraseñas muy faciles de descifrar, para esto" << endl;
					cout << "se utiliza un metodo muy eficiente, a partir de investigadores de redes que" << endl;
					cout << "aportan las contraseñas mas comunes que hay en cierto tipo de routers se crean " << endl;
					cout << "diccionarios, que son archivos de texto plano con una gran cantidad de palabras" << endl;
					cout << "que son combinaciones de letras y nunmeros, estas son las contraseñas mas comunes." << endl;
					cout << "Este método es muy parecido al de redes WPA con la diferencia de que utilizaremos" << endl;
					cout << "un diccionario en lugar de realizar el metodo de bruteforce(si quieres conocerlo" << endl;
					cout << "busca en el apartado de WPA)." << endl;

					system("pause");
					system("cls");

					cout << "Esto es lo que se hara en seguida: se va a capturar el handshake de la red a" << endl;
					cout << "hackear.El handshake es la contraseña del router encriptada, que esta enviandose" << endl;
					cout << "continuamente desde los dispositivos que estan conectados a la red WiFi en" << endl;
					cout << "cuestion.Por esto, para el metodo que utilizaremos necesitamos a un usuario" << endl;
					cout << "conectado a la red a hackear para poder desautenticarlo(desconectarlo) de la red" << endl;
					cout << "WiFi para que, cuando el usuario se reconecte, tenga que mandar el handshake" << endl;
					cout << "inicial, que es el que se tiene que desencriptar con un diccionario o con" << endl;
					cout << "Ademas de esto, necesitaremos escanear las redes cercanas, enfocarnos en una," << endl;
					cout << "saber su bssid y su canal" << endl;

					system("pause");
					system("cls");


					cout << "Buscando redes" << endl<<endl;

					cout << "      BSSID           CHANNEL     ENCRYPTION     ESSID" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));//espera 2 segundos para simular un escaneo real
					cout << "1)03:32:JJ:70:3K:10      1           WEP         SCHOOL" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));//espera 1 segundos para simular un escaneo real
					cout << "2)85:J2:34:T5:36:FW     11           WEP       NEIGHBOUR" << endl;
					this_thread::sleep_for(std::chrono::seconds(1/2));//espera 1 segundos para simular un escaneo real
					cout << "3)DO:RG:HN:F2:35:0L      6           WEP          GF" << endl;
					this_thread::sleep_for(std::chrono::seconds(1/2));//espera 1/2 segundos para simular un escaneo real
					system("pause");
					cout <<endl<<endl<< "Escribe el numero de la red que quieres atacar (1, 2 o 3): ";
					cin >> opCase31;

					system("cls");

					switch (opCase31) {
						case 1:
						case 2:
						case 3:
							cout << "Desautenticando a cliente..."<<endl;
							this_thread::sleep_for(std::chrono::seconds(2));
							cout << "Listo!!! Handshake capturado"<<endl<<endl;
							this_thread::sleep_for(std::chrono::seconds(1));
							cout << "Leyendo el diccionario..." << endl;
							this_thread::sleep_for(std::chrono::seconds(1));
							read();
							cout << "Se encontro la contrasena!!!" << endl<<endl;
							cout << "--------" << endl;
							//se reutiliza el arreglo character del case 2
							//esto se hace para simular haber encontrado una contraseña
							//de las más comunes en las redes tipo WEP
							
							for (int x = 0; x < 8; x = x+2) { //Llena las posiciones pares de numeros del 0 al 9
								 //seria de 48 a 57 (numeros 0-9)
								character[x] = rand() % 9 + 48;
							}
							
							for (int x = 1; x < 8; x = x + 2) { //Llena las posiciones impares de letras mayusculas A-Z
								 //seria de 65 a 90 (letras mayusculas A-Z)
								character[x] = rand() % 25 + 65;
							}

							for (int x = 0; x < 8; x++) { //imprime el arreglo para mostrar la contraseña completa
								cout << character[x];
							}

							for (int x = 0; x < passLong; x++) { //ciclo para reiniciar el valor del arreglo
								character[x] = NULL;
							}

							cout << endl;
							cout << "--------" << endl;
							cout << endl << endl;

							break;
						default:
							cout << "VALOR INCORRECTO" << endl;
							return system("pause");
					}
					
					break;
				case 2: //REDES WPA
					cout << "Existen distintos tipos de protocolos WPA como el WPA, el WPA2, el WPA2 PSK," << endl;
					cout << "el WPA2 - TKIP, etc.pero nos concentraremos en el metodo de hacking mas" << endl;
					cout << "utilizado en general para todos los tipos de WPA.El metodo a utilizar es el" << endl;
					cout << "de fuerza bruta o bruteforce en ingles, el metodo consiste en capturar el" << endl;
					cout << "handshake de la red a  hackear.El handshake es la contraseña del router" << endl;
					cout << "encriptada, que esta enviandose continuamente desde los dispositivos que estan" << endl;
					cout << "conectados a la red WiFi en cuestion." << endl<<endl;
					cout << "Por esto, para el metodo que utilizaremos necesitamos a un usuario conectado" << endl;
					cout << "a la red a hackear para poder desautenticarlo(desconectarlo) de la red WiFi" << endl;
					cout << "para que, cuando el usuario se reconecte, tenga que mandar el handshake" << endl;
					cout << "inicial, que es el que se tiene que desencriptar con un diccionario o con" << endl;
					cout << "bruteforce.Ademas de esto, necesitamos escanear las redes cercanas," << endl;
					cout << "enfocarnos en una, sabes su bssid y su canal." << endl<<endl;

					system("pause");
					system("cls");

					cout << "Buscando redes" << endl << endl;

					cout << "      BSSID           CHANNEL     ENCRYPTION     ESSID" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));//espera 2 segundos para simular un escaneo real
					cout << "1)G4:FE:54:JF:4G:J7      6           WPA         FRIEND" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));//espera 1 segundos para simular un escaneo real
					cout << "2)DE:F5:5C:GU:H7:F6      1           WPA2        STORE" << endl;
					this_thread::sleep_for(std::chrono::seconds(1 / 2));//espera 1 segundos para simular un escaneo real
					cout << "3)55:65:J2:V0:J8:J7     11           WPA2        MARKET" << endl;
					this_thread::sleep_for(std::chrono::seconds(1 / 2));//espera 1/2 segundos para simular un escaneo real
					system("pause");
					cout << endl << endl << "Escribe el numero de la red que quieres atacar (1, 2 o 3): ";
					cin >> opCase31;

					system("cls");

					switch (opCase31) {
					case 1:
					case 2:
					case 3:
						cout << "Desautenticando a cliente..." << endl;
						this_thread::sleep_for(std::chrono::seconds(2));
						cout << "Listo!!! Handshake capturado" << endl << endl;
						this_thread::sleep_for(std::chrono::seconds(1));
						cout << "Bruteforcing now" << endl;
						this_thread::sleep_for(std::chrono::seconds(2));
						//Algoritmo que simula el bruteforce 
						//se reutilizan los arreglos del case 2
						//esto se hace para simular haber encontrado una contraseña
						//de las más comunes en las redes tipo WPA

							for (int x = 0; x < 8; x++) { //cilo para reiniciar los valores de los arreglos
								character[x] = 48;
							}




							for (int y = 0; y < 8; y++) {


								for (int x = 48; x < 58; x++) { //numeros del 0 al 9
									//seria de 48 a 57 (numeros 0-9)
									character[y] = x;
									for (int k = 7; k > -1; k--) { //imprime el arreglo para mostrar la contraseña completa
										cout << character[k];
									}
									cout << endl; //da el salto de linea para que se imprima la password siguiente
									//system("cls");
								}

								for (int x = 65; x < 91; x++) { //letras mayusculas de A-Z
																////seria de 65 a 90 (letras mayusculas A-Z)
									character[y] = x;
									for (int k = 7; k > -1; k--) { //imprime el arreglo para mostrar la contraseña completa
										cout << character[k];
									}
									cout << endl; //da el salto de linea para que se imprima la password siguiente
									//system("cls");
								}

								for (int x = 0; x < 8; x++) { //cilo para reiniciar los valores de los arreglos
									character[x] = 48;
								}

							}



						for (int x = 0; x < 8; x++) { //ciclo para reiniciar los valores del arreglo
							character[x] = NULL;
						}

						cout <<endl<< "Se encontro la contrasena!!!" << endl << endl;

					}
					
					break;
				case 3: //REDES WPS

					
					cout << "Este es un protocolo que puede estar incluido en routers con WEP o WPA de" << endl;
					cout << "cualquier tipo.Este protocolo funciona de la siguiente manera : hay un boton" << endl;
					cout << "que se encuentra en el router que dice WPS, esto hace que mande una contrasena" << endl;
					cout << "de 8 digitos por un pequeno lapso, en el que, si hay un dispositivo mandando" << endl;
					cout << "una señal WPS se conectaraal router en cuestion, conectandose asi a Internet." << endl<<endl;
					cout << "Este protocolo es muy vulnerable a ataques, pues siempre es de 8 digitos y solo" << endl;
					cout << "pueden ser numeros del 0 al 9, elunico inconveniente es que es muy lento, ya que" << endl;
					cout << "la computadora tiene realizar un ataque a fuerza bruta, probando todas las" << endl;
					cout << "contraseñas posibles(probando con un algoritmo que prueba las contraseñas WPS" << endl;
					cout << "mas comunes hasta las menos comunes) y la computadora debe estar cerca del" << endl;
					cout << "router para que pruebe las contraseñas.Ademas, hay routers que cuentan con un" << endl;
					cout << "sistema de seguridad para este tipo de ataques, pues si prueban con 3" << endl;
					cout << "contraseñas de WPS estos se bloquearan para que ya no puedan mandar este tipo" << endl;
					cout << "de contraseñas." << endl;

					system("pause");
					system("cls");

					cout << "Buscando redes" << endl << endl;

					cout << "      BSSID           CHANNEL     ENCRYPTION     ESSID" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));//espera 2 segundos para simular un escaneo real
					cout << "1)G4:FE:54:JF:4G:J7      6        WEP - WPS      FRIEND" << endl;
					this_thread::sleep_for(std::chrono::seconds(1));//espera 1 segundos para simular un escaneo real
					cout << "2)DE:F5:5C:GU:H7:F6      1        WPA - WPS      STORE" << endl;
					this_thread::sleep_for(std::chrono::seconds(1 / 2));//espera 1 segundos para simular un escaneo real
					cout << "3)55:65:J2:V0:J8:J7     11        WPA2 - WPS     MARKET" << endl;
					this_thread::sleep_for(std::chrono::seconds(1 / 2));//espera 1/2 segundos para simular un escaneo real
					system("pause");
					cout << endl << endl << "Escribe el numero de la red que quieres atacar (1, 2 o 3): ";
					cin >> opCase4;

					system("cls");

					switch (opCase4) {
					case 1:
					case 2:
					case 3:

						cout << "Utilizar protocolo WPS..." << endl;
						cout << "INICIANDO" << endl<<endl;

						while (contador != 3) {
							cout << "Probando PIN" << endl;
							for (int x = 0; x < 8; x++) { //Llena el arreglo de numeros del 0 al 9
								//seria de 48 a 57 (numeros 0-9)
								character[x] = rand() % 9 + 48;
							}

							for (int x = 0; x < 8; x++) { //imprime el arreglo para mostrar la contraseña completa
								cout << character[x];
							}
							this_thread::sleep_for(std::chrono::seconds(2));
							cout << endl<<"Pin erroneo"<<endl<<endl;
							contador++;
						}


						//ULTIMO CICLO PARA SIMULAR ENCONTRAR EL WPS

						cout <<endl<< "Se encontro el pin WPS!!!" << endl << endl;
						cout << "--------" << endl;
						for (int x = 0; x < 8; x++) { //Llena el arreglo de numeros del 0 al 9
													  //seria de 48 a 57 (numeros 0-9)
							character[x] = rand() % 9 + 48;
						}

						for (int x = 0; x < 8; x++) { //imprime el arreglo para mostrar la contraseña completa
							cout << character[x];
						}

						cout <<endl<< "--------" << endl;

						for (int x = 0; x < 8; x++) { //ciclo para reiniciar los valores del arreglo
							character[x] = NULL;
						}

					}
					
					break;
				default:
					cout << "VALOR INCORRECTO" << endl;
					return system("pause");
			}

			break;
		case 3:
			cout << "Nos vemos ;)" << endl << endl;
			return system("pause");
		default:
			cout << "Has escogido una opcion incorrecta :(" << endl;
			return system("pause");
		}

	}

	return system("pause");
}


void read() {
	ifstream archivo;
	string texto;

	archivo.open("diccionario.txt", ios::in);

	if (archivo.fail()) {
		cout << "Error al abrir el archivo" << endl;
		system("pause");
		exit(1);
	}


	while (!archivo.eof()) {
		getline(archivo, texto);
		cout << texto << endl;
	}

	archivo.close();
}