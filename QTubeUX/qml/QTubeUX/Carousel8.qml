/*************************************************************************
 *
 * Copyright (c) 2011, Nokia Corporation and/or its subsidiary(-ies).
 * All rights reserved.
 *
 * See the LICENSE.txt file shipped along with this file for the license.
 *
 *************************************************************************/

import QtQuick 1.0

Rectangle {
    width: 1366
    height: 768
    color: "black"
    PathView {
        id: view
        x: -38
        focus: true
        width: parent.width
        height: parent.height + y
        y: -141
        model: Menu8 {}
//        delegate: Image {
//            source: iconSource
//            width: 64
//            height: 64
//            scale: 4. * y / parent.height
//            z: y
//            smooth: true
//            opacity: scale / 3.
//        }
        delegate: QTubeThumbnailStack{
            scale: 4* (x / view.width / 2)

            thumb1_image_src: src1
            thumb1_video_title_text: text1
            thumb1_video_duration: duration1
            thumb1_video_author: author1
            thumb1_is_hd: hd1

            thumb2_image_src: src2
            thumb2_video_title_text: text2
            thumb2_video_duration: duration2
            thumb2_video_author: author2
            thumb2_is_hd: hd2

            thumb3_image_src: src3
            thumb3_video_title_text: text3
            thumb3_video_duration: duration3
            thumb3_video_author: author3
            thumb3_is_hd: hd3
        }
        path: Ellipse8 {
            width: 2000
            height: view.height
        }
        preferredHighlightBegin: 0
        preferredHighlightEnd: 0
        highlightRangeMode: PathView.StrictlyEnforceRange
        Keys.onLeftPressed: decrementCurrentIndex()
        Keys.onRightPressed: incrementCurrentIndex()

        Flickable {
            id: flickable1
            x: 46
            y: 151
            width: 1346
            height: 754
        }
    }
//    Text {
//        id: label
//        text: view.model.title(view.currentIndex)
//        color: "paleturquoise"
//        font.pixelSize: 16
//        font.bold: true
//        anchors.horizontalCenter: parent.horizontalCenter
//        anchors.bottom: parent.bottom
//    }
}
