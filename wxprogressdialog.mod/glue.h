/*
  Copyright (c) 2007,2008 Bruce A Henderson
 
  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:
  
  The above copyright notice and this permission notice shall be included in
  all copies or substantial portions of the Software.
  
  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
  THE SOFTWARE.
*/ 

#include "wxglue.h"
#include "wx/progdlg.h"

class MaxProgressDialog;

extern "C" {

#include <blitz.h>

	wxProgressDialog * bmx_wxprogressdialog_create(BBObject * handle, BBString * title, BBString * message, int maximum, wxWindow * parent, int style);
	void bmx_wxprogressdialog_resume(wxProgressDialog * dialog);
	bool bmx_wxprogressdialog_updateprogress(wxProgressDialog * dialog, int value, BBString * newMessage, bool * skip);
	bool bmx_wxprogressdialog_pulse(wxProgressDialog * dialog, BBString * newMessage, bool * skip);

}

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

class MaxProgressDialog : public wxProgressDialog
{
public:
	MaxProgressDialog(BBObject * handle, const wxString& title, const wxString& message, int max,
		wxWindow * parent, int style);
	~ MaxProgressDialog();
	
};
