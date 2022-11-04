#ifndef ELEMENT_H
#define ELEMENT_H
#include <string>
class Element{
public:
    Element(std::string fileName);
    virtual ~Element();
    
    std::string getName() { return _fileName; }
    void setName(std::string fileName) {_fileName = fileName;}
    Element* getNextElement(){return _nextElement;}
    void setElement(Element* new_element){_nextElement = new_element;}
private:
    Element* _nextElement;
    std::string _fileName;
};
#endif /* ELEMENT_H_ */