#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject(parent)
    , conn_state(Digi::ConnectState_Disconnected)
    , dev_name(QString("NULL"))
{
}

DataBase::~DataBase()
{
}
