// My actaul XML Program.
//THIS IS NOT INTENDED TO BE SECURE, i.e., I wll NOT be using exceptions, though they are defined thanks to 
//tinyxml2's great work, as the rest of the program does not have exceptions.
#if defined( _MSC_VER )
#if !defined( _CRT_SECURE_NO_WARNINGS )
#define _CRT_SECURE_NO_WARNINGS		// This file is not intended to be secure.
#endif
#endif

#include "tinyxml2.h"
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace tinyxml2;
#include<iostream>
using namespace std;

int main()
{
	//static const char* xml = "<?xml version="1.0" encoding="UTF - 8"?>"
	int i = 0;
	XMLDocument doc;
	doc.LoadFile("result.xml");
	int check;
	check = doc.ErrorID();
	if (check != 0)
	{
		std::cout << "Document load failed. Aborting program.";
		system("exit");
	}
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
	XMLElement * pTournamentElement = NULL;
	while (pMatchElement != NULL && i < 11)
	{
		const char* schedule = pMatchElement->Attribute("scheduled");
		//cout << schedule << endl;
		pHomeElement = pMatchElement->FirstChildElement("home");
		pAwayElement = pMatchElement->FirstChildElement("away");
		pVenueElement = pMatchElement->FirstChildElement("venue");
		pTournamentElement = pMatchElement->FirstChildElement("tournament");
		i++;
		const char* text = pHomeElement->Attribute("name");
		const char* text1 = pAwayElement->Attribute("name");
		const char* venue = pVenueElement->Attribute("name");
		const char* tournament = pTournamentElement->Attribute("name");
		cout << text << " vs " << text1 << " at " << schedule << " in " << venue << " leaugue: " << tournament<<endl;
		system("pause");

		pMatchElement=pMatchElement->NextSiblingElement("match");
		if (pMatchElement == NULL)cout << "Error";
	}
		
	system("pause");
}
