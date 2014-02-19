#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <cmath>
#include <QtXml>
#include "business.h"

// Includes sharps
#define NUMBER_OF_CHORDS 12

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_startTrainingButton_clicked();

    void on_consultChordButton_clicked();

    void on_listMakerButton_clicked();

    void on_backToMenuConsultChord_clicked();

    void on_backToMenuSelectList_clicked();

    void on_backToMenuCreateList_clicked();

    void on_normalChordsRadioButton_clicked();

    void on_splitChordsRadioButton_clicked();

    void on_normalChordsComboBox_activated(const QString &arg1);

    void on_chordsModificatorsComboBox_activated(const QString &arg1);

    void on_splitChordsComboBox_activated(const QString &arg1);

    void on_backToMenuTraining_clicked();

    void on_createNewListButton_clicked();

    void on_createListButton_clicked();

    void on_changeChordVariationUpButton_clicked();

    void on_changeChordVariationDownButton_clicked();

private:
    // Training
    void startTutorial();

    // Dictionary
    void updateGraphics();
    QList<QString> findChords(QString mainChord);
    QVarLengthArray<int> getFrets(QString mainChord, QString modifier);

    // Lists
    void updateListsList();

    Ui::MainWindow * ui;
    Business * businessManager;
    QGraphicsScene * chordScene;
    const QPixmap * guitarArm;
    QList<QString> mainChords;

    struct Point {
        double X;
        double Y;
        Point(double x, double y): X(x), Y(y) {}
    };

    struct Braco {
        double trastePosition[17];
        double casaPosition[17];
        double cordaSize;
        double cordaDistance;

        Braco(double cordaSizeIn, double cordaDistanceIn):
            cordaSize(cordaSizeIn), cordaDistance(cordaDistanceIn) {

            int trastes = 17;
            int casas = 17;
            for (int i = 0; i < trastes; i++)
                trastePosition[i] = getDistanceTraste(cordaSize, i);

            for (int i = 1; i < casas; i++)
                casaPosition[i] = (trastePosition[i] + trastePosition[i - 1]) / 2;
        }

        Point * getPoint(int corda, int casa) {
            Point * point = new Point(40 + casaPosition[casa], 145 + corda * (cordaDistance + 1 - trastePosition[casa] / casaPosition[casa]));
            return point;
        }

        double getDistanceTraste(double l, int n) {
            double p = pow(2, ((double) n / 12));
            return l * (1 - (1 / p));
        }
    };
};

#endif // MAINWINDOW_H