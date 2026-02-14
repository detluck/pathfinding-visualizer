import QtQuick 2.15
import QtQuick.Controls
import QtQuick.Layouts
import "components"
import "../ui/theme"

Window{
    visible: true
    ColumnLayout{
        anchors.centerIn: parent
        spacing: 20

        StyledButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            id: button1
            text: "Start node"
            width: 100
            height: 50
            iconSize: 40
            fontSize: 40
            svgPath: "../assets/svgs/startNode.svg"
        }
        StyledButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Target node"
            width: 100
            height: 50
            iconSize: 40
            fontSize: 40
            svgPath: "../assets/svgs/endNode.svg"
        }
        StyledButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Deleate Tile"
            width: 100
            height: 50
            iconSize: 40
            fontSize: 40
            svgPath: "../assets/svgs/deleate.svg"
        }
        StyledButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Clear Grid"
            width: 100
            height: 50
            iconSize: 40
            fontSize: 40
            svgPath: "../assets/svgs/clean.svg"
        }
        StyledButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Start"
            width: 100
            height: 50
            iconSize: 40
            fontSize: 40
            svgPath: "../assets/svgs/start.svg"
        }
        StyledButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Terminate"
            width: 100
            height: 50
            iconSize: 40
            fontSize: 40
            svgPath: "../assets/svgs/terminate.svg"
        }
        StyledButton{
            Layout.fillWidth: true
            Layout.fillHeight: true
            text: "Pause"
            width: 100
            height: 50
            iconSize: 40
            fontSize: 40
            svgPath: "../assets/svgs/pause.svg"
        }

    }



}
