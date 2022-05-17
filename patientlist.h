#ifndef PATIENTLIST_H
#define PATIENTLIST_H

#include <QWidget>
#include <QString>
#include<QVector>
#include"patient.h"
#include"patientdialog.h"
#include "patientfulllist.h"
#include "patientsearch.h"
namespace Ui {
class PatientList;
}
class QListWidgetItem;
class PatientList : public QWidget
{
    Q_OBJECT

public:
    explicit PatientList(QWidget *parent = nullptr);
    ~PatientList();
    void Show();
    void AddPatient(Patient* patient);
    void AddPatient(QString name);
    void AddPatient(QString sh,QString name ,QString date,QString gender,QString department, QString disease,int room, long long money);
    void RemovePatient(Patient* patient);

    void readFile();
    int count1();
    void writeFile();
private slots:
    void on_Add_btn_clicked();

    void on_delete_btn_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_Full_btn_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::PatientList *ui;
    QVector<Patient*> m_Patients;
    PatientDialog* m_PatientDialog;
    PatientFullList* m_PatientFullList;
    PatientSearch* m_PatientSearch;

};

#endif // PATIENTLIST_H
