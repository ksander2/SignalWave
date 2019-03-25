import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtCharts 2.0
import com.myinc.Calculation 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10

        MainPresenter
        {
            id: mp1
        }

        Button
        {
            objectName: "InfoButton"
            signal click1()
            text: "1111"
            onClicked:
            {
                var dd = mp1.computevec()
                btn2.text = mp1.compute(444, 66)
            }
        }

        Button
        {
            id: btn2
            text: "2222"
        }


        ChartView {
            title: "Line"
            antialiasing: true

            height: 400
            width: 400

            LineSeries {
                name: "LineSeries"
                XYPoint { x: 0; y: 0 }
                XYPoint { x: 1.1; y: 2.1 }
                XYPoint { x: 1.9; y: 3.3 }
                XYPoint { x: 2.1; y: 2.1 }
                XYPoint { x: 2.9; y: 4.9 }
                XYPoint { x: 3.4; y: 3.0 }
                XYPoint { x: 4.1; y: 3.3 }
            }
        }


    }
}
