#ifndef PATIENTSEARCH_H
#define PATIENTSEARCH_H
#include <QVector>
#include <QDialog>
#include "patient.h"
namespace Ui {
class PatientSearch;
}

class PatientSearch : public QDialog
{
    Q_OBJECT

public:
    explicit PatientSearch(QWidget *parent = nullptr);
    ~PatientSearch();
    void Show();

    QVector<Patient*> m_Patients1;

private slots:
    void on_pushButton_clicked();

private:
    Ui::PatientSearch *ui;
};

#endif // PATIENTSEARCH_H
