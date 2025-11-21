#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

struct dish{
	string name;
	string type;
	double price;
};

vector<dish> readFile(ifstream& inFile){
	vector<dish> dishes;
	string name;
	string type;
	double price;
	string line;
	while(getline(inFile, line)){
		istringstream stream(line);
		getline(stream, name, ';');
		getline(stream, type, ';');
		stream >> price;
		dishes.push_back({name, type, price});
	}
	return dishes;
}

void output(const vector<dish>& dishes){
	for(dish i : dishes){
		cout << i.name << "; " << i.type << "; " << i.price << endl;
	}
}

void writeFile(const vector<dish>& dishes){
	string name;
	string type;
	double price;
	ofstream outFile("menu.txt", ios::out);
	if(outFile.is_open()){
		for(size_t i = 0; i < dishes.size(); i++){
			name = dishes[i].name;
			type = dishes[i].type;
			price = dishes[i].price;
			outFile << name << ";" << type << ";" << price << endl;;
		}
		outFile.close();
	} else{
		cerr << "Неудалось открыть файл для записи" << endl;
	}
}

bool isType(const string& str){
	vector<string> Types = {"Закуски", "Основные блюда", "Десерты", "Напитки", "Для детей"};
	return find(Types.begin(), Types.end(), str) != Types.end();

}

void input(ofstream& outFile){
	string line;
	string name;
	string type;
	double price;
	cout << "Вводите данные в формате: название,тип,цена (или пустая строка для выхода):" << endl;
	while(true){
		getline(cin, line);
		istringstream stream(line);
		if(line.empty()) break;
		getline(stream, name, ',');
		getline(stream, type, ',');
		while(!isType(type)){
			cout << "Ошибка ввода типа блюда. Напишите ещё раз: ";
			getline(cin, type);
	}
		stream >> price;
		while(price <= 0){
			cout << "Цена не может быть отрицательной. Напишите ещё раз: ";
			cin >> price;
		}
		outFile << name << ";" << type << ";" << price << endl;
		cout << "Блюдо успешно добавлено" << endl;
	}
}

bool dishSearch(ifstream& inFile, const string& name){
	string name_dish;
	string line;
	string type;
	double price;
	bool f = true;
	while(getline(inFile, line)){
		if(line.find(name) != string::npos){
			istringstream stream(line);
			getline(stream, name_dish, ';');
			cout << "Название блюда: " << name_dish << ", ";
			getline(stream, type, ';');
			cout << "Тип блюда: " << type << ", ";
			stream >> price;
			cout << "Стоимость блюда: " << price << " р.";
			f = false;
			break;
		}
	}
	if(f){
		cout << "Ошибка: блюдо не найдено";
	}
	return f;
}

void sortByPrice(vector<dish>& dishes){
	sort(dishes.begin(), dishes.end(), [](const dish a, const dish b){return a.price < b.price;});
	output(dishes);
	writeFile(dishes);
}

void sortByType(vector<dish>& dishes){
	sort(dishes.begin(), dishes.end(), [](const dish& a, const dish& b){return a.type < b.type;});
	output(dishes);
	writeFile(dishes);
}

void addFile(ofstream& outFile){
	string line;
	string name;
	string type;
	double price;
	cout << "Вводите данные в формате: название,тип,цена (или пустая строка для выхода):" << endl;
	getline(cin, line);
	istringstream stream(line);
	getline(stream, name, ',');
	getline(stream, type, ',');
	while(!isType(type)){
		cout << "Ошибка ввода типа блюда. Напишите ещё раз: ";
		getline(cin, type);
	}
	stream >> price;
	while(price <= 0){
		cout << "Цена не может быть отрицательной. Напишите ещё раз: ";
		cin >> price;
	}
	outFile << name << ";" << type << ";" << price << endl;
	cout << "Блюдо успешно добавлено" << endl;
}

void query(ifstream& inFile, double pr){
	vector<dish> dishes;
	string name;
	string type;
	double price;
	string line;
	while(getline(inFile, line)){
		istringstream stream(line);
		getline(stream, name, ';');
		getline(stream, type, ';');
		stream >> price;
		dishes.push_back({name, type, price});
	}
	cout << "Блюда с ценой до " << pr << endl;
	for(dish i : dishes){
		if(i.price <= pr){
			cout << i.name << ";" << i.type << ";" << i.price << endl;
		}
	}
}

