#include <iostream>
#include <string>

using namespace std;

class cofee {
private: 
	//ee svoistva
	int sugar;
	string type;
	string add;
	string taste;

public: cofee(string cname, string ctaste, string cadd, int csugar) {
	//prinimaet zancheniya
	type = cname;
	add = cadd;
	sugar = csugar;
	taste = ctaste;
}

//vvod peremennyukh
public: void setadd(string k) {
	add = k;
}
public: void setaste(string k) {
	taste = k;
}
public: void settype(string k) {
	type = k;
}
public: void setsugar(float k) {
	sugar = k;
}

//vivod peremennyukh
public: string getadd() {
	return add;
}
public: string getaste() {
	return taste;
}
public: string gettype() {
	return type;
}
public: int getsugar() {
	return sugar;
}
};

int main() {
	setlocale(LC_ALL, "rus");
	cout << "Торговый автомат\nВыберите кофе и нажмите на соответствующую цифру:\n";
	cofee cofeelist[6] =
	{
		//kakoe coffee imeet takoe znach (1)
		cofee("Латте", "Горький", "Карамель", 31),
		cofee("Капучино", "Горький", "Сливки", 31),
		cofee("Кофейное молоко", "Сладкий", "Молоко", 31),
		cofee("Эспрессо", "Горький", "Молоко", 31),
		cofee("Латте-макиато", "Сладкий", "Вишневый сироп", 31),
		cofee("Белое кофе", "Сладкий", "Молоко", 31)
	};
	for (int i = 0; i < sizeof(cofeelist) / sizeof(cofee); i++) {
		std::cout << i << ") " << cofeelist[i].gettype() << endl;
	}
	int sel;
	cin >> sel;
	while ((sel < 0) || (sel > sizeof(cofeelist) / sizeof(cofee) - 1)) {
		cout << "Введите корректное число!\n";
		cin >> sel;
	}
	cout << "Вы выбрали " << sel << " пункт.\n";
	while (true) {
		//vivod (1)
		cout << "Название кофе: " << cofeelist[sel].gettype() << endl;
		cout << "Количество сахара: " << cofeelist[sel].getsugar() << " г." << endl;
		cout << "Добавка: " << cofeelist[sel].getadd() << endl;
		cout << "Вкус: " << cofeelist[sel].getaste() << endl;
		cout << "Если вы хотите поменять какой-либо параметр нажмите соотвествующую клавишу (1-Количество сахара, 2-Добавка; 0-Ничего не менять, взять кофе.)\n";
		int choice = 0;
		cin >> choice;
		while ((choice != 1) && (choice != 2) && (choice != 0)) { cout << "Повторите ввод!\n"; cin >> choice; }
		if (choice == 1) {
			int newpar;
			cout << "Введите желаемое количество сахара в граммах\n";
			cin >> newpar;
			cofeelist[sel].setsugar(newpar);
		}
		else if (choice == 2) {
			cout << "Выберите добавку (1-Карамель, 2-Вишневый сироп, 3-Молоко, 4-Сливки)\n";
			int newpar;
			cin >> newpar;
			if (newpar == 1) cofeelist[sel].setadd("Карамель");
			else if (newpar == 2)cofeelist[sel].setadd("Вишневый сироп");
			else if (newpar == 3)cofeelist[sel].setadd("Молоко");
			else if (newpar == 4)cofeelist[sel].setadd("Сливки");
		}
		else {
			break;
		}
	}
	cout << "Спасибо за покупку.\n";
	//vivod dannyukh (pokupki)
	cout << "Ваше " << cofeelist[sel].gettype() << " с " << cofeelist[sel].getadd() << " и " << cofeelist[sel].getsugar() << " грамм сахара\nПриходите еще\n";
	system("pause");
	return 0;
}
