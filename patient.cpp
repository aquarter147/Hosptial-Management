#include "patient.h"

Patient::Patient(QString name)
    :People(name)
{

}
Patient::Patient(QString sh,QString name ,QString date,QString gender,QString department, QString disease, int room, long long money)
    :People( sh,  name,  date,  gender,  department),
    Disease(disease),
    Room(room),
    Money(money)
{

}
