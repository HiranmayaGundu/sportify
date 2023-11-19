#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include<iostream>
#include<string>
#include"graphics.h"
//using namespace std;
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

#ifndef DLSOCCER_H
#define DLSOCCER_H

int dlsoc()
{
	initwindow(912, 681, "Football");
	readimagefile("Images//Pages//Football//dlfoot.jpg", 0, 0, getmaxx(), getmaxy());
	//char * url = "http://api.sportsdatallc.org/soccer-t2/eu/matches/2014/03/01/summary.xml?api_key=m665dmrqynqn4t9r4vdxp2c7";
	//std::string s = "http://api.sportsdatallc.org/soccer-t2/eu/matches/2014/03/01/summary.xml?api_key=m665dmrqynqn4t9r4vdxp2c7";

	//auto fileStream = std::make_shared<ostream>();

	// Open a stream to the file to write the HTTP response body into.
	auto fileBuffer = std::make_shared<concurrency::streams::streambuf<uint8_t>>();
	return file_buffer<uint8_t>::open(L"resultFOOT.xml", std::ios::out).then([=](concurrency::streams::streambuf<uint8_t> outFile) -> pplx::task<http_response>
	{
		*fileBuffer = outFile;

		// Create an HTTP request.
		http_client client(U("http://api.sportsdatallc.org/soccer-t2/eu/matches/schedule.xml?api_key=m665dmrqynqn4t9r4vdxp2c7") );
		return client.request(methods::GET);
	})
		// Write the response body into the file buffer.
		.then([=](http_response response) -> pplx::task<size_t>
	{
		std::cout<<"Response status code %u returned.\n"<< response.status_code();
		return response.body().read_to_end(*fileBuffer);
	})
		// Close the file buffer.
		.then([=](size_t datasize)
	{
		std::cout << datasize;
		closegraph(CURRENT_WINDOW);
		return fileBuffer->close();
	}).wait();
	return 0;
}

#endif