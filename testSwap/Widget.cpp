#include "Widget.h"



Widget::Widget(const Widget & rhs)
{
	pImpl = rhs.pImpl;
}

Widget::Widget(int a)
{
	pImpl = new WidgetImpl;
	pImpl->a = a;
}


Widget::~Widget()
{
	delete pImpl;
}


void Widget::swap(Widget& other)
{
	using std::swap;
	swap(pImpl, other.pImpl);
}
