#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#pragma comment(lib, "cpprest_2_10")

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

#include <iostream>
#include <ostream>
#include <string>
using namespace std;

#define TRACE(msg)            wcout << msg

void display_json(json::value const & jvalue)
{
    wcout << (jvalue.serialize()).c_str() << endl;
}

void handle_get(http_request request)
{
    TRACE("Processing request\n");
    const uri& address = request.request_uri();
    string path = utility::conversions::to_utf8string(address.path());
    TRACE(path.c_str() << endl);
    //
    auto myObj = json::value::object();
    myObj["one"] = json::value::string("HELLO");
    myObj["two"] = json::value::string("WORLD");

    auto array = json::value::array();
    array[0] = json::value::string("A");
    array[1] = json::value::string("B");
    array[2] = json::value::string("C");

    myObj["Array"] = array;

    display_json(myObj);
    //
    request.reply(status_codes::OK, "Hello World\n");
}

int main()
{
    auto address = uri("http://localhost:8023");
    http_listener listener(address);
    
    listener.support(methods::GET, handle_get);

    try
    {
        listener
            .open()
            .then([&listener]() {TRACE(L"\nstarting to listen\n"); })
            .wait();
        
        while (true);
    }
    catch (exception const & e)
    {
        cout << e.what() << endl;
    }

    return 0;
}