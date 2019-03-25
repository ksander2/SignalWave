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

        Button
        {
            objectName: "InfoButton"
            signal click1()
            text: "1111"
            onClicked:
            {
                var dd = mp1.computevec()

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

                for(var i=0; i < 256; i++)
                {
                    series1.append(i, dd[i])

                }

               // btn2.text = mp1.compute(444, 66)
            }
        }

        Button
        {
            id: btn2
            text: "2222"

            onClicked:
            {

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
