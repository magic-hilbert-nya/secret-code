#ifndef FIELD
#define FIELD

#include <iostream>
#include <deque>
#include<fstream>


class Field {

public:

	std::deque<bool> element;


public:
	Field();
	Field(const int x);
	Field(std::fstream& c_in);

	Field operator=(const Field give);

	Field operator+(const Field x) const;
	Field operator*(const Field x) const;

	bool operator==(const Field x) const;
	bool operator!=(const Field y) const;

	Field inverse() const;


	void printMat() const;
	void printNum() const;

};

const Field add_id;
const Field mult_id(1);

Field::Field()
{

	for (int i = 0; i < 256; i++) { element.push_back(0); }

}

Field::Field(const int x)
{
	if (x == 1)
	{
		element.push_back(1);

		for (int i = 0; i < 255; i++) { element.push_back(0); }
	}

}

Field::Field(std::fstream& c_in)
{

	for (int i = 0; i < 256; i++)
	{
		char c_in_result;
		c_in >> c_in_result;
		if (c_in_result == '0') { element.push_back(0); }
		else { element.push_back(1); }

		c_in >> c_in_result;

	}

}

Field Field::operator=(const Field give)
{

	for (int i = 0; i < 256; i++) { element[i] = give.element[i]; }
	return *this;

}

Field Field::operator+(const Field x) const
{
	Field y;

	for (int i = 0; i <= 255; i++)
	{
		if (x.element[i] == element[i]) { y.element[i] = 0; }
		else { y.element[i] = 1; }

	}

	return y;

}

Field Field::operator*(Field x) const
{

	bool mdz[512] = {};

	for (int i = 0; i <= 255; i++)
	{



		for (int j = 0; j <= 255; j++)
		{
			bool add[256];


			if (x.element[i] == 1 && element[j] == 1) { add[j] = 1; }
			else { add[j] = 0; }


			if (mdz[i + j] == add[j]) { mdz[i + j] = 0; }
			else { mdz[i + j] = 1; }


		}


	}





	for (int i = 511; i >= 256; i--)
	{
		if (mdz[i] == 0) { ; }
		else
		{
			mdz[i] = 0, mdz[i - 15] = !mdz[i - 15], mdz[i - 78] = !mdz[i - 78],
				mdz[i - 135] = !mdz[i - 135], mdz[i - 256] = !mdz[i - 256];

		}


	}

	Field y;

	for (int i = 0; i <= 255; i++)
	{
		y.element[i] = mdz[i];
	}

	return y;

}

bool Field::operator==(const Field x) const
{
	for (int i = 0; i <= 255; i++) 
	{
		if (element[i] != x.element[i]) return false;
	}

	return true;
}

bool Field::operator!=(const Field x) const
{
	
	return !(*this == x);

}

Field Field::inverse() const
{
	Field y(1);
	Field sum = *this;

	for (int i = 1; i <= 255; i++)
	{

		sum = sum * sum;

		y = y * sum;


	}

	return y;
}

void Field::printMat() const
{

	for (int i = 0; i < 256; i++)
	{

		if (i % 32 == 0) { std::cout << std::endl << this->element[i]; }
		else { std::cout << this->element[i]; }

	}

	std::cout << std::endl;


}

void Field::printNum() const
{
	
	std::cout << std::endl;
	

	for (int i = 8; i >= 2; i--)
	{

		for (int j = 8; j >= 1; j--)
		{

			int k = (int)element[32 * i - 32 + 4 * j - 4] + 2 * (int)element[32 * i - 32 + 4 * j - 3] + 4 * (int)element[32 * i - 32 + 4 * j - 2] + 8 * (int)element[32 * i - 32 + 4 * j - 1];

			if (k == 0) { std::cout << '0'; }
			else if (k == 1) { std::cout << '1'; }
			else if (k == 2) { std::cout << '2'; }
			else if (k == 3) { std::cout << '3'; }
			else if (k == 4) { std::cout << '4'; }
			else if (k == 5) { std::cout << '5'; }
			else if (k == 6) { std::cout << '6'; }
			else if (k == 7) { std::cout << '7'; }
			else if (k == 8) { std::cout << '8'; }
			else if (k == 9) { std::cout << '9'; }
			else if (k == 10) { std::cout << 'A'; }
			else if (k == 11) { std::cout << 'B'; }
			else if (k == 12) { std::cout << 'C'; }
			else if (k == 13) { std::cout << 'D'; }
			else if (k == 14) { std::cout << 'E'; }
			else if (k == 15) { std::cout << 'F'; }
		

		}

		std::cout << ' ';

	}

	//特例。单独取出，去掉最后一个' '键。
	for (int i = 1; i >= 1; i--)
	{

		for (int j = 8; j >= 1; j--)
		{

			int k = (int)element[32 * i - 32 + 4 * j - 4] + 2 * (int)element[32 * i - 32 + 4 * j - 3] + 4 * (int)element[32 * i - 32 + 4 * j - 2] + 8 * (int)element[32 * i - 32 + 4 * j - 1];

			if (k == 0) { std::cout << '0'; }
			else if (k == 1) { std::cout << '1'; }
			else if (k == 2) { std::cout << '2'; }
			else if (k == 3) { std::cout << '3'; }
			else if (k == 4) { std::cout << '4'; }
			else if (k == 5) { std::cout << '5'; }
			else if (k == 6) { std::cout << '6'; }
			else if (k == 7) { std::cout << '7'; }
			else if (k == 8) { std::cout << '8'; }
			else if (k == 9) { std::cout << '9'; }
			else if (k == 10) { std::cout << 'A'; }
			else if (k == 11) { std::cout << 'B'; }
			else if (k == 12) { std::cout << 'C'; }
			else if (k == 13) { std::cout << 'D'; }
			else if (k == 14) { std::cout << 'E'; }
			else if (k == 15) { std::cout << 'F'; }
			

		}


	}

	std::cout << std::endl;

}

#endif
