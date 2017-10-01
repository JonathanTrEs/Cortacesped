/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QGraphicsView *graphicsView;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout;
    QLineEdit *x1;
    QLineEdit *y1;
    QLineEdit *x2;
    QLineEdit *y2;
    QLineEdit *ancho;
    QLineEdit *alto;
    QPushButton *resize;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSlider *Slider;
    QLabel *v_slider;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *start;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(436, 272);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(436, 272));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(graphicsView->sizePolicy().hasHeightForWidth());
        graphicsView->setSizePolicy(sizePolicy2);
        graphicsView->setMinimumSize(QSize(418, 192));

        gridLayout_4->addWidget(graphicsView, 1, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        x1 = new QLineEdit(centralWidget);
        x1->setObjectName(QStringLiteral("x1"));

        verticalLayout->addWidget(x1);

        y1 = new QLineEdit(centralWidget);
        y1->setObjectName(QStringLiteral("y1"));

        verticalLayout->addWidget(y1);

        x2 = new QLineEdit(centralWidget);
        x2->setObjectName(QStringLiteral("x2"));

        verticalLayout->addWidget(x2);

        y2 = new QLineEdit(centralWidget);
        y2->setObjectName(QStringLiteral("y2"));

        verticalLayout->addWidget(y2);


        horizontalLayout_4->addLayout(verticalLayout);

        ancho = new QLineEdit(centralWidget);
        ancho->setObjectName(QStringLiteral("ancho"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Ignored);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(ancho->sizePolicy().hasHeightForWidth());
        ancho->setSizePolicy(sizePolicy3);
        ancho->setMinimumSize(QSize(125, 23));
        ancho->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(ancho);

        alto = new QLineEdit(centralWidget);
        alto->setObjectName(QStringLiteral("alto"));
        sizePolicy3.setHeightForWidth(alto->sizePolicy().hasHeightForWidth());
        alto->setSizePolicy(sizePolicy3);
        alto->setMinimumSize(QSize(125, 23));
        alto->setLayoutDirection(Qt::LeftToRight);
        alto->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(alto);

        resize = new QPushButton(centralWidget);
        resize->setObjectName(QStringLiteral("resize"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(resize->sizePolicy().hasHeightForWidth());
        resize->setSizePolicy(sizePolicy4);
        resize->setMinimumSize(QSize(80, 23));

        horizontalLayout_4->addWidget(resize);


        gridLayout_4->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(label_3->sizePolicy().hasHeightForWidth());
        label_3->setSizePolicy(sizePolicy5);
        label_3->setMinimumSize(QSize(67, 15));
        label_3->setScaledContents(true);

        horizontalLayout_2->addWidget(label_3);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        Slider = new QSlider(centralWidget);
        Slider->setObjectName(QStringLiteral("Slider"));
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(Slider->sizePolicy().hasHeightForWidth());
        Slider->setSizePolicy(sizePolicy6);
        Slider->setMinimumSize(QSize(84, 15));
        Slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(Slider);

        v_slider = new QLabel(centralWidget);
        v_slider->setObjectName(QStringLiteral("v_slider"));
        v_slider->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(v_slider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_5->addWidget(pushButton);

        start = new QPushButton(centralWidget);
        start->setObjectName(QStringLiteral("start"));
        start->setMinimumSize(QSize(80, 23));

        horizontalLayout_5->addWidget(start);


        gridLayout_4->addLayout(horizontalLayout_5, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        QWidget::setTabOrder(ancho, alto);
        QWidget::setTabOrder(alto, resize);
        QWidget::setTabOrder(resize, graphicsView);
        QWidget::setTabOrder(graphicsView, start);
        QWidget::setTabOrder(start, pushButton);
        QWidget::setTabOrder(pushButton, Slider);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Interfaz Cortacesped OP", 0));
        resize->setText(QApplication::translate("MainWindow", "Resize", 0));
        label_3->setText(QApplication::translate("MainWindow", "Obst\303\241culos", 0));
        v_slider->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Start Search", 0));
        start->setText(QApplication::translate("MainWindow", "DFS Start", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
