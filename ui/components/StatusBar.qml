import QtQuick
import QtQuick.Layouts
import Pathfinding

Rectangle{
    height: 20
    color: Theme.bgBase

    RowLayout {
        spacing: 0
        anchors.fill: parent
        anchors.leftMargin: 10
        anchors.rightMargin: 10
        anchors.verticalCenter: parent.verticalCenter

        Toaster{
            id: toaster

            Layout.preferredHeight: 20
            Layout.preferredWidth: 70
            Layout.alignment: Qt.AlignVCenter
        }

        Item{
            Layout.fillWidth: true
        }

        StyledText{
            Layout.fillHeight: true
            Layout.preferredWidth: 70

            text: Theme.isDark? "Dark mode": "Light mode"
            MouseArea{
                anchors.fill: parent
                onClicked: Theme.toggleTheme()
            }
        }

        StyledIcon{
            Layout.fillHeight: true
            Layout.preferredWidth: 20
            imageSource: Theme.isDark? "../assets/svgs/dark.svg": "../assets/svgs/light.svg"
            imageColor: Theme.bgBaseReverse

            MouseArea{
                anchors.fill: parent
                onClicked: Theme.toggleTheme()
            }
        }
    }

    Connections{
        target: controller

        function onToast(message, level){
            toaster.showMessage(message, level);
        }
    }
}
