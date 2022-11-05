//РАЗРАБОТКА АВТОМАТИЗИРОВАННОЙ СИСТЕМЫ УЧЁТА ТОВАРОВ В АПТЕКЕ
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <memory>
#include <typeinfo>
#include"лекарства.h"
#include"Menu.h"
using namespace std;


int main() {
	//setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	system("cls");
	setlocale(LC_ALL, ".1251");
	main_menu();
}