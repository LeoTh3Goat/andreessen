#include <iostream>

#include "http/Http.h"
#include "dom/Parser.h"
#include "layout/LayoutEngine.h"
#include "render/render.h"

int startApp() {

    Http http;
    std::string doc = http.entryPoint("andreessen.jackfischer.me");

    Parser parser;
    parser.parseHTML(doc);
   
    parser.root->print("","");
    std::cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
    
    std::map< std::string, std::map<std::string, std::string> > css = parser.css;
    for (auto iter : css) {
        std::map<std::string, std::string> s = iter.second;
        for (auto i : s) {
            std::cout<<"F: "<<iter.first<<" S: "<<i.first<<" E: "<<i.second<<'\n';
        }
    }
    std::cout<<"\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";

    LayoutEngine layout(parser.root, parser.css);
    layout.startLayout();
    // startBrowser(argc, argv, layout.toLayoutData());
    loadLayoutData(layout.toLayoutData());
    // std::cout << layout.toString();

    return 0;
}
