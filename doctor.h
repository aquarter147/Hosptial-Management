#ifndef DOCTOR_H
#define DOCTOR_H
#include "people.h"

class Doctor: public People
{
public:
    Doctor();
    Doctor(QString name);
    Doctor(QString sh,QString name ,QString date,QString gender,QString department, QString specialist, QString shift);
    ~Doctor(){}

    void SetSpecialist(QString specialist);
    void SetShift(QString shift);

    QString GetSpecialist();
    QString GetShift();

protected:
    QString Specialist;
    QString Shift;
};

inline void Doctor::SetSpecialist(QString specialist){
    Specialist = specialist;
}

inline void Doctor::SetShift(QString shift){
    Shift = shift;
}




inline QString Doctor:: GetSpecialist(){
    return Specialist;
}

inline QString Doctor:: GetShift(){
    return Shift;
}


#endif // DOCTOR_H
