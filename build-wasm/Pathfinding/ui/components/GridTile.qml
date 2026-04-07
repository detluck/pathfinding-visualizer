import QtQuick
import QtQuick.Layouts
import App.Controller 1.0

Rectangle{
    id: root
    property string svgPath: ""
    border.color: "skyblue"
    property bool isHovered
    scale: isHovered? 1.6: 1.0
    z: isHovered? 10: 0

    Image {
        id: svgIcon
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

    Behavior on scale {
        NumberAnimation { duration: 150 }
    }

}
