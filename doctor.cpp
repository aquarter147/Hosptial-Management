#include "doctor.h"

Doctor::Doctor(QString name)
    :People(name)
{

}

Doctor::Doctor(QString sh,QString name ,QString date,QString gender,QString department, QString specialist, QString shift)
    :People( sh,  name,  date,  gender,  department),
      Specialist(specialist),
      Shift(shift)
{

}
