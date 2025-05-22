#ifndef DATE_H
#define DATE_H

class date {
public:
    date();
    date(int d, int m, int a);
    virtual ~date();
private:
    int dia;
    int mes;
    int anio;
};

#endif /* DATE_H */

