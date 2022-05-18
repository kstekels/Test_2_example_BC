#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
B. (max 12 points) 
Create the class hierarchy animal-animalwithwings with all fields defined as private or protected 
according to the source code that uses the classes, where animalwithwings class inherits from animal class. 

Class animal object should contain fields name, and leg_count. 
Class animalwithwings object should additionally contain fields wings and species as a list of species for that kind of animals. 
The following methods should be implemented for each class: constructor, destructor, print method. 
For animalwithwings class, the method add_species should be implemented.
*/

/*
// name, legs
    animal *h = new animal("horse",4);
    h->print(); // horse, 4 leg
    cout<<endl;
    //name, legs, wings
    animal *m = new animalwithwings("bird",2,2);
    m->add_species("eagle");
    m->add_species("dove");
    m->add_species("eagle"); // is ignored, as already exists
    m->print(); // bird, 2 legs, 2 wings, species: eagle dove
    delete m;
    delete h;

*/

class animal
{
    string name;
    int leg_count;
public:
    animal(string n, int l)
    {
        name = n;
        leg_count = l;
    }
    virtual void print()
    {
        cout << name << ": " << leg_count << " legs" << endl;
    }
    virtual ~animal()
    {
        cout << "Animal deleted" << endl;
    }
};

class animalwithwings: public animal
{
    int wings;
    vector<string> species;
public:
    animalwithwings(string name, int leg_count, int w) : animal(name, leg_count)
    {
        wings = w;
    }
    void print()
    {
        animal::print();
        cout << wings << " wings : ";
        for (auto &i : species)
            cout << i << ", ";
        cout << endl;
    }
    void add_species(string s)
    {
        if (find(species.begin(), species.end(), s) == species.end())
            species.push_back(s);
    }
    ~animalwithwings()
    {
        cout << "Animal with wings deleted" << endl;
    }
};


int main()
{
    
    animal *h = new animal("horse", 4);
    h->print(); // horse, 4 leg
    cout<<endl;
    //name, legs, wings
    animalwithwings *m = new animalwithwings("bird",2,2);
    m->add_species("eagle");
    m->add_species("dove");
    m->add_species("eagle"); // is ignored, as already exists
    m->print(); // bird, 2 legs, 2 wings, species: eagle dove
    delete m;
    delete h;

    return 0;
}