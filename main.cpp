#include "myapplication.h"
#include "diginamespace.h"

int main(int argc, char *argv[])
{
    qRegisterMetaType<Digi::ConnectState_t>("Digi::ConnectState_t");

    MyApplication app(argc, argv);
    return app.exec();
}
