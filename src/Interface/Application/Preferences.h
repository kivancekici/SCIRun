/*
   For more information, please see: http://software.sci.utah.edu

   The MIT License

   Copyright (c) 2012 Scientific Computing and Imaging Institute,
   University of Utah.

   License for the specific language governing rights and limitations under
   Permission is hereby granted, free of charge, to any person obtaining a
   copy of this software and associated documentation files (the "Software"),
   to deal in the Software without restriction, including without limitation
   the rights to use, copy, modify, merge, publish, distribute, sublicense,
   and/or sell copies of the Software, and to permit persons to whom the
   Software is furnished to do so, subject to the following conditions:

   The above copyright notice and this permission notice shall be included
   in all copies or substantial portions of the Software.

   THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
   OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
   FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
   THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
   LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
   FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
   DEALINGS IN THE SOFTWARE.
*/

#ifndef INTERFACE_APPLICATION_PREFERENCES_H
#define INTERFACE_APPLICATION_PREFERENCES_H

#include "ui_Preferences.h"

namespace SCIRun {
namespace Gui {

  class NetworkEditor;

class PreferencesWindow : public QDialog, public Ui::PreferencesDialog
{
	Q_OBJECT
	
public:
  explicit PreferencesWindow(NetworkEditor* editor, QWidget* parent = 0);
  
  bool isRegression() const { return regressionMode_; }
  void setRegressionMode(bool mode) { regressionMode_ = mode; }

  QString regressionTestDataDir() const { return regressionTestDataDir_; }
  void setRegressionTestDataDir(const QString& dir) { regressionTestDataDir_ = dir; }

  void setDisableModuleErrorDialogs(bool disableModuleErrorDialogs) { disableModuleErrorDialogs_ = disableModuleErrorDialogs; }
  bool disableModuleErrorDialogs() const { return disableModuleErrorDialogs_; }

public Q_SLOTS:
  void updateRegressionTestDataDir();
  void setRegressionTestDataDir();
  
private:
  NetworkEditor* networkEditor_;
  bool regressionMode_, disableModuleErrorDialogs_;
  QString regressionTestDataDir_;
};

}
}

#endif
