#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
class Element{
public:
    Element(std::string name);
    ~Element();
    void setUnderElement(Element* element) {_underElement = element; }
    Element* getUnderElement() { return _underElement; }
    void setName(std::string name){ _name = name; }
    std::string getName(){ return _name; }
private:
    Element* _underElement;
    std::string _name;
};
#endif