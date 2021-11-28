#include<iostream>
using namespace std;
 
class Complex
{
public:
	Complex(double real,double image);
	void Print();
	bool operator==(const Complex &c);
	Complex& operator++();   //前置++
	Complex operator++(int); //后置++
	Complex& operator--();   //前置--
	Complex operator--(int); //后置--
	bool operator>(const Complex &c);
	Complex& operator=(const Complex &c);
	
	Complex operator+(const Complex &c); 
	Complex& operator+=(const Complex &c);
	Complex operator-(const Complex &c);
	Complex& operator-=(const Complex &c);
	Complex operator*(const Complex &c);
	Complex& operator*=(const Complex &c);
	Complex operator/(const Complex &c);
	Complex& operator/=(const Complex &c);
private:
	double _real;
	double _image;
};

Complex::Complex(double real=0.0,double image=0.0)  //构造函数
	:_real(real)
	,_image(image)
{}
 
void Complex::Print()
{
	if(_image == 0.0)   //虚部为0
	{
		cout<<_real<<endl;
	}
	else
	{
		cout<<_real<<"+"<<_image<<"*i"<<endl;
	}
}
 
Complex Complex::operator+(const Complex &c)
{
	Complex tmp;
	tmp._real=_real+c._real;
	tmp._image=_image+c._image;
	return tmp;
}
 
Complex Complex::operator-(const Complex &c)
{
	Complex tmp;
	tmp._real=_real-c._real;
	tmp._image=_image-c._image;
	return tmp;
}
 
Complex Complex::operator*(const Complex &c)
{
	Complex tmp;
	tmp._real=_real*c._real-_image*c._image;
	tmp._image=_real*c._image+_image*c._real;
	return tmp;
}
 
Complex Complex::operator/(const Complex &c)
{
	Complex tmp;
	double t=c._real*c._real+c._image*c._image;
	tmp._real=(_real*c._real-_image*(-c._image))/t;
	tmp._image=(_real*(-c._image)+_image*c._real)/t;
	return tmp;
 
}
 
Complex& Complex::operator+=(const Complex &c)
{
	_real+=c._real;
	_image+=c._image;
	return *this;
}
 
Complex& Complex::operator-=(const Complex &c)
{
	_real-=c._real;
	_image-=c._image;
	return *this;
}
 
Complex& Complex::operator*=(const Complex &c)
{
	Complex tmp(*this);  //拷贝构造函数
	_real=tmp._real*c._real-_image*c._image;
	_image=tmp._real*c._image+tmp._image*c._real;
	return *this;
}
 
Complex& Complex::operator/=(const Complex &c)
{
	Complex tmp(*this);
	double t=c._real*c._real+c._image*c._image;
	_real=(tmp._real*c._real-tmp._image*(-c._image))/t;
	_image=(tmp._real*(-c._image)+tmp._image*c._real)/t;
	return *this;
}
 
bool Complex::operator==(const Complex &c)
{
	return (_real == c._real)&&
		(_image == c._image);
}
 
Complex& Complex::operator++()  //前置++
{
	_real++;
	_image++;
	return *this;
}
 
Complex Complex::operator++(int) //后置++
{
	Complex tmp(*this);  //拷贝构造函数暂存this所指向的值
	_real++;
	_image++;
	return tmp;
}
 
Complex& Complex::operator--()   //前置--
{
	_real--;
	_image--;
	return *this;
}
 
Complex Complex::operator--(int) //后置--
{
	Complex tmp(*this);
	_real--;
	_image--;
	return tmp;
}
 
bool Complex::operator>(const Complex &c)
{
	return (_real > c._real)&&
		(_image > c._image);
}
 
Complex& Complex::operator=(const Complex &c)
{
	if(this != &c)
	{
		_real=c._real;
		_image=c._image;
	}
	return *this;
}