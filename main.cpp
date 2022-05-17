#include "hospital.h"
#include "doctorlist.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Hospital w;
    w.show();
    return a.exec();
}
