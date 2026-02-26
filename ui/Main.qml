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
        ControlPanel{
            id: controlPanel
            width: root.width
            height: root.height /4
        }
        PathGrid{
            width: root.width
            height: root.height - controlPanel.height
            tileNumber: 100
        }

    }



}
