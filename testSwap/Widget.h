#pragma once
#include <iostream>
struct WidgetImpl
{
	int a;
};
class Widget
{
private:
	WidgetImpl* pImpl;
public:
	Widget(const Widget& rhs);
	Widget(int a);
	
	~Widget();
	void swap(Widget& other);
};

