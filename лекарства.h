#pragma once
#include <iostream>
#include <windows.h>
#include <iomanip>
#include <string.h>
#include <string>
#include <memory>
#include<fstream>
#include <typeinfo>
#define LINES 100

using namespace std;
char line[LINES][100];
char str[50];
char str1[50];
char s[] = "                                                                                                                                                              ";
ofstream infile("Medicaments.txt", ios::app);
int CreateInt() {
	int correct = 0;
	char str[70];
	while (!correct)
	{
		cin >> str;
		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			if (str[i] < '0' || str[i]>'9') {
				cout << "������� �������� ��������\n";
				correct = 0;
				break;
			}
			correct = 1;
		}
	}
	return atoi(str);
}
class Date {//���� ������������ � ��������� ����� ��������
private:
	int daybegin;
	int monthbegin;
	int yearbegin;
	int dayend;
	int monthend;
	int yearend;
	
public:
	Date() {

		cout << "������� ���� ������������ �������������� ���������" << endl;
		//���� ���� ������
		while (1) {
			cout << "������� ���:" << endl;
			yearbegin = CreateInt();
			if (yearbegin < 2010) {
				cout << "������������ ����" << endl;
			}
			else { break; }
		}
		
		
		//����� ������
		while (1) {
			cout << "������� �����:" << endl;
			monthbegin = CreateInt();
			if (monthbegin < 1 || monthbegin > 12) {
				cout << "������������ ����" << endl;
			}
			else { break; }
		}//���� ������ ������
		
		//���� ������
		while (1) {
			cout << "������� ����:" << endl;
			daybegin = CreateInt();
			if (daybegin < 1) {
				cout << "������������ ����" << endl;
			}
			else if (monthbegin == 2 && daybegin > 28) {
				cout << "������������ ����" << endl;
			}
			else if ((monthbegin == 1 || monthbegin == 3 || monthbegin == 5 || monthbegin == 7 || monthbegin == 8 || monthbegin == 10 || monthbegin == 12) && daybegin > 31) {
				cout << "������������ ����" << endl;
			}
			else if ((monthbegin == 4 || monthbegin == 6 || monthbegin == 9 || monthbegin == 11) && daybegin > 30) {
				cout << "������������ ����" << endl;
			}
			else { break; }
		}
		infile << daybegin<<"-"<<monthbegin<<"-"<<yearbegin << "          | ";
	
		cout << "������� ���� ��������� ����� �������� ���������" << endl;
		//����� �����
		while (1) {
			cout << "������� �����:" << endl;
			monthend = CreateInt();
			if (monthend < 1 || monthend > 12) {
				cout << "������������ ����" << endl;
			}
			else { break; }
		}
		
		//���� �����
		while (1) {
			cout << "������� ����:" << endl;
			dayend = CreateInt();
			if (dayend < 1) {
				cout << "������������ ����" << endl;
			}
			else if (monthend == 2 && dayend > 28) {
				cout << "������������ ����" << endl;
			}
			else if ((monthend == 1 || monthend == 3 || monthend == 5 || monthend == 7 || monthend == 8 || monthend == 10 || monthend == 12) && dayend > 31) {
				cout << "������������ ����" << endl;
			}
			else if ((monthbegin == 4 || monthbegin == 6 || monthbegin == 9 || monthbegin == 11) && daybegin > 30) {
				cout << "������������ ����" << endl;
			}
			else { break; }
		}
		
		//��� �����
		while (1) {
			cout << "������� ���" << endl;
			cin >> yearend;
			break;
		}
		
		infile << dayend << "-" << monthend << "-" << yearend << "                  ";
	}
	~Date() {

	}
	void printData(Date *arr, int i) {
		
		cout << "���� ������������";
		cout << arr[i].daybegin << "." << arr[i].monthbegin << "." << arr[i].yearbegin << endl;
		cout << "���� ��������� ����� ��������";
		cout << arr[i].dayend << "." << arr[i].monthend << "." << arr[i].yearend << endl;
		
	}
};

