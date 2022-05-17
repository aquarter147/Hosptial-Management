#ifndef PATIENT_H
#define PATIENT_H
#include "people.h"

class Patient: public People
{
public:
    Patient();
    Patient(QString name);
    Patient(QString sh,QString name ,QString date,QString gender,QString department, QString disease,int room, long long money );
    ~Patient(){}

    void SetDisease(QString disease);
    void SetMoney( long long money);
    void SetRoom(int room);

    QString GetDisease();
    long GetMoney();
    int GetRoom();
protected:
    QString Disease;
    int Room;
    long long Money;

};

inline void Patient::SetDisease(QString disease){
    Disease = disease;
}

inline void Patient::SetMoney( long long money){
    Money = money;
}
inline void Patient::SetRoom(int room){
    Room=room;
}



inline QString Patient:: GetDisease(){
    return Disease;
}

inline long Patient:: GetMoney(){
    return Money;
}

inline int Patient::GetRoom(){
    return Room;
}



#endif // PATIENT_H
