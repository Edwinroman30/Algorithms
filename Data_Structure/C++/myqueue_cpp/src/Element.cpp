#include "Element.h"

Element::Element(std::string fileName) : _fileName(fileName), _nextElement(NULL) {

}

Element::~Element()
{
  //It must free the memory space it fill.   
}