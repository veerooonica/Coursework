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
#include"������������.h"
#include"���������.h"
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
	//���������� ������
	int Sign_in() {
		ofstream lfile("Admin_login.txt", ios::app|ios::in|ios::out);
		ofstream pfile("Admin_password.txt", ios::app);
		if (!lfile.is_open() && !pfile.is_open()) {
			cout << "������ �������� �����!!!" << endl;
		}
		else {
			cout << "������� ����� " << endl;
			rewind(stdin);
			getline(cin, login_admin);
			cout << "������� ������ " << endl;
			rewind(stdin);
			getline(cin, password_admin);
			lfile << login_admin;
			pfile << password_admin;
			cout << "����������� ������ �������!" << endl;
			return 0;
		}
	}
	//���� ������
	int Entrance() {
		vector<char> password;
		
		char c;
		fstream lfile("Admin_login.txt", ios::app | ios::in | ios::out);
		fstream pfile("Admin_password.txt", ios::app | ios::in | ios::out);
		if (!lfile.is_open() && !pfile.is_open()) {
			cout << "������ �������� ������" << endl;
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
			cout << "������� �����: ";
			cin >> login_admin;
			cout << "������� ������: ";
			while ((c = _getch()) != '\r')
			{
				password.push_back(c);
				_putch('*');
				
			}
			string password_admin1(password.begin(), password.end());
			if(login_admin!=log_chek || password_admin1!=pas_chek){
				cout << "\n����� ��� ������ ����� �������!!!" << endl;
			}
			else {
				cout << "\n������ ������� �����!" << endl;
				menu_Admin();
			}
			return 0;
		}
	}
};