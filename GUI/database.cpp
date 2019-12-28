#include "database.h"

DataBase *DataBase::instance = NULL;

DataBase::DataBase(QObject *parent)
    : QObject(parent)
{
}

DataBase::~DataBase()
{
}
