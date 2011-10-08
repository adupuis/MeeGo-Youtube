import QtQuick 1.0

Rectangle {
    width: 160
    height: 380
    color: "#00000000"
    property url thumb1_image_src: "../../../QTubeUX/images/hqdefault.1.jpg"
    property string thumb1_video_title_text: qsTr("This is a video title")
    property string thumb1_video_duration: qsTr("01:00")
    property string thumb1_video_author: qsTr("Author Name")
    property bool thumb1_is_hd: false

    property url thumb2_image_src: "../../../QTubeUX/images/hqdefault.1.jpg"
    property string thumb2_video_title_text: qsTr("This is a video title")
    property string thumb2_video_duration: qsTr("01:00")
    property string thumb2_video_author: qsTr("Author Name")
    property bool thumb2_is_hd: false

    property url thumb3_image_src: "../../../QTubeUX/images/hqdefault.1.jpg"
    property string thumb3_video_title_text: qsTr("This is a video title")
    property string thumb3_video_duration: qsTr("01:00")
    property string thumb3_video_author: qsTr("Author Name")
    property bool thumb3_is_hd: false

    QTubeThumbnail {
        id: qtubethumbnail1
        x: 0
        y: 0
        image_src: thumb1_image_src
        video_title_text: thumb1_video_title_text
        video_duration: thumb1_video_duration
        video_author: thumb1_video_author
        is_hd: thumb1_is_hd
    }

    QTubeThumbnail {
        id: qtubethumbnail2
        x: 0
        y: 130
        image_src: thumb2_image_src
        video_title_text: thumb2_video_title_text
        video_duration: thumb2_video_duration
        video_author: thumb2_video_author
        is_hd: thumb2_is_hd
    }

    QTubeThumbnail {
        id: qtubethumbnail3
        x: 0
        y: 260
        image_src: thumb3_image_src
        video_title_text: thumb3_video_title_text
        video_duration: thumb3_video_duration
        video_author: thumb3_video_author
        is_hd: thumb3_is_hd
    }
}
