/********************************************************************************
** Form generated from reading UI file 'trenchcoatqt.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRENCHCOATQT_H
#define UI_TRENCHCOATQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrenchCoatQtClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TrenchCoatQtClass)
    {
        if (TrenchCoatQtClass->objectName().isEmpty())
            TrenchCoatQtClass->setObjectName(QStringLiteral("TrenchCoatQtClass"));
        TrenchCoatQtClass->resize(600, 400);
        menuBar = new QMenuBar(TrenchCoatQtClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        TrenchCoatQtClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TrenchCoatQtClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        TrenchCoatQtClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(TrenchCoatQtClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        TrenchCoatQtClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(TrenchCoatQtClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        TrenchCoatQtClass->setStatusBar(statusBar);

        retranslateUi(TrenchCoatQtClass);

        QMetaObject::connectSlotsByName(TrenchCoatQtClass);
    } // setupUi

    void retranslateUi(QMainWindow *TrenchCoatQtClass)
    {
        TrenchCoatQtClass->setWindowTitle(QApplication::translate("TrenchCoatQtClass", "TrenchCoatQt", 0));
    } // retranslateUi

};

namespace Ui {
    class TrenchCoatQtClass: public Ui_TrenchCoatQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRENCHCOATQT_H
