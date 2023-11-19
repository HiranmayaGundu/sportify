#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include<iostream>
#include<string>
//using namespace std;
using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams
char * url = "http://api.sportsdatallc.org/soccer-t2/eu/matches/2014/03/01/summary.xml?api_key=m665dmrqynqn4t9r4vdxp2c7";
std::string s = "http://api.sportsdatallc.org/soccer-t2/eu/matches/2014/03/01/summary.xml?api_key=m665dmrqynqn4t9r4vdxp2c7";
int main(int argc, char* argv[])
{
	//auto fileStream = std::make_shared<ostream>();

	// Open a stream to the file to write the HTTP response body into.
	auto fileBuffer = std::make_shared<streambuf<uint8_t>>();
	return file_buffer<uint8_t>::open(L"resultNBA.xml", std::ios::out).then([=](streambuf<uint8_t> outFile) -> pplx::task<http_response>
	{
		*fileBuffer = outFile;

		// Create an HTTP request.
		http_client client(U("http://api.sportsdatallc.org/nba-t3/games/2014/REG/schedule.xml?api_key=kqx57brpa9bgy2p2tgw23suc") );
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
		return fileBuffer->close();
	}).wait();
	system("pause");
	return 0;
}