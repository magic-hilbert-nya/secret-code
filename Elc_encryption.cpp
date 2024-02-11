#include <iostream>
#include <deque>
#include <fstream>

#include "./Field.h"
#include "./Ellc.h"


// 定义ANSI转义序列
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"



std::fstream fieldatum("./test.csv");
Field tes_td(fieldatum);

int main()
{

	void pointSeek(int a,int b);
	void pointMult(Ellc x);

//	pointSeek(10000, 1000);

	Ellc p;
	pointMult(p);

	


}


void pointSeek(int a, int b)
{

	Ellc cal;

	for (int i = 0; i <= a; i++)
	{

		Field x;

		for (int res = i; res != 0;)
		{

			int j = 0, k = 0;

			for (int p = 1; p <= res; p = p * 2)
			{
				j = p;
				k++;

			}

			res = res - j;

			if (j != 0) { x.element[k - 1] = 1; }

		}

		x.printNum();

		for (int ii = 0; ii <= b; ii++)
		{

			Field y;


			for (int res = ii; res != 0;)
			{

				int j = 0, k = 0;

				for (int p = 1; p <= res; p = p * 2)
				{
					j = p;
					k++;

				}

				res = res - j;

				if (j != 0) { y.element[k - 1] = 1; }

			}

			if (ii % 100 == 0) { std::cout << ii << " "; }

			std::cout << ANSI_COLOR_GREEN;
			if (add_id == (y * y + x * y + x * x * x + cal.a_curve * x * x + cal.b_curve)) { y.printNum(); std::cout << "we find" << std::endl; }
			std::cout << ANSI_COLOR_RESET;

		}

	}


}

void pointMult(Ellc x)
{

	Ellc y=x;

	std::cout << std::endl << "basic point" << std::endl;
	y.coor_x.printNum();
	y.coor_y.printNum();
	std::cout << std::endl << "exponent on-goiong ......  " << std::endl;

	for (int i = 1; i <= 100; i++)
	{
		y = y + y;

		std::cout << std::endl << "table: " << i;

		y.coor_x.printNum();
		y.coor_y.printNum();

		if (y.Ellc_on())
		{

			// 设置输出字符的颜色
			std::cout << ANSI_COLOR_GREEN;


			std::cout << std::endl << "		point on the 'algebraic variety'  ECC_cal succeed。		" << std::endl;


			// 设置输出字符的颜色
			std::cout << ANSI_COLOR_RESET;

		}
		else
		{

			// 设置输出字符的颜色
			std::cout << ANSI_COLOR_RED;


			std::cout << std::endl << "		!!WARNING!!  Point Off!!   ECC Drop Out		" << std::endl;


			// 设置输出字符的颜色
			std::cout << ANSI_COLOR_RESET;

		}

		std::cout << std::endl << std::endl << std::endl;

	}


}




