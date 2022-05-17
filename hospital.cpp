#include "hospital.h"
#include "ui_hospital.h"
#include "doctorlist.h"
#include "patientlist.h"
Hospital::Hospital(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Hospital)
{
    ui->setupUi(this);
}

Hospital::~Hospital()
{
    delete ui;
    delete m_DoctorList;
    delete m_PatientList;
}


void Hospital::on_pushButton_released()
{
    m_DoctorList = new DoctorList;
    m_DoctorList->Show();
    m_DoctorList->AddDoctor("D123","Thao Anh","4/1/2001","nu","than kinh","phan tu","hanh chinh");

}


void Hospital::on_pushButton_2_clicked()
{
     m_PatientList = new PatientList;
     m_PatientList->Show();
     m_PatientList->AddPatient("P3213","Thảo Anh","4/1/2001","nữ","than kinh","Đau đầu",213,3456000);
}

