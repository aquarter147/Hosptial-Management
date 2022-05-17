#include "doctorlist.h"
#include "ui_doctorlist.h"
#include <iostream>
#include<stdlib.h>
#include <string>
#include<math.h>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
#include <fstream>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QJsonDocument>
#include<QDebug>
#include<QJsonObject>
#include<QJsonArray>
#include <QMessageBox>
#include "doctorfulllist.h"
#include <QMessageBox>
#include "doctorsearch.h"
DoctorList::DoctorList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoctorList)
{
    ui->setupUi(this);
    m_DoctorDialog = new DoctorDialog;
    m_DoctorFullList= new DoctorFullList;
    m_DoctorSearch = new DoctorSearch;
    setWindowTitle(QString::fromUtf8("Danh sách bác sĩ"));

}

int DoctorList::count1(){
    std::ifstream f1;
    char c;
    int numchars, numlines;

    f1.open("Doctor.txt");

       numchars = 0;
       numlines = 0;
       f1.get(c);
       while (f1) {
         while (f1 && c != '\n') {
           numchars = numchars + 1;
           f1.get(c);
         }
         numlines = numlines + 1;
         f1.get(c);
       }
       return numlines;
}

void DoctorList:: readFile(){
    QString val;
    QFile file;
    file.setFileName("Doctor.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream textStream(&file);
    textStream.setCodec("UTF-8");
    val = textStream.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString::fromUtf8("List of Doctor"));
    QJsonObject item = value.toObject();
    QJsonArray test = item["Doctor"].toArray();

    QJsonObject item1;
    QJsonValue subobj;
    QJsonValue subobj1;
    QJsonValue subobj2;
    QJsonValue subobj3;
    QJsonValue subobj4;
    QJsonValue subobj5;
    QJsonValue subobj6;

    for(int i=0;i<count1()-6;i++){
        item1 = test[i].toObject();
        subobj = item1["SH"];
        subobj1 = item1["Name"];
        subobj2 = item1["Date"];
        subobj3 = item1["Gender"];
        subobj4 = item1["Department"];
        subobj5 = item1["Specialist"];
        subobj6 = item1["Shift"];
        AddDoctor(subobj.toString(),subobj1.toString(),subobj2.toString(),subobj3.toString(),subobj4.toString(),subobj5.toString(),subobj6.toString());
    }
}
void DoctorList::writeFile(){
    std::ofstream ofs("DoctorWrite.txt");
    for (int i = 0; i < m_Doctors.size(); i++) {
        ofs<< "  {\"SH\" : \"";
        ofs<<m_Doctors[i]->GetSh().toStdString();
        ofs<<"\", \"Name\" : \"";
        ofs<<m_Doctors[i]->GetName().toStdString();
        ofs<<"\", \"Date\" : \"";
        ofs<< m_Doctors[i]->GetDate().toStdString();

        ofs<<"\", \"Gender\" : \"";
        ofs<< m_Doctors[i]->GetGender().toStdString();
        ofs<<"\", \"Department\" : \"";

        ofs<< m_Doctors[i]->GetDepartment().toStdString();

        ofs<<"\", \"Specialist\" : \"";
        ofs<< m_Doctors[i]->GetSpecialist().toStdString();

        ofs<<"\", \"Shift\" : \"";
        ofs<< m_Doctors[i]->GetShift().toStdString();
        ofs<< "\"}, \n";
    }
    ofs.close();
}

void DoctorList::Show(){
    show();
}
void DoctorList::AddDoctor(Doctor *doctor){
    ui->listWidget->addItem((QListWidgetItem*) doctor);
    m_Doctors.push_back(doctor);
    m_DoctorSearch->m_Doctors1.push_back(doctor);
}
void DoctorList::AddDoctor(QString name){
    Doctor* doctor = new Doctor(name);
    AddDoctor(doctor);
}
void DoctorList:: AddDoctor(QString sh,QString name ,QString date,QString gender,QString department, QString specialist, QString shift){
    Doctor* doctor = new Doctor(sh,name,date,gender,department,specialist,shift);
    AddDoctor(doctor);
}
void DoctorList::RemoveDoctor(Doctor *doctor){
    ui->listWidget->removeItemWidget((QListWidgetItem*) doctor);
    for(int i=0;i<m_Doctors.size();i++){
        if(m_Doctors[i]==doctor){
            m_Doctors.remove(i);
            delete doctor;
        }
    }
}
DoctorList::~DoctorList()
{
    for(int i=0;i<m_Doctors.size();i++){
        RemoveDoctor(m_Doctors[i]);
    }
    delete ui;
    delete m_DoctorDialog;
    delete m_DoctorFullList;
    delete m_DoctorSearch;
}

struct Sort_Name
{
    inline bool operator() (Doctor* doctor1,Doctor* doctor2)
    {
        return (doctor1->GetName() < doctor2->GetName());
    }
};



void DoctorList::on_Add_btn_clicked()
{
//    AddDoctor(QString::fromUtf8("Bác sĩ mới"));
    AddDoctor("None",QString::fromUtf8("Bác sĩ mới"),"none","none","none","none","none");
}

void DoctorList::on_delete_btn_clicked()
{
    RemoveDoctor((Doctor*)ui->listWidget->currentItem());
}


void DoctorList::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    m_DoctorDialog->Show((Doctor*) item);
}


void DoctorList::on_read_btn_clicked()
{
    readFile();
}


void DoctorList::on_write_btn_clicked()
{
    writeFile();
    QMessageBox msgBox(QMessageBox::Information,"Thông báo","Đã sao lưu thông tin vào file DoctorWrite.txt!",QMessageBox::Ok);
    msgBox.exec();
}


void DoctorList::on_Full_btn_clicked()
{
    m_DoctorFullList-> Show(m_Doctors,m_Doctors.size());
}


void DoctorList::on_pushButton_2_clicked()
{
    std::sort(m_Doctors.begin(),m_Doctors.end(),Sort_Name());
    m_DoctorFullList-> Show(m_Doctors,m_Doctors.size());
}


void DoctorList::on_pushButton_clicked()
{
    m_DoctorSearch->Show();
}

