#ifndef DATE_H
#define DATE_H
#include <string>
#include <iostream>
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
    bool operator>(const date& otra) const; //manolo was here hypercharging the operator
    void SetearFecha();
    
private:
    int dia;
    int mes;
    int anio;
};

#endif /* DATE_H */

