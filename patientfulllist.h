#ifndef PATIENTFULLLIST_H
#define PATIENTFULLLIST_H

#include <QWidget>
#include <QVector>
#include "patient.h"

namespace Ui {
class PatientFullList;
}

class PatientFullList : public QWidget
{
    Q_OBJECT

public:
    explicit PatientFullList(QWidget *parent = nullptr);
    ~PatientFullList();
    void Show(QVector<Patient*> patient, int size);

private slots:
    void on_pushButton_clicked();

private:
    Ui::PatientFullList *ui;
};

#endif // PATIENTFULLLIST_H
