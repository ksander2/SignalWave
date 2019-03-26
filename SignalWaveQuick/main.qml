import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtCharts 2.0
import com.myinc.Calculation 1.0

Window {
    visible: true
    width: 1200
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        width: parent.width


        MainPresenter
        {
            id: mp1
        }

        LineSeries {
            id: lineSeries
            name: "LineSeries2"

        }

        GridLayout
        {
            columns: 2

            Text
            {
                text: "Частота"
            }

            SpinBox
            {
                id: frequencySbx
                from: 0
                to: 1200
                value: 20
            }

            Text
            {
                text: "Выборки"
            }

            SpinBox
            {
                id: samplesSbx
                from: 0
                to: 1200
                value: 256
            }

            Button
            {
                objectName: "InfoButton"
                signal click1()
                text: "Build Signal"
                onClicked:
                {
                    var dd = mp1.computevec(frequencySbx.value, 1, samplesSbx.value)

                    chv1.removeAllSeries()
                    var series1 = chv1.createSeries(ChartView.SeriesTypeLine, "first")

                    series1.axisX.min = 0;
                    series1.axisX.max = 270;
                    series1.axisY.min = -1.2;
                    series1.axisY.max = 1.2;
                    series1.axisY.tickCount = 6;
                    series1.axisY.titleText = "speed (kph)";
                    series1.axisX.titleText = "speed trap";
                    series1.axisX.labelFormat = "%.0f";

                    for(var i=0; i < samplesSbx.value; i++)
                    {
                        series1.append(i, dd[i])

                    }

                    // btn2.text = mp1.compute(444, 66)
                }
            }
            Button
            {
                id: btn2
                text: "+"

                onClicked:
                {

                }
            }


        }



        ChartView {
            id: chv1
            title: "Line"
            antialiasing: true

            height: 400
            // width: parent.width
            width: 1200

        }


    }
}
