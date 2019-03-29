import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtCharts 2.0
import com.myinc.Calculation 1.0

Window {
    visible: true
    width: 1200
    height: 780
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
                editable: true
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
                editable: true
            }

            Text
            {
                text: "Тип"
            }

            ComboBox {
                width: 200
                model: [ "Sine", "Triangle", "Saw" ]
            }

            Button
            {
                objectName: "InfoButton"
                signal click1()
                text: "Build Signal"
                onClicked:
                {
                    var signalArray = mp1.computevec(frequencySbx.value, 1, samplesSbx.value)
                    var fftArray = mp1.computefft(signalArray);

                    var maxfft = Math.max.apply(Math, fftArray)

                    signalChartView.removeAllSeries()
                    fftChartView.removeAllSeries()

                    var series1 = signalChartView.createSeries(ChartView.SeriesTypeLine, "first")
                    var series2 = fftChartView.createSeries(ChartView.SeriesTypeLine, "first")

                    series1.axisX.min = 0;
                    series1.axisX.max = signalArray.length;
                    series1.axisY.min = -1.2;
                    series1.axisY.max = 1.2;
                    series1.axisY.tickCount = 6;
                    series1.axisY.titleText = "speed (kph)";
                    series1.axisX.titleText = "speed trap";
                    series1.axisX.labelFormat = "%.0f";

                    series2.axisX.min = 0;
                    series2.axisX.max = fftArray.length / 2;
                    series2.axisY.min = 0;
                    series2.axisY.max = maxfft;
                    series2.axisY.tickCount = 6;
                    series2.axisY.titleText = "speed (kph)";
                    series2.axisX.titleText = "speed trap";
                    series2.axisX.labelFormat = "%.0f";

                    for(var i = 0; i < samplesSbx.value; i++)
                    {
                        series1.append(i, signalArray[i])
                    }

                    for(var i = 0; i < samplesSbx.value/2; i++)
                    {              
                        series2.append(i, fftArray[i])
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
            id: signalChartView
            title: "signal"
            antialiasing: true

            Layout.fillHeight: true
            Layout.fillWidth: true

            LineSeries {

                XYPoint { x: 0; y: 0 }
                XYPoint { x: 100; y: 0 }
            }

        }

        ChartView {
            id: fftChartView
            title: "fft"
            antialiasing: true

            Layout.fillHeight: true
            Layout.fillWidth: true

            LineSeries {

                XYPoint { x: 0; y: 0 }
                XYPoint { x: 100; y: 0 }
            }

        }


    }
}
