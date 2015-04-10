/*************************************************************
*File Name: GeneratedCodeItem.qml
*Author: Match
*Email: Match.YangWanQing@gmail.com
*Created Time: 2015年04月21日 星期二 14时16分07秒
*Description:
*
*************************************************************/
import QtQuick 2.1
import Deepin.Widgets 1.0

Item {


    function setCodeText(value){
        codeText.text = value
    }

    Rectangle {
        id: contentRec2
        width: parent.width
        height: childrenRect.height
        anchors.top: parent.top
        color: dconstants.contentBgColor

        TextEdit {
            id: codeText
            enabled: false
            width: parent.width
            height: 50
            font.pixelSize: 24
            color: dconstants.activeColor
            horizontalAlignment: Text.AlignHCenter
            verticalAlignment: Text.AlignVCenter
            anchors {top: parent.top; horizontalCenter: parent.horizontalCenter}
            text: "kfjfhf"
        }

        Text {
            id: tipText
            width: parent.width - 16 * 2
            height: contentHeight + 10
            lineHeight: 1.3
            horizontalAlignment: Text.AlignLeft
            verticalAlignment: Text.AlignVCenter
            wrapMode: Text.Wrap
            font.pixelSize: 10
            color: "#7C7C7C"
            anchors {top: codeText.bottom; topMargin: 10; horizontalCenter: parent.horizontalCenter}
            text: dsTr("To start sharing your desktop, please provide the above verification code to whom will assist you;  your shared session will begin immediately after verification code input")
        }
    }

    DSeparatorHorizontal {
        id:createdTextSeparator
        anchors.top: contentRec2.bottom
    }

    Row {
        anchors {right: parent.right; rightMargin: 8; top: createdTextSeparator.bottom; topMargin: 5}
        spacing: 5


        DTextButton {
            text: dsTr("Copy")

            onClicked: {
                codeText.selectAll()
                codeText.copy()
                codeText.deselect()
            }
        }

        DTextButton {
            text: dsTr("Cancel")

            onClicked: {
                reset()
                remotingServer.Stop()
            }
        }
    }
}
