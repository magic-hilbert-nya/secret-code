#ifndef Ecc
#define Ecc

#include <iostream>
#include <deque>
#include <fstream>
#include <vector>

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




void pointSeek(int a, int b)
{


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


		std::cout << std::endl;
		x.printNum();
		std::cout << std::endl;


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
			if (add_id == (y * y + x * y + x * x * x + a_curve * x * x + b_curve)) { {std::cout << std::endl; y.printNum(); std::cout << std::endl; } std::cout << "we find" << std::endl; }
			std::cout << ANSI_COLOR_RESET;

		}

	}


}

void pointMult(Ellc x)
{

	Ellc y = x;

	std::cout << std::endl << "basic point" << std::endl;
	
	std::cout << std::endl;
	y.coor_x.printNum();
	std::cout << std::endl;
	std::cout << std::endl;
	y.coor_y.printNum();
	std::cout << std::endl;

	std::cout << std::endl << "exponent on-goiong ......  " << std::endl;

	for (int i = 1; i <= 100; i++)
	{
		y = y + y;

		std::cout << std::endl << "table: " << i;

		std::cout << std::endl;
		y.coor_x.printNum();
		std::cout << std::endl;
		std::cout << std::endl;
		y.coor_y.printNum();
		std::cout << std::endl;


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

/*std::vector<std::vector<bool>> trans_1(std::vector<std::vector<bool>> input)
{

	for (int i = 0; i < input.size(); i++)
	{
		if()
	
	
	
	}







}*/

Field a_t(Field u_t)
{
	return u_t;
}

Field b_t(Field u_t)
{
	return u_t* u_t* u_t + a_curve * u_t * u_t + b_curve;
}

Field solveEqu(Field a, Field b)
{
	//	x^2+ax=b

	Field x[256];
	Field com_x;
	bool com_b;


	//std::cout << "table 1" << std::endl;

	for(int i=0;i<256;i++)
	{
		Field p;
		p.element[i] = 1;


		x[i]= p*p+a*p;
		
		//x[i].printNum();
		//std::cout << "  ----->  " << b.element[i] << "	----	" << "line " << i + 1;
		//std::cout << std::endl;
	}

	//std::cout << std::endl << std::endl << std::endl << "table 2" << std::endl;

	bool com_k;

	for (int i = 0; i < 256; i++)
	{
		for (int j = i; j < 256; j++) { com_k= x[i].element[j]; x[i].element[j] = x[j].element[i]; x[j].element[i] = com_k; }
		//std::cout << i << ' ';
	}


	//std::cout << std::endl << std::endl << std::endl << "table 3" << std::endl;

	

	for (int i = 0; i < 256; i++)
	{
		/*
		for (int j = 0, m = 0, n = 255; j < 256; j++)
		{
			if (m == n) { break; }
			else if (x[j].element[i])
			{
				com_x = x[j]; x[j] = x[m]; x[m] = com_x;
				com_b = b.element[j]; b.element[j] = b.element[m]; b.element[m] = com_b;
				m++; std::cout << "m is :" << m << std::endl;
			}
			else
			{
				com_x = x[j]; x[j] = x[n]; x[n] = com_x;
				com_b = b.element[j]; b.element[j] = b.element[n]; b.element[n] = com_b;
				n--; std::cout << "n is :" << n << std::endl;
			}
			//std::cout << "@" << j << "@";

		}
		*/
		for (int j = 0 + i; j < 256; j++)
		{
			
			if (x[j].element[i])
			{
				com_x = x[j]; x[j] = x[i]; x[i] = com_x;
				com_b = b.element[j]; b.element[j] = b.element[i]; b.element[i] = com_b;
				break;
			}
		
		}
		for (int j = 0; j < 256; j++)
		{
			if (j != i)
			{
				if (x[j].element[i]) { x[j] = x[j] + x[i]; b.element[j] = !(b.element[j] == b.element[i]); }
			}
			
		}
		//std::cout << "i is :" << i << std::endl;

		/*for (int k = 0; k < 256; k++)
		{


			x[k].printNum();
			std::cout << "  ----->  " << b.element[k] << "	----	" << "line " << k + 1;
			std::cout << std::endl;
		}*/
	}




	//std::cout << std::endl << std::endl << std::endl << "table 4" << std::endl;
	
	for (int i = 0; i < 256; i++)
	{
		

		//x[i].printNum();
		//std::cout << std::endl;
		//for (int j = 0; j < 256; j++) { std::cout << x[i].element[j]; }

		//std::cout << "  ----->  " << b.element[i] << "	----	" << "line " << i + 1;
		//std::cout << std::endl;
	}

	com_x = add_id;
	
	for (int i = 0; i < 256; i++) {
		if (b.element[i]) { com_x = com_x + x[i]; }
	}

	Ellc x_on_1(a,com_x);

	if (x_on_1.Ellc_on()) { return com_x; }
	else
	{
		for (int i = 1; i < 256; i++)
		{
			if (!x[i].element[i]) { com_x.element[i] = !com_x.element[i]; break; }
		}
	
	}

	Ellc x_on_2(a, com_x);

	if (!x_on_2.Ellc_on()) { std::cout << "		!!!!!warning!!!!!		" << std::endl; }

	return com_x;


}


#endif
