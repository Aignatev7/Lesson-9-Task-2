#include <iostream>

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

	int operator*(Fraction other) {
		if (denominator_ == other.denominator_) {
			return denominator_;
		}
		else {
			return denominator_ * other.denominator_;
		}
	}
	int operator/(Fraction other) {
		if (denominator_ == other.denominator_) {
			return numerator_ / other.numerator_;
		}
		else {
			return denominator_ * other.denominator_;
		}
	}
	int operator+(Fraction other) {
		if (denominator_ == other.denominator_) {
			return numerator_ + other.numerator_;
		}
		else {
			return ((numerator_ * other.denominator_) + (denominator_ * other.numerator_));
		}
	}
	int operator-(Fraction other) {
		if (denominator_ == other.denominator_) {
			return numerator_ - other.numerator_;
		}
		else {
			return ((numerator_ * other.denominator_) - (denominator_ * other.numerator_));
		}
	}
	};

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

		std::cout << numerator_1 << "/" << denominator_1 << " + " << numerator_2 << "/" << denominator_2 << " = " << f1 + f2 << "/" << f1 * f2 << std::endl;
		std::cout << numerator_1 << "/" << denominator_1 << " - " << numerator_2 << "/" << denominator_2 << " = " << f1 - f2 << "/" << f1 * f2 << std::endl;
		std::cout << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << f1 * f2 << "/" << f1 * f2 << std::endl;
		std::cout << numerator_1 << "/" << denominator_1 << " / " << numerator_2 << "/" << denominator_2 << " = " << f1 / f2 << "/" << f1 * f2 << std::endl;
		std::cout << "++" << numerator_1 << "/" << denominator_1 << " * " << numerator_2 << "/" << denominator_2 << " = " << std::endl;
		std::cout << "�������� ����� 1 = ";

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