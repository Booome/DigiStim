#include "database.h"

DataBase::DataBase(QObject *parent)
    : QObject(parent)
    , m_conn_state(Digi::ConnectState_Disconnected)
    , m_dev_name(QString(""))
{
}

DataBase::~DataBase()
{
}
