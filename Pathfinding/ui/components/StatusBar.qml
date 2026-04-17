import QtQuick
import Pathfinding

Rectangle{
    height: 30
    color: Theme.bgBase

    Toaster{
        id: toaster

        anchors.left: parent.left
        anchors.verticalCenter: parent.verticalCenter
        anchors.leftMargin: 20
    }

    Connections{
        target: controller

        function onToast(message, level){
            toaster.showMessage(message, level);
        }
    }
}
