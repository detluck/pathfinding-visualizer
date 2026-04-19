import QtQuick
import Pathfinding

Item {
    //1 - normal state
    //2 - warning
    //3 - error
    id: root

    property string message: ""
    property int level: 0
    property bool isShown: false

    function showMessage(message, level){
        if(message && message.trim().length > 0){
            switch(level){
                case 1:
                    root.message = message;
                    timer.start();
                    break;
                case 2: root.message = "[Warning] " + message; break;
                case 3: root.message = "[Error] " + message; break;
                default: root.message = message; break;
            }
            if(level > 0 && level < 4){
                 root.level = level;
            }
            isShown = true;
        }
    }

    function switchColor(type){
        switch(type){
            case 1: return Theme.textSub
            case 2: return Theme.warning
            case 3: return Theme.error
            default: return Theme.textSub
        }
    }

    StyledButton{
        id: statusButton

        anchors.verticalCenter: parent.verticalCenter
        hoverEnabled: false
        opacity: root.isShown? 1.0: 0.0
        backgroundColor: "transparent"
        svgPath:{
            switch(root.level){
                    case 1: return "../assets/svgs/status.svg"
                    case 2: return "../assets/svgs/warning.svg"
                    case 3: return "../assets/svgs/error.svg"
                    default: return ""
            }
        }
        text: root.message
        visible: root.message != "" && root.isShown
        labelColor: root.switchColor(root.level)
        svgColor: root.switchColor(root.level)

        Behavior on opacity {
            NumberAnimation {
                duration: 300
                easing.type: Easing.InOutQuad
            }
        }
    }

    Timer{
        id: timer

        interval: 5000
        onTriggered: {
            isShown = false
            root.message = ""
        }
    }

}
