import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import "ui/components"
import "ui/theme"
import Pathfinding

Window{
    id:root
    visible: true
    width: 1200
    height: 800
    color: Theme.bgGrid

    Behavior on color { ColorAnimation { duration: 150 } }

    ColumnLayout{
        anchors.fill: parent
        ControlPanel{
            id: controlPaneL
            Layout.fillWidth: true
        }
        PathGrid{
            Layout.fillHeight: true
            Layout.fillWidth: true
        }
    }
}
