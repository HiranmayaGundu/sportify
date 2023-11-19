#include"account_det.h"		//base class

#ifndef REGISTER_H
#define REGISTER_H

class reg : public account
{
	int len, cur;				//string length, current window
	char X[20], text[40];		//confirm pass
	void getusername();			//username input
	void getpass();				//password input
	void getconfirmpass();		//confirm password
	void check();				//check for password match
	bool white(char);			//to check for white spaces
	void error();				//to check which error
public:
	void signup();				//to signup
	reg()
	{
		len = 0;
		cur = -6;
		text[0] = X[0] = '\0';
		strcpy_s(img, "Images\\Pages\\Account\\register.jpg");		//background
		allok = 1;		
	}
};

void reg::signup()		
{	
	cur = initwindow(912, 684, "Register");			//new window opens
	readimagefile(img, 0, 0, getmaxx(), getmaxy());
	while (allok)
	{
		//clicks
		while (!ismouseclick(WM_LBUTTONUP));
		getmouseclick(WM_LBUTTONUP, x, y);
		clearmouseclick(WM_LBUTTONUP);
		if (x >= 334 && y >= 291 && x <= 628 && y <= 331)
			getusername();			//input username
		else if (x >= 334 && y >= 373 && x <= 628 && y <= 414)
			getpass();				//input password
		else if (x >= 334 && y >= 457 && x <= 628 && y <= 499)
			getconfirmpass();		//Confirmation of Password
		else if (x >= 410 && y >= 535 && x <= 523 && y <= 568)
			check();				//check for availiblity
		else if (x >= 435 && y >= 595 && x <= 493 && y <= 670)
		{
			closegraph();		//control returned to main function
			allok = 0;
		}
	}		
}

void reg::getusername()
{
	int i = 0, ch = 0;
	//Text styling
	setusercharsize(1, 2, 1, 2);
	settextstyle(4, HORIZ_DIR, 0);
	//Text onto graphic window
	while (1)
	{
		ch = getch();
		if (ch == 8)	//Backspace
		{
			i--;
			text[i] = '\0';
		}
		else if (white(ch))
			break;
		else            //Accept Text
		{
			text[i] = ch;
			++i;
			text[i] = '\0';
		}
		cleardevice();
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		outtextxy(341, 298, text);
	}
	strcpy_s(current.username, text);
}

void reg::getpass()
{
	int i = 0, ch = 0;
	//text styling
	setusercharsize(1, 2, 1, 2);
	settextstyle(4, HORIZ_DIR, 0);
	//Graphic response
	while (1)
	{
		ch = getch();
		if (ch == 8)	//Backspace
		{
			i--;
			text[i] = '\0';
		}
		else if (white(ch))
			break;
		else            //Accept Text
		{
			text[i] = ch;
			++i;
			text[i] = '\0';
		}
		cleardevice();
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		outtextxy(341, 298, current.username);
		setfillstyle(SOLID_FILL, WHITE);
		for (int j = 0; j < i; ++j)
		{			
			circle(350 + (20 * j), 390, 8);
			floodfill(350 + (20 * j), 390, WHITE);
		}
	}
	len = i;
	strcpy_s(current.password, text);
}

void reg::getconfirmpass()
{
	int i = 0, ch = 0;
	//Text Styling
	setusercharsize(1, 2, 1, 2);
	settextstyle(4, HORIZ_DIR, 0);
	//Graphic Response
	while (1)
	{
		ch = getch();
		if (ch == 8)	//Backspace
		{
			i--;
			text[i] = '\0';
		}
		else if (white(ch))
			break;
		else            //Accept Text
		{
			text[i] = ch;
			++i;
			text[i] = '\0';
		}
		cleardevice();
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		outtextxy(341, 298, current.username);
		setfillstyle(SOLID_FILL, WHITE);
		for (int j = 0; j < len; ++j)
		{
			circle(350 + (20 * j), 390, 8);
			floodfill(350 + (20 * j), 390, WHITE);
		}
		for (int j = 0; j < i; ++j)
		{
			circle(350 + (20 * j), 480, 8);
			floodfill(350 + (20 * j), 480, WHITE);
		}
	}
	strcpy_s(X, text);
}

void reg::check()
{
	allok = 0;		//Assuming everything is alright
	std::fstream f("users.dat", std::ios::in | std::ios::binary);
	detail acc;
	while (f)
	{
		f.read((char*)&acc, sizeof(detail));
		if (!strcmp(current.username, acc.username))			//username taken
			allok = -1;
		else if (strcmp(current.password, X))					//passwords don't match
			allok = -2;
	}
	f.close();
	error();
	allok = 0;		//to break out of while loop
}

bool reg::white(char x)
{
	if (x == 0 || x == 7 || x == 8 || x == 9 || x == 10 || x == 13 || x == 32 || x == 255)
		return 1;
	else
		return 0;
}

void reg::error()
{
	switch (allok)
	{
	case -1://username taken
		initwindow(911, 683, "Error!");
		strcpy_s(img, "Images\\Pages\\Account\\usertaken.jpg");
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		break;
	case -2://passwords dont match
		initwindow(913, 678, "Error!");
		strcpy_s(img, "Images\\Pages\\Account\\passnomatch.jpg");
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		break;
	case 0://Registered!
		infile();
		initwindow(906, 682, "Registered!");
		strcpy_s(img, "Images\\Pages\\Account\\registerd.jpg");
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
	}
	//clicks
	while (!ismouseclick(WM_LBUTTONUP));
	getmouseclick(WM_LBUTTONUP, x, y);
	clearmouseclick(WM_LBUTTONUP);
	if (x >= 435 && y >= 595 && x <= 493 && y <= 670)	//back
		closegraph();		
}

#endif