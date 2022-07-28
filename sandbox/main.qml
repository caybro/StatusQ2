import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import QtQuick.Window 2.15

import StatusQ.Components 1.0
import StatusQ.Core.Theme 1.0

ApplicationWindow {
    id: root
    width: 1024
    height: 768
    visible: true
    title: qsTr("StatusQ2 Sandbox")

    color: Theme.palette.backgroundColor
    Behavior on color { ColorAnimation { duration: 50 } }

    //    Component.onCompleted: {
    //        Theme.type = Palette.Type.Dark
    //    }

    ListModel {
        id: pageModel
        ListElement {
            name: "Colors"
            category: "Basics"
            source: "pages/Colors.qml"
        }
        ListElement {
            name: "StatusCheckBox"
            category: "Controls"
            source: "pages/StatusCheckBoxPage.qml"
        }
        ListElement {
            name: "StatusLabel"
            category: "Controls"
            source: "pages/StatusLabelPage.qml"
        }
        ListElement {
            name: "StatusRadioButton"
            category: "Controls"
            source: "pages/StatusRadioButtonPage.qml"
        }
        ListElement {
            name: "StatusSwitch"
            category: "Controls"
            source: "pages/StatusSwitchPage.qml"
        }
        ListElement {
            name: "StatusTextField"
            category: "Controls"
            source: "pages/StatusTextFieldPage.qml"
        }
    }

    header: ToolBar {
        id: toolbar
        leftPadding: 8
        background: Rectangle {
            color: Theme.palette.baseColor
            Behavior on color { ColorAnimation { duration: 50 } }
        }

        RowLayout {
            anchors.fill: parent
            RowLayout {
                StatusSwitch {
                    id: themeSwitch
                    checked: Theme.type === Palette.Type.Dark
                    text: checked ? "Dark" : "Light"
                    onToggled: Theme.type = checked ? Palette.Type.Dark : Palette.Type.Light
                    ToolTip.text: "Current theme: %1".arg(Theme.palette.name)
                    ToolTip.visible: themeSwitch.hovered
                }
                StatusLabel {
                    enabled: false
                    text: "(bg color: %1)".arg(Theme.palette.backgroundColor)
                }
            }
            StatusLabel {
                anchors.centerIn: parent
                font.bold: true
                text: pagesListView.currentItem ? pageModel.get(pagesListView.currentIndex).name : ""
            }
            ToolButton {
                Layout.alignment: Qt.AlignRight
                text: qsTr("⋮")
                onClicked: drawer.visible ? drawer.close() : drawer.open()
            }
        }
    }

    Drawer {
        id: drawer
        edge: Qt.RightEdge
        width: 0.4 * parent.width
        y: toolbar.height
        height: parent.height - y
        background: Rectangle {
            color: Theme.palette.backgroundColor
            Behavior on color { ColorAnimation { duration: 50 } }
        }

        ListView {
            id: pagesListView
            anchors.fill: parent
            anchors.margins: 8
            model: pageModel
            currentIndex: -1
            section.property: "category"
            section.delegate: StatusLabel {
                text: section
            }

            delegate: ItemDelegate {
                width: ListView.view.width
                text: model.name
                highlighted: ListView.isCurrentItem
                font.bold: ListView.isCurrentItem
                onClicked: {
                    if (index !== ListView.view.currentIndex) {
                        ListView.view.currentIndex = index
                        stack.push(model.source)
                    }
                    drawer.close()
                }
            }
        }
    }

    StackView {
        id: stack
        anchors.fill: parent
        background: Rectangle {
            color: Theme.palette.backgroundColor
            Behavior on color { ColorAnimation { duration: 50 } }
        }
        initialItem: StatusLabel {
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: 32
            font.weight: Font.DemiBold
            text: "Welcome to StatusQ Sandbox<br><font size='-2'>Choose the page from the menu in the upper left corner</font>"
        }
    }
}
