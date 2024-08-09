// COPYRIGHT_BEGIN
//
// The MIT License (MIT)
//
// Copyright (c) 2019-2024 Wizzer Works
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//
//  For information concerning this header file, contact Mark S. Millard,
//  of Wizzer Works at msm@wizzerworks.com.
//
//  More information concerning Wizzer Works may be found at
//
//      http://www.wizzerworks.com
//
// COPYRIGHT_END

// Include Open Inventor header files.
#include <QApplication>

#include <Inventor/nodes/SoBaseColor.h>
#include <Inventor/nodes/SoCone.h>
#include <Inventor/nodes/SoSeparator.h>

#include <Quarter/Quarter.h>
#include <Quarter/QuarterWidget.h>

using namespace SIM::Coin3D::Quarter;

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    // Initialize Quarter (and implicitly Coin). This returns a main window to use.
    // If unsuccessful, exit.
    Quarter::init();

    // Create a scene graph by using the Coin library,
    // containing a single yellow cone under the scenegraph root.
    SoSeparator * root = new SoSeparator;
    root->ref();

    SoBaseColor * col = new SoBaseColor;
    col->rgb = SbColor(1, 1, 0);
    root->addChild(col);
    root->addChild(new SoCone);

    // Create a QuarterWidget for displaying a Coin scene graph.
    QuarterWidget * viewer = new QuarterWidget;
    viewer->setSceneGraph(root);

    // Make the viewer react to input events similar to the good old
    // ExaminerViewer.
    viewer->setNavigationModeFile(QUrl("coin:///scxml/navigation/examiner.xml"));

    // Pop up the QuarterWidget.
    viewer->show();

    // Set current camera position to view the entire scene graph.
    viewer->viewAll();

    // Loop until exit.
    app.exec();

    // Clean up resources.
    root->unref();
    delete viewer;
    Quarter::clean();

    return 0;
}
