#include "database.h"

DataBase *DataBase::instance = NULL;

DataBase::DataBase(QObject *parent)
    : QObject(parent)
    , conn_state(Digi::ConnectState_Connected)
{
}

DataBase::~DataBase()
{
}
