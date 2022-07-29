import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Components 1.0
import StatusQ.Core.Theme 1.0

Pane {
    id: root

    background: Rectangle {
        color: Theme.palette.backgroundColor
        Behavior on color { ColorAnimation { duration: 50 } }
    }

    component ColorTile: Rectangle {
        property alias text: label.text
        property alias textColor: label.color

        Layout.preferredWidth: childrenRect.width
        Layout.preferredHeight: childrenRect.height

        StatusLabel {
            id: label
            padding: 8
            anchors.centerIn: parent
            text: "<b>Neutral</b><br>Text: %1<br>Base: %2".arg(color).arg(parent.color)
        }
    }

    component ColorRow: RowLayout {
        id: row
        property string text
        property var color
        StatusLabel {
            Layout.preferredWidth: 100
            text: parent.text
        }
        Repeater {
            model: [Palette.Shade95, Palette.Shade90, Palette.Shade60, Palette.Shade50]
            delegate: Rectangle {
                id: rect
                Layout.preferredWidth: 100
                Layout.preferredHeight: childrenRect.height
                color: row.color(modelData)
                StatusLabel {
                    padding: 8
                    anchors.centerIn: parent
                    text: "%1: %2".arg(modelData).arg(parent.color)
                    color: Theme.palette.white() // FIXME contrast color
                }
            }
        }
    }

    ColumnLayout {
        width: parent.width

        ColorTile {
            color: Theme.palette.baseColor
            text: "<b>Neutral</b><br>Text: %1<br>Base: %2".arg(textColor).arg(color)
        }

        ColorTile {
            color: Theme.palette.baseColor
            opacity: Theme.palette.disabledOpacity
            text: "<b>Neutral disabled</b><br>Text: %1<br>Base: %2".arg(textColor).arg(color)
        }

        ColorTile {
            color: Theme.palette.secondaryBaseColor
            textColor: Theme.palette.secondaryTextColor
            text: "<b>Neutral secondary</b><br>Text: %1<br>Base: %2".arg(textColor).arg(color)
        }

        ColorTile {
            color: Theme.palette.secondaryBaseColor
            opacity: Theme.palette.disabledOpacity
            textColor: Theme.palette.secondaryTextColor
            text: "<b>Neutral secondary disabled</b><br>Text: %1<br>Base: %2".arg(textColor).arg(color)
        }

        ColorRow {
            text: "Neutral:"
            color: function(shade) { return Theme.palette.neutralColor(shade); }
        }

        ColorRow {
            text: "Primary:"
            color: function(shade) { return Theme.palette.primaryColor(shade); }
        }

        ColorRow {
            text: "Success:"
            color: function(shade) { return Theme.palette.successColor(shade); }
        }

        ColorRow {
            text: "Info:"
            color: function(shade) { return Theme.palette.infoColor(shade); }
        }

        ColorRow {
            text: "Warning:"
            color: function(shade) { return Theme.palette.warningColor(shade); }
        }

        ColorRow {
            text: "Danger:"
            color: function(shade) { return Theme.palette.dangerColor(shade); }
        }
    }
}
