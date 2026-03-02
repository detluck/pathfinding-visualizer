import QtQuick
import QtQuick.Layouts
import App.Controller 1.0

Rectangle{
    id: root
    property string svgPath: ""
    border.color: "skyblue"
    scale: mouseArea.containsMouse? 1.4: 1.0
    z: mouseArea.containsMouse? 10: 0

    Image {
        id: svgIcon
        //anchors.fill: parent
        source: root.svgPath
        height: root.height
        width: height
        sourceSize.height: height
        sourceSize.width: width
        Layout.alignment: verticalAlignment
        fillMode: Image.PreserveAspectFit
        visible: root.svgPath !== "" && type !== 0
        asynchronous: true
    }

    MouseArea{
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        preventStealing: true
        drag.target: null

        onClicked: {
            controller.handleClick(index)
            if(cursorHelper.cursor !== ""){
                svgPath = "qrc:/" + cursorHelper.cursor;
            }
        }

        onEntered: {
            if(mouseArea.pressedButtons & Qt.LeftButton)
            {
                controller.handleClick(index)
                if(cursorHelper.cursor !== ""){
                    svgPath = "qrc:/" + cursorHelper.cursor;
                }
            }
        }
    }

    Behavior on scale {
        NumberAnimation { duration: 150 }
    }

}
