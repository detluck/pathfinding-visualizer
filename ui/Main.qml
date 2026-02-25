import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "components"
import "../ui/theme"

Window{
    id:root
    visible: true
    width: 1200
    height: 800
    ColumnLayout{
        anchors.fill: parent
        spacing: 0
        ControlPanel{
            Layout.fillWidth: true
            height: root.height / 3
        }

    }



}
