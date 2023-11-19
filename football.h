#include"sport.h"
#include"dlsoccer.h"
#include"readsoccer.h"

#ifndef FOOTBALL_H
#define FOOTBALL_H

class foot : public sport
{
	int cur;
public:
	void page();
	foot()
	{
		strcpy_s(img, "Images//Pages//Football//Home.jpg");
		cur = initwindow(911, 684, "Football");
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		x = y = -1;
	}
};

void foot::page()
{
	dlsoc();
	setcurrentwindow(cur);
	xmlsoc();
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