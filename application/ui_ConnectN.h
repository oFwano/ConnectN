/********************************************************************************
** Form generated from reading UI file 'ConnectN.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTN_H
#define UI_CONNECTN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ConnectN
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *size_label;
    QComboBox *size_cbox;
    QGraphicsView *gamewindow;
    QGridLayout *gridLayout_2;
    QLabel *label_2;
    QComboBox *win_cbox;
    QLabel *statuslabel;
    QLabel *statuslabel2;
    QPushButton *newgame_btn;

    void setupUi(QMainWindow *ConnectN)
    {
        if (ConnectN->objectName().isEmpty())
            ConnectN->setObjectName(QString::fromUtf8("ConnectN"));
        ConnectN->resize(1159, 960);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ConnectN->sizePolicy().hasHeightForWidth());
        ConnectN->setSizePolicy(sizePolicy);
        ConnectN->setStyleSheet(QString::fromUtf8(""));
        centralWidget = new QWidget(ConnectN);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, -1, 15);
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setKerning(true);
        groupBox->setFont(font);
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(15);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        gridLayout_3->setContentsMargins(15, 15, 15, 15);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        size_label = new QLabel(groupBox);
        size_label->setObjectName(QString::fromUtf8("size_label"));
        sizePolicy.setHeightForWidth(size_label->sizePolicy().hasHeightForWidth());
        size_label->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setPointSize(10);
        size_label->setFont(font1);
        size_label->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);

        verticalLayout_2->addWidget(size_label);

        size_cbox = new QComboBox(groupBox);
        size_cbox->setObjectName(QString::fromUtf8("size_cbox"));
        sizePolicy.setHeightForWidth(size_cbox->sizePolicy().hasHeightForWidth());
        size_cbox->setSizePolicy(sizePolicy);
        size_cbox->setMaximumSize(QSize(16777215, 16777215));

        verticalLayout_2->addWidget(size_cbox);


        gridLayout_3->addLayout(verticalLayout_2, 2, 0, 1, 1);

        gamewindow = new QGraphicsView(groupBox);
        gamewindow->setObjectName(QString::fromUtf8("gamewindow"));
        gamewindow->viewport()->setProperty("cursor", QVariant(QCursor(Qt::ArrowCursor)));
        gamewindow->setMouseTracking(true);
        gamewindow->setStyleSheet(QString::fromUtf8("\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:0.519802, y2:0.539773, stop:0 rgba(51, 8, 103, 255), stop:1 rgba(48, 207, 208, 255));"));
        gamewindow->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gamewindow->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        gamewindow->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        gamewindow->setTransformationAnchor(QGraphicsView::AnchorViewCenter);
        gamewindow->setResizeAnchor(QGraphicsView::NoAnchor);

        gridLayout_3->addWidget(gamewindow, 0, 0, 1, 2);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        win_cbox = new QComboBox(groupBox);
        win_cbox->setObjectName(QString::fromUtf8("win_cbox"));

        gridLayout_2->addWidget(win_cbox, 3, 0, 1, 1);

        statuslabel = new QLabel(groupBox);
        statuslabel->setObjectName(QString::fromUtf8("statuslabel"));
        QFont font2;
        font2.setPointSize(11);
        font2.setBold(true);
        font2.setWeight(75);
        statuslabel->setFont(font2);
        statuslabel->setAutoFillBackground(false);

        gridLayout_2->addWidget(statuslabel, 0, 0, 1, 1);

        statuslabel2 = new QLabel(groupBox);
        statuslabel2->setObjectName(QString::fromUtf8("statuslabel2"));
        statuslabel2->setFont(font2);

        gridLayout_2->addWidget(statuslabel2, 1, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_2, 1, 1, 2, 1);

        newgame_btn = new QPushButton(groupBox);
        newgame_btn->setObjectName(QString::fromUtf8("newgame_btn"));
        sizePolicy.setHeightForWidth(newgame_btn->sizePolicy().hasHeightForWidth());
        newgame_btn->setSizePolicy(sizePolicy);
        newgame_btn->setAutoDefault(false);
        newgame_btn->setFlat(false);

        gridLayout_3->addWidget(newgame_btn, 1, 0, 1, 1);


        gridLayout->addWidget(groupBox, 1, 0, 3, 1);

        ConnectN->setCentralWidget(centralWidget);

        retranslateUi(ConnectN);

        newgame_btn->setDefault(false);


        QMetaObject::connectSlotsByName(ConnectN);
    } // setupUi

    void retranslateUi(QMainWindow *ConnectN)
    {
        ConnectN->setWindowTitle(QApplication::translate("ConnectN", "connectfourboard", nullptr));
        groupBox->setTitle(QString());
        size_label->setText(QApplication::translate("ConnectN", "Board Size (Rows and Column):", nullptr));
        label_2->setText(QApplication::translate("ConnectN", "Consective pieces need to win:", nullptr));
        statuslabel->setText(QString());
        statuslabel2->setText(QString());
        newgame_btn->setText(QApplication::translate("ConnectN", "New Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectN: public Ui_ConnectN {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTN_H
