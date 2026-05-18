import QtQuick
import QtQuick.Controls.Basic
import Pathfinding

Rectangle{
    id: root
    signal valueChanged(real value);
    Row {
        spacing: 10
        anchors.fill: parent

        Slider {
            id: control
            from: 0
            to: 100
            value: 50
            stepSize: 1

            background: Rectangle {
                x: control.leftPadding
                y: control.topPadding + control.availableHeight / 2 - height / 2
                implicitWidth: 200
                implicitHeight: 4
                width: control.availableWidth
                height: implicitHeight
                radius: 2
                color: "#bdbebf"

                Rectangle {
                    width: control.visualPosition * parent.width
                    height: parent.height
                    color: Theme.slider
                    radius: 2
                }
            }

            handle: Rectangle {
                x: control.leftPadding + control.visualPosition * (control.availableWidth - width)
                y: control.topPadding + control.availableHeight / 2 - height / 2
                implicitWidth: 26
                implicitHeight: 26
                radius: 13
                color: control.pressed ? "#f0f0f0" : "#f6f6f6"
                border.color: "#bdbebf"
            }

            onValueChanged: root.valueChanged(control.value);
        }

        StyledText{
            text: control.value
        }
    }
}
