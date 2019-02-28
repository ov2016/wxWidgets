

#ifndef menu_h
#define menu_h
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
    void Quit( wxCommandEvent& event );
    void NewFile( wxCommandEvent& event );
    void OpenFile( wxCommandEvent& event );
    void SaveFile( wxCommandEvent& event );
    void SaveFileAs( wxCommandEvent& event );
    void CloseFile( wxCommandEvent& event );
    
private:
    wxMenuBar* menuBar;
    wxTextCtrl* text;
    wxPanel* panel;
    wxString CurrentDocPath;
    DECLARE_EVENT_TABLE()
};

enum
{
    ID_panel,
    ID_tc,      
    ID_new,
    ID_open,
    ID_save,
    ID_saveAs,
    ID_close,
    ID_quit
};

BEGIN_EVENT_TABLE ( Frame, wxFrame )
EVT_MENU(ID_new, Frame::NewFile)
EVT_MENU(ID_open, Frame::OpenFile)
EVT_MENU(ID_close, Frame::CloseFile)
EVT_MENU(ID_save, Frame::SaveFile)
EVT_MENU(ID_saveAs, Frame::SaveFileAs)
EVT_MENU(ID_quit, Frame::Quit)
END_EVENT_TABLE()

#endif /* menu_h */
