#include"sport.h"
#include"readnba.h"
#include"dlnba.h"

#ifndef NBA_H
#define NBA_H

class nba : public sport
{
	int bball;
public:
	void page();
	nba()
	{
		strcpy_s(img, "Images//Pages//Basketball//Home.jpg");
		bball = initwindow(912, 682, "NBA Home");
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
	}
};

void nba::page()
{
	dlnba();
	setcurrentwindow(bball);
	xmlnba();
	while (!ismouseclick(WM_LBUTTONUP));
	getmouseclick(WM_LBUTTONUP, x, y);
	clearmouseclick(WM_LBUTTONUP);
	if (x >= 436 && y >= 596 && x <= 491 && y <= 668)	//back
	{
		closegraph(CURRENT_WINDOW);
		setcurrentwindow(hom);
	}
}

#endif