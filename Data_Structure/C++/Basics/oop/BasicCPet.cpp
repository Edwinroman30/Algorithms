#include <iostream>
#include <string>

using namespace std;

namespace WorkingWithStructs{

    struct Person{
        string name;
        short age;
        char gender;
    };
}

namespace WorkingWithClases {

    class Pet
    {
        private:
            string name;

        public:
            string       getName()            { return name; }
            void         setName(string newValue){ name = newValue; }
            virtual void voice()              { cout << name << ": DEFAULT VOICE" << endl; }
            void         interact(Pet* other) { voice(); other->voice(); }
            void         annoy()              { cout << name << " annoys you." << endl; }

        Pet(){}
        Pet(string pname ) : name(pname) {}
    };

    class Dog : public Pet {
        public:
            Dog() {}
            Dog(string pname) : Pet(pname) {}
    };


}


using namespace WorkingWithClases;

int main(){

 //Working with Structs:
 /* Difference Between Classes and Structs in C++ */
 /* The C++ class is an extension of the C language structure. Because the only difference between a structure
  and a class is that structure members have public access by default and class members have private access by 
  default, you can use the keywords class or struct to define equivalent classes.
 */
   /*   WorkingWithStructs::Person Nano;
        Nano.name = "Makuin";
        Nano.gender = 'M';
        Nano.age = 22;

        cout << "Follow it: @" << Nano.name << endl;
        cout << "And my size on memory is: " << sizeof(Nano) << endl;

        Nano.name = "Beyond your thoughts!";
        cout << "Follow it: @" << Nano.name << endl;
 */
    
    Dog mypet("Nuo");
       
    std::cout << mypet.getName();

    mypet.setName("Petete"); //Here was using a simple string data type and it result was: 

    std::cout << mypet.getName();

    return 0;
}