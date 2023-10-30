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
		
		return *this; }
	Fraction operator--()
	{
		Fraction temp = *this;
		(*this)--;
		return temp;
	}

	Fraction operator++(int) { return *this; }
	Fraction operator--(int)
	{
		Fraction temp = *this;
		(*this)--;
		return temp;
	}

	// ������������� ������� ��� ���������� ��������� <<
	friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
};

// ���������� ������� ���������� ��������� <<
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

	std::cout << "������� ��������� ����� 1: ";
	std::cin >> numerator_1;
	std::cout << "������� ����������� ����� 1: ";
	std::cin >> denominator_1;
	std::cout << "������� ��������� ����� 2: ";
	std::cin >> numerator_2;
	std::cout << "������� ����������� ����� 2: ";
	std::cin >> denominator_2;

	Fraction f1(numerator_1, denominator_1);
	Fraction f2(numerator_2, denominator_2);
	Fraction f3 = f1 + f2;
	Fraction f4 = f1 - f2;
	Fraction f5 = f1 * f2;
	Fraction f6 = f1 / f2;
	Fraction sum_pre = ++f1 + f2;
	Fraction sum_post = f1++ + f2;
	 
	std::cout << numerator_1 << "/" << denominator_1 << " + " << numerator_2 << "/" << denominator_2 << " = " << f3 << std::endl;
	std::cout << numerator_1 << "/" << denominator_1 << " - " << numerator_2 << "/" << denominator_2 << " = " << f4 << std::endl;
	std::cout << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << f5 << std::endl;
	std::cout << numerator_1 << "/" << denominator_1 << " / " << numerator_2 << "/" << denominator_2 << " = " << f6 << std::endl;
	std::cout << "++" << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << sum_pre << std::endl;
	std::cout << "�������� ����� 1 = " << std::endl;
	std::cout << numerator_1 << "/" << denominator_1 << "--" << " * " << numerator_2 << "/" << denominator_2 << " = " << sum_post << std::endl;
	std::cout << "�������� ����� 1 = " << std::endl;
	return 0;
}



/*
������ 2. ��������� �������� � �������
� ���� ������� �� �������������� ��������� ��������� ��� ������ �����.

���������� �������������� ��������� ��� ������ Fraction �� ����������� �������:

��������;
���������;
���������;
�������;
������� �����;
��������� ����������� � ����������;
��������� ����������� � ����������.
����������������� ������ ����� ����������. ��������� ������������ ������ ��� ����� � �������� ��������� ������ ��������. �������� ���������� � ���������� �������� � ���������� � ����� 1 ��������������.

��������� ���������, ���������� ����������� � ���������� ��������� � ���������, ����� ������������������ ������� ����� ����������� � ���������� ��������.

������ ������ ���������
�������
������� ��������� ����� 1: 3
������� ����������� ����� 1: 4
������� ��������� ����� 2: 4
������� ����������� ����� 2: 5
3/4 + 4/5 = 31/20
3/4 - 4/5 = -1/20
3/4 * 4/5 = 3/5
3/4 / 4/5 = 15/16
++3/4 * 4/5 = 7/5
�������� ����� 1 = 7/4
7/4-- * 4/5 = 7/5
������� ����� 1 = 3/4
���������
�� ������� ���� ������ �����. ����������� ������� ������ ������ �������������� :)

��� ������������ ��� �������.
���������� � ����������� ������ ����������� ��������� ���������� � ����������� ������.

�� ��������, ��� ��� ������ ����� ���� ��-�������.

�� �������� �������� ���, ����������� �����.
*/

