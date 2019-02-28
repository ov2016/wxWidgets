
#include"menu.h"
IMPLEMENT_APP(App)

bool App::OnInit()
{
    Frame* frame = new Frame(wxString ("My Frame"));
    frame->Show(true);
    return true;
}

Frame::Frame(const wxString& title):wxFrame(NULL,wxID_ANY,title,wxDefaultPosition,wxSize(1000,700))
{
    CreateStatusBar(1);
    wxMenuBar* menuBar = new wxMenuBar;
    wxMenu* file = new wxMenu;
    wxMenu* edit = new wxMenu;
    menuBar->Append(file, "&File");
    menuBar->Append(edit, "&Edit");
    file->Append(ID_new, "&New");
    file->Append(ID_open, "&Open");
    file->Append(ID_close,("&Close"),("CLOSE THE CURRENT FILE"));
    file->Append(ID_save, "&Save");
    file->Append(ID_saveAs,("&Save As"),("SAVE CURRENT DOCUMENT UNDER NEW NAME"));
    file->AppendSeparator();
    file->Append(wxID_EXIT, "&Quit");
    file->AppendSeparator();
    edit->Append(wxID_SELECTALL, "&SelectAll");
    edit->Append(wxID_COPY, "&Copy");
    edit->Append(wxID_CUT, "&Cut");
    edit->Append(wxID_CLEAR, "&Clear");
    edit->Append(wxID_PASTE, "&Paste");
    SetMenuBar(menuBar);
    
    panel = new wxPanel(this,wxID_ANY,wxDefaultPosition,wxDefaultSize,wxEXPAND);
    wxBoxSizer* hbox = new wxBoxSizer(wxHORIZONTAL);
    text = new wxTextCtrl(panel,wxID_ANY,wxEmptyString,wxDefaultPosition,wxDefaultSize,wxTE_MULTILINE);
    hbox->Add(text,1, wxALL | wxEXPAND, 15);
    panel->SetSizer(hbox);
    Center();
}

void Frame::NewFile(wxCommandEvent& WXUNUSED(event))
{
    text->Clear();
    CurrentDocPath = wxT("/");
    SetTitle(_("Edit - untitled *"));
    text->AppendText(wxString(wxT("")));
}

void Frame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog *OpenDialog = new wxFileDialog( this,("Choose a file to  open"),wxEmptyString ,wxEmptyString ,("Text files (*.txt)|*.txt|C++ Source Files (*.cpp, *.cxx)|*.cpp;*.cxx|C Source files (*.c)|*.c|C header files (*.h)|*.h") ,wxFD_OPEN , wxDefaultPosition);
    
    
    if (OpenDialog->ShowModal() == wxID_OK)
    {
        CurrentDocPath = OpenDialog->GetPath();
        text->LoadFile(CurrentDocPath);
        wxString temp= OpenDialog->GetFilename();
        this->SetTitle( wxString(wxT("Edit - ")) + temp);
    }
}

void Frame::CloseFile(wxCommandEvent& WXUNUSED(event))
{
    text->Clear();
    CurrentDocPath = wxT("/");
    this->SetTitle(_("Edit - untitled *"));
}

void Frame::SaveFile(wxCommandEvent& WXUNUSED(event))
{
    text->SaveFile(CurrentDocPath);
}

void Frame::SaveFileAs(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog *SaveDialog = new wxFileDialog(this,("Save File As _?"), wxEmptyString, wxEmptyString,("Text files (*.txt)|*.txt|C++ Source Files (*.cpp)|*.cpp|C Source files (*.c)|*.c|C header files (*.h)|*.h"),wxFD_SAVE | wxFD_OVERWRITE_PROMPT,wxDefaultPosition);
    
    
    if (SaveDialog->ShowModal() == wxID_OK)
    {
        CurrentDocPath = SaveDialog->GetPath();
        text->SaveFile(CurrentDocPath);
    }
    
    SaveDialog->Destroy();
}

void Frame::Quit(wxCommandEvent& WXUNUSED(event))
{
    Close(TRUE);
}







