pragma Singleton
import QtQuick

// This file defines the color palette for the application, including both light and dark themes.
// The palette was taken from the Catppuccin palette, see https://catppuccin.com/palette/

QtObject {
    id: root

    property bool isDark: true

    property color bgBase: isDark ? "#1e1e2e" : "#eff1f5"
    property color bgBaseReverse: isDark? "#eff1f5": "#1e1e2e"
    property color bgGrid: isDark? "#181825": "#e6e9ef"
    property color bgMantle: isDark ? "#181825" : "#e6e9ef"

    //surface
    property color surface0: isDark ? "#313244" : "#ccd0da"
    property color surface1: isDark ? "#45475a" : "#bcc0cc"
    property color surface2: isDark ? "#585b70" : "#acb0be"
    property color slider: isDark? "#a6e3a1": "#40a02b"

    property color textMain: isDark ? "#cdd6f4" : "#4c4f69"
    property color textSub: isDark ? "#bac2de" : "#5c5f77"
    property color primary: isDark ? "#cba6f7" : "#8839ef"
    property color primaryHover: isDark ? "#b4befe" : "#7287fd"

    //grid
    property color startNode: isDark ? "#a6e3a1" : "#40a02b"
    property color endNode: isDark ? "#f38ba8" : "#d20f39"
    property color path: "#ffd700"
    property color visited: "#74c7ec"
    property color wall: isDark? "#7f849c": "#8c8fa1"
    property color empty: isDark? "#89dceb": "#04a5e5"
    property color weightLight: isDark? "#a6e3a1": "#40a02b"
    property color weightMiddle: isDark? "#fab387": "#fe640b"
    property color weightHeavy: isDark? "#eba0ac": "#e64553"

    //status
    property color warning: isDark? "#f9e2af": "#df8e1d"
    property color error: isDark? "#f38ba8": "#d20f39"

    function toggleTheme() {
        isDark = !isDark
    }
}
