#ifndef ELLC
#define ELLC

#include <iostream>

#include "./Field.h"


#define a_curve a_cur
#define b_curve b_cur

#define base_coor_x basePoint_x
#define base_coor_y basePoint_y


class Ellc {

public:

	Field coor_x;
	Field coor_y;

	//群加法原点pt_O；
	bool pt_O;

public:
	Ellc();
	Ellc(Field x, Field y);


public:
	bool Ellc_on() const;//特殊函数，检验点是否在曲线上

public:
	Ellc operator=(const Ellc give);

	Ellc operator+(const Ellc x) const;
	Ellc operator*(const Ellc x) const;

};


Ellc::Ellc()
{

	coor_x = base_coor_x;

	coor_y = base_coor_y;

	bool inf = false;
	pt_O = inf;

}

Ellc::Ellc(Field x, Field y)
{
	
	coor_x = x;
	coor_y = y;

	bool inf = false;
	pt_O = inf;

}

//特殊函数，检验点是否在曲线上
bool Ellc::Ellc_on() const
{
	//椭圆曲线的方程为：$y^2+xy=x^3+ax^2+b$ over $F_{x^{256}$
	
	Field x = coor_y * coor_y + coor_x * coor_y + coor_x * coor_x * coor_x + a_curve * coor_x * coor_x + b_curve;

	
	if (x != add_id) { return false; }

	return true;
}

Ellc Ellc::operator=(const Ellc give)
{

	coor_x = give.coor_x;
	coor_y = give.coor_y;

	return *this;
}

Ellc Ellc::operator+(const Ellc x) const
{

	//  Elliptic Curve Equation: $ y^2+xy=x^3+ax^2+b$ over $F_{x^{256} $
	//  rmk: a_curve=a_cur,b_curve=b_cur。

//O:
	if (pt_O) { return x; }


	//A:
	else if (coor_x == x.coor_x && coor_y != x.coor_y) { Ellc y; y.pt_O = false; return y; }


	//B:
	else if (coor_x == x.coor_x && coor_y == x.coor_y)
	{
		//先看 " C:" 的计算比较好一点。

		//k=x+y/x
		Field k = coor_x + coor_y * coor_x.inverse();

		//return_x=k^2+k+a_curve
		Ellc y;
		y.coor_x = k * k + k + a_curve;
		//return_y=(k+1)*return_x+x^2
		y.coor_y = k * y.coor_x + y.coor_x + coor_x * coor_x;

		return y;
	}


	//C:
	else
	{
		//k=(y_1+y_2)/(x_1+x_2)
		Field k;
		k = (coor_y + x.coor_y) * ((coor_x + x.coor_x).inverse());

		//return_x=k^2+k+a_curve+(x_1+x_2)
		Ellc y;
		y.coor_x = k * k + k + a_curve + (coor_x + x.coor_x);
		//retur_y=k*(x_1+return_x)+return_x+y_1
		y.coor_y = k * (coor_x + y.coor_x) + y.coor_x + coor_y;

		return y;
	}







}




#endif
