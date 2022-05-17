#ifndef DOCTORLIST_H
#define DOCTORLIST_H

#include "doctor.h"
#include <QWidget>
#include <QString>
#include<QVector>
#include"doctordialog.h"
#include "doctorfulllist.h"
#include "doctorsearch.h"
namespace Ui {
class DoctorList;
}
class QListWidgetItem;
class QDebug;
class DoctorList : public QWidget
{
    Q_OBJECT

public:
    explicit DoctorList(QWidget *parent = nullptr);
    ~DoctorList();

    void Show();

    void AddDoctor(Doctor* doctor);
    void AddDoctor(QString name);
    void AddDoctor(QString sh,QString name ,QString date,QString gender,QString department, QString specialist, QString shift);
    void RemoveDoctor(Doctor* doctor);

    void readFile();
    int count1();
    void writeFile();
private slots:
    void on_Add_btn_clicked();

    void on_delete_btn_clicked();

    void on_listWidget_itemDoubleClicked(QListWidgetItem *item);

    void on_read_btn_clicked();

    void on_write_btn_clicked();

    void on_Full_btn_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::DoctorList *ui;
    QVector<Doctor*> m_Doctors;
    DoctorDialog* m_DoctorDialog;
    DoctorFullList* m_DoctorFullList;
    DoctorSearch* m_DoctorSearch;
};

#endif // DOCTORLIST_H
