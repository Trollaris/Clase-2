#include <iostream>
#include "Pair.h"
#include "MiVector.h"
#include <time.h>

/*template <typename T>
T promedio(T valores[], int num){
	T acum = 0;
	for (int i = 0; i < num; i++){
		acum += valores[i];
	}
	return acum / num;
}*/

/// <summary>
/// Compara si a es menor que b
/// </summary>
/// <typeparam name="T"></typeparam>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
template <typename T>
bool lessthan(T& a, T& b){
	if (a < b) return true;
	else return false;
}

int main(){
	float flotantes[5] = { 23.3, 56.3,45.6,34.4,32.67 };
	int enteros[20] = { 5,4,3,7,9, 15,14,13,17,19, 65,64,63,67,69, 45,44,43,47,49 };
	std::string strings[5] = {"abc", "aei", "uwu", "aaa", "F"};

	/*float prom = promedio(flotantes, 5);
	int prom2 = promedio(enteros, 5);
	std::string prom3 = promedio(strings, 5);
	std::cout << "promedio de floats: " << prom << std::endl;
	std::cout << "promedio de doubles: " << prom2 << std::endl;
	int a = 6;
	int b = 4;
	std::cout << "6 < 4? " << lessthan(b, a) << std::endl;
	double i = 6.243654643;
	double j = 4.234423437;
	std::cout << "6. < 4.? " << lessthan(j, i) << std::endl;*/

	//ordenar por metodo de la burbuja
	clock_t t;
	t = clock();
	for (int i = 0; i < 20; i++){
		for (int j = i; j < 20; j++){
			if (!lessthan(enteros[i], enteros[j])){
				int temp = enteros[i];
				enteros[i] = enteros[j];
				enteros[j] = temp;
			}
		}
	}
	for (int i = 0; i < 20; i++)
		std::cout << enteros[i] << std::endl;
	t = clock() - t;
	double t_secs = ((float)t) / CLOCKS_PER_SEC;
	std::cout << "Tiempo de calculo de burbuja: " << t_secs*1000 << "ms" << std::endl;

	std::cout << "ahora vienen los floats" << std::endl;

	//ordenar los flotantes
	for (int i = 0; i < 5; i++){
		for (int j = i; j < 5; j++){
			if (!lessthan(flotantes[i], flotantes[j])){
				float temp = flotantes[i];
				flotantes[i] = flotantes[j];
				flotantes[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		printf("%f \n", flotantes[i]);

	std::cout << "ahora vienen los strings" << std::endl;

	for (int i = 0; i < 5; i++) {
		for (int j = i; j < 5; j++) {
			if (!lessthan(strings[i], strings[j])) {
				std::string temp = strings[i];
				strings[i] = strings[j];
				strings[j] = temp;
			}
		}
	}
	for (int i = 0; i < 5; i++)
		printf("%f \n", strings[i]);

	char* s1 = (char*)"hola";
	char* s2 = (char*)"mundo";

	if (lessthan(s1, s2)){
		std::cout << "menor que";
	}
	else{
		std::cout << "mayor que";
	}

	//seccion de prueba de clase Pair
	Pair<int>* parA = new Pair<int>();
	parA->name = "Player1";
	parA->value = 53;

	Pair<double>* parB = new Pair<double>();
	parB->name = "Player2";
	parB->value = 234.67636357;

	Pair<std::string>* parDeStrings = new Pair<std::string>();
	parDeStrings->name = "hola";
	parDeStrings->value = "mundo";

	parA->print();
	parB->print();
	parDeStrings->print();

	//ejemplo de vectores
	MiVector<float>* v1 = new MiVector<float>();
	v1->x = 78.2345;
	v1->y = 43.213;

	std::cout << "velocidad: (" << v1->x << "," << v1->y << "), rapidez=" << v1->SqrMagnitude(*v1) << std::endl;

	MiVector<float>* v2 = new MiVector<float>(*v1);

	std::cout << "velocidad: (" << v2->x << "," << v2->y << "), rapidez=" << v2->SqrMagnitude(*v1) << std::endl;

	puts("**************");
	puts("*   Vector3  *");
	puts("**************");

	MiVector<float> *u = new MiVector<float>(2, 3, 4);

	std::cout << "u = " << u->ToString() << std::endl;

	MiVector<float>* v = new MiVector<float>(6, 7, 4);

	float productopunto = u->ProductoPunto(*v);

	std::cout << "u*v = " << productopunto << std::endl;

}
