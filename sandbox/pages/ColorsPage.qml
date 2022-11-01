import QtQuick 2.15
import QtQuick.Layouts 1.15
import QtQuick.Controls 2.15

import StatusQ.Core.Theme 1.0

Pane {
    id: root

    component ColorTile: Rectangle {
        property alias text: label.text
        property alias textColor: label.color

        Layout.preferredWidth: childrenRect.width
        Layout.preferredHeight: childrenRect.height

        Label {
            id: label
            padding: Theme.metrics.halfPadding
            anchors.centerIn: parent
            text: "<b>Neutral</b><br>Text: %1<br>Base: %2".arg(color).arg(parent.color)
        }
    }

    component ColorRow: RowLayout {
        id: row
        property string text
        property var color
        property var model: [Palette.Shade95, Palette.Shade90, Palette.Shade80, Palette.Shade70, Palette.Shade60,
            Palette.Shade50, Palette.Shade40, Palette.Shade30, Palette.Shade20, Palette.Shade10, Palette.Shade5]

        Label {
            Layout.preferredWidth: 100
            text: parent.text
        }
        Repeater {
            model: parent.model
            delegate: Rectangle {
                id: rect
                Layout.preferredWidth: 100
                Layout.preferredHeight: childrenRect.height
                color: row.color(modelData)
                Label {
                    padding: Theme.metrics.halfPadding
                    anchors.centerIn: parent
                    text: "%1: %2".arg(modelData).arg(parent.color)
                    font.bold: modelData === Palette.Shade50
                    color: modelData < Palette.Shade50 ? Theme.palette.neutralColor(Palette.Shade90)
                                                       : Theme.palette.white()
                }
            }
        }
    }

    component CustomizationRow: Flow {
        Layout.preferredWidth: parent.width
        spacing: 5

        Label {
            width: 100
            text: "Custom:"
        }
        Repeater {
            model: Object.entries(Theme.palette.customizationColors)
            delegate: Rectangle {
                width: customizationLabel.width
                height: customizationLabel.height
                color: modelData[1]
                Label {
                    id: customizationLabel
                    padding: Theme.metrics.halfPadding
                    anchors.centerIn: parent
                    text: "%1: %2".arg(modelData[0]).arg(parent.color)
                    color: Theme.palette.white() // TODO contrasting color
                }
            }
        }
    }

    component IdenticonRow: Flow {
        Layout.preferredWidth: parent.width
        spacing: 5

        Label {
            width: 100
            text: "Identicon:"
        }
        Repeater {
            model: Theme.palette.identiconColors
            delegate: Rectangle {
                width: identiconLabel.width
                height: identiconLabel.height
                color: modelData
                Label {
                    id: identiconLabel
                    padding: Theme.metrics.halfPadding
                    anchors.centerIn: parent
                    text: modelData
                    color: Theme.palette.white() // TODO contrasting color
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
            color: (shade) => Theme.palette.neutralColor(shade)
        }

        ColorRow {
            text: "Primary:"
            color: (shade) => Theme.palette.primaryColor(shade)
        }

        ColorRow {
            text: "Success:"
            color: (shade) => Theme.palette.successColor(shade)
        }

        ColorRow {
            text: "Info:"
            color: (shade) => Theme.palette.infoColor(shade)
        }

        ColorRow {
            text: "Warning:"
            color: (shade) => Theme.palette.warningColor(shade)
        }

        ColorRow {
            text: "Danger:"
            color: (shade) => Theme.palette.dangerColor(shade)
        }

        CustomizationRow {}

        IdenticonRow {}
    }
}
