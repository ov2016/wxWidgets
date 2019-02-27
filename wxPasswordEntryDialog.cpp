#include <wx/wx.h>

class App : public wxApp
{
public:
    virtual bool OnInit();
};

class Frame : public wxFrame
{
public:
    Frame(const wxString& title);
    
};

IMPLEMENT_APP(App)

bool App::OnInit()
{
    Frame* frame = new Frame(wxString ("My Frame"));
    frame->Show(true);
    return true;
}

Frame::Frame(const wxString& title):wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxDefaultSize)
{
    CreateStatusBar(1);
    wxPasswordEntryDialog pw(this,"Enter your password", "PASSWORD", wxEmptyString, wxOK | wxCANCEL );
    while (pw.ShowModal() == wxOK)
    {
        pw.GetValue();
    }
        if (pw.GetValue() == "password")
        {
            // Show Frame
        }else
    {
        Close();
    }
   
    Center();
}
