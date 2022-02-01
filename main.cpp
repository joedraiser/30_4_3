#include <iostream>
#include <cpr/cpr.h>

int main()
{
    cpr::Pair pair={"",""};
    std::vector<cpr::Pair> pairs;

    std::string URL="http://httpbin.org";

    while(true)
    {
        std::cout << "Input args and their value or type 'post' or 'get' to set corresponding request: ";
        std::cin >> pair.key;

        if(pair.key=="get"||pair.key=="post")
            break;

        std::cin >> pair.value;

        pairs.push_back(pair);
    }

    cpr::Response r;


    if(pair.key=="get")
    {
        URL=URL+"/get";
        if(!pairs.empty())
        {
            URL+='?';
            for(auto it=pairs.begin();it!=pairs.end();it++)
            {
                URL+=it->key+'='+it->value+'&';
            }
        }
        r = cpr::Get(cpr::Url(URL.c_str()));
        std::cout << r.text;
    }
    else if(pair.key=="post")
    {
        URL=URL+"/post";
        r = cpr::Post(cpr::Url(URL.c_str()), cpr::Payload(pairs.begin(), pairs.end()));
        std::cout << r.text;
    }

    return 0;
}