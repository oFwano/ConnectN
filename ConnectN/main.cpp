#include "ConnectN.h"
#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    ConnectN w;
    w.show();

    return a.exec();
}
