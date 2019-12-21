#include "myapplication.h"

int main(int argc, char *argv[])
{
    MyApplication app(argc, argv);
    app.installEventFilter(&app);
    return app.exec();
}