void menu(){
	cout << "Меню действий:" << endl;
	cout << "1.Добавить Блюдо" << endl;
	cout << "2.Поиск блюда" << endl;
	cout << "3.Сортировка по цене" << endl;
	cout << "4.Сортировка по типу" << endl;
	cout << "5.Запрос по цене" << endl;
	cout << "6.Вывод данных" << endl;
	cout << "0.Выход из меню" << endl;
	cout << "Выберите одну из команд: ";
}

int main()
{
	cout << "Создайте меню" << endl;
	ofstream outFile("menu.txt");
	if(outFile.is_open()){
		input(outFile);
		outFile.close();
	} else{
		cerr << "Неудалось открыть файл для записи" << endl;
	}
	int i;
	menu();
	cin >> i;
	cin.ignore();

	ofstream outTemp("output.txt", ios::out | ios::app);
	switch (i) {
		case 1:{
			ofstream outFile("menu.txt", ios::app);
			if(outFile.is_open()){
				addFile(outFile);
				outTemp << "Успешно выполнена операция 1" << endl;
				outFile.close();
			} else{
				cerr << "Неудалось открыть файл для записи" << endl;
				outTemp << "Операцию 1 выполнить не удалось" << endl;
			}
			outTemp.close();
			break;
		}

		case 2:{
			ifstream inFile("menu.txt", ios::in);
			if(inFile.is_open()){
				string name;
				cout << "Введите название блюда: ";
				getline(cin, name);
				if(!dishSearch(inFile, name)){
					outTemp << "Успешно выполнена операция 2" << endl;
				}
				else{
					outTemp << "Операцию 2 выполнить не удалось" << endl;
				}

				inFile.close();
			} else{
				cerr << "Неудалось открыть файл для записи" << endl;
				outTemp << "Операцию 2 выполнить не удалось" << endl;
			}
			outTemp.close();
			break;
		}

		case 3:{
			vector<dish> dishes;
			ifstream inFile("menu.txt", ios::in);
			if(inFile.is_open()){
				dishes = readFile(inFile);
				sortByPrice(dishes);
				outTemp << "Успешно выполнена операция 3" << endl;
				inFile.close();
			} else{
				cerr << "Неудалось открыть файл для записи" << endl;
				outTemp << "Операцию 3 выполнить не удалось" << endl;
			}
			outTemp.close();
			break;
		}

		case 4:{
			vector<dish> dishes;
			ifstream inFile("menu.txt", ios::in);
			if(inFile.is_open()){
				dishes = readFile(inFile);
				sortByType(dishes);
				outTemp << "Успешно выполнена операция 4" << endl;
				inFile.close();
			} else{
				cerr << "Неудалось открыть файл для записи" << endl;
				outTemp << "Операцию 4 выполнить не удалось" << endl;
			}
			outTemp.close();
			break;
		}

		case 5:{
			ifstream inFile("menu.txt", ios::in);
			double pr;
			cout << "Введите стоимость: ";
			cin >> pr;
			if(pr < 0){
				cout << "Стоимость не может быть отрицательной" << endl;
				outTemp << "Операцию 5 выполнить не удалось" << endl;
				outTemp.close();
				break;
			}
			if(inFile.is_open()){
				cout << endl;
				query(inFile, pr);
				outTemp << "Успешно выполнена операция 5" << endl;
				inFile.close();
			} else{
				cerr << "Неудалось открыть файл для записи" << endl;
				outTemp << "Операцию 5 выполнить не удалось" << endl;
			}
			outTemp.close();
			break;
		}

		case 6:{
			vector<dish> dishes;
			ifstream inFile("menu.txt", ios::in);
			if(inFile.is_open()){
				dishes = readFile(inFile);
				output(dishes);
				outTemp << "Успешно выполнена операция 6" << endl;
				inFile.close();
			} else{
				cerr << "Неудалось открыть файл для записи" << endl;
				outTemp << "Операцию 6 выполнить не удалось" << endl;
			}
			outTemp.close();
			break;
		}

		case 0:{
			cout << "Выход из программы." << endl;
			break;
		}

		default:{
			cout << "Неверный выбор." << endl;
		}
	}
	return 0;
}
