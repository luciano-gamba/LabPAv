/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/class.h to edit this template
 */

/* 
 * File:   DataCompra.h
 * Author: brito
 *
 * Created on 18 de junio de 2025, 22:25
 */

#ifndef DATACOMPRA_H
#define DATACOMPRA_H
#include "date.h"
#include "DataProd.h"

class DataCompra {
public:
    DataCompra();
    DataCompra(const DataCompra& orig);
    virtual ~DataCompra();
private:
    date fecha;
   float monto;
   DataProd producto;
};

#endif /* DATACOMPRA_H */

