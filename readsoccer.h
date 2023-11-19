#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
#define _CRT_SECURE_NO_WARNINGS		
#endif
#endif

#include "graphics.h"
#include "tinyxml2.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace tinyxml2;
#include<iostream>
using namespace std;

#ifndef READSOCCER_H
#define READSOCCER_H

void sdatetime(char buffer[25])
{
	time_t rawtime;
	struct tm * timeinfo;
	time(&rawtime);
	timeinfo = localtime(&rawtime);
	strftime(buffer, 80, "%Y-%m-%dT%I:%M:%SZ", timeinfo);
}

void xmlsoc()
{
	int i = 0;
	char buf[25];
	sdatetime(buf);
	tinyxml2::XMLDocument doc;
	doc.LoadFile("resultFOOT.xml");
	int check;
	check = doc.ErrorID();
	if (check != 0)
		std::cout << "Document load failed.";
	XMLNode * pRoot = doc.FirstChild();
	if (pRoot == NULL)
		cout << "ERROR";
	XMLElement * pMatchesElement = doc.FirstChildElement();
	if (pMatchesElement == NULL)
		cout << "ERROR2";
	XMLElement * pIDKElement = pMatchesElement->FirstChildElement();
	if (pIDKElement == NULL)
		cout << "ERROR3";
	XMLElement * pMatchElement = pIDKElement->FirstChildElement("match");
	XMLElement * pHomeElement = NULL;
	XMLElement * pAwayElement = NULL;
	XMLElement * pVenueElement = NULL;
	XMLElement * pCategoryElement = NULL;
	while (pMatchElement != NULL && i < 10)
	{
		//const char* status = pMatchElement->Attribute("status");
		const char* schedule = pMatchElement->Attribute("scheduled");
		if (/*!strcmp(status, "scheduled") && */strcmp(schedule, buf) == 1)
		{
			pHomeElement = pMatchElement->FirstChildElement("home");
			pAwayElement = pMatchElement->FirstChildElement("away");
			pVenueElement = pMatchElement->FirstChildElement("venue");
			pCategoryElement = pMatchElement->FirstChildElement("category");
			const char* text = pHomeElement->Attribute("alias");
			const char* text1 = pAwayElement->Attribute("alias");
			const char* venue = pVenueElement->Attribute("city");
			const char* category = pCategoryElement->Attribute("name");
			//Text Styling
			setusercharsize(1, 2, 1, 2);
			settextstyle(4, HORIZ_DIR, 0);
			setbkcolor(COLOR(0, 144, 0));
			outtextxy(33, 233 + 37 * i, (char*)text);
			outtextxy(125, 233 + 37 * i, (char*)text1);
			outtextxy(266, 233 + 37 * i, (char*)venue);
			outtextxy(469, 233 + 37 * i, (char*)schedule);
			outtextxy(727, 233 + 37 * i, (char*)category);
			i++;
		}
		pMatchElement = pMatchElement->NextSiblingElement("match");
	}
}

#endif