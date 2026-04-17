import QtQuick
import Pathfinding

Item {
    //1 - normal state
    //2 - warning
    //3 - error
    id: root

    property string message: ""
    property int level: 0

    function showMessage(message, level){
        if(message && message.trim().length > 0){
            root.message = message;
        }

        if(level > 0 && level < 4){
             root.level = level;
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

        anchors.fill: parent

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
        visible: root.message != ""
        labelColor: root.switchColor(root.level)
        svgColor: root.switchColor(root.level)
    }

}
