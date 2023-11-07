#include <iostream>
#include <numeric>

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}

	Fraction operator+(Fraction other) {

		int up = ((numerator_ * other.denominator_) + (denominator_ * other.numerator_));
		int down = other.denominator_ * denominator_;
		int q = std::gcd(up, down);
		Fraction result(up / q, down / q);
		return result;
	}

	Fraction operator-(Fraction other) {

		int up = ((numerator_ * other.denominator_) - (denominator_ * other.numerator_));
		int down = other.denominator_ * denominator_;
		int q = std::gcd(up, down);
		Fraction result(up / q, down / q);
		return result;
	}

	Fraction operator*(Fraction other) {

		int up = numerator_ * other.numerator_;
		int down = other.denominator_ * denominator_;
		int q = std::gcd(up, down);
		Fraction result(up / q, down / q);
		return result;
	}

	Fraction operator/(Fraction other) {

		int up = numerator_ * other.denominator_;
		int down = denominator_ * other.numerator_;
		int q = std::gcd(up, down);
		Fraction result(up / q, down / q);
		return result;
	}

	Fraction& operator++() { 
		++this->numerator_ * denominator_;
		return *this; }

	/*Fraction operator--()
	{
		Fraction temp = *this;
		(*this)--;
		return temp;
	}*/

	//Fraction operator--(int) { return *this; }
	
	/*Fraction operator--(int)
	{
		Fraction temp = *this;
		(*this)--;
		return temp;
	}*/

	// Дружественная функция для перегрузки оператора <<
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

// Реализация функции перегрузки оператора <<
std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
	out << fraction.numerator_ << "/" << fraction.denominator_;
	return out;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	int numerator_1 = 0;
	int denominator_1 = 0;
	int numerator_2 = 0;
	int denominator_2 = 0;

	std::cout << "Введите числитель дроби 1: ";
	std::cin >> numerator_1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> denominator_1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> numerator_2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> denominator_2;

	Fraction f1(numerator_1, denominator_1);
	Fraction f2(numerator_2, denominator_2);
	Fraction f3 = f1 + f2;
	Fraction f4 = f1 - f2;
	Fraction f5 = f1 * f2;
	Fraction f6 = f1 / f2;
	Fraction inc_pre = ++f1 * f2;
	//Fraction dec_post = f1-- * f2;
	 
	std::cout << numerator_1 << "/" << denominator_1 << " + " << numerator_2 << "/" << denominator_2 << " = " << f3 << std::endl;
	std::cout << numerator_1 << "/" << denominator_1 << " - " << numerator_2 << "/" << denominator_2 << " = " << f4 << std::endl;
	std::cout << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << f5 << std::endl;
	std::cout << numerator_1 << "/" << denominator_1 << " / " << numerator_2 << "/" << denominator_2 << " = " << f6 << std::endl;
	std::cout << "++" << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << inc_pre << std::endl;
	std::cout << "Значение дроби 1 = " << std::endl;
	//std::cout << numerator_1 << "/" << denominator_1 << "--" << " * " << numerator_2 << "/" << denominator_2 << " = " << dec_post << std::endl;
	std::cout << "Значение дроби 1 = " << std::endl;
	return 0;
}



/*
Задача 2. Остальные операции с дробями
В этом задании вы переопределите остальные операторы для класса дроби.

Необходимо переопределить операторы для класса Fraction из предыдущего задания:

сложение;
вычитание;
умножение;
деление;
унарный минус;
инкремент постфиксный и префиксный;
декремент постфиксный и префиксный.
Продемонстрируйте работу ваших операторов. Попросите пользователя ввести две дроби и покажите результат каждой операции. Операции декремента и инкремента отнимают и прибавляют к дроби 1 соответственно.

Составьте выражения, содержащие постфиксный и префиксный инкремент и декремент, чтобы продемонстрировать разницу между постфиксной и префиксной версиями.

Пример работы программы
Консоль
Введите числитель дроби 1: 3
Введите знаменатель дроби 1: 4
Введите числитель дроби 2: 4
Введите знаменатель дроби 2: 5
3/4 + 4/5 = 31/20
3/4 - 4/5 = -1/20
3/4 * 4/5 = 3/5
3/4 / 4/5 = 15/16
++3/4 * 4/5 = 7/5
Значение дроби 1 = 7/4
7/4-- * 4/5 = 7/5
Значени дроби 1 = 3/4
Подсказки
Не читайте этот раздел сразу. Попытайтесь сначала решить задачу самостоятельно :)

Что использовать для решения.
Префиксная и постфиксная версии различаются фальшивым аргументом в постфиксной версии.

Не забудьте, что две версии ведут себя по-разному.

Не забудьте написать код, сокращающий дроби.
*/

