/**
  * @file mainwindow.h
  * @brief main window
  * @author Roman Safin
  */
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "sort.h"
#include <QChart>
#include <QChartView>
#include <QBarSeries>
#include <QBarSet>
#include <QBarCategoryAxis>
#include <QValueAxis>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

using namespace QtCharts;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief constructor MainWindow
     * @param parent
     */
    MainWindow(QWidget *parent = nullptr);
    /**
      * @brief destructor MainWindow
      */
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QThread *thread;
    Sort* array;
    QChart *chart;
    QChartView *view;
    QBarSeries *series;
    QTimer *timer;

private:
    /**
     * @brief create chart
     */
    void createChart();
    /**
     * @brief create series
     * @return
     */
    QBarSeries* createSeries();
    /**
     * @brief create X axis
     * @return
     */
    QBarCategoryAxis* createXAxis();
    /**
     * @brief create Y axis
     * @return
     */
    QValueAxis* createYAxis();
    /**
     * @brief create chart view
     */
    void createChartView();
    /**
     * @brief create set for series
     * @return
     */
    QBarSet* createSet();

private slots:
    /**
     * @brief start button clicked
     */
    void startClicked();
    /**
     * @brief stop button clicked
     */
    void stopClicked();
    /**
     * @brief change series
     */
    void changeSeries();
    /**
     * @brief sort finished
     */
    void sortFinished();
};
#endif // MAINWINDOW_H
