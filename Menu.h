#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <memory>
#include <typeinfo>
#include"лекарства.h"
#include"functions.h"
#include"админ.h"
#include"All_func.h"
using namespace std;

int main_menu() {
	int choice;
	cout << "===============ДОБРО ПОЖАЛОВАТЬ В НАШУ АПТЕКУ===============\n" << endl;
	cout << "         МЕНЮ:       " << endl;
	cout << "1. Вход \n2. Регистрация \n3. Выход" << endl;
	cout << "=============================================" << endl;
	cout << "Введите: ";
	cin >> choice;
	switch (choice) {
	case 1:
		Enter();
		break;
	case 2:
		sign_In();
		break;
	case 3:
		cout << "Заканчиваем работу..." << endl;
		exit(0);
		break;
	}
}

int menu_tovar() {
	int vib;
	do {
		cout << "===============ДОБРО ПОЖАЛОВАТЬ В НАШУ АПТЕКУ===============\n" << endl;
		cout << "         МЕНЮ:       " << endl;
		cout << "1. Добавление данных о лекарственном препарате \n2. Вывод данных о лекарственных перпаратах\n3. Поиск \n4. Выход" << endl;
		cout << "=============================================" << endl;
		cout << "Введите: ";
		cin >> vib;
		
	} while (vib >4);
	return vib;
}

//меню действий администратора
int menu_Admin() {
	int vib=0;
	bool parametr = false;
	Medicament** mas;
	mas = new Medicament * [100];
while (1) {
	switch (menu_tovar()) {
	case 1:
		number = inputMedicament(mas);

		break;

	case 2:
		system("cls");
		output_file();
		break;
	case 3:
		system("cls");
		find();
		break;
	case 4:
		cout << "Заканчиваем работу..." << endl;
		exit(0);
		break;
	}
      }

}

//меню поиска
int menu_find() {
	int choice;
	do {
		
		cout << "------------По какому из параметров вы хотите произвести поиск?--------" << endl;
		cout << "1. Название\n2. Показание к применению\n3. Формакологическа группа\n4. Назад" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "Введите: ";
		cin >> choice;
	} while (choice > 5);
	return choice;
}

int find() {
	int choice = 0;
	while (1) {
		switch (menu_find()) {
		case 1:
			system("cls");
			find_name();
			break;
		case 2:
			system("cls");
			find_indication_for_use();
			break;
		case 3:
			system("cls");
			find_formacol_group();
			break;
		case 4:
			menu_tovar();
			break;
		}
	}
}
//меню входа
int menu_enter() {
	int choice;
	do {
		cout << "1. Вход от имени администратора\n2. Вход от имени пользователя\n3. Назад" << endl;
		cin >> choice;
	} while (choice > 3);
	return choice;
}
//вход админа или пользователя
int Enter() {
	int choice = 0;
	Customer ent;
	Admin enter;
	while (1) {
		switch (menu_enter()) {
		case 1:
			system("cls");
			enter.Entrance();


			break;
		case 2:
			system("cls");
			ent.Entrance_cust();
			break;
		case 3:
			main_menu();
			break;

		}
	}
}

//меню регистрации
int menu_signIn() {
	int choice;
	do {
		cout << "=================РЕГИСТРАЦИЯ===================" << endl;
		cout << "1. Регистрация от имени администратора\n2. Регистрация от имени пользователя\n3. Назад" << endl;
		cout << "===============================================" << endl;
		cout << "Введите:" << endl;
		cin >> choice;
	} while (choice > 3);
	return choice;
}

//регистрация админа и пользователя
int sign_In() {
	int choice = 0;
	string chek_pas = "admin";
	string password;
	Customer regestr;
	Admin signIn;

	while (1) {
		switch (menu_signIn()) {
		case 1:
			
			cout << "Для регистрации под именем админимтсратора введите пароль, который Вам выдал дирректор: ";
			cin >> password;
			if (password == chek_pas) {
				signIn.Sign_in();
			}
			else {
				cout << "Вы ввели неправильный проверочный пароль!!!" << endl;
			}
			
			break;
		case 2:
			regestr.Sign_in_cust();
			break;
		case 3:
			main_menu();
			break;
		
		}
	}
}