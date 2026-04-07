pragma Singleton
import QtQuick

//appearance properties
QtObject {
    id: root

    property bool isDark: false
    readonly property QtObject current: isDark? dark: light

        property QtObject dark: QtObject{
            property color backgroundMain: "#0f1117"
            property color backgroundPanel: "#161a23"
            property color backgroundGrid: "#0b0e14"
            property color hoverBtn: Qt.rgba(0, 0, 0, 0.2)
            property color pressedBtn: Qt.rgba(0, 0, 0, 0.4)

            property color textPrimary: "#e6e6eb"
            property color textSecondary: "#9aa0b2"
            property color textMuted: "#5f6475"

            property color cellEmpty: "#0b0e14"
            property color cellWall: "#2a2f3a"
            property color cellStart: "#00d1b2"
            property color cellEnd: "#ff4d6d"
            property color cellVisited: "#3a86ff"
            property color cellFrontier: "#5fa8ff"
            property color cellPath: "#ffd166"
        }
        property QtObject light: QtObject{
            property color backgroundMain: "#f5f7fb"
            property color backgroundPanel: "#ffffff"
            property color backgroundGrid: "#e9edf5"
            property color hoverBtn: Qt.rgba(0, 0, 0, 0.06)
            property color pressedBtn: Qt.rgba(0, 0, 0, 0.12)
            property color textPrimary: "#1c1f26"
            property color textSecondary: "#4b5563"
            property color textMuted: "#8a94a6"
            property color cellEmpty: "#e9edf5"
            property color cellWall: "#c7cedb"
            property color cellStart: "#00b894"
            property color cellEnd: "#e63946"
            property color cellVisited: "#3a86ff"
            property color cellFrontier: "#74a9ff"
            property color cellPath: "#ffbe0b"
        }

    property QtObject padding: QtObject{
        property int small: 8
        property int middle: 16
        property int big: 24
    }

    property QtObject radius:QtObject{
        property int small: 4
        property int middle: 14
        property int round: 99
    }

    property QtObject animationSpeed: QtObject{
        property int middle: 200
    }

    property QtObject font: QtObject{
        property QtObject family: QtObject{
            property string main: "JetBrains Mono"
        }
        property QtObject size: QtObject {
            property int smallest: 10
            property int smaller: 12
            property int smallie: 13
            property int small: 15
            property int normal: 16
            property int large: 17
            property int larger: 19
            property int big: 21
            property int huge: 22
            property int hugeass: 23
            property int wildass: 40
            property int title: huge

            property QtObject icon: QtObject {
                property int smallest: 10
                property int smaller: 12
                property int small: 14
                property int normal: 16
                property int large: 17
                property int larger: 19
                property int huge: 22
                property int hugeass: 23
            }
        }
    }
}
