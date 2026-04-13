import QtQuick
import QtQuick.Layouts
import QtQuick.Effects
import App.Controller 1.0
import Pathfinding

Rectangle{
    id: root
    property string svgPath: ""
    border.color: Theme.empty
    property bool isHovered
    scale: isHovered? 1.6: 1.0
    z: isHovered? 10: 0

    Behavior on color { ColorAnimation { duration: 150 } }

    // Image {
    //     id: svgIcon
    //     source: root.svgPath
    //     height: root.height
    //     width: height
    //     sourceSize.height: height
    //     sourceSize.width: width
    //     Layout.alignment: verticalAlignment
    //     fillMode: Image.PreserveAspectFit
    //     visible: root.svgPath !== "" && type !== 0
    //     asynchronous: true
    // }

    Item {
        height: root.height
        width: height
        anchors.verticalCenter: parent.verticalCenter
        visible: root.svgPath !== "" && type !== 0

        Image {
            id: svgIcon
            source: root.svgPath
            sourceSize.height: parent.height
            sourceSize.width: parent.width
            fillMode: Image.PreserveAspectFit
            visible: false
        }

        MultiEffect {
            id: svgEffect
            source: svgIcon
            anchors.fill: parent
            colorization: 1.0
            colorizationColor: Theme.bgBaseReverse

            Behavior on colorizationColor {
                ColorAnimation {
                    duration: 250
                }
            }
        }
    }


    Behavior on scale {
        NumberAnimation { duration: 150 }
    }

}
