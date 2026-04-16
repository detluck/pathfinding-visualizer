pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects
import Pathfinding
import App.Controller 1.0

Item {
    id: root

    property bool isEditing: false
    property int delegateWidth: 40

    implicitWidth: button.implicitWidth > 0? button.implicitWidth: 120
    implicitHeight: button.implicitHeight > 0? button.implicitHeight: 50

    StyledButton{
        id: button
        anchors.fill: parent
        svgPath: "../assets/svgs/weight.svg"
        text: "Weight node"
        onClicked: popup.open()
    }

    Popup{
        id: popup
        modal: true

        background: Rectangle{
            color: Theme.surface0
            border.color: Theme.surface2
            radius: 20
        }

        ColumnLayout{
            anchors.centerIn: parent
            spacing: 0

            StyledText{
                text: "Select Node weight"
                font.bold: true
                Layout.alignment: Qt.AlignCenter
            }

            Grid{
                Layout.fillWidth: true
                columnSpacing: 10
                rowSpacing: 30
                columns: 4
                padding: 15

                Repeater{
                    model: controller.availableWeights

                    delegate: Rectangle{
                        id: delegateItem
                        required property int modelData

                        width: root.delegateWidth
                        height: root.delegateWidth
                        border.width: 2
                        border.color: Theme.surface1
                        radius: 10
                        color: "transparent"

                        Item {
                            id: image
                            height: 25
                            width: 25
                            anchors.centerIn: parent

                            Image {
                                id: svgIcon
                                source:  "../assets/svgs/weight.svg"
                                sourceSize.height: parent.height
                                sourceSize.width: parent.width
                                fillMode: Image.PreserveAspectFit
                                visible: false
                            }

                            MultiEffect {
                                id: svgEffect
                                source: svgIcon
                                anchors.fill: parent
                                opacity: Math.max(0.2, modelData/ 100.0)
                                colorization: 1.0
                                colorizationColor: {
                                    switch(true){
                                        case modelData <= 33:
                                            return Theme.weightLight
                                        case modelData <= 66:
                                            return Theme.weightMiddle
                                        case modelData <= 100:
                                            return Theme.weightHeavy
                                        default:
                                            return Theme.bgBaseReverse
                                    }
                                }

                                Behavior on colorizationColor {
                                    ColorAnimation {
                                        duration: 250
                                    }
                                }
                            }
                        }

                        StyledText{
                            id: label
                            anchors.top: image.bottom
                            anchors.topMargin: 10
                            anchors.horizontalCenter: image.horizontalCenter
                            text: delegateItem.modelData
                        }

                        MouseArea{
                            anchors.fill: parent

                            onClicked: {
                                controller.currentWeight = modelData
                                controller.type = Controller.WeightNode
                                button.changeCursor()
                                popup.close()
                            }
                        }
                    }
                }

                Rectangle{
                    id: newButton

                    width: delegateWidth
                    height: delegateWidth
                    border.width: 2
                    border.color: Theme.surface1
                    radius: 10
                    color: "transparent"

                    StyledText{
                        anchors.centerIn: parent
                        text: "+"
                        visible: !isEditing
                    }

                    TextField{
                        id: newField
                        visible: isEditing
                        anchors.fill: parent
                        z:999

                        color: Theme.textMain

                        cursorDelegate: Rectangle {
                            width: 2
                            color: Theme.textMain

                            SequentialAnimation on opacity {
                                loops: Animation.Infinite
                                running: newField.activeFocus

                                NumberAnimation { to: 1; duration: 0 }
                                PauseAnimation { duration: 500 }

                                NumberAnimation { to: 0; duration: 0 }
                                PauseAnimation { duration: 500 }
                            }
                        }

                        background: Rectangle{
                            color: "transparent"
                        }

                        inputMethodHints: Qt.ImhFormattedNumbersOnly
                        validator: IntValidator{
                            bottom: 0
                            top: 1000
                        }

                        onVisibleChanged: {
                            if (visible) {
                                forceActiveFocus()
                            }
                        }

                        onAccepted: {
                            let weight = parseInt(text)
                            if (!isNaN(weight)) {

                                controller.addWeight(weight);
                                text = ""
                                root.isEditing = false
                            }
                        }
                    }

                    MouseArea{
                        anchors.fill: newButton

                        onClicked: {
                            isEditing = !isEditing
                        }
                    }
                }
            }
        }
    }
}
