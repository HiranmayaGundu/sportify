#include"home.h"
#include"register.h"

#ifndef LOGIN_H
#define LOGIN_H

class login : public account
{
	char textstring[20];
	void check();			//to check for login
	void getuser();			//inpput username
	void getpassword();		//input password
	bool white(char);		//to check for white spaces
	void error();			//to check which error
public:
	void signin();		//graphic window	
	login()
	{
		textstring[0] = '\0';
		strcpy_s(img, "Images\\Pages\\Account\\login.jpg");		//background
		allok = 1;
	}
};

void login::signin()
{
	initwindow(914, 683, "Signin");					//new window opens
	readimagefile(img, 0, 0, getmaxx(), getmaxy());
	while (allok)			//to check for signin
	{
		//clicks
		while (!ismouseclick(WM_LBUTTONUP));
		getmouseclick(WM_LBUTTONUP, x, y);
		clearmouseclick(WM_LBUTTONUP);
		if (x >= 345 && y >= 360 && x <= 640 && y <= 400)
			getuser();		//username
		else if (x >= 345 && y >= 460 && x <= 640 && y <= 500)
			getpassword();	//password
		else if (x >= 420 && y >= 520 && x <= 510 && y <= 550)
			check();		//sign in
		else if (x >= 430 && y >= 600 && x <= 490 && y <= 670)
		{
			closegraph();	//back
			allok = 0;
		}
	}
}

void login::getuser()
{
	int i = 0, ch = 0;
	//Text Styling
	setusercharsize(1, 2, 1, 2);
	settextstyle(4, HORIZ_DIR, 0);
	//text onto graphic window
	while (1)
	{
		ch = getch();
		if (ch == 8)	//Backspace
		{
			i--;
			textstring[i] = '\0';
		}
		else if (white(ch))
			break;
		else            //Accept Text
		{
			textstring[i] = ch;
			++i;
			textstring[i] = '\0';
		}
		cleardevice();
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		outtextxy(355, 370, textstring);
	}
	strcpy_s(current.username, textstring);
}

void login::getpassword()
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
			textstring[i] = '\0';
		}
		else if (white(ch))
			break;
		else           //Accept Text
		{
			textstring[i] = ch;
			++i;
			textstring[i] = '\0';
		}
		cleardevice();
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		outtextxy(355, 370, current.username);
		setfillstyle(SOLID_FILL, WHITE);
		for (int j = 0; j < i; ++j)
		{
			circle(365 + (20 * j), 485, 8);
			floodfill(360 + (20 * j), 485, WHITE);
		}
	}
	strcpy_s(current.password, textstring);
}

void login::check()
{
	bool chk = 0;		//1 if login success
	detail temp;
	std::fstream f("users.dat", std::ios::in | std::ios::binary);
	while (f.read((char*)&temp, sizeof(detail)) && !chk)
	{
		if (!strcmp(temp.username, current.username))		//if username exists
		{
			if (!strcmp(temp.password, current.password))	//passwords match
			{
				allok = 0;
				chk = 1;
			}
			else 
				allok = 2;		
		}
		else 
			allok = 1;
	}
	f.close();
	error();
	allok = 0;		//to break while loop
}

bool login::white(char x)
{
	if (x == 0 || x == 7 || x == 8 || x == 9 || x == 10 || x == 13 || x == 32 || x == 255)
		return 1;
	else
		return 0;
}

void login::error()
{
	home h;
	reg r1;
	switch (allok)
	{
	case 0://login successful
		closegraph(CURRENT_WINDOW);
		h.acchome();
		break;
	case 1://username does not exist
		initwindow(912, 682, "Error!");
		strcpy_s(img, "Images\\Pages\\Account\\usernoexist.jpg");
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		//clicks
		while (!ismouseclick(WM_LBUTTONUP));
		getmouseclick(WM_LBUTTONUP, x, y);
		clearmouseclick(WM_LBUTTONUP);
		if (x >= 435 && y >= 595 && x <= 493 && y <= 670)		//back
			closegraph();
		else if (x >= 400 && y >= 460 && x <= 525 && y <= 505)	//signup
			r1.signup();
		break;
	case 2://password is wrong
		initwindow(913, 678, "Error!");
		strcpy_s(img, "Images\\Pages\\Account\\passnomatch.jpg");
		readimagefile(img, 0, 0, getmaxx(), getmaxy());
		while (!ismouseclick(WM_LBUTTONUP));
		getmouseclick(WM_LBUTTONUP, x, y);
		clearmouseclick(WM_LBUTTONUP);
		if (x >= 435 && y >= 595 && x <= 493 && y <= 670)	//back
			closegraph();
		break;
	}
}

#endif