pragma ComponentBehavior: Bound
import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Effects
import Pathfinding

Item {

    StyledButton{
        id: button
        anchors.fill: parent
        svgPath: "../assets/svgs/terminate.svg"

        onClicked: popup.open()
    }

    Popup{
        id: popup
        width: button.width
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
                        width: 30
                        height: 30
                        color: Theme.surface1

                        Item {
                            id: image
                            height: root.iconSize
                            width: root.iconSize
                            anchors.verticalCenter: parent.verticalCenter

                            Image {
                                id: svgIcon
                                source:  "../assets/svgs/terminate.svg"
                                sourceSize.height: parent.height
                                sourceSize.width: parent.width
                                fillMode: Image.PreserveAspectFit
                                visible: false
                            }

                            MultiEffect {
                                id: svgEffect
                                source: svgIcon
                                anchors.fill: parent
                                colorization: 1.0
                                colorizationColor: Theme.bgBase

                                Behavior on colorizationColor {
                                    ColorAnimation {
                                        duration: 250
                                    }
                                }
                            }
                        }

                        StyledText{
                            id: label
                            required property int modelData
                            anchors.top: image.bottom
                            text: modelData
                        }
                    }
                }
            }
        }
    }
}