class Medicament:public Date {//���������� � ���������
private:
	int age;
	char method[20];
	char name[30];
	char indication_for_use[20];//��������� � ����������
	char formacol_group[20];//����������, ���������������������
	char side_effects[20];//�������� �������
	char release_form[20];//����� �������(��������, �����, ����)
public:
	Medicament() {
		if (infile.is_open()) {
			//���� �������� ���������
			while (true) {
				try {
					cout << "������� �������� ��������� " << endl;
					rewind(stdin);
					cin.getline(name, 30);

					//int length = name.size();
					for (int i = 0; i < 15; i++) {
						if (isdigit(name[i])) {
							throw runtime_error("��� �� ������");
						}
						else {
							break;
						}
					}
					break;
				}
				catch (runtime_error err) {
					cout << err.what() << "������� �������� ��������, ���������� ��� ���..." << endl;
				}
				cout << "������� �������� ���������: " << endl;
				rewind(stdin);
				cin.getline(name, 30);
				break;
			}

			infile <<setfill(' ')<< setw(15) << left << name;
			//���� ������ ����������
			while (true) {
				try {
					cout << "������� ����� ���������� ���������: " << endl;
					rewind(stdin);
					cin.getline(method, 20);

					for (int i = 0; i < 20; i++) {
						if (isdigit(method[i])) {
							throw runtime_error("��� �� ������");
						}
						else {
							break;
						}
					}
					break;
				}
				catch (runtime_error err) {
					cout << err.what() << "������� �������� ��������, ���������� ��� ���..." << endl;
				}
				cout << "������� ����� ���������� ���������: " << endl;
				rewind(stdin);
				cin.getline(method, 20);
				break;
			}
			infile << setfill(' ') << "     " << setw(28) << left << method;
			//���� �������� ���������
			while (true) {
				cout << "������� ������� ����������" << endl;
				cin >> age;
				if ((age < 0) || (age > 99)) throw exception();
				break;
			}
			infile << setfill(' ') << setw(25) << left << age;
			//���� ��������� � ����������
			while (true) {
				try {
					cout << "������� ��������� � ���������� " << endl;
					rewind(stdin);
					cin.getline(indication_for_use, 20);

					for (int i = 0; i < 20; i++) {
						if (isdigit(indication_for_use[i])) {
							throw runtime_error("��� �� ������");
						}
						else {
							break;
						}
					}
					break;
				}
				catch (runtime_error err) {
					cout << err.what() << "������� �������� ��������, ���������� ��� ���..." << endl;
				}
				cout << "������� ��������� � ����������: " << endl;
				rewind(stdin);
				cin.getline(indication_for_use, 20);
				break;
			}
			infile << setfill(' ') << setw(20) << left << indication_for_use;
			//���� ����������������� ������
			while (true) {
				try {
					cout << "������� ����������������� ������: " << endl;
					rewind(stdin);
					cin.getline(formacol_group, 20);

					for (int i = 0; i < 20; i++) {
						if (isdigit(formacol_group[i])) {
							throw runtime_error("��� �� ������");
						}
						else {
							break;
						}
					}
					break;
				}
				catch (runtime_error err) {
					cout << err.what() << "������� �������� ��������, ���������� ��� ���..." << endl;
				}
				cout << "������� ����������������� ������: " << endl;
				rewind(stdin);
				cin.getline(formacol_group, 20);
				break;
			}
			infile << setfill(' ') << setw(20) << left << formacol_group;
			//���� �������� ��������
			while (true) {
				try {
					cout << "������� �������� �������: " << endl;
					rewind(stdin);
					cin.getline(side_effects, 20);

					for (int i = 0; i < 20; i++) {
						if (isdigit(side_effects[i])) {
							throw runtime_error("��� �� ������");
						}
						else {
							break;
						}
					}
					break;
				}
				catch (runtime_error err) {
					cout << err.what() << "������� �������� ��������, ���������� ��� ���..." << endl;
				}
				cout << "������� �������� �������: " << endl;
				rewind(stdin);
				cin.getline(side_effects, 20);
				break;
			}
			infile << setfill(' ') << setw(25) << left << side_effects;
			//���� ����� �������
			while (true) {
				try {
					cout << "������� ����� �������: " << endl;
					rewind(stdin);
					cin.getline(release_form, 20);

					for (int i = 0; i < 20; i++) {
						if (isdigit(release_form[i])) {
							throw runtime_error("��� �� ������");
						}
						else {
							break;
						}
					}
					break;
				}
				catch (runtime_error err) {
					cout << err.what() << "������� �������� ��������, ���������� ��� ���..." << endl;
				}
				cout << "������� ����� �������: " << endl;
				rewind(stdin);
				cin.getline(release_form, 20);
				break;
			}
			infile << setfill(' ') << setw(17) << left << release_form << endl;
			
		}
		
	}
	~Medicament() {

	}
	void printData(Medicament *arr, int i) {
		cout << "�������� ���������";
		cout << arr[i].name << endl;
		cout << "������������� ������� ����������";
		cout << arr[i].age;
		cout << "����� ����������";
		cout << arr[i].method << endl;
		cout << "����������������� ������";
		cout << arr[i].formacol_group << endl;
		cout << "��������� � ����������";
		cout << arr[i].indication_for_use << endl;
		cout << "�������� �������";
		cout << arr[i].side_effects << endl;
		cout << "����� �������";
		cout << arr[i].release_form << endl;
	}

	void setRole() {
		string newName = "������������� ��������";
		
	}

static void output_file();


};

int number = 0;
int inputMedicament(Medicament** mas) {//���� ������
	int i = 0;
	bool param = false;
	while (param == false) {
		mas[i] = new Medicament();
		mas[i]->setRole();
		i++;
		number++;
		param == true;
		break;
	}
	return number;
}



