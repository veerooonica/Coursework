#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <memory>
#include <typeinfo>
#include"���������.h"
#include"functions.h"
#include"�����.h"
#include"All_func.h"
using namespace std;

int main_menu() {
	int choice;
	cout << "===============����� ���������� � ���� ������===============\n" << endl;
	cout << "         ����:       " << endl;
	cout << "1. ���� \n2. ����������� \n3. �����" << endl;
	cout << "=============================================" << endl;
	cout << "�������: ";
	cin >> choice;
	switch (choice) {
	case 1:
		Enter();
		break;
	case 2:
		sign_In();
		break;
	case 3:
		cout << "����������� ������..." << endl;
		exit(0);
		break;
	}
}

int menu_tovar() {
	int vib;
	do {
		cout << "===============����� ���������� � ���� ������===============\n" << endl;
		cout << "         ����:       " << endl;
		cout << "1. ���������� ������ � ������������� ��������� \n2. ����� ������ � ������������� ����������\n3. ����� \n4. �����" << endl;
		cout << "=============================================" << endl;
		cout << "�������: ";
		cin >> vib;
		
	} while (vib >4);
	return vib;
}

//���� �������� ��������������
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
		cout << "����������� ������..." << endl;
		exit(0);
		break;
	}
      }

}

//���� ������
int menu_find() {
	int choice;
	do {
		
		cout << "------------�� ������ �� ���������� �� ������ ���������� �����?--------" << endl;
		cout << "1. ��������\n2. ��������� � ����������\n3. ���������������� ������\n4. �����" << endl;
		cout << "------------------------------------------------------------------------" << endl;
		cout << "�������: ";
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
//���� �����
int menu_enter() {
	int choice;
	do {
		cout << "1. ���� �� ����� ��������������\n2. ���� �� ����� ������������\n3. �����" << endl;
		cin >> choice;
	} while (choice > 3);
	return choice;
}
//���� ������ ��� ������������
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

//���� �����������
int menu_signIn() {
	int choice;
	do {
		cout << "=================�����������===================" << endl;
		cout << "1. ����������� �� ����� ��������������\n2. ����������� �� ����� ������������\n3. �����" << endl;
		cout << "===============================================" << endl;
		cout << "�������:" << endl;
		cin >> choice;
	} while (choice > 3);
	return choice;
}

//����������� ������ � ������������
int sign_In() {
	int choice = 0;
	string chek_pas = "admin";
	string password;
	Customer regestr;
	Admin signIn;

	while (1) {
		switch (menu_signIn()) {
		case 1:
			
			cout << "��� ����������� ��� ������ ��������������� ������� ������, ������� ��� ����� ���������: ";
			cin >> password;
			if (password == chek_pas) {
				signIn.Sign_in();
			}
			else {
				cout << "�� ����� ������������ ����������� ������!!!" << endl;
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