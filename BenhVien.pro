QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    doctor.cpp \
    doctordialog.cpp \
    doctorfulllist.cpp \
    doctorlist.cpp \
    doctorsearch.cpp \
    main.cpp \
    hospital.cpp \
    patient.cpp \
    patientdialog.cpp \
    patientfulllist.cpp \
    patientlist.cpp \
    patientsearch.cpp \
    people.cpp

HEADERS += \
    doctor.h \
    doctordialog.h \
    doctorfulllist.h \
    doctorlist.h \
    doctorsearch.h \
    hospital.h \
    patient.h \
    patientdialog.h \
    patientfulllist.h \
    patientlist.h \
    patientsearch.h \
    people.h

FORMS += \
    doctordialog.ui \
    doctorfulllist.ui \
    doctorlist.ui \
    doctorsearch.ui \
    hospital.ui \
    patientdialog.ui \
    patientfulllist.ui \
    patientlist.ui \
    patientsearch.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
