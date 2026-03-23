#include <iostream>
#include <vector>

class Names {
protected:
        std::vector<std::string> names;
        
public:
    Names(){};
    Names(const std::string& name_i): names{name_i}{};

    virtual ~Names(){};

    void addName(std::string& name);
    void removeName(const std::string& name);

    void showNames();
};