#ifndef PEOPLE_H
#define PEOPLE_H
#include <QString>
#include<QListWidgetItem>

class People: public QListWidgetItem
{
public:
    People(){  }
    People(QString name);
    People(QString sh,QString name ,QString date,QString gender,QString department);
    ~People(){}


    void SetName(QString name);
    void SetDate(QString date);
    void SetDepartment(QString department);
    void SetSh(QString SH);
    void SetGender(QString gender);

    QString GetName() ;
    QString GetDate() ;
    QString GetDepartment() ;
    QString GetSh();
    QString GetGender();

protected:
    QString Name;
    QString Sh;
    QString Date;
    QString Gender;
    QString Department;
};

inline void People:: SetName(QString name){
    QListWidgetItem::setText(name);
}
inline void People:: SetDate(QString date){
    Date=date;
}
inline void People::SetDepartment(QString department){
    Department = department;
}
inline void People:: SetSh(QString sh){
    Sh=sh;
}
inline void People:: SetGender(QString gender){
    Gender=gender;
}

inline QString People::GetName(){
    return QListWidgetItem::text();
}
inline QString People::GetDate(){
    return Date;
}
inline QString People::GetDepartment(){
    return Department;
}
inline QString People::GetGender(){
    return Gender;
}
inline QString People::GetSh(){
    return Sh;
}
#endif // PEOPLE_H
