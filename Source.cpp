#include "login.h"
#include "register.h"

int account::hom = -6;

int main()
{
	int x, y;
	bool e = 0;		//Exit
	login l;
	reg r;
	initwindow(913, 682, "Welcome");
	readimagefile("Images\\Pages\\Account\\splash.jpg", 0, 0, getmaxx(), getmaxy());	//Background
	//clicks
	while (!ismouseclick(WM_LBUTTONUP));
	getmouseclick(WM_LBUTTONUP, x, y);
	clearmouseclick(WM_LBUTTONUP);
	if (x >= 388 && y >= 348 && x <= 545 && y <= 408)
		r.signup();		//register page
	else if (x >= 390 && y >= 251 && x <= 534 && y <= 314)
		l.signin();		//login page
	else if (x >= 440 && y >= 440 && x <= 490 && y <= 470)
		e = 1;
	if (!e)
		main();
	else
		closegraph();
}