#include"football.h"
#include"nba.h"

#ifndef HOME_H
#define HOME_H

class home : public account
{
	sport *s;
public:
	home()
	{
		s = NULL;
		strcpy_s(img, "Images\\Pages\\Account\\Home.jpg");
	}
	void acchome();
};

void home::acchome()
{
	hom = initwindow(910, 683, "Home");
	readimagefile(img, 0, 0, getmaxx(), getmaxy());
	while (1)
	{
		s = NULL;
		while (!ismouseclick(WM_LBUTTONUP));
		getmouseclick(WM_LBUTTONUP, x, y);
		clearmouseclick(WM_LBUTTONUP);
		if (x >= 404 && y >= 237 && x <= 527 && y <= 272)		//football
			s = new foot;
		else if (x >= 391 && y >= 323 && x <= 539 && y <= 356)	//baseball
			s = new nba;
		if (s)
			s->page();
		else if (x >= 396 && y >= 407 && x <= 536 && y <= 446)	//sign out
			break;
	}
	closegraph(ALL_WINDOWS);
}

#endif