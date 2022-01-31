#include <iostream>
#include <cpr/cpr.h>

int main()
{
    std::string URL="http://httpbin.org", URL_args="", input[2];

    while(true)
    {
        std::cout << "Input args and their value or type 'post' or 'get' to set corresponding request: ";
        std::cin >> input[0];

        if(input[0]=="get"||input[0]=="post")
            break;

        std::cin >> input[1];

        if(URL_args.size()==0)
            URL_args='?'+input[0]+'='+input[1];
        else
            URL_args=URL_args+'&'+input[0]+'='+input[1];
    }

    cpr::Response r;

    if(input[0]=="get")
    {
        URL = URL + "/get" + URL_args;
        r = cpr::Get(cpr::Url(URL.c_str()));
        std::cout << r.text;
    }
    else if(input[0]=="post")
    {
        URL = URL + "/post" + URL_args;
        r = cpr::Post(cpr::Url(URL.c_str()));
        std::cout << r.text;
    }

    return 0;
}