// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
#include <fstream>

using namespace std;

class Animal
{
	char* nazv;
	uint32_t ves;
	char* okras;
public:
	Animal(const char* newNazv, uint32_t newVes, const char* newOkras)
		: nazv{ newNazv ? new char[strlen(newNazv) + 1] : nullptr }, ves{ newVes }, okras{ newOkras ? new char[strlen(newOkras) + 1] : nullptr }
	{
		if (nazv)
		{
			strcpy_s(nazv, strlen(newNazv) + 1, newNazv);
		}
		if (okras)
		{
			strcpy_s(okras, strlen(newOkras) + 1, newOkras);
		}

		cout << "Animal конструктор с параметром находится в " << this << "\n";
	}

	Animal() : Animal("Название", 0, "Окрас") {}

	Animal(Animal&& object)
		: nazv{ object.nazv ? new char[strlen(object.nazv) + 1] : nullptr }, ves{ object.ves }, okras{ object.okras ? new char[strlen(object.okras) + 1] : nullptr }
	{
		object.nazv = nullptr;
		object.ves = 0;
		object.okras = nullptr;
		cout << "Animal конструктор перемещения находится в " << this << "\n";
	}

	Animal(const Animal& cop)
		: nazv{ cop.nazv ? new char[strlen(cop.nazv) + 1] : nullptr }, ves{ cop.ves }, okras{ cop.okras ? new char[strlen(cop.okras) + 1] : nullptr }
	{
		if (nazv)
		{
			strcpy_s(nazv, strlen(cop.nazv) + 1, cop.nazv);
		}
		if (okras)
		{
			strcpy_s(okras, strlen(cop.okras) + 1, cop.okras);
		}
		cout << "Animal конструктор копирования находится в " << this << "\n";
	}

	Animal& operator=(Animal&& object)
	{
		if (!(this == &object))
		{
			delete nazv;
			delete okras;
			nazv = object.nazv;
			ves = object.ves;
			okras = object.okras;
			object.nazv = nullptr;
			object.ves = 0;
			object.okras = nullptr;
		}
		return *this;
	}

	void print() const
	{
		if (nazv)
		{
			cout << "\nНазвание: " << nazv << "\nВес: " <<
				ves << "\nОкрас: " << okras << endl;
		}
		else
			cout << "Пусто\n";
	}

	~Animal()
	{
		delete[] nazv;
		delete[] okras;
		cout << "Деструктор для " << this << '\n';
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	Animal dog("Собака", 20, "Светлый");
	dog.print();

	Animal animal;
	animal.print();

}