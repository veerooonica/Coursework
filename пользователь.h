#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <memory>
#include <typeinfo>
using namespace std;

fstream lufile("User_login.txt", ios::app);
fstream pufile("User_password.txt", ios::app);
class Customer {
private:
	string login_user;
	string password_user;
	
public:
	Customer() {
		}
	~Customer() {

	}
	//����������� ����������
	int Sign_in_cust() {
		ofstream lufile("User_login.txt", ios::app | ios::in | ios::out);
		ofstream pufile("User_password.txt", ios::app);
		if (!lufile.is_open() && !pufile.is_open()) {
			cout << "������ �������� �����!!!" << endl;
		}
		else {
			cout << "������� ����� " << endl;
			rewind(stdin);
			getline(cin, login_user);
			cout << "������� ������ " << endl;
			rewind(stdin);
			getline(cin, password_user);
			lufile << login_user;
			pufile << password_user;
			cout << "����������� ������ �������!" << endl;
			return 0;
		}
	}
	//���� ����������
	int Entrance_cust() {
		vector<char> password;

		char c;
		fstream lufile("User_login.txt", ios::app | ios::in | ios::out);
		fstream pufile("User_password.txt", ios::app | ios::in | ios::out);
		if (!lufile.is_open() && !pufile.is_open()) {
			cout << "������ �������� ������" << endl;
		}
		else {
			string log_chek;
			string pas_chek;
			while (!lufile.eof()) {
				log_chek = "";
				lufile >> log_chek;
			}
			while (!pufile.eof()) {
				pas_chek = "";
				pufile >> pas_chek;
			}
			cout << "������� �����: ";
			cin >> login_user;
			cout << "������� ������: ";
			while ((c = _getch()) != '\r')
			{
				password.push_back(c);
				_putch('*');

			}
			string password_user1(password.begin(), password.end());
			if (login_user != log_chek || password_user1 != pas_chek) {
				cout << "\n����� ��� ������ ����� �������!!!" << endl;
			}
			else {
				cout << "\n������ ������� �����!" << endl;

			}
			return 0;
		}
	}
};