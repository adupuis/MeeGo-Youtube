import QtQuick 1.0

Rectangle {
    id: qtubethumbail
    property url image_src: "../../../QTubeUX/images/hqdefault.1.jpg"
    property string video_title_text: qsTr("This is a video title")
    property string video_duration: qsTr("01:00")
    property string video_author: qsTr("Author Name")
    property bool is_hd: false
    color: "#00000000"

    Image {
        id: image1
        width: 160
        height: 120
        anchors.rightMargin: -160
        anchors.bottomMargin: -120
        anchors.fill: parent
        source: image_src
    }

    Rectangle {
        id: rectangle1
        x: 0
        y: 60
        width: 160
        height: 60
        color: "#000000"
        opacity: 0.820

        Text {
            id: duration
            x: 5
            y: 3
            color: "#ffffff"
            text: video_duration
            style: Text.Normal
            font.bold: true
            smooth: true
            font.family: "Droid Serif [unknown]"
            verticalAlignment: Text.AlignVCenter
            font.pixelSize: 13
        }

        Text {
            id: title
            x: 5
            y: 23
            width: 148
            height: 14
            color: "#ffffff"
            text: video_title_text
            wrapMode: Text.WordWrap
            font.family: "Droid Sans Mono [unknown]"
            verticalAlignment: Text.AlignVCenter
            smooth: true
            font.pixelSize: 12
        }

        Text {
            id: author
            x: 5
            y: 44
            width: 148
            height: 14
            color: "#ffffff"
            text: video_author
            font.italic: false
            font.bold: true
            wrapMode: Text.WordWrap
            smooth: true
            font.family: "Droid Sans Mono [unknown]"
            font.pixelSize: 12
        }

        Text {
            id: hd_text
            x: 136
            y: 3
            width: 22
            height: 17
            color: "#ffffff"
            text: ""
            styleColor: "#ffffff"
            font.bold: true
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
            smooth: true
            font.pixelSize: 14
        }

        states: State {
            name: "hd_state"
            PropertyChanges { target: hd_text; text: qsTr("HD") }
            when: qtubethumbail.is_hd
        }
    }
}
