pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects
import Pathfinding
import App.Controller 1.0

Item {
    id: root

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
        width: 400
        height: 200
        modal: true

        background: Rectangle{
            color: Theme.surface0
            border.color: Theme.surface2
            radius: 20
        }

        ColumnLayout{
            anchors.fill: parent
            anchors.margins: 15

            StyledText{
                text: "Select Node weight or create one"
                font.bold: true
            }

            Flow{
                Layout.fillWidth: true
                spacing: 10

                Repeater{
                    model: controller.availableWeights

                    delegate: Rectangle{
                        id: delegateItem
                        required property int modelData

                        width: 30
                        height: 30
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
            }
        }
    }
}
