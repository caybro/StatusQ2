import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

import StatusQ.Core 1.0
import StatusQ.Core.Theme 1.0

Button {
    id: root

    // close button
    property bool removable

    enum Type {
        Normal,
        Primary,
        Success,
        Warning,
        Error
    }
    property int type: StatusTag.Type.Normal

    enum Size {
        ThirtyTwoPx,
        TwentyFourPx
    }
    property int size: StatusTag.Size.ThirtyTwoPx

    property string prefix
    property string label: text

    // stringlists of token symbols
    property var leftTokens: []
    property var rightTokens: []

    signal removeClicked()

    // TODO move to T.Button?
    opacity: enabled ? 1 : Theme.palette.disabledOpacity
    spacing: 4
    horizontalPadding: size === StatusTag.Size.TwentyFourPx ? 12 : 16
    verticalPadding: 0
    icon.color: Theme.palette.textColor
    // end T.Button

    implicitHeight: size === StatusTag.Size.TwentyFourPx ? 24 : 32

    font.weight: Font.Medium
    font.pixelSize: size === StatusTag.Size.TwentyFourPx ? 11 : 13

    indicator: null

    background: Rectangle {
        radius: 20
        color: Theme.palette.secondaryBaseColor // TODO more Type
        border.width: 1
        border.color: Theme.palette.baseColor // TODO more Type
    }

    contentItem: RowLayout {
        spacing: root.spacing
        StatusIcon {
            Layout.preferredWidth: visible ? width : 0
            visible: !!icon
            small: true
            icon: root.icon.name
            color: root.icon.color
        }
        // TODO leftTokens
        Label {
            Layout.preferredWidth: visible ? width : 0
            visible: text
            text: root.prefix
            font: root.font
            color: Theme.palette.secondaryTextColor
        }
        Label {
            Layout.preferredWidth: visible ? width : 0
            visible: text
            text: root.label
            font: root.font
        }
        // TODO rightTokens
        StatusIcon {
            // TODO make this bgless ToolButton
            Layout.preferredWidth: visible ? width : 0
            visible: root.removable
            icon: "Close"
            color: Theme.palette.secondaryTextColor
            TapHandler {
                onTapped: root.removeClicked()
            }
        }
    }
}
