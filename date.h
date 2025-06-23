#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class date {
public:
    date();
    date(int,int,int);
    virtual ~date();
    
    int getDia();
    int getMes();
    int getAnio();
    
    string getInfoDate();
    
private:
    int dia;
    int mes;
    int anio;
};

#endif /* DATE_H */

