#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <memory>
#include <typeinfo>
#include<vector>
#include<conio.h>
#include"пользователь.h"
#include"лекарства.h"
#include"Menu.h"
using namespace std;

int menu_Admin();

fstream lfile("Admin_login.txt", ios::app);
fstream pfile("Admin_password.txt", ios::app);
class Admin{
private:
	string login_admin;
	string password_admin;
	
public:
	Admin() {	}
	~Admin() {

	}
	//регитрация админа
	int Sign_in() {
		ofstream lfile("Admin_login.txt", ios::app|ios::in|ios::out);
		ofstream pfile("Admin_password.txt", ios::app);
		if (!lfile.is_open() && !pfile.is_open()) {
			cout << "Ошибка открытия файла!!!" << endl;
		}
		else {
			cout << "Введите логин " << endl;
			rewind(stdin);
			getline(cin, login_admin);
			cout << "Введите пароль " << endl;
			rewind(stdin);
			getline(cin, password_admin);
			lfile << login_admin;
			pfile << password_admin;
			cout << "Регистрация прошла успешно!" << endl;
			return 0;
		}
	}
	//вход админа
	int Entrance() {
		vector<char> password;
		
		char c;
		fstream lfile("Admin_login.txt", ios::app | ios::in | ios::out);
		fstream pfile("Admin_password.txt", ios::app | ios::in | ios::out);
		if (!lfile.is_open() && !pfile.is_open()) {
			cout << "Ошибка открытия файлов" << endl;
		}
		else {
			string log_chek;
			string pas_chek;
			while (!lfile.eof()) {
				log_chek = "";
				lfile >> log_chek;
			}
			while (!pfile.eof()) {
				pas_chek = "";
				pfile >> pas_chek;
			}
			cout << "Введите логин: ";
			cin >> login_admin;
			cout << "Введите пароль: ";
			while ((c = _getch()) != '\r')
			{
				password.push_back(c);
				_putch('*');
				
			}
			string password_admin1(password.begin(), password.end());
			if(login_admin!=log_chek || password_admin1!=pas_chek){
				cout << "\nЛогин или пароль введён неверно!!!" << endl;
			}
			else {
				cout << "\nДанные введены верно!" << endl;
				menu_Admin();
			}
			return 0;
		}
	}
};