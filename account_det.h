#include<fstream>
#include<string.h>
#include"graphics.h"

#ifndef ACCOUNT_DET_H
#define ACCOUNT_DET_H

struct detail		//Account Details
{
	char username[20], password[20];
};

class account
{
protected:
	int x, y;
	static int hom;
	char img[40];		//Background Image
	detail current;		//current account
	int allok;			//login successful/unsuccessful
	/*----------------------------
	allok references
	+2 - password wrong
	+1 - username does not exist
	 0 - everything ok
	-1 - username taken
	-2 - passwords do not match
	-------------------------------*/
	void infile()		//to input into file
	{
		std::ofstream f("Data//users.dat", std::ios::binary | std::ios::app);
		//f.seekg(0, std::ios_base::end);
		f.write((char*)&current, sizeof(current));
		f.close();
	}
public:
	account()
	{
		x = y = -1;
		img[0] = current.username[0] = current.password[0] = '\0';		
		allok = 3;
	}
};

#endif