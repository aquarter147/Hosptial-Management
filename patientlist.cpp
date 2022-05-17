#include "patientlist.h"
#include "ui_patientlist.h"
#include "patient.h"
#include <fstream>
#include<QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QJsonDocument>
#include<QDebug>
#include<QJsonObject>
#include<QJsonArray>
#include "patientfulllist.h"
#include "patientsearch.h"
PatientList::PatientList(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PatientList)
{
    ui->setupUi(this);
     m_PatientDialog = new PatientDialog;
     m_PatientFullList = new PatientFullList;
     m_PatientSearch = new PatientSearch;
    setWindowTitle(QString::fromUtf8("Danh sách bệnh nhân"));

}
void PatientList::Show(){
    show();
}

void PatientList::AddPatient(Patient *patient){
    ui->listWidget->addItem((QListWidgetItem*) patient);
    m_Patients.push_back(patient);
    m_PatientSearch->m_Patients1.push_back(patient);
}
void PatientList::AddPatient(QString name){
    Patient* patient = new Patient(name);
    AddPatient(patient);
}
void PatientList:: AddPatient(QString sh,QString name ,QString date,QString gender,QString department, QString disease, int room,long long money){
    Patient* patient = new Patient(sh,name,date,gender,department,disease,room,money);
    AddPatient(patient);
}
void PatientList::RemovePatient(Patient *patient){
    ui->listWidget->removeItemWidget((QListWidgetItem*) patient);
    for(int i=0;i<m_Patients.size();i++){
        if(m_Patients[i]==patient){
            m_Patients.remove(i);
            delete patient;
        }
    }
}
PatientList::~PatientList()
{
    for(int i=0;i<m_Patients.size();i++){
        RemovePatient(m_Patients[i]);
    }
    delete ui;
    delete m_PatientDialog;
    delete m_PatientFullList;
    delete m_PatientSearch;
}



int PatientList::count1(){
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

void PatientList:: readFile(){
    QString val;
    QFile file;
    file.setFileName("Patient.txt");
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QTextStream textStream(&file);
    textStream.setCodec("UTF-8");
    val = textStream.readAll();
    file.close();
    QJsonDocument d = QJsonDocument::fromJson(val.toUtf8());
    QJsonObject sett2 = d.object();
    QJsonValue value = sett2.value(QString::fromUtf8("Danh sách"));
    QJsonObject item = value.toObject();
    QJsonArray test = item["Patient"].toArray();

    QJsonObject item1;
    QJsonValue subobj;
    QJsonValue subobj1;
    QJsonValue subobj2;
    QJsonValue subobj3;
    QJsonValue subobj4;
    QJsonValue subobj5;
    QJsonValue subobj6;
    QJsonValue subobj7;
    int r;
    long long m;
    for(int i=0;i<count1()-6;i++){
        item1 = test[i].toObject();
        subobj = item1["SH"];
        subobj1 = item1["Name"];
        subobj2 = item1["Date"];
        subobj3 = item1["Gender"];
        subobj4 = item1["Department"];
        subobj5 = item1["Disease"];
        subobj6 = item1["Room"];
        r = subobj6.toString().toInt();
        subobj7 = item1["Money"];
        m = subobj7.toString().toLongLong();
        AddPatient(subobj.toString(),subobj1.toString(),subobj2.toString(),subobj3.toString(),subobj4.toString(),subobj5.toString(),r,m);
    }
}

void PatientList::writeFile(){
    std::ofstream ofs("PatientWrite.txt");
    for (int i = 0; i < m_Patients.size(); i++) {
        ofs<< "  {\"SH\" : \"";
        ofs<<m_Patients[i]->GetSh().toStdString();
        ofs<<"\", \"Name\" : \"";
        ofs<<m_Patients[i]->GetName().toStdString();
        ofs<<"\", \"Date\" : \"";
        ofs<< m_Patients[i]->GetDate().toStdString();

        ofs<<"\", \"Gender\" : \"";
        ofs<< m_Patients[i]->GetGender().toStdString();
        ofs<<"\", \"Department\" : \"";

        ofs<< m_Patients[i]->GetDepartment().toStdString();

        ofs<<"\", \"Disease\" : \"";
        ofs<< m_Patients[i]->GetDisease().toStdString();

        ofs<<"\", \"Room\" : \"";
        ofs<< m_Patients[i]->GetRoom();

        ofs<<"\", \"Money\" : \"";
        ofs<< m_Patients[i]->GetMoney();
        ofs<< "\"}, \n";
    }
    ofs.close();
}

struct Sort_Name
{
    inline bool operator() (Patient* patient1,Patient* patient2)
    {
        return (patient1->GetName() < patient2->GetName());
    }
};

struct Sort_Money
{
    inline bool operator() (Patient* patient1,Patient* patient2)
    {
        return (patient1->GetMoney() > patient2->GetMoney());
    }
};


void PatientList::on_Add_btn_clicked()
{
    AddPatient("none",QString::fromUtf8("Bênh nhân mới"),"none","none","none","none",0,0);

}

void PatientList::on_delete_btn_clicked()
{
    RemovePatient((Patient*)ui->listWidget->currentItem());
}


void PatientList::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    m_PatientDialog->Show((Patient*) item);
}

void PatientList::on_pushButton_clicked()
{
    readFile();
}


void PatientList::on_pushButton_2_clicked()
{
    writeFile();
    QMessageBox msgBox(QMessageBox::Information,"Thông báo","Đã sao lưu thông tin vào file PatientWrite.txt!",QMessageBox::Ok);
    msgBox.exec();
}


void PatientList::on_Full_btn_clicked()
{
    m_PatientFullList-> Show(m_Patients,m_Patients.size());
}


void PatientList::on_pushButton_6_clicked()
{
    std::sort(m_Patients.begin(),m_Patients.end(),Sort_Name());
    m_PatientFullList->Show(m_Patients,m_Patients.size());
}


void PatientList::on_pushButton_4_clicked()
{
    std::sort(m_Patients.begin(),m_Patients.end(),Sort_Money());
    m_PatientFullList->Show(m_Patients,m_Patients.size());
}


void PatientList::on_pushButton_3_clicked()
{
    m_PatientSearch->Show();
}

