#include "people.h"

People::People(QString name) :QListWidgetItem(name)
{

}
People::People(QString sh, QString name, QString date, QString gender, QString department)
    : QListWidgetItem(name),Sh(sh),Date(date),Gender(gender) ,Department(department)
{

}


