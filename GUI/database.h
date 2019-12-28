#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class DataBase : public QObject
{
    Q_OBJECT

private:
    explicit DataBase(QObject *parent = nullptr);
    ~DataBase();

public:
    DataBase *getInstance() {
        if (!instance)
            instance = new DataBase;
        return instance;
    }

private:
    static DataBase *instance;

private:

};

#endif // DATABASE_H
